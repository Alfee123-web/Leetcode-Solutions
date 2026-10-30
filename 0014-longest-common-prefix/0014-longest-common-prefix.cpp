class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin() , strs.end());
        string s = strs[0];
        string e = strs[strs.size()-1];
        int n = s.length();
        int m = e.length();
        int i = 0;
        int j =0;
        while(i < n && j < m){
            if(s[i] == e[j]){
                i++;
                j++;
            }else{
                break;
            }
        }
return s.substr(0 , i);
        
    }
};