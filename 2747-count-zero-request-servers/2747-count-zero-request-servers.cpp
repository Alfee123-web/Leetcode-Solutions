class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = queries.size();
        vector<int> ans(m);
        
        // Pair each query with its original index
        vector<pair<int, int>> sortedQueries(m);
        for (int i = 0; i < m; ++i) {
            sortedQueries[i] = {queries[i], i};
        }
        
        // Sort queries and logs by time
        sort(sortedQueries.begin(), sortedQueries.end());
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int logLen = logs.size();
        int left = 0, right = 0;
        unordered_map<int, int> serverFreq;
        
        for (const auto& q : sortedQueries) {
            int queryTime = q.first;
            int originalIndex = q.second;
            int windowStart = queryTime - x;
            int windowEnd = queryTime;
            
            // Expand the right boundary to include logs up to windowEnd
            while (right < logLen && logs[right][1] <= windowEnd) {
                serverFreq[logs[right][0]]++;
                right++;
            }
            
            // Shrink the left boundary to remove logs older than windowStart
            while (left < logLen && logs[left][1] < windowStart) {
                serverFreq[logs[left][0]]--;
                if (serverFreq[logs[left][0]] == 0) {
                    serverFreq.erase(logs[left][0]);
                }
                left++;
            }
            
            // Total servers minus servers that received at least one request in the window
            ans[originalIndex] = n - serverFreq.size();
        }
        
        return ans;
    }
};