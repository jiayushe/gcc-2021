#pragma GCC optimize("Ofast,unroll-loops,inline")
#pragma GCC option("arch=native","tune=native","no-zero-upper")
#pragma GCC target("bmi,bmi2,lzcnt,popcnt,movbe,aes,pclmul,rdrnd,abm,mmx,avx,avx2,f16c,fma,sse,sse2,sse3,ssse3,sse4.1,sse4.2")
#include <cstdio>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

__attribute__((optimize("-Ofast")))
struct intpair {
    int first;
    int second;
};

__attribute__((optimize("-Ofast")))
inline char getch() {
    static char buf[1000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000, stdin), p1 == p2) ? EOF : *p1++;
}

__attribute__((optimize("-Ofast")))
inline int read() {
    char c;
    while(!isdigit(c = getch()) && c != EOF);
    if(c == EOF) return 0;
    int res = c ^ 48;
    while(isdigit(c = getch())) res = res * 10 + (c ^ 48);
    return res;
}

__attribute__((optimize("-Ofast")))
inline int min_fast(int x, int y) {
    int m = (y - x) >> 31;
    return y & m | x & ~m;
}

__attribute__((optimize("-Ofast")))
int main() {
    int z = read(), data, n = 0, ans = 0;
    vector<intpair> v;
    while((data = read())) v.push_back({data, ++n});
    sort(v.begin(), v.end(), [](const intpair& a, const intpair& b) { return a.first < b.first; });
    for(int i = 0; i < n; ++i) {
        auto& curr = v[i];
        if(z < curr.first) break;
        int x = min_fast(z / curr.first, curr.second);
        ans += x;
        z -= x * curr.first;
    }
    printf("%d", ans);
    return 0;
}
