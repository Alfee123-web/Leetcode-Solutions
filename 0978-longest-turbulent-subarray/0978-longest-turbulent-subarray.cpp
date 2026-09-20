class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int maxL = 1;
        int inc = 1;
        int dec = 1;
        for(int i = 1 ;i < arr.size(); i ++){
            if(arr[i] > arr[i-1]){//increasing step
                inc = dec +1 ;
                //we extend the previous dec sequence
                dec = 1;
            }
            else if(arr[i] < arr[i-1]){//decreasing step
                dec = inc +1;
                //We extend the previous inc
                inc = 1;
            }else{
                inc = 1,dec =1;
            }
            maxL = max(maxL ,max(inc , dec));
        }
        return maxL;
    }
};