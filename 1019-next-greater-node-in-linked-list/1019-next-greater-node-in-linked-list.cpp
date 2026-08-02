/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>arr;
        for(ListNode* curr = head;curr!= NULL;curr=curr->next){
            arr.push_back(curr->val);
        }
        vector<int>ans(arr.size(),0);
        stack<int>st;
        for(int i = 0; i < arr.size();i++){
           while(!st.empty() && arr[st.top()] < arr[i]){
              int t = st.top();
              st.pop();
              ans[t] = arr[i];
           }
               st.push(i);

        }
        return ans;
    
    }
};