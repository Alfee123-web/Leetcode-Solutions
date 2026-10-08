class Solution {
public:
    string removeOuterParentheses(string s) {
        int k = 0;
        string ans = "";
        for(int i = 0; i< s.length(); i++){
            if(s[i] == '(' ){
                 k++;
                if(k > 1){
                      ans += s[i];
                }
            }else{
                k--;
                if(k > 0){
                   ans += s[i];
                }
            }
        }
        return ans;
    }
};
//k > 1 open add krna
//k > 0 closing add krna 
