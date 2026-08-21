class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int maxF = 0;
        int currF = 0;
        int ans = -1;
        for (int i = 0; i < n; i++) {
            if(nums[i] % 2 != 0 ){

                continue;
            }

            if (i == 0 || nums[i] != nums[i - 1]) {
                currF = 1;
            } else {
                currF++;
            }
            if (currF > maxF) {
                maxF = currF;
                ans = nums[i];
            }
        }
        return ans;
    }
};