
typedef long long ll;

struct SegmentTree {
    #define lc c << 1
    #define rc c << 1 | 1
    #define ls lc, l, mid
    #define rs rc, mid + 1, r

    ll sum[N << 2], lazy[N << 2];
    void clear() {
        memset(sum, 0, sizeof(sum));
        memset(lazy, 0, sizeof(lazy));
    }
    void push_down(int c, int l, int r, int val) {
        sum[c] = (sum[c] + 1LL * val * (r - l + 1)) % mod;
        lazy[c]+= val;
    }

    void insert(int c, int l, int r, int L, int R, int val) {
        if (r < L || l > R) return;

        if (L <= l && r <= R) {
            push_down(c, l, r, val);
            return;
        }

        int mid = (l + r) >> 1;
        if (lazy[c]) push_down(ls, lazy[c]), push_down(rs, lazy[c]), lazy[c] = 0;

        insert(ls, L, R, val);
        insert(rs, L, R, val);

        sum[c] = (sum[lc] + sum[rc]) % mod;
    }

    ll query(int c, int l, int r, int L, int R) {
        if (r < L || l > R) return 0;
        if (L <= l && r <= R) {
            return sum[c];
        }
        int mid = (l + r) >> 1;
        if (lazy[c]) push_down(ls, lazy[c]), push_down(rs, lazy[c]), lazy[c] = 0;

        return (query(ls, L, R) + query(rs, L, R)) % mod;
    }
};
