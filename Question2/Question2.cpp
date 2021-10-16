#pragma GCC optimize("Ofast,unroll-loops,inline")
#pragma GCC option("arch=native","tune=native","no-zero-upper")
#pragma GCC target("bmi,bmi2,lzcnt,popcnt,movbe,aes,pclmul,rdrnd,abm,mmx,avx,avx2,f16c,fma,sse,sse2,sse3,ssse3,sse4.1,sse4.2")
#include <cstdio>
#include <cctype>
#include <algorithm>

using namespace std;

struct intpair {
    int first;
    int second;
};

__attribute__((optimize("-Ofast")))
inline int min_fast(int x, int y) {
    int m = (y - x) >> 31;
    return y & m | x & ~m;
}

__attribute__((optimize("-Ofast")))
int main() {
    char buf[120], *p1 = buf, *p2 = buf + fread(buf, 1, 120, stdin);
    int input, n(0), ans(0);
    intpair v[51];
    while(1) {
        while(p1 < p2 && !isdigit(*p1)) ++p1;
        if(p1 == p2) break;
        input = *p1++ ^ 48;
        while(isdigit(*p1)) input = input * 10 + (*p1++ ^ 48);
        v[n] = {input, n};
        ++n;
    }
    int z = v[0].first;
    sort(v + 1, v + n, [](const intpair& a, const intpair& b) { return a.first < b.first; });
    for(int i = 1; i < n; ++i) {
        auto& curr = v[i];
        if(z < curr.first) break;
        input = min_fast(z / curr.first, curr.second);
        ans += input;
        z -= input * curr.first;
    }
    printf("%d", ans);
    return 0;
}
