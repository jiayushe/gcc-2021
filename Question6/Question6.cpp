#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

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

void theHackathon(int n, int m, int a, int b, int f, int s, int t) {
    // Participant code here
    string x, y;
    int g;
    unordered_map<int, string> idx_nme;
    unordered_map<string, int> nme_idx;
	vector<int> d(n, -1), cnt(n, 1), fcnt(n, 0), scnt(n, 0), tcnt(n, 0);
    for(int i = 0; i < n; i++) {
		cin>>x>>g;
		idx_nme[i] = x;
		nme_idx[x] = i;
		switch(g) {
			case 1:
				fcnt[i]++;
				break;
			case 2:
				scnt[i]++;
				break;
			default:
				tcnt[i]++;
		}
	}
	for(int i = 0; i < m; i++) {
		cin>>x>>y;
		int xg = find(d, nme_idx[x]), yg = find(d, nme_idx[y]);
		if(xg != yg && cnt[xg] + cnt[yg] <= b && fcnt[xg] + fcnt[yg] <= f
			&& scnt[xg] + scnt[yg] <= s && tcnt[xg] + tcnt[yg] <= t) {
			join(d, xg, yg);
			cnt[yg] += cnt[xg];
			fcnt[yg] += fcnt[xg];
			scnt[yg] += scnt[xg];
			tcnt[yg] += tcnt[xg];
		}
	}
	int mx = a - 1;
	vector<int> idxs;
	for(int i = 0; i < n; i++) {
		if(cnt[i] > mx) {
			mx = cnt[i];
			idxs = {i};
		} else if(cnt[i] == mx && idxs.size()) {
			idxs.push_back(i);
		}
	}
	if(idxs.size() == 0) {
		cout<<"no groups";
		return;
	}
	int idx = idxs[0];
	for(auto i : idxs) {
		join(d, i, idx);
	}
	vector<string> res;
	for(int i = 0; i < n; i++) {
		if(find(d, i) == idx) {
			res.push_back(idx_nme[i]);
		}
	}
	sort(res.begin(), res.end());
	for(auto i : res) {
		cout<<i<<"\n";
	}
}

int main()
{
    string inputdata_temp;
    getline(cin, inputdata_temp);

    vector<string> inputdata = split_string(inputdata_temp);

    int n = stoi(inputdata[0]);

    int m = stoi(inputdata[1]);

    int a = stoi(inputdata[2]);

    int b = stoi(inputdata[3]);

    int f = stoi(inputdata[4]);

    int s = stoi(inputdata[5]);

    int t = stoi(inputdata[6]);

    theHackathon(n, m, a, b, f, s, t);

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
