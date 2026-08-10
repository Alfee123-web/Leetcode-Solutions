class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string f = strs[0];
        string l = strs.back();
        int i = 0;
        while(i < f.length() && i < l.length() && f[i] == l[i]){
            i++;
        }
        return l.substr(0,i);
    }
};