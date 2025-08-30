class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head; // edge case: 0 or 1 node
        
        ListNode* odd = head;              // pointer for odd indexed nodes
        ListNode* even = head->next;       // pointer for even indexed nodes
        ListNode* evenHead = even;         // keep start of even list to connect later
        
        while (even && even->next) {
            odd->next = even->next;        // link odd to next odd
            odd = odd->next;               // move odd pointer
            
            even->next = odd->next;        // link even to next even
            even = even->next;             // move even pointer
        }
        
        odd->next = evenHead;              // attach even list after odd list
        return head;
    }
};

