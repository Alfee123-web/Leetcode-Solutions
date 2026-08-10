class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftS = 0;

        int totS = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            totS += nums[i]; // 28
        }
        for (int i = 0; i < n; i++) {
            int rightS = totS - (leftS + nums[i]); // 20

            if (leftS == rightS) {
                return i;
            } else {
                leftS += nums[i]; // 1
            }
        }
        return -1;
    }
};