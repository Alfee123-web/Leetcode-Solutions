class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
       string s = strs[0];
       string e = strs.back();
       int i = 0;
       while(i < s.length() && i < e.length() && s[i] == e[i]){
        i++;
       }
       return s.substr(0,i);//length
    }
};