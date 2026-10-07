class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k == 0){
            return 0;
        }
        int n = nums.size();
        int l = 0;
        long long currP = 1;
        int subarray = 0;

        for(int r = 0; r < n ; r++){
            currP *= nums[r];

            while(l <= r && currP >= k){//invalid condition
               currP = currP / nums[l] ;
               l++;
            }
            subarray += (r-l+1);
        }
        return subarray;
    }
};