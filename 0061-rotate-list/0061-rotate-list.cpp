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
        if (!head || !head->next || k == 0)
            return head;

        ListNode* curr = head;
        int l = 0;
        while (curr) {
            curr = curr->next;
            l++;
        }
        // Normalize k
        k = k % l;
        if (k == 0)
            return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* slow = head;
        ListNode* fast = head;
        for (int i = 0; i < k; i++) {
            fast = fast->next;
        }
        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        fast->next = dummy.next;
        dummy.next = slow->next;
        slow->next = NULL;
        return dummy.next;
    }
};