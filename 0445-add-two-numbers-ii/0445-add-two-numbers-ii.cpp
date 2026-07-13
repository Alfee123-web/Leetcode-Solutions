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
    ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode dummy(0);
        ListNode* ptr = &dummy;
        int carry = 0;
        while (l1 != NULL || l2 != NULL || carry != 0) {
            int s = carry;
            if (l1) {
                s += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                s += l2->val;
                l2 = l2->next;
            }
            carry = s / 10;
            ptr->next = new ListNode(s % 10);
            ptr = ptr->next;
        }
        return reverse(dummy.next);
    }
};