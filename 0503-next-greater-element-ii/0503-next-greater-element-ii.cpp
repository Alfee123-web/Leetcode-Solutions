class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;

        int n = nums.size();
        vector<int> ans(n, -1);
        for (int i = 0; i < 2 * n; i++) {
            while (!st.empty() && nums[i % n] > nums[st.top()]) {
                int t = st.top();
                st.pop();
                ans[t] = nums[i % n];
            }
            if (i < n) {
                st.push(i);
            }
        }
        return ans;
    }
};