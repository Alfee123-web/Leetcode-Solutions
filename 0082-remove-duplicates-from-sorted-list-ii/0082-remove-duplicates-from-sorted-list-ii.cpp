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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* slow = &dummy;
        ListNode *fast = head;
        while (fast != NULL) {
            if ( fast->next != NULL && fast->val == fast->next->val) {
                while (fast->next != NULL && fast->val == fast->next->val) {
                    ListNode* temp = fast;
                    fast= fast->next;
                    delete temp;
                }
                ListNode* dupTail = fast;
                slow->next = fast->next;
                fast= fast->next;
                delete dupTail;
            } else {
                slow = slow->next;
                fast = fast->next;
            }
        }
        return dummy.next;
    }
};