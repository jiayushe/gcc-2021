#include <bits/stdc++.h>
using namespace std;
 
int securitiesBuying(int z, int security_value[], int n) {
    int no_of_stocks = 0;
	// participants code here
	vector<pair<int, int>> v;
	for(int i = 0; i < n; i++) {
		v.push_back({security_value[i], i + 1});
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < n; i++) {
		auto& curr = v[i];
		if(z < curr.first) {
			break;
		}
		int x = min(z / curr.first, curr.second);
		no_of_stocks += x;
		z -= x * curr.first;
	}
    return no_of_stocks;
}
 
int main(){
	int z;
	cin>>z;
	vector<int> input_data;
	string buffer;
	int data;
	getline(cin, buffer);
	getline(cin, buffer);
	istringstream iss(buffer);
	while (iss >> data)
		input_data.push_back(data);
	int n = input_data.size(); 
	int security_value[n];
	for (int i = 0; i < n; i++) {
		security_value[i] = input_data[i];
	}
	int no_of_stocks_purchased = securitiesBuying(z, security_value, n);
	cout << no_of_stocks_purchased;
}
