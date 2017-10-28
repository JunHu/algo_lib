/*************************************************************************
	> File Name: main.cpp
	> Author: JunHU
	> Mail: hujun09012@gmail.com
    > Problem: https://www.hackerrank.com/contests/womens-codesprint-4/challenges/lexicographically-smaller-or-equal-strings/problem
 ************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int C = 26;

int n, q;
char s[100];

struct PersistTrie {
    int root[N];
    struct Node {
        int son[C];
        int sum, words_cnt;
    }node[N * 30];
    int sz;
    int new_node(int _sum=0, int _words_cnt=0) {
        node[sz].sum = _sum;
        node[sz].words_cnt = _words_cnt;
        memset(node[sz].son, 0, sizeof(node[sz].son));
        return sz++;
    }
    void init() {
        sz = 0;
        memset(root, 0, sizeof(root));
        root[0] = new_node(); 
    }
    void build(int x, int &y, char *s, int idx = 0) {
        y = new_node(node[x].sum + 1, node[x].words_cnt);
        for (int i = 0; i < C; ++i) node[y].son[i] = node[x].son[i];
        if (!s[idx]) {
            node[y].words_cnt ++;
            return;
        }
        int ch = s[idx] - 'a';
        build(node[x].son[ch], node[y].son[ch], s, idx + 1);
    }
    int query(int x, int y, char *s, int idx = 0) {
        int ret = node[y].words_cnt - node[x].words_cnt; 
        if (!s[idx]) return ret;
        int ch = s[idx] - 'a';
        for (int i = 0; i < ch; ++i) ret += node[node[y].son[i]].sum - node[node[x].son[i]].sum;
        ret += query(node[x].son[ch], node[y].son[ch], s, idx + 1);
        return ret;
    }
}trie;

int main() {
    trie.init();
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", s);
        trie.build(trie.root[i - 1], trie.root[i], s);
    }
    scanf("%d", &q);
    for (int i = 0, l, r; i < q; ++i) {
        scanf("%d %d %s", &l, &r, s);
        printf("%d\n", trie.query(trie.root[l - 1], trie.root[r], s));
    }
    return 0;
}
