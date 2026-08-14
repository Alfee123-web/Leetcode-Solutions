class Solution {
public:
    int getCh(char r) {
        switch (r) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
        }
    }
    int romanToInt(string s) {
        int v = 0;
        for (int i = 0; i < s.length(); i++) {
            int c = getCh(s[i]);
            if (i < s.length() - 1 && c < getCh(s[i + 1])) {
                v -= c;
            } else {
                v += c;
            }
        }
        return v;
    }
};
