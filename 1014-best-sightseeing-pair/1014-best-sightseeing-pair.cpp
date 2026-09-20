class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0;
      
        int maxi = values[0] + 0;
    
        for(int j = 1; j < values.size();j++){
            int score = maxi + values[j] - j;
             ans = max(ans,score);
             maxi = max(maxi,values[j] + j);
        }
        return ans;
    }
};