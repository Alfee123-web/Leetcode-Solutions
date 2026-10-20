#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int total_sum = 0;

        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());

        // Precompute prefix counts of sorted elements to verify min/max ranges quickly
        for (int k = 1; k <= n; ++k) {
            if (n % k != 0) continue;

            bool all_blocks_valid = true;

            for (int i = 0; i < n; i += k) {
                if (!isCyclicSortedBlock(nums, sorted_nums, i, k)) {
                    all_blocks_valid = false;
                    break;
                }
            }

            if (all_blocks_valid) {
                total_sum += k;
            }
        }

        return total_sum;
    }

private:
    bool isCyclicSortedBlock(const vector<int>& nums, const vector<int>& sorted_nums, int start, int k) {
        if (k == 1) return nums[start] == sorted_nums[start];

        int drops = 0;
        int min_val = nums[start];
        int max_val = nums[start];

        for (int m = 0; m < k - 1; ++m) {
            int cur = nums[start + m];
            int next = nums[start + m + 1];
            if (cur > next) {
                drops++;
                if (drops > 1) return false;
            }
            min_val = min(min_val, next);
            max_val = max(max_val, next);
        }

        // A cyclically sorted non-decreasing array has at most 1 drop.
        // If drops == 1, the last element must be <= the first element.
        if (drops == 1 && nums[start + k - 1] > nums[start]) {
            return false;
        }

        // Check if the range of values matches the expected block in sorted_nums
        if (min_val != sorted_nums[start] || max_val != sorted_nums[start + k - 1]) {
            return false;
        }

        return true;
    }
};