class NumArray {
public:
    vector<int>ans;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        ans.resize(n+1);
        for(int i = 1; i<=n ; i++){
            ans[i] = nums[i-1] + ans[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        int sum = ans[right+1]-ans[left];
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */