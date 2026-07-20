class Solution {
public:
    int maxDepth(string s) {
        int depth = 0; 
        int maxD = 0;
        for(int i = 0; i< s.size(); i++){
            if(s[i] == '('){
                depth++;
                maxD = max(maxD , depth);
            }else if (s[i]== ')'){
                depth--;
            }
        }
        return maxD;
    }
};