class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int>st;
        int moves = 0;
       
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                st.push(s[i]); 
            }else{
                  if(!st.empty()){
                st.pop();
               }else{
                     moves++;
            }
        }
        }
        return moves + st.size();
    }
};