class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minV = *min_element(nums1.begin(), nums1.end());

        if (minV % 2 != 0) { // odd
            return true;
        }
        for (int num : nums1) {
            if (num % 2 != 0) { // odd
                return false;
            }
        }
        return true;
    }
};