class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size()-1;
        while(s <= e){
            int m = s + (e-s)/2;
             if(nums[m] == target){
                return m;
            }
            if(nums[s] <= nums[m]){//left half
           
            if(nums[s] <= target && target < nums[m]){
               e = m-1;//left
            }else{
                s = m +1;//right
            }

            }
            //right half 
            else{
                if(target > nums[m] && target <= nums[e]){
                    s = m +1;//right
                }else{
                    e = m-1;//left
                }
            }     
        }
        return -1;
    }
};