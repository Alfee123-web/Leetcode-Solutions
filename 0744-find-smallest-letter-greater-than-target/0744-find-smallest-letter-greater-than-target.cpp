class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {

        int s = 0;
        int e = letters.size();
        while (s < e) {
            int m = s + (e - s) / 2; // 1
            // If the current character is less than or equal to the target,
            // the answer must lie to the right.
            if (letters[m] <= target) {
                s = m + 1;
            }
            // If the current character is strictly greater than the target,
            // it's a valid candidate, but we search the left side for a smaller one.
            if (letters[m] > target) {
                e = m;
            }
        }
        return letters[s % letters.size()];
    }
};