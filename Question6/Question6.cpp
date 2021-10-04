#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cstring>

using namespace std;

#define MAXN 10000

int d[MAXN], cnt[MAXN], fcnt[MAXN], scnt[MAXN], tcnt[MAXN];

inline int find(int a) {
    if(d[a] == -1) return a;
    return d[a] = find(d[a]);
}

inline void join(int a, int b) {
    a = find(a), b = find(b);
    if(a == b) return;
    d[a] = b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, a, b, f, s, t, g, xg, yg;
    cin>>n>>m>>a>>b>>f>>s>>t;
    string x, y;
    unordered_map<int, string> idx_nme;
    unordered_map<string, int> nme_idx;
    memset(d, -1, sizeof d);
    for(int i = 0; i < n; i++) {
        cin>>x>>g;
        idx_nme[i] = x;
        nme_idx[x] = i;
        cnt[i] = 1;
        if(g == 1) fcnt[i]++;
        else if(g == 2) scnt[i]++;
        else tcnt[i]++;
    }
    for(int i = 0; i < m; i++) {
        cin>>x>>y;
        xg = find(nme_idx[x]), yg = find(nme_idx[y]);
        if(xg != yg && cnt[xg] + cnt[yg] <= b && fcnt[xg] + fcnt[yg] <= f
            && scnt[xg] + scnt[yg] <= s && tcnt[xg] + tcnt[yg] <= t) {
            join(xg, yg);
            cnt[yg] += cnt[xg];
            fcnt[yg] += fcnt[xg];
            scnt[yg] += scnt[xg];
            tcnt[yg] += tcnt[xg];
        }
    }
    int mx = a - 1;
    vector<int> idxs;
    for(int i = 0; i < n; i++) {
        if(cnt[i] > mx) mx = cnt[i], idxs = {i};
        else if(cnt[i] == mx && idxs.size()) idxs.push_back(i);
    }
    if(idxs.size() == 0) {
        cout<<"no groups"<<endl;
        return 0;
    }
    int idx = idxs[0];
    for(auto i : idxs) join(i, idx);
    vector<string> res;
    for(int i = 0; i < n; i++)
        if(find(i) == idx) res.push_back(idx_nme[i]);
    sort(res.begin(), res.end());
    for(auto i : res) cout<<i<<"\n";
    return 0;
}
