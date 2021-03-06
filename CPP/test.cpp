#include <functional>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <climits>
#include <utility>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <cctype>
#include <bitset>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <deque>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <new>
#include <map>
#include <set>

using namespace std;
//#pragma comment(linker, "/STACK:102400000,102400000")

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef vector<int> vec;
typedef vector<vec> mat;
#define PB push_back
#define MP(a, b) make_pair(a, b)
#define FI first
#define SE second
#define gcd(x, y) __gcd(x, y)
#define gcd3(x, y, z) __gcd(__gcd(x, y), z)

const double EPS = 1e-15;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MAXN = 200000 + 10;
const int MOD = 1000000007;

LL bit[MAXN], bit1[MAXN], n;

LL sum(int i) {
    LL s = 0;
    while (i > 0) {
        (s += bit[i]) %= MOD;
        i -= i & -i;
    }
    return s;
}

void add(int i, LL x) {
    while (i <= 10000) {
        (bit[i] += x) %= MOD;
        i += i & -i;
    }
}

LL sum1(int i) {
    LL s = 0;
    while (i > 0) {
        (s += bit1[i]) %= MOD;
        i -= i & -i;
    }
    return s;
}

void add1(int i, LL x) {
    while (i <= 10000) {
        (bit1[i] += x) %= MOD;
        i += i & -i;
    }
}

struct node {
    LL p, v;
    bool operator < (const node& rhs) const {
        return p < rhs.p;
    }
};

node a[MAXN];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a[i].p);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a[i].v);
    }
    sort(a, a + n);
    LL ans = 0;
    for (int i = 0; i < n; ++i) {
        LL cnt = sum(a[i].v);
        LL s = sum1(a[i].v);
        (ans += (((cnt * a[i].p - s) % MOD + MOD) % MOD) * a[i].v) %= MOD;
        add(a[i].v, 1);
        add1(a[i].v, a[i].p);
    }
    memset(bit, 0, sizeof bit);
    memset(bit1, 0, sizeof bit1);
    for (int i = n - 1; i >= 0; --i) {
        LL cnt = sum(a[i].v);
        LL s = sum1(a[i].v);
        (ans += (((s - cnt * a[i].p) % MOD + MOD) % MOD) * a[i].v) %= MOD;
        add(a[i].v, 1);
        add1(a[i].v, a[i].p);
    }
    memset(bit, 0, sizeof bit);
    memset(bit1, 0, sizeof bit1);
    for (int i = n - 1; i >= 0; --i) {
        LL cnt = sum(a[i].v) - sum(a[i].v - 1);
        LL s = ((sum1(a[i].v) - sum1(a[i].v - 1)) % MOD + MOD) % MOD;
        (ans -= (((s - cnt * a[i].p) % MOD + MOD) % MOD) * a[i].v) %= MOD;
        add(a[i].v, 1);
        add1(a[i].v, a[i].p);
    }
    printf("%lld\n", (ans % MOD + MOD) % MOD);
    return 0;
}
