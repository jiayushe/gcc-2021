#pragma GCC optimize("Ofast,unroll-loops,inline")
#pragma GCC option("arch=native","tune=native","no-zero-upper")
#pragma GCC target("bmi,bmi2,lzcnt,popcnt,movbe,aes,pclmul,rdrnd,abm,mmx,avx,avx2,f16c,fma,sse,sse2,sse3,ssse3,sse4.1,sse4.2")
#include <cstring>
#include <cstdio>
#include <cctype>

using namespace std;

char buf[10000], *p = buf;

__attribute__((optimize("-Ofast")))
inline int read() {
    while(!isdigit(*p)) ++p;
    int res = *p++ ^ 48;
    while(isdigit(*p)) res = res * 10 + (*p++ ^ 48);
    return res;
}

__attribute__((optimize("-Ofast")))
inline int max_fast(int x, int y) {
    int m = (x - y) >> 31;
    return x + ((y - x) & m);
}

__attribute__((optimize("-Ofast")))
int main() {
    fread(buf, 1, 10000, stdin);
    int n = read(), k = read(), d = read(), m = read(), returns[n], rsum[n + 1][n + 1], memo[k][n];
    memset(rsum, 0, sizeof rsum);
    memset(memo, 0, sizeof memo);
    rsum[0][0] = returns[0] = read();
    for(register int j = 1; j < n; ++j) {
        returns[j] = read();
        rsum[0][j] = rsum[0][j - 1] + returns[j];
    }
    for(register int i = 1; i < n; ++i) {
        auto& curr_rsum = rsum[i];
        curr_rsum[i] = returns[i] * m;
        for(register int j = i + 1; j < n; ++j) {
            curr_rsum[j] = curr_rsum[j - 1] + returns[j] * (j - i < d ? m : 1);
        }
    }
    for(register int curr = n - 1; curr >= k - 1; --curr) {
        memo[k - 1][curr] = rsum[curr + 1][n - 1];
    }
    for(register int trans = k - 2; trans >= 0; --trans) {
        for(register int curr = n - k + trans; curr >= trans; --curr) {
            int &ans = memo[trans][curr];
            for(register int nxt = curr + 1; nxt <= n - k + trans + 1; ++nxt) {
                ans = max_fast(ans, rsum[curr + 1][nxt - 1] + memo[trans + 1][nxt]);
            }
        }
    }
    int ans = memo[0][0];
    for(register int i = 1; i <= n - k; ++i) {
        ans = max_fast(ans, rsum[0][i - 1] + memo[0][i]);
    }
    printf("%d", ans);
    return 0;
}
