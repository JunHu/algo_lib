bool findPath(int x, const vector<vector<int>>& e, vector<bool>& flag, vector<int>& match) {
    for (int y : e[x]) {
        if (!flag[y]) {
            flag[y] = true;
            if (match[y] == -1 || findPath(match[y], e, flag, match)) {
                match[y] = x;
                return true;
            }
        }
    }
    return false;
}
int Hungary(int n, vector<vector<int>>& e) {
    int ans = 0;
    vector<int> match(n, -1);

    for (int i = 0; i < n; ++i) {
        vector<bool> flag(n);
        if (findPath(i, e, flag, match)) ans ++;
    }
    return ans;
}
