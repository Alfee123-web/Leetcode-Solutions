class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (ch == '(') {
                st.push(i);

            } else if (ch == ')') {
                if (!st.empty() ) {
                    st.pop();
                }else{
                    s[i] = '*';
                }
            }
        }
        while(!st.empty()){
            s[st.top()] = '*';
            st.pop();
        }
        string ans = "";
        for(char ch : s){
            if(ch != '*'){
                ans += ch;
            }
        }
       
        return ans;
    }
};