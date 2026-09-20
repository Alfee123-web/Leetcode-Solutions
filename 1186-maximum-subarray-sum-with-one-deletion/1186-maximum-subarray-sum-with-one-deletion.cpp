class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int ans = arr[0];
        int noDel = arr[0];
        int oneDel = arr[0];

        for(int i = 1;i < arr.size();i++){
             

             //variation
            oneDel = max(noDel , arr[i] + oneDel);
             //basic kadanes
            noDel = max(arr[i],arr[i] + noDel);

            ans = max(ans,max(noDel , oneDel));

        }
        return ans;
    }
};