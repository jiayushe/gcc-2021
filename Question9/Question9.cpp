#include <bits/stdc++.h>

using namespace std;

#define LSOne(S) ((S) & -(S))

const int inf = 1e9;
int b, c;
vector<vector<vector<int>>> rsum;
vector<vector<int>> memo;

int solve(int curr, int mask) {
	if(curr == c) return 0;
	if(mask == 0) return inf;
	int& ans = memo[curr][mask];
	if(ans != inf) return ans;
	int m = mask;
	while(m) {
		int pow_v = LSOne(m);
		int new_mask = mask ^ pow_v;
		int v = __builtin_ctz(pow_v);
		auto& curr_rsum = rsum[v];
		ans = min(ans, solve(curr, new_mask));
		for(int nxt = curr; nxt < c; nxt++) {
			ans = min(ans, curr_rsum[curr][nxt] + solve(nxt + 1, new_mask));
		}
		m ^= pow_v;
	}
	return ans;
}

int bankersAndClients(vector<vector<int>>& time) {
	rsum.assign(b, vector<vector<int>>(c, vector<int>(c, 0)));
	for(int i = 0; i < b; i++) {
		auto& curr_time = time[i];
		auto& curr_rsum = rsum[i];
		for(int x = 0; x < c; x++) {
			curr_rsum[x][x] = curr_time[x];
			for(int y = x + 1; y < c; y++) {
				curr_rsum[x][y] = curr_rsum[x][y - 1] + curr_time[y];
			}
		}
	}
	memo.assign(c, vector<int>(1 << b, inf));
	return solve(0, (1 << b) - 1);
}

int main(){
	cin>>c>>b;
	int answer;
	vector<vector<int>> time(b, vector<int>(c));
	for(int i = 0; i < b; i++) {
		for(int j = 0; j < c; j++) {
			cin>>time[i][j];
		}
	}
	answer = bankersAndClients(time);
	// Do not remove below line
	cout << answer << endl;
	// Do not print anything after this line
	return 0;
}
