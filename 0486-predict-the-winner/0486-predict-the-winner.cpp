class Solution {
public:
    bool predictTheWinner(vector<int>& nums ) {
        int n = nums.size();
        std::vector<int>dp(n,0);
        for(int i = 0 ; i<  n ; i++){
            dp[i] = nums[i];
        }
        for(int i = n -2;i>=0;i--){
            for(int j = i+1;j<n;j++){
                dp[j] = std::max(nums[i]-dp[j] , nums[j]-dp[j-1]);
            }
        }
        return dp[n-1] >= 0;
    }
};