class Solution {
public:
    bool isCycle(int s, vector<bool>& vis, vector<bool>& rec,
                 vector<vector<int>>& prerequisites) {
        vis[s] = true;
        rec[s] = true;

        //[0,1][v,u] = > 1 se 0 jayega => u se v jayega
        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            if (u == s) {
                if (!vis[v]) { // neighbour is not visited
                    if (isCycle(v, vis, rec,
                                prerequisites)) { // is cycle se visit kra denge
                        return true;
                    }
                } else {
                    if (rec[v]) { // neighbour already vis hai rec me exist krta
                                  // hai
                        return true;
                    }
                }
            }
        }
        rec[s] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // prerequesites => graph
        // topological sorting => DAGs
        int V = numCourses; // total number of vertices
        vector<bool> vis(V, false);
        vector<bool> rec(V, false);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (isCycle(i, vis, rec, prerequisites)) {
                    return false;
                }
            }
        }
        return true;
    }
};