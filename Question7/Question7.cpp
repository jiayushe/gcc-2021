#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;

ll twopowmod(ll p) {
    ll res = 1, a = 2;
    while(p) {
        if(p & 1) res = res * a % mod;
        a = a * a % mod, p >>= 1;
    }
    return res;
}

inline int find(vector<int>& d, int a) {
    if(d[a] == -1) return a;
    return d[a] = find(d, d[a]);
}

inline void join(vector<int>& d, int a, int b) {
    a = find(d, a), b = find(d, b);
    if(a == b) return;
    d[a] = b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> values(n);
    for(int i = 0; i < n; i++) cin>>values[i];
    int mx = *max_element(values.begin(), values.end());
    vector<int> prime, lp(mx + 1, 0);
    unordered_map<int, int> prime_map;
    for(int i = 2; i <= mx; i++) {
        if(lp[i] == 0)
            lp[i] = i, prime.push_back(i), prime_map[i] = prime.size() - 1;
        for(int j = 0; j < (int)prime.size() && i * prime[j] <= mx; j++)
            lp[i * prime[j]] = prime[j];
    }
    int m = prime.size();
    vector<int> prime_grp(m, -1), d(n, -1), pf;
    int cnt = n;
    for(int i = 0; i < n; i++) {
        pf.clear();
        int curr = values[i], j = 0, f = prime[j];
        while(f * f <= curr) {
            if(curr % f == 0) pf.push_back(j);
            while(curr % f == 0) curr /= f;
            if(++j == m) break;
            f = prime[j];
        }
        if(curr != 1) pf.push_back(prime_map[curr]);
        for(auto p : pf) {
            if(prime_grp[p] == -1) {
                prime_grp[p] = i;
            } else if(find(d, i) != find(d, prime_grp[p])) {
                join(d, i, prime_grp[p]);
                cnt--;
            }
        }
    }
    int ans = (twopowmod(cnt) - 2) % mod;
    cout<<(ans ? "YES\n" : "NO\n")<<ans<<endl;
    return 0;
}
