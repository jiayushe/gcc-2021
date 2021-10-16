#pragma GCC optimize("Ofast,unroll-loops,inline")
#pragma GCC option("arch=native","tune=native","no-zero-upper")
#pragma GCC target("bmi,bmi2,lzcnt,popcnt,movbe,aes,pclmul,rdrnd,abm,mmx,avx,avx2,f16c,fma,sse,sse2,sse3,ssse3,sse4.1,sse4.2")
#include <cstdio>
#include <cctype>

using namespace std;

__attribute__((optimize("-Ofast")))
int main() {
    char buf[100000], *p = buf;
    fread(buf, 1, 100000, stdin);
    int one(0), two(0);
    while(!isdigit(*p)) ++p;
    while(isdigit(*p)) {
        int curr = 0;
        while(*p++ == 48) ++curr;
        if(curr > one) two = one, one = curr;
        else if(curr > two) two = curr;
    }
    putchar(((one & 1) && (one >> 1) >= two) ? 'A' : 'B');
    return 0;
}
