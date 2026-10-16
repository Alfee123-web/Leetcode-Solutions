class Solution {
public:
    long long sum_sq[400005];
    long long sum_c[400005];
    long long lazy[400005];
    long long MOD = 1e9 + 7;

    void push(int node, int L, int R) {
        if (lazy[node] != 0) {
            int mid = L + (R - L) / 2;
            long long val = lazy[node];
            lazy[node] = 0;
            
            // Update Left Child
            long long len_left = mid - L + 1;
            sum_sq[2 * node] = (sum_sq[2 * node] + 2 * val * sum_c[2 * node] + val * val % MOD * len_left) % MOD;
            sum_c[2 * node] = (sum_c[2 * node] + val * len_left) % MOD;
            lazy[2 * node] = (lazy[2 * node] + val) % MOD;
            
            // Update Right Child
            long long len_right = R - mid;
            sum_sq[2 * node + 1] = (sum_sq[2 * node + 1] + 2 * val * sum_c[2 * node + 1] + val * val % MOD * len_right) % MOD;
            sum_c[2 * node + 1] = (sum_c[2 * node + 1] + val * len_right) % MOD;
            lazy[2 * node + 1] = (lazy[2 * node + 1] + val) % MOD;
        }
    }

    void update(int node, int L, int R, int l, int r, long long val) {
        if (r < L || R < l) return;
        if (l <= L && R <= r) {
            long long len = R - L + 1;
            sum_sq[node] = (sum_sq[node] + 2 * val * sum_c[node] + val * val % MOD * len) % MOD;
            sum_c[node] = (sum_c[node] + val * len) % MOD;
            lazy[node] = (lazy[node] + val) % MOD;
            return;
        }
        push(node, L, R);
        int mid = L + (R - L) / 2;
        update(2 * node, L, mid, l, r, val);
        update(2 * node + 1, mid + 1, R, l, r, val);
        sum_sq[node] = (sum_sq[2 * node] + sum_sq[2 * node + 1]) % MOD;
        sum_c[node] = (sum_c[2 * node] + sum_c[2 * node + 1]) % MOD;
    }

    long long query(int node, int L, int R, int l, int r) {
        if (r < L || R < l) return 0;
        if (l <= L && R <= r) return sum_sq[node];
        push(node, L, R);
        int mid = L + (R - L) / 2;
        return (query(2 * node, L, mid, l, r) + query(2 * node + 1, mid + 1, R, l, r)) % MOD;
    }

    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        memset(sum_sq, 0, sizeof(sum_sq));
        memset(sum_c, 0, sizeof(sum_c));
        memset(lazy, 0, sizeof(lazy));
        
        unordered_map<int, int> last_pos;
        long long total_sum = 0;
        
        for (int i = 1; i <= n; i++) {
            int x = nums[i - 1];
            // Only add 1 to subarrays that start AFTER the last time we saw 'x'
            int l = last_pos.count(x) ? last_pos[x] + 1 : 1; 
            int r = i;
            
            update(1, 1, n, l, r, 1);
            total_sum = (total_sum + query(1, 1, n, 1, i)) % MOD;
            last_pos[x] = i;
        }
        return total_sum;
    }
};
