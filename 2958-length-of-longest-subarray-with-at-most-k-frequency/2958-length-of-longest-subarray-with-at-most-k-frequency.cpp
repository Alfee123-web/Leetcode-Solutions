class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        int l = 0;
        int left = 0;
        //i = right
        for(int i = 0 ; i < nums.size();i++){
            freq[nums[i]]++;
            while(freq[nums[i]] > k){
                freq[nums[left]]--;
                left++;
            }
            l = max(l , i - left + 1);
        }
        return l;
    }
};