#pragma G++ optimize("O3")
#pragma GCC optimize("O3")
#include <cstdio>
#include <cctype>

using namespace std;

inline char getch() {
    static char buf[10], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 10, stdin), p1 == p2) ? EOF : *p1++;
}

inline int read() {
    char c;
    while(!isdigit(c = getch()));
    int res = c - '0';
    while(isdigit(c = getch())) res = res * 10 + c - '0';
    return res;
}

int main() {
    int n = read();
    printf("%d\n", n / 3 * 2 + (n % 3 > 0));
}
