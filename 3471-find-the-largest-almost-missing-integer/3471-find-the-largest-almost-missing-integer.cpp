class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();//5
        int freq[51] = {0};
        for(int num : nums){
            freq[num]++;
        }

        int maxV = -1;
       if(k == n){
        for(int num : nums){
            maxV = max(maxV , num);
        }
        return maxV;
       }
       if (k == 1) {
            for (int num : nums) {
                if (freq[num] == 1) {
                    maxV = max(maxV, num);
                }
            }
            return maxV;
        }
       if(freq[nums[0]] == 1){
        maxV = max(maxV , nums[0]);
       }
       if(freq[nums[n-1]] == 1){
        maxV = max(maxV , nums[n-1]);
       }
    return maxV;
    }
};