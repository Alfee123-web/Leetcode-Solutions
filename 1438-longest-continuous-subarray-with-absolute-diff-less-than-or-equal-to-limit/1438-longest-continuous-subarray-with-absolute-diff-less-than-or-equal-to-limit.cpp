class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int>maxQ;
        deque<int>min;
        int l = 0;
        int len = 0;
        for(int r = 0; r < nums.size();r++){
            while(!maxQ.empty() && maxQ.back() < nums[r]){
                maxQ.pop_back();
            }
            maxQ.push_back(nums[r]);
            while(!min.empty() && min.back() > nums[r]){
                min.pop_back();
            }
            min.push_back(nums[r]);
            while(maxQ.front() - min.front() > limit){
                if(maxQ.front() == nums[l]){
                    maxQ.pop_front();
                }
                if(min.front() == nums[l]){
                    min.pop_front();
                }
                l++;
            }
            len = max(len , r - l+ 1);
        }
        return len;
    }
};