class Solution {
public:

// before -> node before the reversed portion
// temp   -> first node of the reversed portion
// curr   -> current node being processed
// prev   -> previous node used for reversal
// nex    -> next node (stored temporarily)

    ListNode* reverseBetween(ListNode* head, int left, int right) {

        ListNode* temp = head;
        ListNode* before = nullptr;   // Node just before the reversal starts
        int pos = 1;

        // Empty list
        if (head == nullptr) {
            return head;
        }

        // No need to reverse
        else if (left == right) {
            return head;
        }

        else {
            while (temp != nullptr) {

                // Move to the starting position
                if (pos < left) {
                    before = temp;
                    temp = temp->next;
                    pos++;
                }

                else {

                    // Starting node of the sublist
                    ListNode* curr = temp;

                    // Used to reverse the links
                    ListNode* prev = nullptr;

                    // Number of nodes to reverse
                    int times = right - left + 1;

                    while (times--) {

                        // Store the next node
                        ListNode* nex = curr->next;

                        // Reverse the pointer
                        curr->next = prev;

                        // Move both pointers ahead
                        prev = curr;
                        curr = nex;
                    }

                    // Connect the tail of the reversed list
                    // to the remaining part of the list
                    temp->next = curr;

                    // If the reversed part is not starting from the head
                    if (before != nullptr) {
                        before->next = prev;
                        return head;
                    }

                    // If left == 1, the new head becomes prev
                    return prev;
                }
            }
        }

        return head;
    }
};