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
        if (head == nullptr || head->next == nullptr)
            return nullptr;
        ListNode* ptr = head;
        int c = 0;
        while (ptr != nullptr) {

            c++;
            ptr = ptr->next;
        }
        int target = c / 2;
        ListNode* mid = head;
        for (int i = 0; i < target - 1; i++) {
            mid = mid->next;
        }
        ListNode* del = mid->next;
        mid->next = del->next;
        delete del;
        return head;
    }
};