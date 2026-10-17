class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<tuple<int, int, int>> arr; // {sum, number, original_index}
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int number = nums[i];
            int sum = 0;
            int temp = number;

            while (temp > 0) {
                int dig = temp % 10;
                sum += dig;
                temp /= 10;
            }
            arr.push_back({sum, number, i});
        }
        
        sort(arr.begin(), arr.end());
        int swaps = 0;
        vector<bool> visited(n, false);
        
        for (int i = 0; i < n; i++) {
            int original_index = get<2>(arr[i]);
            
            if (visited[i] || original_index == i) {
                continue;
            }
            
            int cycle_size = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = get<2>(arr[j]);
                cycle_size++;
            }
            
            if (cycle_size > 0) {
                swaps += (cycle_size - 1);
            }
        }
        return swaps;
    }
};