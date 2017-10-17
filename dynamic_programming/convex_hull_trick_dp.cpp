/*************************************************************************
	> File Name: main.cpp
	> Author: JunHU
	> Mail: hujun09012@gmail.com
    > Problem: https://www.hackerrank.com/contests/moodys-analytics-fall-university-codesprint/challenges/modified-subsequence-sum
 ************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int N = 300010;

typedef long long ll;

int n, k; 
ll dp[N], a[N], ans;

struct Point {
    ll x, y;
    Point() {}
    Point(ll x, ll y): x(x), y(y) {}
    Point operator - (const Point &o) {
        return Point(x - o.x, y - o.y);
    }
    ll operator * (const Point &o) {
        return x * o.y - y * o.x;
    }
};

Point Q[N];
int head, tail;

inline ll sqr(ll x) {
    return x * x;
}
ll getDP(ll i, const Point &o) {
    return o.x * i + o.y + a[i] - k * sqr(i - 1);
}
int main() {
    scanf("%d %d", &n, &k);
    dp[0] = 0;
    head = tail = 0;
    for (int i = 1; i <= n; ++i) scanf("%lld", a + i);
    dp[1] = ans = a[1];
    Q[tail++] = Point(2 * k, dp[1] - 3 * k);
    for (int i = 2; i <= n; ++i) {
        while (head + 1 < tail && getDP(i, Q[head + 1]) > getDP(i, Q[head])) head ++;
        dp[i] = max(a[i], getDP(i, Q[head]));
        Point cur = Point(2LL * k * i, dp[i] - 2LL * k * i - k * sqr(i));
        while (head + 1 < tail && (cur - Q[tail - 1]) * (Q[tail - 1] - Q[tail - 2]) < 0) tail --;
        Q[tail++] = cur;
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}
