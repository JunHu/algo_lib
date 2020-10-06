namespace MCMF {
    int inf = ~0U >> 2;
    int n, start, end;

    struct Edge {
        int to, c, w, next;
    };
    std::vector<int> box, p, dis;
    std::vector<Edge> edges;

    void _add(int from, int to, int c, int w) {
        edges.push_back({to, c, w, box[from]});
        box[from] = edges.size() - 1;
    }

    void add(int from, int to, int c, int w) {
        _add(from, to, c, w);
        _add(to, from, 0, -w);
    }
    void init(int _n, int _s, int _e) {
        n = _n, start = _s, end = _e;
        box.clear(), box.resize(n, -1);
        edges.clear();
        p.resize(n);
        dis.resize(n);
    }
    bool spfa(int start, int end) {
        std::queue<int> que;
        std::vector<bool> flag(n);

        std::fill(p.begin(), p.end(), -1);
        std::fill(dis.begin(), dis.end(), inf);


        dis[start] = 0, flag[start] = true;
        que.push(start);

        while(!que.empty()) {
            int x = que.front();
            que.pop();
            flag[x] = false;
            for (int i = box[x]; ~i; i = edges[i].next) {
                int y = edges[i].to;
                if (edges[i].c) {
                    int w = edges[i].w;
                    if (w < dis[y] - dis[x]) {
                        dis[y] = dis[x] + w;
                        p[y] = i;
                        if(!flag[y]) {
                            que.push(y);
                            flag[y] = true;
                        }
                    }
                }
            }
        }
        return dis[end] != inf;
    }
    int run() {
        int ans = 0;
        while(spfa(start, end)) {
            int u = end, flow = inf;
            while(~p[u]) {
                flow = min(flow, edges[p[u]].c);
                u = edges[p[u]^1].to;
            }
            u = end;
            while(~p[u]) {
                edges[p[u]].c -= flow;
                edges[p[u]^1].c += flow;
                u = edges[p[u]^1].to;
            }
            ans += dis[end] * flow;
        }
        return ans;
    }
};
