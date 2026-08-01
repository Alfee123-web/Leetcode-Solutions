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
        vector<int>ans;
        for(ListNode* curr = head; curr!= NULL;curr=curr->next){
            ans.push_back(curr->val);
        }
        int n = ans.size();
        vector<int>res(n,0);
        stack<int>st;
        //next greater same 
        for(int i = 0;i < n ; i++){
            while(!st.empty() && ans[st.top()] < ans[i] ){
                res[st.top()] = ans[i];
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};