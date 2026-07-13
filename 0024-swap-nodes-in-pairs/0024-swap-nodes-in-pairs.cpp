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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy;
      while(prev->next && prev->next->next){
            ListNode* curr = prev->next;
            ListNode *next = prev->next->next;
            prev->next = next;//0-2
            curr->next = next->next;//2-1
            next->next = curr;

            prev = curr;

        }
        return dummy.next;
    }
};