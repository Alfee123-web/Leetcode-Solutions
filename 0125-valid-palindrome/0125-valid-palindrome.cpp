class Solution {
public:
    bool isPalindrome(string s) {
        string ans = "";
        for(char ch : s){
            if(isalnum(ch)){
                ans += tolower(ch);
            }
        }
        int st = 0;
        int e = ans.length()-1;
        while(st < e){
            if(ans[st] != ans[e]) return false;
            st++;
            e--;
        }
        return true;
    }
};