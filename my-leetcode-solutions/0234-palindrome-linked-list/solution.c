/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverse(struct ListNode* head){

    if(head==NULL || head->next==NULL){
        return head;
    }

    struct ListNode* newHead = reverse(head->next);

    struct ListNode* front = head->next;
    front->next = head;
    head->next = NULL;

    return newHead; 
}
bool isPalindrome(struct ListNode* head) {
        if(head==NULL || head->next==NULL){
        return head;
    }

    struct ListNode* slow = head;
    struct ListNode* fast =  head;

    while(fast->next != NULL && fast->next->next != NULL){
        fast=fast->next->next;
        slow=slow->next;
    }

    struct ListNode* head2 = reverse(slow->next);

    struct ListNode* first = head;
    struct ListNode* second = head2;

    while(second!=NULL){
        if(first->val != second->val){
            reverse(head2);

            return false;
        }
        first=first->next;
        second=second->next;
    }

    reverse(head2);

    return true;
}
