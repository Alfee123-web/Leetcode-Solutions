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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k ==0) return head;
    
        ListNode *curr = head;
        int n =0 ;
        while(curr){
            curr = curr->next;
            n++;//5
        }
        k = k % n;
        if(k ==0 ) return head;
         ListNode dummy(0);
         dummy.next = head;
                ListNode* slow = head;
        ListNode* fast = head;
         for(int i = 0 ; i < k ; i++){
              fast = fast->next;
         }
         while(fast->next != NULL){
              fast = fast->next;
              slow = slow->next;
         }
        fast->next = dummy.next;
        dummy.next = slow->next;
        //4 head
        slow->next = NULL;
     // 3 break 4
        return dummy.next;
    }
};