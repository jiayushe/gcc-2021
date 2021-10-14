#pragma GCC optimize("Ofast,unroll-loops,inline")
#pragma GCC option("arch=native","tune=native","no-zero-upper")
#pragma GCC target("bmi,bmi2,lzcnt,popcnt,movbe,aes,pclmul,rdrnd,abm,mmx,avx,avx2,f16c,fma,sse,sse2,sse3,ssse3,sse4.1,sse4.2")
#include <cstdio>
#include <cctype>

using namespace std;
typedef unsigned long long ll;

#define MAXN 100000
#define MAXV 500000
#define m 169

__attribute__((optimize("-Ofast")))
inline char getch() {
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}

__attribute__((optimize("-Ofast")))
inline int read() {
    char c;
    while(!isdigit(c = getch()));
    int res = c ^ 48;
    while(isdigit(c = getch())) res = res * 10 + (c ^ 48);
    return res;
}

const ll mod = 1e9 + 7;
int prime[] = {0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997};
int d[MAXN], prime_grp[MAXV], cnt;

__attribute__((optimize("-Ofast")))
inline int find(int a) {
    if(!d[a]) return a;
    return d[a] = find(d[a]);
}

__attribute__((optimize("-Ofast")))
inline void join(int a, int b) {
    a = find(a), b = find(b);
    if(a == b) return;
    d[a] = b;
}

__attribute__((optimize("-Ofast")))
inline void update(int i, int f) {
    f = (f + 1) >> 1;
    if(!prime_grp[f]) {
        prime_grp[f] = i;
    } else if(find(i) != find(prime_grp[f])) {
        join(i, prime_grp[f]);
        cnt--;
    }
}

__attribute__((optimize("-Ofast")))
int main() {
    int n = read(), curr, j, f;
    cnt = n;
    for(register int i = 1; i <= n; ++i) {
        curr = read(), j = 1, f = prime[j];
        do {
            if(curr % f == 0) {
                update(i, f);
                do { curr /= f; } while(curr % f == 0);
            }
            if(++j == m) break;
            f = prime[j];
        } while(f * f <= curr);
        if(curr != 1) update(i, curr);
    }
    ll ans = 1, a = 2;
    do {
        if(cnt & 1) ans = ans * a % mod;
        a = a * a % mod, cnt >>= 1;
    } while(cnt);
    ans -= 2;
    puts(ans ? "YES" : "NO");
    printf("%d", ans);
    return 0;
}
