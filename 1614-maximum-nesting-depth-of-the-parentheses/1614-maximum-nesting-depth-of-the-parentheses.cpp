class Solution {
public:
    int maxDepth(string s) {
        // stack<int>st;
        int depth = 0;
        int maxD = 0;
        for(int i =0 ; i <s.length();i++){
            char ch = s[i];
            if(ch == '('){
                // st.push(ch);
                depth++;
                maxD = max(depth , maxD);
            }else{
            if( ch == ')')
                // st.pop();
                depth--;
        }
        }
return maxD;
    }
};