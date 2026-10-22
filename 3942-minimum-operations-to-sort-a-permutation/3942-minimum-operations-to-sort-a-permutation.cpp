
class Solution {
public:
    int minOperations(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        auto get_shift = [&](const std::vector<int>& target) {
            int pos = -1;
            for (int i = 0; i < n; ++i) {
                if (nums[i] == target[0]) {
                    pos = i;
                    break;
                }
            }
            if (pos == -1) return -1;
            for (int i = 0; i < n; ++i) {
                if (nums[(pos + i) % n] != target[i]) {
                    return -1;
                }
            }
            return pos;
        };

        std::vector<int> inc(n), dec(n);
        std::iota(inc.begin(), inc.end(), 0);
        for (int i = 0; i < n; ++i) dec[i] = n - 1 - i;

        int ans = 1e9;

        int shift_inc = get_shift(inc);
        if (shift_inc != -1) {
            ans = std::min(ans, shift_inc);
            ans = std::min(ans, 2 + (n - shift_inc) % n);
        }

        int shift_dec = get_shift(dec);
        if (shift_dec != -1) {
            ans = std::min(ans, 1 + (n - shift_dec) % n);
            ans = std::min(ans, shift_dec + 1);
        }

        return ans == 1e9 ? -1 : ans;
    }
};