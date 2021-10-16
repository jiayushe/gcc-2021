#pragma GCC optimize("Ofast,unroll-loops,inline")
#pragma GCC option("arch=native","tune=native","no-zero-upper")
#pragma GCC target("bmi,bmi2,lzcnt,popcnt,movbe,aes,pclmul,rdrnd,abm,mmx,avx,avx2,f16c,fma,sse,sse2,sse3,ssse3,sse4.1,sse4.2")
#include <cstdio>
#include <cctype>

using namespace std;

char buf[900000], *p = buf;
int curr;

__attribute__((optimize("-Ofast")))
inline void read() {
    while(!isdigit(*p)) ++p;
    curr = *p++ ^ 48;
    while(isdigit(*p)) curr = curr * 10 + (*p++ ^ 48);
}

__attribute__((optimize("-Ofast")))
int main() {
    fread(buf, 1, 900000, stdin);
    read();
    int n = curr, v[n], ans(0), k(0);
    for(int i = 0; i < n; ++i) {
        read();
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
