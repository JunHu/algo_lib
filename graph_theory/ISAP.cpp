/*************************************************************************
	> File Name: main.cpp
	> Author: JunHU
	> Mail: hujun09012@gmail.com
    > Problem: http://poj.org/problem?id=1273
 ************************************************************************/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 4010;
const int M = 100000;

namespace ISAP {
    struct Edge {
        int to, c, next, id;
    }e[M << 1];
    int box[N], size;

	int n, m, start, end, h[N], vh[N];

    void _add(int from, int to, int c, int id=-1) {
        e[size].to = to;
        e[size].id = id;
        e[size].next = box[from];
        e[size].c = c;
        box[from] = size++;
        
    }
    void add(int from, int to, int c, int id=-1) {
        _add(from, to, c, id);
        _add(to, from, 0, -1);
    }
    void init(int _n, int _s, int _e) {
        memset(box, -1, sizeof(box)), size = 0;
        n = _n, start = _s, end = _e;
    }


	int aug(int x, int c) {
		if(x == end) return c;
		int l = c, tem = h[x] + 1;
		for(int i = box[x]; ~i; i = e[i].next)
			if(e[i].c && h[e[i].to] + 1 == h[x]) {
				int d = aug(e[i].to, l < e[i].c ? l : e[i].c);
				e[i].c -= d, e[i ^ 1].c += d, l -= d;
				if(h[start] == n || !l) return c - l;
			}
		for(int i = box[x]; ~i; i = e[i].next)
			if(e[i].c) tem = min(tem, h[e[i].to]);
		if(!--vh[h[x]]) h[start] = n; else ++vh[h[x] = tem + 1];
		return c - l;
	}
	int get_flows() {
		int ans = 0;
		memset(h, 0, sizeof(h));
		memset(vh, 0, sizeof(h));
		vh[0] = n;;
		while(h[start] < n) ans += aug(start, ~0U >> 1);
        return ans;
	}
};

using namespace ISAP;

int main() {
    while (cin >> m >> n) {
        ISAP::init(n, 1, n);

        for (int i = 0, x, y, c; i < m; ++i) {
            cin >> x >> y >> c;
            add(x, y, c);
        }
        cout << get_flows() << endl;
    }
    return 0;
}
