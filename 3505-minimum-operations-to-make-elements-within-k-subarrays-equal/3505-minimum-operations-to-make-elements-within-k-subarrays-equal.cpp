
class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        multiset<int> low, high;
        long long sumLow = 0, sumHigh = 0;

        auto balance = [&]() {
            int target = (low.size() + high.size() + 1) / 2;

            while ((int)low.size() > target) {
                int val = *low.rbegin();
                low.erase(prev(low.end()));
                sumLow -= val;

                high.insert(val);
                sumHigh += val;
            }

            while ((int)low.size() < target) {
                int val = *high.begin();
                high.erase(high.begin());
                sumHigh -= val;

                low.insert(val);
                sumLow += val;
            }
        };

        auto add = [&](int val) {
            if (low.empty() || val <= *low.rbegin()) {
                low.insert(val);
                sumLow += val;
            } else {
                high.insert(val);
                sumHigh += val;
            }
            balance();
        };

        auto remove = [&](int val) {
            auto it = low.find(val);

            if (it != low.end()) {
                low.erase(it);
                sumLow -= val;
            } else {
                it = high.find(val);
                high.erase(it);
                sumHigh -= val;
            }

            balance();
        };

        vector<long long> cost;

        // Calculate the cost of every window of size x.
        for (int i = 0; i < n; i++) {
            add(nums[i]);

            if (i >= x) {
                remove(nums[i - x]);
            }

            if (i >= x - 1) {
                long long median = *low.rbegin();

                long long leftCost =
                    median * low.size() - sumLow;

                long long rightCost =
                    sumHigh - median * high.size();

                cost.push_back(leftCost + rightCost);
            }
        }

        // DP: dp[j][i] = minimum cost to select
        // j non-overlapping windows from first i elements.

        const long long INF = LLONG_MAX / 4;

        vector<vector<long long>> dp(
            k + 1, vector<long long>(n + 1, INF)
        );

        dp[0][0] = 0;

        for (int j = 0; j <= k; j++) {
            for (int i = 0; i <= n; i++) {

                if (dp[j][i] == INF)
                    continue;

                // Skip current position.
                if (i < n) {
                    dp[j][i + 1] = min(
                        dp[j][i + 1],
                        dp[j][i]
                    );
                }

                // Select a window of size x.
                if (j < k && i + x <= n) {
                    dp[j + 1][i + x] = min(
                        dp[j + 1][i + x],
                        dp[j][i] + cost[i]
                    );
                }
            }
        }

        return dp[k][n];
    }
};
