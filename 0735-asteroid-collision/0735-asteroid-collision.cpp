class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        for (int& asteroid : asteroids) {
            bool exp = false;

            while (!st.empty() && st.back() > 0 && asteroid < 0) {
                if (st.back() < abs(asteroid)) {
                    st.pop_back();
                } else if (st.back() == abs(asteroid)) {
                    st.pop_back();
                    exp = true;
                    break;

                } else {
                    exp = true;
                    break;
                }
            }
            if (!exp) {
                st.push_back(asteroid);
            }
        }
        return st;
    }
};