class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n + 1, 0);
        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }
        int m = -1;
        for (int i = 0; i <= n; i++) {
            if (freq[i] == 0) {
                m = i;
                break;
            }
        }
        return m;
    }
};