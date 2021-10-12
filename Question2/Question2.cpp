#pragma G++ optimize("O3")
#pragma GCC optimize("O3")
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct intpair {
    int first;
    int second;
};

inline char getch() {
    static char buf[1000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000, stdin), p1 == p2) ? EOF : *p1++;
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
    int z = read(), data, n = 0, ans = 0;
    vector<intpair> v;
    while((data = read())) v.push_back({data, ++n});
    sort(v.begin(), v.end(), [](const intpair& a, const intpair& b) { return a.first < b.first; });
    for(int i = 0; i < n; ++i) {
        auto& curr = v[i];
        if(z < curr.first) break;
        int x = min(z / curr.first, curr.second);
        ans += x;
        z -= x * curr.first;
    }
    printf("%d", ans);
    return 0;
}
