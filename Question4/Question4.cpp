#pragma G++ optimize("O3")
#include <cstdio>

using namespace std;

inline int read() {
    char c;
    while((c = getchar()) < '0' || c > '9');
    int res = c - '0';
    while((c = getchar()) >= '0' && c <= '9') res = res * 10 + c - '0';
    return res;
}

int main() {
    int n = read();
    int v[n], ans = 0, curr, k = 0;
    for(int i = 0; i < n; i++) {
        curr = read();
        while(k) {
            ans++;
            if(curr > v[k - 1]) k--;
            else break;
        }
        v[k++] = curr;
    }
    printf("%d", ans);
    return 0;
}
