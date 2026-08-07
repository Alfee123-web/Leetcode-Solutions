class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        // 2 3 5 7 11 13 17
        queue<int> q;

        for (int i = 0; i < deck.size(); i++) {
            q.push(i); // index
        }
        vector<int> ans(deck.size());
        for (int i = 0; i < deck.size(); i++) {
            ans[q.front()] = deck[i];
            q.pop();

            if (!q.empty()) {
                q.push(q.front());
                q.pop();
            }
        }
        return ans;
    }
};