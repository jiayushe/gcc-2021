#pragma GCC optimize("Ofast,unroll-loops,inline")
#pragma GCC option("arch=native","tune=native","no-zero-upper")
#pragma GCC target("bmi,bmi2,lzcnt,popcnt,movbe,aes,pclmul,rdrnd,abm,mmx,avx,avx2,f16c,fma,sse,sse2,sse3,ssse3,sse4.1,sse4.2")
#include <stdio.h>
#include <ctype.h>

__attribute__((optimize("-Ofast")))
int main() {
    char buf[16], *p = buf;
    fread(buf, 1, 16, stdin);
    int n = 0;
    while(isdigit(*p)) n = n * 10 + (*p++ ^ 48);
    printf("%d", ((n / 3) << 1) + (n % 3 > 0));
}
