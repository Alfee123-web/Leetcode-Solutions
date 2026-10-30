class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        // Adj list: u -> list of {v, w}
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
        }

        // Min-priority queue to store {weight, node, count}
        // Using tuple: (dist, node, count)
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;

        // dist[node][count] to keep track of minimum weight to reach a state
        // count ranges from 1 to k
        vector<vector<long long>> dist(n, vector<long long>(k + 1, LLONG_MAX));

        // Start from node 0 with count 1 (since labels[0] is part of the path)
        pq.push({0, 0, 1});
        dist[0][1] = 0;

        while (!pq.empty()) {
            auto [d, u, count] = pq.top();
            pq.pop();

            if (u == n - 1) {
                return d;
            }

            if (d > dist[u][count]) {
                continue;
            }

            for (auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int w = neighbor.second;

                int next_count = 1;
                if (labels[u] == labels[v]) {
                    next_count = count + 1;
                }

                // If the consecutive identical character count exceeds k, skip
                if (next_count > k) {
                    continue;
                }

                if (dist[u][count] + w < dist[v][next_count]) {
                    dist[v][next_count] = dist[u][count] + w;
                    pq.push({dist[v][next_count], v, next_count});
                }
            }
        }

        // Find the minimum distance to reach node n - 1 across all valid counts
        long long ans = LLONG_MAX;
        for (int c = 1; c <= k; ++c) {
            ans = min(ans, dist[n - 1][c]);
        }

        return ans == LLONG_MAX ? -1 : ans;
    }
};