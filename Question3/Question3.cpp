#pragma G++ optimize("O3")
#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>

using namespace std;

inline char getch() {
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}

inline int read() {
    char c;
    while(!isdigit(c = getch()) && c != EOF);
    if(c == EOF) return 0;
    int res = c ^ 48;
    while(isdigit(c = getch())) res = res * 10 + (c ^ 48);
    return res;
}

int main() {
    int n = read(), m = read(), x = read(), a[++n], b[++m], n2 = n, m2 = m;
    a[0] = b[0] = 0;
    for(register int i = 1; i < n; ++i) {
        a[i] = a[i - 1] + read();
        if(a[i] >= x) {
            n2 = i + (a[i] == x);
            while(++i < n) read();
        }
    }
    for(register int i = 1; i < m; ++i) {
        b[i] = b[i - 1] + read();
        if(b[i] >= x) {
            m2 = i + (b[i] == x);
            while(++i < m) read();
        }
    }
    int ans = 0, j;
    if(n2 <= m2)
        for(register int i = 0; i < n2; ++i) {
            j = upper_bound(b, b + m2, x - a[i]) - b;
            ans = max(ans, i + j - 1);
        }
    else
        for(register int i = 0; i < m2; ++i) {
            j = upper_bound(a, a + n2, x - b[i]) - a;
            ans = max(ans, i + j - 1);
        }
    printf("%d", ans);
    return 0;
}
