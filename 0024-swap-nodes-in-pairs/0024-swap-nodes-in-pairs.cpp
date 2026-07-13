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
            prev->next = next;
            curr->next = next->next;
            next->next = curr;

            prev = curr;
            //forward

        }
        return dummy.next;
    }
};
// Step 1: Link the previous structure to the second node of the pair
// Step 2: Connect the first node to the rest of the remaining list
// Step 3: Turn the second node back around to point to the first node