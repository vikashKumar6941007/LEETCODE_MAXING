/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        //existing of linklist and only one pointer in linklist
        if(head == nullptr || head->next == nullptr)
        return nullptr;
        ListNode *slow=head;
        ListNode *fast=head;

        //detect cycle
         while(fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow==fast){
            //finding start of cycle using floyd's algo
            slow=head;

            while(slow!=fast){

            slow=slow->next;
            fast=fast->next;
            }

            return slow;
          }
        }
        return nullptr;

        
    }
};