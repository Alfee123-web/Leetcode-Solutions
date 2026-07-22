class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int currN = 0;
        char sign = '+';
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (isdigit(ch)) {
                currN = currN * 10 + (ch - '0');
            }
            if ((!isdigit(ch) && ch != ' ') || i == s.length() - 1) {
                if (sign == '+')
                    st.push(currN);
                else if (sign == '-')
                    st.push(-currN);
                else if (sign == '*') {
                    int top = st.top();
                    st.pop();
                    st.push(top * currN);
                } else if (sign == '/') {
                    int top = st.top();
                    st.pop();
                    st.push(top / currN);
                }
                sign = ch;
                currN = 0;
            }
        }
        int ans = 0;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};