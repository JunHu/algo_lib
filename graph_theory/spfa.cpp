void spfa(int n, vector<vector<pair<int, int>>> &link, vector<int> &dis) {
	vector<bool> flag(n + 1);
	queue<int> Q;
	dis[n] = 0, flag[n] = true;
	Q.push(n);
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
