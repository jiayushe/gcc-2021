#pragma GCC optimize("Ofast,unroll-loops,inline")
#pragma GCC option("arch=native","tune=native","no-zero-upper")
#pragma GCC target("bmi,bmi2,lzcnt,popcnt,movbe,aes,pclmul,rdrnd,abm,mmx,avx,avx2,f16c,fma,sse,sse2,sse3,ssse3,sse4.1,sse4.2")
#include <algorithm>
#include <cstdio>
#include <cctype>

using namespace std;

char buf[100000], *p = buf;

__attribute__((optimize("-Ofast")))
inline int read() {
    while(!isdigit(*p)) ++p;
    int res = *p++ ^ 48;
    while(isdigit(*p)) res = res * 10 + (*p++ ^ 48);
    return res;
}

__attribute__((optimize("-Ofast")))
inline int max_fast(int x, int y) {
    int m = (x - y) >> 31;
    return x + ((y - x) & m);
}

__attribute__((optimize("-Ofast")))
int main() {
    fread(buf, 1, 100000, stdin);
    int n = read(), m = read(), x = read(), a[++n], b[++m], n2 = n, m2 = m, ans(1);
    a[0] = b[0] = 0;
    for(register int i = 1; i < n; ++i) {
        a[i] = a[i - 1] + read();
        if(a[i] >= x) {
            n2 = i + (a[i] == x);
            while(++i < n) read();
        }
    }
    for(register int i = 1; i < m; ++i) {
        b[i] = b[i - 1] + read();
        if(b[i] >= x) {
            m2 = i + (b[i] == x);
            break;
        }
    }
    if(n2 < m2)
        for(register int i = 0; i < n2; ++i) {
            ans = max_fast(ans, (int)(upper_bound(b, b + m2, x - a[i]) - b) + i);
        }
    else
        for(register int i = 0; i < m2; ++i) {
            ans = max_fast(ans, (int)(upper_bound(a, a + n2, x - b[i]) - a) + i);
        }
    printf("%d", ans - 1);
    return 0;
}
