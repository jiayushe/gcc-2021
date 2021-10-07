#pragma G++ optimize("O3")
#pragma GCC optimize("O3")
#pragma comment(linker, "/STACK:102400000,102400000")
#include <cstring>
#include <cstdio>
#include <cctype>
#include <iostream>

using namespace std;

#define LSOne(S) ((S) & -(S))
#define MAXB 10
#define MAXC 21
#define inf 100000

char buf[1000], *p = buf;
int rsum[MAXB][MAXC][MAXC], memo[1<<MAXB][MAXC];

inline int read() {
    char c;
    while(!isdigit(c = *p++));
    int res = c ^ 48;
    while(isdigit(c = *p++)) res = res * 10 + (c ^ 48);
    return res;
}

int main() {
    fread(buf, 1, 1000, stdin);
    int c = read(), b = read();
    memset(rsum, 0, sizeof rsum);
    memset(memo, 0, sizeof memo);
    for(register int i = 0; i < b; ++i) {
        auto& curr_rsum = rsum[i];
        curr_rsum[0][0] = read();
        for(register int y = 1; y < c; ++y) {
            curr_rsum[0][y] = curr_rsum[0][y - 1] + read();
        }
        for(register int x = 1; x < c; ++x) {
            for(register int y = x; y < c; ++y) {
                curr_rsum[x][y] = curr_rsum[x - 1][y] - curr_rsum[x - 1][x - 1];
            }
        }
    }
    for(register int curr = 0; curr < c; ++curr) memo[0][curr] = inf;
    for(register int mask = 1; mask < (1<<b); ++mask) {
        auto& curr_memo = memo[mask];
        for(register int curr = c - 1; curr >= 0; --curr) {
            int& ans = curr_memo[curr] = inf;
            int m = mask;
            while(m) {
                int pow_v = LSOne(m);
                int new_mask = mask ^ pow_v;
                auto& curr_rsum = rsum[__builtin_ctz(pow_v)];
                ans = min(ans, memo[new_mask][curr]);
                int nxt = curr;
                while(nxt < c) ans = min(ans, curr_rsum[curr][nxt] + memo[new_mask][++nxt]);
                m ^= pow_v;
            }
        }
    }
    printf("%d", memo[(1<<b) - 1][0]);
    return 0;
}
