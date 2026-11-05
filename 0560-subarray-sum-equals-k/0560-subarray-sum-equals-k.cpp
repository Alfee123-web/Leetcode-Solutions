class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount;
        int c = 0;
        int s = 0;
        prefixCount[0] = 1;

        for (int num : nums) {
            s += num;
            int t = s - k;
            if (prefixCount.find(t) != prefixCount.end()) {
                c += prefixCount[t];
            }
            prefixCount[s]++;
        }
        return c;
    }
};