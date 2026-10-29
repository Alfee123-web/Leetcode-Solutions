class Solution {
    int n;
    vector<vector<int>> adj;
    vector<int> parent_node, depth, heavy, head, pos;
    vector<int> tree; // Fenwick tree for 26-bit masks
    int cur_pos;
    string s_chars;

    // First DFS to compute subtree sizes, depth, parent, and heavy child
    int dfs1(int u, int p, int d) {
        parent_node[u] = p;
        depth[u] = d;
        int size = 1;
        int max_sub_size = 0;
        for (int v : adj[u]) {
            if (v != p) {
                int sub_size = dfs1(v, u, d + 1);
                size += sub_size;
                if (sub_size > max_sub_size) {
                    max_sub_size = sub_size;
                    heavy[u] = v;
                }
            }
        }
        return size;
    }

    // Second DFS to set chain heads and positions for HLD
    void dfs2(int u, int h) {
        head[u] = h;
        pos[u] = ++cur_pos;
        if (heavy[u] != -1) {
            dfs2(heavy[u], h);
        }
        for (int v : adj[u]) {
            if (v != parent_node[u] && v != heavy[u]) {
                dfs2(v, v);
            }
        }
    }

    // Fenwick Tree update
    void update_bit(int idx, int val) {
        for (; idx <= n; idx += idx & -idx) {
            tree[idx] ^= val;
        }
    }

    // Fenwick Tree range/prefix XOR query
    int query_bit(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx) {
            res ^= tree[idx];
        }
        return res;
    }

    // Query XOR sum in range [L, R]
    int query_range(int l, int r) {
        if (l > r) return 0;
        return query_bit(r) ^ query_bit(l - 1);
    }

public:
    vector<bool> palindromePath(int n_nodes, vector<vector<int>>& edges, string s, vector<string>& queries) {
        n = n_nodes;
        s_chars = s;
        adj.assign(n, vector<int>());
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        parent_node.assign(n, -1);
        depth.assign(n, 0);
        heavy.assign(n, -1);
        head.assign(n, 0);
        pos.assign(n, 0);
        tree.assign(n + 1, 0);
        cur_pos = 0;

        dfs1(0, -1, 0);
        dfs2(0, 0);

        // Initialize Fenwick tree with initial character masks
        for (int i = 0; i < n; ++i) {
            update_bit(pos[i], 1 << (s[i] - 'a'));
        }

        vector<bool> answer;

        for (const string& q : queries) {
            if (q[0] == 'u') {
                // Format: "update u c"
                int space1 = q.find(' ', 7);
                int u = stoi(q.substr(7, space1 - 7));
                char c = q.back();

                int old_mask = 1 << (s_chars[u] - 'a');
                int new_mask = 1 << (c - 'a');
                if (old_mask != new_mask) {
                    update_bit(pos[u], old_mask ^ new_mask);
                    s_chars[u] = c;
                }
            } else {
                // Format: "query u v"
                int space1 = q.find(' ', 6);
                int space2 = q.find(' ', space1 + 1);
                int u = stoi(q.substr(6, space1 - 6));
                int v = stoi(q.substr(space1 + 1, space2 - space1 - 1));

                int path_xor = 0;
                while (head[u] != head[v]) {
                    if (depth[head[u]] > depth[head[v]]) {
                        swap(u, v);
                    }
                    path_xor ^= query_range(pos[head[v]], pos[v]);
                    v = parent_node[head[v]];
                }
                if (depth[u] > depth[v]) {
                    swap(u, v);
                }
                path_xor ^= query_range(pos[u], pos[v]);

                // Check if path_xor has at most one bit set
                bool is_palindrome = (path_xor & (path_xor - 1)) == 0;
                answer.push_back(is_palindrome);
            }
        }

        return answer;
    }
};