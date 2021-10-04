#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int z, data, n = 0, ans = 0;
    cin>>z;
    cin.ignore();
    string buffer;
    getline(cin, buffer);
    istringstream iss(buffer);
    vector<pair<int, int>> v;
    while(iss>>data) v.push_back({data, ++n});
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++) {
        auto& curr = v[i];
        if(z < curr.first) break;
        int x = min(z / curr.first, curr.second);
        ans += x;
        z -= x * curr.first;
    }
    cout<<ans<<endl;
    return 0;
}
