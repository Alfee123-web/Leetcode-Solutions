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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0,head);
        //dummy => next ptr == head
      
       ListNode* fast = &dummy;
       ListNode* slow = &dummy;
       //points memory address

       for(int i = 0; i <= n ; i++){
        fast = fast->next;
       }
       while(fast != NULL){
        slow = slow->next;
        fast = fast->next;
       }
       ListNode* temp = slow->next;
       slow->next = slow->next->next;
       delete temp;
       return dummy.next;
       //new head of the list
    }
};