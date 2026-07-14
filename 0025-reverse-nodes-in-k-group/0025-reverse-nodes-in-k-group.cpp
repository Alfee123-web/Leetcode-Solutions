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
    ListNode* reverseKGroup(ListNode* head, int k) {
          ListNode* temp = head;
        int c = 0;
          //check k nodes exists
        while (c < k) {
            if (temp == NULL)
                return head;
                temp = temp->next;
                c++;
        }
        //recursively call for rest of LL
        //temp = new head
        ListNode* prevNode = reverseKGroup(temp, k);
        //reverse curr group 
        temp = head;
        c =0 ;
        while(c <  k){
        ListNode *next = temp->next;
        temp->next = prevNode;

       prevNode = temp;
       temp = next;
       c++;
        }
       return prevNode;
       //new head
    }
};