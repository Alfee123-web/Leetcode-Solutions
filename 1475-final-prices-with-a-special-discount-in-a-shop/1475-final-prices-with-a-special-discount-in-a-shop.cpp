class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<int>st;
        vector<int>ans = prices;
        for(int i = 0 ;i < n ; i++){
        while(!st.empty() && prices[i] <= prices[st.top()]){
            int prev = st.top();
                st.pop();
                ans[prev] -= prices[i];//discount
            }
                st.push(i);
            
        }
      return ans;
    }
};
