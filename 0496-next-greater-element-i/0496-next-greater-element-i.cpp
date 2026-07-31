class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>nextG;
        stack<int>st;
       
        for(int num : nums2){
        while(!st.empty() && num > st.top()){
            nextG[st.top()] = num;
            st.pop();
            
        }
        st.push(num);
        }
         vector<int>ans;
         ans.reserve(nums1.size());
         for(int num : nums1){
           if(nextG.count(num)){
            ans.push_back(nextG[num]);
           }else{
            ans.push_back(-1);
           }

         }
return ans;
        
    }
};