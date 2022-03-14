void spfa(int src, vector<vector<pair<int, int>>> &link, vector<long long> &dis) {
    vector<bool> flag(dis.size());
    queue<int> Q;
    dis[src] = 0, flag[src] = true;
    Q.push(src);
    while (Q.size()) {
        int x = Q.front();
        Q.pop(); flag[x] = false;
        for (auto e: link[x]) {
            int y = e.first, w = e.second;
            if (dis[y] == -1 || dis[y] - dis[x] > w) {
                dis[y] = dis[x] + w;
                if (!flag[y]) {
                    Q.push(y);
                    flag[y] = true;
                }
            }
        }
    }
}
