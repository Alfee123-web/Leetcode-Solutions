class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxs = 0;
        int n = gain.size();
        vector<int>ans(n);
        ans[0] = 0;
        for(int i = 1; i <= n; i++){
            ans.resize(n+1);
            ans[i] = ans[i-1] + gain[i-1];
        }
        for(int i =0 ;i <ans.size(); i++){
            maxs = max(ans[i], maxs);
        }
       
    return maxs;
    }
};