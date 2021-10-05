#pragma G++ optimize("O3")
#pragma GCC optimize("O3")
#pragma comment(linker, "/STACK:102400000,102400000")
#include <cstring>
#include <vector>
#include <cstdio>
#include <cctype>

using namespace std;

#define MAXN 5001

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
    int n = read(), k = read(), d = read(), m = read(), returns[MAXN];
    for(register int i = 0; i < n; ++i) {
        returns[i] = read();
    }
    vector<vector<int>> rsum(n + 1, vector<int>(n + 1)), memo(k, vector<int>(n));
    rsum[0][0] = returns[0];
    for(register int j = 1; j < n; ++j) {
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
