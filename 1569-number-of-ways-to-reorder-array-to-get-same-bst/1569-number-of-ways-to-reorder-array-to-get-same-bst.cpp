#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

static constexpr int Mod = 1e9 + 7;
using ll = long long;

static ll inverse(ll a) {
    ll b = Mod;
    ll x0 = 1, x1 = 0;
    while (b > 0) {
        auto [q, r] = div(a, b);
        x0 = exchange(x1, x0 - q * x1);
        a = exchange(b, r);
    }
    return (x0 < 0) ? x0 + Mod : x0;
}

static constexpr int N = 1001;
static int F[N], invF[N];

class Solution {
private:
    static void compute_F_invF() {
        if (F[0] == 1) return;
        ll prod = 1;
        F[0] = 1;
        for (int i = 1; i < N; i++) {
            prod = (prod * i) % Mod;
            F[i] = prod;
        }
        invF[N - 1] = inverse(F[N - 1]);
        for (int i = N - 2; i >= 0; i--) {
            invF[i] = (1LL * invF[i + 1] * (i + 1)) % Mod;
        }
    }

    static inline int compute_C_N_choose_K(int n, int k) {
        if (k < 0 || k > n) return 0;
        return (ll)F[n] * invF[k] % Mod * invF[n - k] % Mod;
    }

    ll subproblem(const vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return 1;

        vector<int> left, right;
        int root = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] < root) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }

        ll l = subproblem(left);
        ll r = subproblem(right);

        ll ways = compute_C_N_choose_K(n - 1, left.size());
        ways = (ways * l) % Mod;
        ways = (ways * r) % Mod;
        return ways;
    }

public:
    int numOfWays(vector<int>& nums) {
        compute_F_invF();
        return (subproblem(nums) - 1 + Mod) % Mod;
    }
};

// Fast I/O setup
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 'c';
}();