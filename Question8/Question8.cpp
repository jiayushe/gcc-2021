#pragma G++ optimize("O3")
#pragma GCC optimize("O3")
#pragma comment(linker, "/STACK:102400000,102400000")
#include <cstring>
#include <cstdio>
#include <cctype>
#include <iostream>

using namespace std;

inline char getch() {
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}

inline int read() {
    char c;
    while(!isdigit(c = getch()));
    int res = c ^ 48;
    while(isdigit(c = getch())) res = res * 10 + (c ^ 48);
    return res;
}

int main() {
    int n = read(), k = read(), d = read(), m = read(), returns[n], rsum[n + 1][n + 1], memo[k][n];
    memset(rsum, 0, sizeof rsum);
    memset(memo, 0, sizeof memo);
    rsum[0][0] = returns[0] = read();
    for(register int j = 1; j < n; ++j) {
        returns[j] = read();
        rsum[0][j] = rsum[0][j - 1] + returns[j];
    }
    for(register int i = 1; i < n; ++i) {
        auto& curr_rsum = rsum[i];
        curr_rsum[i] = returns[i] * m;
        for(register int j = i + 1; j < n; ++j) {
            curr_rsum[j] = curr_rsum[j - 1] + returns[j] * (j - i < d ? m : 1);
        }
    }
    for(register int curr = n - 1; curr >= k - 1; --curr) {
        memo[k - 1][curr] = rsum[curr + 1][n - 1];
    }
    for(register int trans = k - 2; trans >= 0; --trans) {
        for(register int curr = n - k + trans; curr >= trans; --curr) {
            int &ans = memo[trans][curr];
            for(register int nxt = curr + 1; nxt <= n - k + trans + 1; ++nxt) {
                ans = max(ans, rsum[curr + 1][nxt - 1] + memo[trans + 1][nxt]);
            }
        }
    }
    int ans = memo[0][0];
    for(register int i = 1; i <= n - k; ++i) {
        ans = max(ans, rsum[0][i - 1] + memo[0][i]);
    }
    printf("%d", ans);
    return 0;
}
