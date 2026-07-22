#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int max_val = *max_element(nums.begin(), nums.end());
        vector<long long> freq(max_val + 1, 0);
        
        for (int num : nums) {
            freq[num]++;
        }
        
        vector<long long> gcd_count(max_val + 1, 0);
        
        for (int i = max_val; i >= 1; i--) {
            long long multiples_count = 0;
            
            for (int j = i; j <= max_val; j += i) {
                multiples_count += freq[j];
            }
            
            long long pairs = multiples_count * (multiples_count - 1) / 2;
            
            for (int j = 2 * i; j <= max_val; j += i) {
                pairs -= gcd_count[j];
            }
            
            gcd_count[i] = pairs;
        }
        
        vector<long long> prefix(max_val + 1, 0);
        for (int i = 1; i <= max_val; i++) {
            prefix[i] = prefix[i - 1] + gcd_count[i];
        }
        
        vector<int> ans;
        for (long long q : queries) {
            int idx = upper_bound(prefix.begin(), prefix.end(), q) - prefix.begin();
            ans.push_back(idx);
        }
        
        return ans;
    }
};