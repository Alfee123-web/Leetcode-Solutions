class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int s = 0;
        int n = nums.size();
        int r = 0;
        mp[0] = -1;
        for (int i = 0; i < n; i++) {
            s += nums[i];
        
        if (k != 0)
            r = s % k;
        if (mp.find(r) != mp.end()) {
            if (i - mp[r] >= 2) {
                return true;
            }
            } else {
                mp[r] = i;
            }
        }

        return false;
    }
};