class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {

        int s = 0;
        int e = letters.size();
        while (s < e) {
            int m = s + (e - s) / 2; // 1
            if (letters[m] <= target) {
                s = m + 1;
            }
            if (letters[m] > target) {
                e = m;
            }
        }
        return letters[s % letters.size()];
    }
};