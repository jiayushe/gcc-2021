#pragma GCC optimize("Ofast,unroll-loops,inline")
#pragma GCC option("arch=native","tune=native","no-zero-upper")
#pragma GCC target("bmi,bmi2,lzcnt,popcnt,movbe,aes,pclmul,rdrnd,abm,mmx,avx,avx2,f16c,fma,sse,sse2,sse3,ssse3,sse4.1,sse4.2")
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cstring>
#include <string>
#include <cstdio>

using namespace std;

#define MAXN 10000

int d[MAXN], cnt[MAXN], fcnt[MAXN], scnt[MAXN], tcnt[MAXN];

__attribute__((optimize("-Ofast")))
inline char getch() {
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}

__attribute__((optimize("-Ofast")))
inline int read() {
    char c;
    while(!isdigit(c = getch()));
    int res = c ^ 48;
    while(isdigit(c = getch())) res = res * 10 + (c ^ 48);
    return res;
}

__attribute__((optimize("-Ofast")))
inline string read_str() {
    char c;
    while(isspace(c = getch()) || c == EOF);
    string res = "";
    res += c;
    while(!isspace(c = getch()) && c != EOF) res += c;
    return res;
}

__attribute__((optimize("-Ofast")))
inline int find(int a) {
    if(d[a] == -1) return a;
    return d[a] = find(d[a]);
}

__attribute__((optimize("-Ofast")))
inline void join(int a, int b) {
    a = find(a), b = find(b);
    if(a == b) return;
    d[a] = b;
}

__attribute__((optimize("-Ofast")))
inline int myhash(string s) {
    int h = 2166136261, n = s.length(), i = 0;
    while(i < n) h *= 16777619, h ^= s[i++];
    return h;
}

__attribute__((optimize("-Ofast")))
int main() {
    int n = read(), m = read(), a = read() - 1, b = read(), f = read(), s = read(), t = read(), xg, yg;
    vector<string> idx_nme(n);
    unordered_map<int, int> nme_idx;
    memset(d, -1, sizeof d);
    for(register int i = 0; i < n; ++i) {
        idx_nme[i] = read_str();
        nme_idx[myhash(idx_nme[i])] = i;
        cnt[i] = 1;
        switch(read()) {
            case 1:
                fcnt[i]++; break;
            case 2:
                scnt[i]++; break;
            case 3:
                tcnt[i]++;
        }
    }
    do {
        xg = find(nme_idx[myhash(read_str())]), yg = find(nme_idx[myhash(read_str())]);
        if(xg != yg && cnt[xg] + cnt[yg] <= b && fcnt[xg] + fcnt[yg] <= f
            && scnt[xg] + scnt[yg] <= s && tcnt[xg] + tcnt[yg] <= t) {
            join(xg, yg);
            cnt[yg] += cnt[xg];
            fcnt[yg] += fcnt[xg];
            scnt[yg] += scnt[xg];
            tcnt[yg] += tcnt[xg];
        }
    } while(--m);
    vector<int> idxs;
    for(register int i = 0; i < n; ++i) {
        if(cnt[i] > a) a = cnt[i], idxs = {i};
        else if(cnt[i] == a && !idxs.empty()) idxs.push_back(i);
    }
    if(idxs.size() == 0) {
        puts("no groups");
        return 0;
    }
    int idx = idxs[0];
    for(auto i : idxs) join(i, idx);
    vector<string> res;
    for(register int i = 0; i < n; ++i)
        if(find(i) == idx) res.push_back(idx_nme[i]);
    sort(res.begin(), res.end());
    for(auto i : res) puts(i.c_str());
    return 0;
}
