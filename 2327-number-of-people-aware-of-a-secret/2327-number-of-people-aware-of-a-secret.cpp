class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        long long MOD  = 1e9 + 7;
        vector<long long>age(forget , 0);
        //track how long people have known the secret.
        age[0] = 1;
        for(int i =2;i <= n ; i++){
            long long share = 0;
            for(int i = delay-1;i < forget -1;i++){
                share = (share + age[i]) % MOD;
            }
              for(int i = forget-1;i > 0;i--){
                age[i] = age[i-1];
                //shifts every group one position to the right
            }
            age[0] = share;
        }
        long long ans = 0;
        for(int i = 0; i < forget;i++){
            ans = (ans + age[i]) % MOD;
        }
        return ans;
    }
};
// The age Array: The array acts as a daily snapshot. The index represents how many days a group has known the secret (0-indexed). It is strictly bounded to the size of forget.

// Daily Shift: Every day, everyone in the array shifts one index to the right (age[i] = age[i - 1]). Whoever reaches the forget - 1 index simply drops off the edge of the array on the next day, simulating the forgetting mechanism.

// New Discoveries: Before shifting, we count how many people fall into the active sharing window (indexes between delay - 1 and forget - 2). This total becomes the new value for age[0].