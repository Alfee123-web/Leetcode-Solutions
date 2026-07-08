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
        if (!head || left == right)
            return head;

        ListNode* prev = &dummy;
        for (int i = 0; i < left - 1; i++) {
            prev = prev->next;
        }
        ListNode* curr = prev->next;

        for (int i = 0; i < right - left; i++) {
            ListNode* nextNode = curr->next;
            //target -> cut
            curr->next = nextNode->next;
            //target ->front
            //back ref
            //2->4 , 2->5
            nextNode->next = prev->next;
            //3->2 , 4->3
            prev->next = nextNode;
            //1->3 , 1->4
        }

        return dummy.next;
    }
};
//1 -> 3 -> 2 -> 4 -> 5
//1 -> 4 -> 3 -> 2 -> 5
