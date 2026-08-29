class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i = 1;i < nums.size();i++){
            if(nums[i] == nums[i-1]){
                nums[i-1] *= 2;
                nums[i] = 0;
            }
        }
        int k =0;
        for(int i =0;i<nums.size();i++){
            if(nums[i] != 0){
                swap(nums[k],nums[i]);
                k++;
            }
        }
        return nums;
    }
};