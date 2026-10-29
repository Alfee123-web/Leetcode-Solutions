class Solution {
public:
    bool isCycle(int s, vector<bool>& vis, vector<bool>& rec,
                 vector<vector<int>>& prerequisites) {
        vis[s] = true;
        rec[s] = true;

        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            if (u == s) {
                if(!vis[v]){
                if (isCycle(v, vis, rec, prerequisites)) {
                    return true;
                }
            } else {
                if (rec[v]) {
                    return true;
                }
            }
            }
        }
        
        rec[s] = false;
        return false;
    }

    void topoSort(int s, vector<bool>& vis2, stack<int>& st,
                  vector<vector<int>>& prerequisites) {
        vis2[s] = true;
        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            if (u == s) {
                if (!vis2[v]) {
                    topoSort(v, vis2, st, prerequisites);
                }
            }
        }
        st.push(s);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // topological sort
        int V = numCourses;
        vector<bool> vis(V, false);
        vector<bool> rec(V, false);
        vector<int> ans;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (isCycle(i, vis, rec, prerequisites)) {
                    return ans; // empty
                }
            }
        }
        // topological sort
        vector<bool> vis2(V, false);
        stack<int> st;

        for (int i = 0; i < V; i++) {
            if (!vis2[i]) {
                topoSort(i, vis2, st, prerequisites);
            }
        }
        while (st.size() > 0) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
//TC => O(V + E)