#pragma G++ optimize("O3")
#pragma GCC optimize("O3")
#pragma comment(linker, "/STACK:102400000,102400000")
#include <vector>
#include <cstdio>

using namespace std;

inline char getch() {
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}

inline int read() {
    char c;
    while((c = getch()) < '0' || c > '9');
    int res = c - '0';
    while((c = getch()) >= '0' && c <= '9') res = res * 10 + c - '0';
    return res;
}

int n, k, d, m;
vector<vector<int>> rsum, memo;

int solve(int curr, int trans) {
    int &ans = memo[curr][trans];
    if(ans != -1) return ans;
    if(trans == k - 1) {
        ans = rsum[curr + 1][n - 1];
    } else {
        for(register int i = curr + 1; i <= min(n - 1, n - k + trans + 1); ++i) {
            ans = max(ans, rsum[curr + 1][i - 1] + solve(i, trans + 1));
        }
    }
    return ans;
}

int main() {
    n = read(), k = read(), d = read(), m = read();
    vector<int> returns(n);
    for(register int i = 0; i < n; ++i) {
        returns[i] = read();
    }
    rsum.assign(n + 1, vector<int>(n + 1, 0));
    rsum[0][0] = returns[0];
    for(register int j = 1; j < n; ++j) {
        rsum[0][j] = rsum[0][j - 1] + returns[j];
    }
    for(register int i = 1; i < n; ++i) {
        rsum[i][i] = returns[i] * m;
        for(register int j = i + 1; j < n; ++j) {
            rsum[i][j] = rsum[i][j - 1] + returns[j] * (j - i < d ? m : 1);
        }
    }
    memo.assign(n, vector<int>(k, -1));
    int ans = solve(0, 0);
    for(register int i = 1; i <= n - k; ++i) {
        ans = max(ans, rsum[0][i - 1] + solve(i, 0));
    }
    printf("%d", ans);
    return 0;
}
