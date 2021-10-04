#include <bits/stdc++.h>

using namespace std;

int totalPairs(int n, vector<int>& values) {
    vector<int> v;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int curr = values[i];
        while(v.size()) {
            ans++;
            if(curr > v.back()) {
                v.pop_back();
            } else {
                break;
            }
        }
        v.push_back(curr);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> values(n);
    for(int i = 0; i < n; ++i) {
        cin>>values[i];
    }
    int answer = totalPairs(n, values);
    cout<<answer<<endl;
    return 0;
}
