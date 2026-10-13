class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n ; i ++){
            nums[i] = abs(nums[i]);
        }
        sort(nums.begin(), nums.end());
        int m = n/2;
        long long maxS = 0;
        for(int i = 0; i< m ; i++){
            maxS -= (long long)nums[i] * nums[i];
            
        }
        for(int i = m ; i< n ; i++){
            maxS += (long long)nums[i] * nums[i];
            
        }
       
        return maxS;
    }
};