#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;
int prime[] = {0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997};
int m = 169;

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
    vector<int> prime_grp(mx + 1, -1), d(n, -1), pf;
    int cnt = n;
    for(int i = 0; i < n; i++) {
        pf.clear();
        int curr = values[i], j = 1, f = prime[j];
        while(f * f <= curr) {
            if(curr % f == 0) pf.push_back(f);
            while(curr % f == 0) curr /= f;
            if(++j == m) break;
            f = prime[j];
        }
        if(curr != 1) pf.push_back(curr);
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
