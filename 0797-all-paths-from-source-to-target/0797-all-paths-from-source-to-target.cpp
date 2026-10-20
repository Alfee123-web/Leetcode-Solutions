class Solution {
    void dfs(vector<vector<int>>& graph, int curr, int target,
             vector<int>& path, vector<vector<int>>& result) {
        if (curr == target) {
            result.push_back(path); // 0 1 3 , 0 2 3
            return;
        }
        for (int neighbour : graph[curr]) {
            path.push_back(neighbour); // 0 1 3
            dfs(graph, neighbour, target, path, result);

            path.pop_back(); // 3 pop back to node 0
        }
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> path;

        int target = graph.size() - 1; // 3
        path.push_back(0);             // 0

        dfs(graph, 0, target, path, result);
        return result;
    }
};