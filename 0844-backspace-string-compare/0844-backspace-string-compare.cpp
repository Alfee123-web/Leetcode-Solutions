class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n = s.length();
        int m = t.length();
        int i = n - 1;// right to left
        int j = m - 1;
        int sk1 = 0;
        int sk2= 0;//Skip the dead 
        while (i >= 0 || j >= 0) {
            while (i >= 0) {
                if (s[i] == '#') {
                    sk1++;
                    i--;
                } else if (sk1 > 0) {
                    sk1--;
                    i--;
                } else {
                    break;
                }
            }
            while (j >= 0) {
                if (t[j] == '#') {
                    sk2++;
                    j--;
                } else if (sk2 > 0) {
                    sk2--;
                    j--;
                } else {
                    break;
                }
            }
            if (i >= 0 && j >= 0) {
                if (s[i] != t[j])
                // find a mismatch?
                    return false;
            } else {
                if (i >= 0 || j >= 0)
                    return false;
            }
        if (i >= 0) {
            i--;
        }
        if (j >= 0) {
            j--;
        }
    }
    return true;
}
};