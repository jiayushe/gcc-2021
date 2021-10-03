#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;

ll powmod(ll a, ll b) {
	ll res = 1; a %= mod;
	for(; b; b >>= 1) {
		if(b&1) res = res * a % mod;
		a = a * a % mod;
	}
	return res;
}

int find(vector<int>& d, int a) {
    if(d[a] == -1) return a;
    return d[a] = find(d, d[a]);
}

void join(vector<int>& d, int a, int b) {
    a = find(d, a);
    b = find(d, b);
    if(a == b) return;
    d[a] = b;
}

void countStablePartitions(int n, vector<int>& values) {
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
	vector<int> prime_grp(m, -1);
	vector<int> d(n, -1);
	int cnt = n;
	for(int i = 0; i < n; i++) {
		int curr = values[i], j = 0, f = prime[j];
		vector<int> pf;
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
			} else {
				if(find(d, i) != find(d, prime_grp[p])) {
					join(d, i, prime_grp[p]);
					cnt--;
				}
			}
		}
	}
	if(cnt == 1) {
		cout<<"NO\n0";
	} else {
		cout<<"YES\n"<<(powmod(2, cnt) + mod - 2) % mod;
	}
}

int main(){
   int n;
   cin >> n;
   vector<int> values(n);
   for (int i = 0; i < n; ++i) {
        cin >> values[i];
   }
   countStablePartitions(n, values);
   return 0;
}
