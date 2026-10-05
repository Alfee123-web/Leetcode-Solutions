class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0); // Base score for the current level
        
        for (char c : s) {
            if (c == '(') {
                st.push(0);
            } else {
                int innerScore = st.top();
                st.pop();
                int currentScore = st.top();
                st.pop();
                
                // If innerScore is 0, it means it was "()", score is 1.
                // Otherwise, it was "(A)", score is 2 * innerScore.
                int addedScore = (innerScore == 0) ? 1 : 2 * innerScore;
                st.push(currentScore + addedScore);
            }
        }
        
        return st.top();
    }
};