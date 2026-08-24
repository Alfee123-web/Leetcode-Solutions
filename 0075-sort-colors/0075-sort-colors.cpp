class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int k = 0;//start
        int m =0;//mid
        int e = n-1;//end
       while(m <= e){
            if(nums[m] == 0){
                swap(nums[k] , nums[m]);
                k++;
                m++;
            }else if (nums[m] == 2){
                swap(nums[e] , nums[m]);
                e--;

             
            }else{
                m++;
            }
        }

    }
};