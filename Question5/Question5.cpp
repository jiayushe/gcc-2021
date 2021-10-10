#pragma G++ optimize("O3")
#pragma GCC optimize("O3")
#include <iostream>

using namespace std;

#define MAXN 100000

inline char getch() {
    static char buf[MAXN], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, MAXN, stdin), p1 == p2) ? EOF : *p1++;
}

inline string read_str() {
    char c;
    while(isspace(c = getch()) || c == EOF);
    string res = "";
    res += c;
    while(!isspace(c = getch()) && c != EOF) res += c;
    return res;
}

int main() {
    string s = read_str();
    int n = s.length();
    int one = 0, two = 0;
    for(int i = 0; i < n; ++i) {
        int j = i;
        while(j < n && s[j] == '0') ++j;
        int curr = j - i;
        if(curr > one) two = one, one = curr;
        else if(curr > two) two = curr;
        i = j;
    }
    putchar(((one & 1) && (one >> 1) + 1 > two) ? 'A' : 'B');
}
