class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;
        int time = 0;
        for (int i = 0; i < tickets.size(); i++) {
            q.push(i);
        }
        while (!q.empty()) {
            int t = q.front();

            q.pop();
            tickets[t]--;

            time++;
            if (tickets[t] == 0 && t == k) {
                return time;
            }
            if (tickets[t] > 0) {
                q.push(t);
            }
        }
        return time;
    }
};