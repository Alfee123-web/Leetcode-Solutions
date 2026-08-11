class Solution {
public:
void merge(vector<int>&nums , int s , int m , int e){
    vector<int>temp;
    int i = s;
    int j = m+1;
    while(i <= m && j <= e){
             if(nums[i] < nums[j]){
                temp.push_back(nums[i]);
                i++;             
    }else{
        temp.push_back(nums[j]);
        j++;
    }
}
while(i <= m){
       temp.push_back(nums[i]);
       i++;
}
while(j <= e){
       temp.push_back(nums[j]);
       j++;
}
for(int idx = 0;idx < temp.size();idx++){
    nums[s + idx] = temp[idx];
}
}
  void mergeSort(vector<int>&nums , int s , int e){
    if(s>=e){
        return;
    }
    int m = s + (e-s)/2;
    mergeSort(nums , s , m);
    mergeSort(nums , m+1,e);

    merge(nums , s, m , e);
  }
    vector<int> sortArray(vector<int>& nums) {
        if(nums.empty()) return nums;
        mergeSort(nums , 0 , nums.size()-1);
        return nums;
    }
};