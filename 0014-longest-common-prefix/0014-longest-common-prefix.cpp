class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin() , strs.end());
        string s = strs[0];
        string e = strs.back();
        int j = 0;
         while(j < s.length() && j < e.length() && s[j] == e[j]){
           
               j++;
        
         }
     return s.substr(0,j);
    }
};