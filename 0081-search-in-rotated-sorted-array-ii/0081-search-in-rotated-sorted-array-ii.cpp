class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size()-1;
        while(s <= e){
            int m = s  + (e-s)/2;
            if(nums[m] == target){
                return true;
            }
            if(nums[s] == nums[m] && nums[e] == nums[m]){
                s++;
                e--;
                continue;
            }
            if(nums[s] <= nums[m] ){//left
                 if(nums[s] <= target &&  target < nums[m]){
                e = m-1;
                 }else{
                    s = m + 1;
                 }
            }else{
                if(nums[m] < target && target <= nums[e]){//right half
                       s = m +1;
                }else{
                    e = m-1;
                }
            }
        }
        return false;
    }
};