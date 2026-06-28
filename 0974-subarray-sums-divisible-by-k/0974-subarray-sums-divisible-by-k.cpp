class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int s = 0;
        int c = 0;
        mp[0]= 1;
        for (int i = 0; i < nums.size(); i++) {
            s += nums[i];
            int r = ((s % k) + k) % k;
            c += mp[r];
            mp[r]++;
        }
        return c;
    }
};