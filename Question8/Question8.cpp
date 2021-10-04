#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;
int n, k, d, m;
vector<vector<int>> rsum;
vector<vector<int>> memo;

int solve(int curr, int trans) {
    int &ans = memo[curr][trans];
    if(ans != -inf) return ans;
    if(trans == k - 1) {
        ans = rsum[curr + 1][n - 1];
    } else {
        for(int i = curr + 1; i <= min(n - 1, n - k + trans + 1); i++) {
            ans = max(ans, rsum[curr + 1][i - 1] + solve(i, trans + 1));
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k>>d>>m;
    vector<int> returns(n);
    for(int i = 0; i < n; i++) {
        cin>>returns[i];
    }
    rsum.assign(n + 1, vector<int>(n + 1, 0));
    rsum[0][0] = returns[0];
    for(int j = 1; j < n; j++) {
        rsum[0][j] = rsum[0][j - 1] + returns[j];
    }
    for(int i = 1; i < n; i++) {
        rsum[i][i] = returns[i] * m;
        for(int j = i + 1; j < n; j++) {
            rsum[i][j] = rsum[i][j - 1] + returns[j] * (j - i < d ? m : 1);
        }
    }
    memo.assign(n, vector<int>(k, -inf));
    int ans = solve(0, 0);
    for(int i = 1; i <= n - k; i++) {
        ans = max(ans, rsum[0][i - 1] + solve(i, 0));
    }
    cout<<ans<<endl;
    return 0;
}
