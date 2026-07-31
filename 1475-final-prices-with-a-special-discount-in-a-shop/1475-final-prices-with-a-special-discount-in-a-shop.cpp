class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int>st;
        vector<int>ans = prices;
        int n = prices.size();
        for(int i = 0 ;i < n ;i++){
            while(!st.empty() && prices[st.top()] >= prices[i]){
                int t = st.top();
                st.pop();
                ans[t] -=  prices[i];
            }
                st.push(i);
        }
    return ans;
    }
};