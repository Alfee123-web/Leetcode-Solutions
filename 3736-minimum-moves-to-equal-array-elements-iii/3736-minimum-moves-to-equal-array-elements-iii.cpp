class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int maxV = INT_MIN;
        for(int i = 0; i< n;i++){
             maxV = max(maxV , nums[i]);
        }
        int moves = 0;
        for(int i =0 ; i < n ; i++){
            moves += abs(nums[i] - maxV);
        }
        return moves;
    }
};