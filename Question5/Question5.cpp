#pragma GCC optimize("Ofast,unroll-loops,inline")
#pragma GCC option("arch=native","tune=native","no-zero-upper")
#pragma GCC target("bmi,bmi2,lzcnt,popcnt,movbe,aes,pclmul,rdrnd,abm,mmx,avx,avx2,f16c,fma,sse,sse2,sse3,ssse3,sse4.1,sse4.2")
#include <cstdio>
#include <cctype>

using namespace std;

#define MAXN 100000

__attribute__((optimize("-Ofast")))
int main() {
    char buf[MAXN], *p1 = buf, *p2;
    p2 = p1 + fread(buf, 1, MAXN, stdin);
    int one = 0, two = 0;
    char c;
    while(isspace(*p1)) ++p1;
    while(p1 < p2 && !isspace(*p1)) {
        int curr = 0;
        while(*p1++ == '0') ++curr;
        if(curr > one) two = one, one = curr;
        else if(curr > two) two = curr;
    }
    putchar(((one & 1) && (one >> 1) + 1 > two) ? 'A' : 'B');
    return 0;
}
