class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int r =0;
        int maxO = 0;
        int zeroes = 0;
        int n = nums.size();
        for(int r = 0 ; r < n ; r++){
             if(nums[r] == 0){
                zeroes++;
             }
             while(zeroes > k){
                if(nums[l] == 0){
                    zeroes--;
                }
               
                l++;
             }
             maxO = max(maxO, r -l + 1);
        }
        return maxO;
    }
};