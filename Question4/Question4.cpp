#include <vector>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> v;
    int ans = 0, curr;
    for(int i = 0; i < n; i++) {
        cin>>curr;
        while(v.size()) {
            ans++;
            if(curr > v.back()) v.pop_back();
            else break;
        }
        v.push_back(curr);
    }
    cout<<ans<<endl;
    return 0;
}
