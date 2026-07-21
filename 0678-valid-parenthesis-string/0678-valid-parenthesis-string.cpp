class Solution {
public:
    bool checkValidString(string s) {
        stack<int>o;
        stack<int>st;
        
        for(int i = 0 ; i < s.size(); i++){
            if(s[i] == '('){
             o.push(i);
            }else if(s[i] == '*'){
                
                st.push(i);
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