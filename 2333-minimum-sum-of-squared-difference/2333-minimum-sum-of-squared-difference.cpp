class Solution {
    long long calcCost(vector<long long>&diff , int m){
        long long totCost = 0;
        for(int i = 0; i < diff.size(); i++){
            if(diff[i] > m) totCost += (diff[i] - m);
        }
        return totCost;
    }
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long ans = 0;
        int n = nums1.size();
        
        long long K = (long long) k1 + k2;
        vector<long long>diff(n);

        for(int i = 0 ; i <n ; i++){
           diff[i] = abs(nums1[i] - nums2[i]);
        }
        //Binary Search
        long long s = 0;
        long long e = 0;
        for(int i = 0; i< n ; i++){
            e = max(e , (long long)diff[i]);
        }
        long long targetCeil = e;
        while(s <= e){
            long long m = s + (e-s)/2;
            if(calcCost(diff,m) <= K){
                targetCeil = m;
                e = m-1;
            }else{
                s = m +1;
            }

        }
          for(int i = 0; i < n ; i++){
            if(diff[i] > targetCeil){
                K -= (diff[i]-targetCeil);
                diff[i] = targetCeil;
            }
        }
        for(int i = 0; i < n ; i++){
            if(diff[i] == targetCeil && diff[i] > 0 && K>0){
                diff[i] -= 1;
                K--;
            }
        }
        for(int i = 0; i < n ; i++){
            diff[i] *= diff[i];
            ans += diff[i];
        }
return ans;
    }
};