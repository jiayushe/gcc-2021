#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define LSOne(S) ((S) & -(S))
#define MAXB 10
#define MAXC 20

const int inf = 1e9;
int b, c;
int t[MAXB][MAXC];
int rsum[MAXB][MAXC][MAXC];
int memo[MAXC][1<<MAXB];

int solve(int curr, int mask) {
    if(curr == c) return 0;
    if(mask == 0) return inf;
    int& ans = memo[curr][mask];
    if(ans != -1) return ans;
    ans = inf;
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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>c>>b;
    for(int i = 0; i < b; i++) {
        for(int j = 0; j < c; j++) {
            cin>>t[i][j];
        }
    }
    memset(rsum, 0, sizeof rsum);
    memset(memo, -1, sizeof memo);
    for(int i = 0; i < b; i++) {
        auto& curr_time = t[i];
        auto& curr_rsum = rsum[i];
        for(int x = 0; x < c; x++) {
            curr_rsum[x][x] = curr_time[x];
            for(int y = x + 1; y < c; y++) {
                curr_rsum[x][y] = curr_rsum[x][y - 1] + curr_time[y];
            }
        }
    }
    cout<<solve(0, (1 << b) - 1);
    return 0;
}
