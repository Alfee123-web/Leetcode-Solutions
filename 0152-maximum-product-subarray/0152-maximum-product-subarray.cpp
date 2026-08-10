class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int m = nums[0];
        int mi = nums[0];
        int p = nums[0];
        for(int i = 1; i < n ; i++){
            int c = nums[i];
            if(c < 0){
                swap(m, mi);
            }
            m = max(c , c * m);
            mi = min(c , c * mi);
            p = max(p , m);
        }
        return p;
    }
};