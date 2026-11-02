class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int minV = INT_MAX;
        for(int i = 0; i < n ; i++){
               minV = min(minV , nums[i]);
        }
        int moves = 0;
        for(int i = 0; i < n ; i++){
                moves += nums[i] - minV;
        }
        return moves;
    }
};