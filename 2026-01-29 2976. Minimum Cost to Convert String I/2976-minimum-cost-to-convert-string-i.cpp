class Solution {
public:
    void dijkstra(int source, vector<vector<pair<int,int>>>& adj,
                  vector<vector<int>>& dist) {
        dist[source][source] = 0;

        priority_queue<pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>> pq;

        pq.push({0, source});

        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (d > dist[source][node]) continue;

            for (auto &edge : adj[node]) {
                int wt = edge.first;
                int next = edge.second;

                if (dist[source][next] > dist[source][node] + wt) {
                    dist[source][next] = dist[source][node] + wt;
                    pq.push({dist[source][next], next});
                }
            }
        }
    }

    long long minimumCost(string source, string target,
                          vector<char>& original,
                          vector<char>& changed,
                          vector<int>& cost) {

        vector<vector<pair<int,int>>> adj(26);
        for (int i = 0; i < original.size(); i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            adj[u].push_back({cost[i], v});
        }

        vector<vector<int>> dist(26, vector<int>(26, 1e9));
        for (int i = 0; i < 26; i++) {
            dijkstra(i, adj, dist);
        }

        long long ans = 0;
        for (int i = 0; i < source.size(); i++) {
            int u = source[i] - 'a';
            int v = target[i] - 'a';
            if (dist[u][v] == 1e9) return -1;
            ans += dist[u][v];
        }

        return ans;
    }
};
