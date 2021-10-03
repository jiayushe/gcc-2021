#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;
int n, k, d, m;
vector<int> returns;
vector<vector<int>> rsum;
vector<vector<int>> memo;

int solve(int curr, int trans) {
	int &ans = memo[curr][trans];
	if(ans != -inf) return ans;
	if(trans == k - 1) {
		ans = rsum[curr + 1][n - 1];
	} else {
		for(int i = curr + 1; i <= min(n - 1, n - k + trans + 1); i++) {
			ans = max(ans, rsum[curr + 1][i - 1] + solve(i, trans + 1));
		}
	}
	return ans;
}

int calculateMaximizedReturns() {
    // Participant's code will go here
    rsum.assign(n + 1, vector<int>(n + 1, 0));
    rsum[0][0] = returns[0];
    for(int j = 1; j < n; j++) {
		rsum[0][j] = rsum[0][j - 1] + returns[j];
	}
    for(int i = 1; i < n; i++) {
		rsum[i][i] = returns[i] * m;
		for(int j = i + 1; j < n; j++) {
			rsum[i][j] = rsum[i][j - 1] + returns[j] * (j - i < d ? m : 1);
		}
	}
    memo.assign(n, vector<int>(k, -inf));
    int ans = solve(0, 0);
    for(int i = 1; i <= n - k; i++) {
		ans = max(ans, rsum[0][i - 1] + solve(i, 0));
	}
    return ans;
}

vector<int> splitStringToInt(const string& str, char delim) {
    vector<int> strings;
    size_t start;
    size_t end = 0;
    while ((start = str.find_first_not_of(delim, end)) != string::npos) {
        end = str.find(delim, start);
        strings.push_back(stoi(str.substr(start, end - start)));
    }
    return strings;
}

int main() {
    string firstLine;
    getline(cin, firstLine);

    vector<int> firstLineVec = splitStringToInt(firstLine, ' ');
    n = firstLineVec[0];
    k = firstLineVec[1];
    d = firstLineVec[2];
    m = firstLineVec[3];

    string returnsStr;
    getline(cin, returnsStr);

    returns = splitStringToInt(returnsStr, ' ');

    int result = calculateMaximizedReturns();

    // Do not remove below line
    cout << result << "\n";
    // Do not print anything after this line

    return 0;
}
