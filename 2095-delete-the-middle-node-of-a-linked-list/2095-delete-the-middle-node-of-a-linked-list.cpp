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
        if(head == nullptr || head->next == nullptr) return nullptr;
        int n = 0;
        ListNode *ptr =  head;
        while(ptr != nullptr){
            n++;
         ptr = ptr->next;
        }
        int target = n/2;
        ListNode *curr = head;
        for(int i = 0; i <target-1;i++ ){
            curr = curr->next;
        }
        ListNode* middle = curr->next;
        curr->next = middle->next;
        delete middle;
        return head;
    }
};