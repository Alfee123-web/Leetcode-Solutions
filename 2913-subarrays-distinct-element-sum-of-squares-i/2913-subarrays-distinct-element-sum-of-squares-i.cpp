class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int sum =0;
        int n = nums.size();
        int size = 0;
        for(int i = 0; i <n ; i++){
            unordered_set<int>s;
            for(int j = i; j < n ; j++){
                s.insert(nums[j]);
                size = s.size();
                sum += size * size;
            }
        }
        return sum;
    }
};