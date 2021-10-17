#pragma GCC optimize("Ofast,unroll-loops,inline")
#pragma GCC option("arch=native","tune=native","no-zero-upper")
#pragma GCC target("bmi,bmi2,lzcnt,popcnt,movbe,aes,pclmul,rdrnd,abm,mmx,avx,avx2,f16c,fma,sse,sse2,sse3,ssse3,sse4.1,sse4.2")
#include <algorithm>
#include <cstdio>
#include <cctype>

using namespace std;
typedef unsigned int uint;

struct intpair {
    uint first;
    uint second;
};

__attribute__((optimize("-Ofast")))
int main() {
    char buf[200], *p1 = buf, *p2 = buf + fread(buf, 1, 200, stdin);
    uint input, n(0), ans(0);
    intpair v[51];
    while(1) {
        while(p1 < p2 && !isdigit(*p1)) ++p1;
        if(p1 == p2) break;
        input = *p1++ ^ 48;
        while(isdigit(*p1)) input = input * 10 + (*p1++ ^ 48);
        v[n] = {input, n};
        ++n;
    }
    uint z = v[0].first;
    sort(v + 1, v + n, [](const intpair& a, const intpair& b) { return a.first < b.first; });
    for(register uint i = 1; i < n; ++i) {
        auto& curr = v[i];
        if(z > curr.first * curr.second) {
            ans += curr.second;
            z -= curr.first * curr.second;
        } else {
            ans += z / curr.first;
            break;
        }
    }
    printf("%d", ans);
    return 0;
}
