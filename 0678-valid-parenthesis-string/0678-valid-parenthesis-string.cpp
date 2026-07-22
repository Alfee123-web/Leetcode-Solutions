class Solution {
public:
    bool checkValidString(string s) {
        stack<int>o;
        stack<int>st;
        for(int i = 0; i< s.length(); i++){
            char ch = s[i];
            if(ch == '('){
                o.push(ch);
            }else if(ch == '*'){
                st.push(ch);
            }else{
                if(!o.empty()){
                    o.pop();
                }else if(!st.empty()){
                    st.pop();
                }else{
                    return false;
                }
            }
        }
            while(!o.empty() && !st.empty()){
                 if(o.top() > st.top()){
 return false;
                 }
               o.pop();
               st.pop();
            }
            return o.empty();
    
    }
};