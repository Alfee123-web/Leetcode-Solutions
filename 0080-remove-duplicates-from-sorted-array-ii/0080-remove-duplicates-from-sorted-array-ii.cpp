class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        int f = 1;
        int c = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                f++; // 2
            } else {
                f = 1;
            }
            if (f <= 2) {
                nums[c] = nums[i]; // 0
                c++;                   // 1
            }
        }

        return c;
    }
};