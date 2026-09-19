class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMin = nums[0];
        int currMax = nums[0];
        int maxP = nums[0];

         for(int i = 1; i < nums.size();i++){
            if(nums[i] < 0) swap(currMax,currMin);
            currMin = min(currMin * nums[i], nums[i]);
            currMax = max(currMax * nums[i] , nums[i]);
            maxP = max( currMax , maxP);

         }
      return maxP;
    }
};
