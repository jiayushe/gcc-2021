#include <bits/stdc++.h>

using namespace std;
int totalPairs(int n, vector<int>& values) {
    // Complete the total pairs function
    vector<int> v;
    int ans = 0;
    for(int i = 0; i < n; i++) {
		int curr = values[i];
		while(v.size()) {
			ans++;
			int prev = v.back();
			if(curr >= prev) {
				v.pop_back();
			}
			if(curr <= prev) {
				break;
			}
		}
		v.push_back(curr);
	}
    return ans;
}

int main(){
   int n;
   cin >> n;
   vector<int> values(n);
   for (int i = 0; i < n; ++i) {
        cin >> values[i];
   }
	int answer = totalPairs(n, values);
    // Do not remove below line
    cout << answer << endl;
    // Do not print anything after this line
        
    return 0;
}
