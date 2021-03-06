#pragma GCC optimize("Ofast,unroll-loops,inline")
#pragma GCC option("arch=native","tune=native","no-zero-upper")
#pragma GCC target("bmi,bmi2,lzcnt,popcnt,movbe,aes,pclmul,rdrnd,abm,mmx,avx,avx2,f16c,fma,sse,sse2,sse3,ssse3,sse4.1,sse4.2")
#include <cstring>
#include <cstdio>
#include <cctype>

using namespace std;

#define LSOne(S) ((S) & -(S))
#define inf 100000

char buf[800], *p = buf;

__attribute__((optimize("-Ofast")))
inline int read() {
    while(!isdigit(*p)) ++p;
    int res = *p++ ^ 48;
    while(isdigit(*p)) res = res * 10 + (*p++ ^ 48);
    return res;
}

__attribute__((optimize("-Ofast")))
inline int min_fast(int x, int y) {
    int m = (y - x) >> 31;
    return y & m | x & ~m;
}

__attribute__((optimize("-Ofast")))
int main() {
    fread(buf, 1, 800, stdin);
    int c = read(), b = read(), k;
    int rsum[b][c][c], memo[1<<b][c+1];
    memset(rsum, 0, sizeof rsum);
    memset(memo, 0, sizeof memo);
    for(register int i = 0; i < b; ++i) {
        auto& curr_rsum = rsum[i];
        for(register int x = 0; x < c; ++x) {
            curr_rsum[x][x] = k = read();
            for(register int y = 0; y < x; ++y) {
                curr_rsum[y][x] = curr_rsum[y][x - 1] + k;
            }
        }
    }
    for(register int curr = 0; curr < c; ++curr) memo[0][curr] = inf;
    k = (1<<b) - 1;
    for(register int mask = 1; mask <= k; ++mask) {
        for(register int curr = c - 1; curr >= 0; --curr) {
            int& ans = memo[mask][curr] = inf;
            int m = mask;
            do {
                int pow_v = LSOne(m), new_mask = mask ^ pow_v, nxt = curr;
                auto& curr_memo = memo[new_mask];
                ans = min_fast(ans, curr_memo[curr]);
                auto& curr_rsum = rsum[__builtin_ctz(pow_v)];
                do { ans = min_fast(ans, curr_rsum[curr][nxt] + curr_memo[++nxt]); } while(nxt < c);
                m ^= pow_v;
            } while(m);
        }
    }
    printf("%d", memo[k][0]);
    return 0;
}
