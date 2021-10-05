#pragma G++ optimize("O3")
#pragma GCC optimize("O3")
#pragma comment(linker, "/STACK:102400000,102400000")
#include <cstring>
#include <cstdio>
#include <cctype>
#include <algorithm>

using namespace std;

#define LSOne(S) ((S) & -(S))
#define MAXB 10
#define MAXC 20

inline char getch() {
    static char buf[1000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000, stdin), p1 == p2) ? EOF : *p1++;
}

inline int read() {
    char c;
    while(!isdigit(c = getch()));
    int res = c ^ 48;
    while(isdigit(c = getch())) res = res * 10 + (c ^ 48);
    return res;
}

const int inf = 1e9;
int b, c;
int t[MAXB][MAXC];
int rsum[MAXB][MAXC][MAXC];
int memo[MAXC][1<<MAXB];

int solve(int curr, int mask) {
    if(curr == c) return 0;
    if(mask == 0) return inf;
    int& ans = memo[curr][mask];
    if(ans != -1) return ans;
    ans = inf;
    int m = mask;
    while(m) {
        int pow_v = LSOne(m);
        int new_mask = mask ^ pow_v;
        int v = __builtin_ctz(pow_v);
        auto& curr_rsum = rsum[v];
        ans = min(ans, solve(curr, new_mask));
        for(register int nxt = curr; nxt < c; ++nxt) {
            ans = min(ans, curr_rsum[curr][nxt] + solve(nxt + 1, new_mask));
        }
        m ^= pow_v;
    }
    return ans;
}

int main() {
    c = read(), b = read();
    for(register int i = 0; i < b; ++i) {
        for(register int j = 0; j < c; ++j) {
            t[i][j] = read();
        }
    }
    memset(rsum, 0, sizeof rsum);
    memset(memo, -1, sizeof memo);
    for(register int i = 0; i < b; ++i) {
        auto& curr_time = t[i];
        auto& curr_rsum = rsum[i];
        for(register int x = 0; x < c; ++x) {
            curr_rsum[x][x] = curr_time[x];
            for(register int y = x + 1; y < c; ++y) {
                curr_rsum[x][y] = curr_rsum[x][y - 1] + curr_time[y];
            }
        }
    }
    printf("%d", solve(0, (1 << b) - 1));
    return 0;
}
