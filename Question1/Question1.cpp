#pragma G++ optimize("O3")
#pragma GCC optimize("O3")
#include <cstdio>
#include <cctype>

using namespace std;

int main() {
    char buf[16], *p = buf;
    fread(buf, 1, 16, stdin);
    int n = 0;
    while(isdigit(*p)) n = n * 10 + (*p++ ^ 48);
    printf("%d", n / 3 * 2 + (n % 3 > 0));
}
