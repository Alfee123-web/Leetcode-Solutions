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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL) return NULL;
      ListNode *ptr = head;
      int c = 0;
        while(ptr != NULL){
            ptr = ptr->next;
            c++;
        }
        int target = c/2;//3
        ListNode *curr = head;
        for(int i = 0 ; i< target-1 ; i++){
              curr= curr->next;
        }
              ListNode *todel = curr->next;
              curr->next = curr->next->next;
              delete todel;
        
return head;
    }
};