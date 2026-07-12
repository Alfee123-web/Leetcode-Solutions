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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0);
        dummy.next = head;
        while (head == NULL || left == right)
            return head;
        ListNode* ptr = &dummy;
        for (int i = 0; i < left - 1; i++) {
            ptr = ptr->next; // prev
        }
        ListNode* curr = ptr->next;
        for (int i = 0; i < right - left; i++) {

            ListNode* next = curr->next;
            curr->next = next->next; // 2-4
            next->next = ptr->next;  // 3-2
            ptr->next = next;        // 1-4
        }
        return dummy.next;
    }
};