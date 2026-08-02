class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        for(int i = 0; i < num.length();i++){
            while(!st.empty() && k > 0 &&  st.top() > num[i]){
               
                 st.pop();
               k--;
            }
            st.push(num[i]);
        }
        while(!st.empty() && k > 0){
            st.pop();
            k--;
        }
         vector<int>ans;
         while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
         }
         reverse(ans.begin(),ans.end());

         string res = "";
         bool leadZ = true;
         for(char ch : ans){
            if(leadZ && ch == '0') continue;
            leadZ = false;
            res.push_back(ch);//digit
         }
       return res.empty() ? "0" : res;
    }
};