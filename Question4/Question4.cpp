#pragma GCC optimize("Ofast,unroll-loops,inline")
#pragma GCC option("arch=native","tune=native","no-zero-upper")
#pragma GCC target("bmi,bmi2,lzcnt,popcnt,movbe,aes,pclmul,rdrnd,abm,mmx,avx,avx2,f16c,fma,sse,sse2,sse3,ssse3,sse4.1,sse4.2")
#include <cstdio>
#include <cctype>

using namespace std;

#define SZ 100000

__attribute__((optimize("-Ofast")))
inline char getch() {
    static char buf[SZ], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, SZ, stdin), p1 == p2) ? EOF : *p1++;
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
int main() {
    int n = read(), v[n], ans = 0, curr, k = 0;
    for(int i = 0; i < n; ++i) {
        curr = read();
        while(k) {
            ++ans;
            if(curr > v[k - 1]) --k;
            else break;
        }
        v[k++] = curr;
    }
    printf("%d", ans);
    return 0;
}
