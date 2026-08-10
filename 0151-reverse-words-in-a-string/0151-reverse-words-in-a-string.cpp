class Solution {
public:
    string reverseWords(string s) {
        int i = s.length()-1;
        string ans = "";
        while(i >= 0){
            while(i >=0 && s[i] == ' '){
                i--;
            }if(i < 0)break;
            int j = i;
            while(i >= 0 && s[i] != ' '){
                i--;
            }
        
        string res = s.substr(i+1,j-i);
        if(ans.empty()){
            ans += res;
        }else{
            ans += " " + res;
        }
        }
        return ans;
    }
};