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
        ListNode* prev = &dummy;

        while (head != NULL) {
            if (head->next != NULL && head->val == head->next->val) {
                while (head->next != NULL && head->val == head->next->val) {
                    ListNode* temp = head;head = head->next;
                    delete temp;
                }
        
            ListNode* deltail = head;
            prev->next = head->next;
            head = head->next;
            delete deltail;
            }
            else {
                head = head->next;
                prev = prev->next;
            }
        }

        return dummy.next;
    }

};