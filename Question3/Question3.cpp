#include <bits/stdc++.h>

using namespace std;

int portfolio_profit_maximisation(int x, vector<int> a, vector<int> b, int n, int m) {
    if(n > m) {
        swap(a, b);
        swap(n, m);
    }
    vector<int> ap, bp;
    ap.push_back(x);
    for(int i = 0; i < n; i++) {
        if(a[i] > ap[i]) break;
        ap.push_back(ap[i] - a[i]);
    }
    bp.push_back(0);
    for(int i = 0; i < m; i++) {
        if(b[i] > x - bp[i]) break;
        bp.push_back(bp[i] + b[i]);
    }
    n = ap.size();
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int j = upper_bound(bp.begin(), bp.end(), ap[i]) - bp.begin();
        ans = max(ans, i + j - 1);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, x;
    cin>>n>>m>>x;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin>>b[i];
    }
    int result = portfolio_profit_maximisation(x, a, b, n, m);
    cout<<result;
    return 0;
}
