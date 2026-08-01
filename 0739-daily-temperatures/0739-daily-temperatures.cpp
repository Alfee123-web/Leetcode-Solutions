class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>st;
        vector<int>ans(temperatures.size());
        for(int i = 0; i < temperatures.size();i++){
            while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                int t = st.top();
                st.pop();
                ans[t] = i - t;
            }
             st.push(i);
        }
       return ans;
    }
};