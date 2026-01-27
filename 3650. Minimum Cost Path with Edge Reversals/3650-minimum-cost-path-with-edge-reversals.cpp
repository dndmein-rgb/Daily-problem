class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<pair<int, int>>> adj;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w * 2});
        }

        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;
            if (u == n - 1) return d;

            for (auto& [v, w] : adj[u]) {
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return -1;
    }
};
