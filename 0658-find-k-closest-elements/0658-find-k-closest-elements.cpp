class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int s = 0;
        int e = arr.size()-k;
        
        while (s < e) {
            int m = s + (e - s) / 2;
            if(x-arr[m] > arr[m+k]-x){
                s = m+1;
            }else{
                e =m;
            }
        }
        return vector<int>(arr.begin()+s,arr.begin() + s + k);
    }
};