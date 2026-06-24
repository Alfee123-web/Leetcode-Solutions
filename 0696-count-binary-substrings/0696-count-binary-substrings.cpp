class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev = 0;
        int curr = 1;
        int c = 0;
        for(int i = 1; i < s.length();i++){
            if(s[i] == s[i-1]){
                curr++;
            }else{
                c += min(prev,curr);//score
                prev = curr;//promote
                curr =1;//start new runner
            }
        }
        c += min(prev,curr);
        return c;
    }
};
// runLength × (numberOfRuns - 1).
//  "10101": 1 × (5-1) = 4

// "00110011": 2 × (4-1) = 6

