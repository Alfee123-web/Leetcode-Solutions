class Solution {
public:
    bool isValid(string s) {
        stack<char>t;
        for(int i =0 ;i < s.size();i++){
            char ch = s[i];
            //opening
            if(ch == '(' || ch == '[' || ch == '{'){
                t.push(ch);
            }else{
                if(t.empty()){
                    return false;
                }
            //matching
            int top = t.top();
            if((top == '{' && ch == '}') 
            || (top == '[' && ch == ']') 
            || (top == '(' && ch == ')') ){
                t.pop();
            }else{
                return false;
            }
            }
        }
         return t.empty();
    }
};