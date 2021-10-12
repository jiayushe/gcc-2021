#pragma GCC optimize("O3")
#include <stdio.h>
#include <ctype.h>

#define SZ 100000

char buf[SZ], *p1 = buf, *p2 = buf;

char getch();
int read();

inline char getch() {
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, SZ, stdin), p1 == p2) ? EOF : *p1++;
}

inline int read() {
    char c;
    while(!isdigit(c = getch()));
    int res = c ^ 48;
    while(isdigit(c = getch())) res = res * 10 + (c ^ 48);
    return res;
}

int main() {
    int n = read();
    int v[n], ans = 0, curr, k = 0;
    for(int i = 0; i < n; ++i) {
        curr = read();
        while(k) {
            ++ans;
            if(curr > v[k - 1]) --k;
            else break;
        }
        v[k++] = curr;
    }
    printf("%d", ans);
    return 0;
}
