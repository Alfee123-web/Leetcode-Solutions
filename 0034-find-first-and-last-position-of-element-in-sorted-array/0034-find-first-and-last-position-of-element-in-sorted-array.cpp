class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1,-1};

        int s = 0;
        int e = (int)nums.size()-1;
        int first = -1;
        int last = -1;
        while(s <= e){
            int m = s + (e-s)/2;
            if(nums[m] == target){
                   first = m;
            e = m-1;
            } 
            else if(nums[m] < target){
              s = m + 1;
            } 
            else{
             e = m -1;
            } 

        }
        s = 0, e = nums.size()-1;
        while(s <= e){
             int m = s + (e-s)/2;
            if(nums[m] == target){
                 last = m;
                 s = m + 1;
            } 
            else if(nums[m] < target){
               s = m + 1;
            } 
            else {
                e = m -1;
        }
    }
   return {first, last};
    }
};