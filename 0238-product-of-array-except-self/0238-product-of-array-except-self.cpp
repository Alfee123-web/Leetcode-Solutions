class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        ans[0] = 1;
        for(int i = 1; i < n ; i++){
              ans[i] = ans[i-1] * nums[i-1];//prefix
              // 1 1 2 6 
        }
        int s = 1;
        for(int i = n-1; i >= 0 ; i--){
            ans[i] = ans[i] * s;
            s = s * nums[i];//6
            // 6 
        }
        return ans;
    }
};