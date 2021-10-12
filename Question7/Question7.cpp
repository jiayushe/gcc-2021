#pragma G++ optimize("O3")
#pragma GCC optimize("O3")
#include <cstring>
#include <cstdio>
#include <cctype>

using namespace std;
typedef unsigned long long ll;

#define MAXN 100000
#define MAXV 1000001
#define m 169

inline char getch() {
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}

inline int read() {
    char c;
    while(!isdigit(c = getch()));
    int res = c ^ 48;
    while(isdigit(c = getch())) res = res * 10 + (c ^ 48);
    return res;
}

const ll mod = 1e9 + 7;
int prime[] = {0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997};
int d[MAXN], rk[MAXN], prime_grp[MAXV], cnt;

inline int twopowmod(int p) {
    ll res = 1, a = 2;
    while(p) {
        if(p & 1) res = res * a % mod;
        a = a * a % mod, p >>= 1;
    }
    return res;
}

inline int find(int a) {
    if(d[a] == -1) return a;
    return d[a] = find(d[a]);
}

inline void join(int a, int b) {
    a = find(a), b = find(b);
    if(a == b) return;
    if(rk[a] == rk[b]) --rk[b];
    (rk[a] > rk[b]) ? d[a] = b : d[b] = a;
}

inline void update(int i, int f) {
    if(prime_grp[f] == -1) {
        prime_grp[f] = i;
    } else if(find(i) != find(prime_grp[f])) {
        join(i, prime_grp[f]);
        cnt--;
    }
}

int main() {
    int n = read(), curr, j, f;
    cnt = n;
    memset(prime_grp, -1, sizeof prime_grp);
    memset(d, -1, sizeof d);
    memset(rk, -1, sizeof rk);
    for(register int i = 0; i < n; ++i) {
        curr = read(), j = 1;
        while((f = prime[j]) * f <= curr) {
            if(curr % f == 0) update(i, f);
            while(curr % f == 0) curr /= f;
            if(++j == m) break;
        }
        if(curr != 1) update(i, curr);
    }
    int ans = (twopowmod(cnt) - 2) % mod;
    puts(ans ? "YES" : "NO");
    printf("%d", ans);
    return 0;
}
