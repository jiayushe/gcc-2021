#pragma GCC optimize("Ofast,unroll-loops,inline")
#pragma GCC option("arch=native","tune=native","no-zero-upper")
#pragma GCC target("bmi,bmi2,lzcnt,popcnt,movbe,aes,pclmul,rdrnd,abm,mmx,avx,avx2,f16c,fma,sse,sse2,sse3,ssse3,sse4.1,sse4.2")
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define MAXN 10000

int d[MAXN], cnt[MAXN], fcnt[MAXN], scnt[MAXN], tcnt[MAXN];

char buf[150000], *p = buf;

__attribute__((optimize("-Ofast")))
inline int read() {
    while(!isdigit(*p)) ++p;
    int res = *p++ ^ 48;
    while(isdigit(*p)) res = res * 10 + (*p++ ^ 48);
    return res;
}

__attribute__((optimize("-Ofast")))
inline string read_str() {
    while(!isalnum(*p)) ++p;
    string res = "";
    do { res += *p++; } while(isalnum(*p));
    return res;
}

__attribute__((optimize("-Ofast")))
inline int find(int a) {
    if(d[a] == -1) return a;
    return d[a] = find(d[a]);
}

__attribute__((optimize("-Ofast")))
inline int myhash(string s) {
    int h = 2166136261, n = s.length(), i = 0;
    while(i < n) h *= 16777619, h ^= s[i++];
    return h;
}

__attribute__((optimize("-Ofast")))
inline int max_fast(int x, int y) {
    int m = (x - y) >> 31;
    return x + ((y - x) & m);
}

__attribute__((optimize("-Ofast")))
int main() {
    fread(buf, 1, 150000, stdin);
    int n = read(), m = read(), a = read(), b = read(), f = read(), s = read(), t = read(), xg, yg;
    string idx_nme[n];
    gp_hash_table<int, int> nme_idx;
    memset(d, -1, sizeof d);
    for(register int i = 0; i < n; ++i) {
        idx_nme[i] = read_str();
        nme_idx[myhash(idx_nme[i])] = i;
        cnt[i] = 1;
        switch(read()) {
            case 1: ++fcnt[i]; break;
            case 2: ++scnt[i]; break;
            case 3: ++tcnt[i];
        }
    }
    int mx(1);
    do {
        xg = find(nme_idx[myhash(read_str())]), yg = find(nme_idx[myhash(read_str())]);
        if(xg != yg && cnt[xg] + cnt[yg] <= b && fcnt[xg] + fcnt[yg] <= f
            && scnt[xg] + scnt[yg] <= s && tcnt[xg] + tcnt[yg] <= t) {
            d[xg] = yg;
            cnt[yg] += cnt[xg];
            fcnt[yg] += fcnt[xg];
            scnt[yg] += scnt[xg];
            tcnt[yg] += tcnt[xg];
            mx = max_fast(mx, cnt[yg]);
        }
    } while(--m);
    if(mx < a) {
        puts("no groups");
        return 0;
    }
    for(register int i = 0; i < n; ++i) if(cnt[find(i)] == mx) idx_nme[m++] = idx_nme[i];
    sort(idx_nme, idx_nme + m);
    for(register int i = 0; i < m; ++i) puts(idx_nme[i].c_str());
    return 0;
}
