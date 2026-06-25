class Solution {
public:
    int countBinarySubstrings(string s) {
          int c =0;
          int curr = 1;
          int prev = 0;
          for(int i = 1; i< s.length(); i++){
            if(s[i] == s[i-1]){
                curr++;
            }else{
                c += min(prev , curr);
                prev = curr;
                curr =1;
            }
          }
          c += min(prev , curr);
          return c;

    }
};