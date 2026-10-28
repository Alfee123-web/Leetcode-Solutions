class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int n = deadends.size();
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000"))
            return -1;

        unordered_set<string> visited;
        queue<string> q;

        q.push("0000");
        visited.insert("0000");
        int turns = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string curr = q.front();
                q.pop();
                if (curr == target)
                    return turns;
                //  Generate all 8 possible neighbor states from the current
                //  state.
                // A lock has 4 wheels, and each wheel can turn 2 ways (+1 or
                // -1).
                for (int j = 0; j < 4; j++) {
                    char orgChar = curr[j];

                    for (int diff : {-1, 1}) {
                        char newChar =
                            (((orgChar - '0') + diff + 10) % 10) + '0';
                        // Create the neighbor state string
                        string nextState = curr;
                        nextState[j] = newChar;
                        //  Validation check: Proceed only if it's not a deadend
                        //  and hasn't been visited yet.
                        if (!dead.count(nextState) &&
                            !visited.count(nextState)) {
                            visited.insert(nextState);
                            q.push(nextState);
                        }
                    }
                }
            }
            turns++;
        }
        return -1;
    }
};
// 9. Wheel wrap-around arithmetic:
// (originalChar - '0'): converts char digit to integer (e.g., '5' -> 5)
// + diff: applies the turn (+1 or -1)
// + 10: prevents negative numbers before applying modulo
// % 10: handles wrap-around ('9' -> '0' and '0' -> '9')
// + '0': converts the resulting integer back to a character