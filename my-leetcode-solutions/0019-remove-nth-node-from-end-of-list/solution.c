/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int length(struct ListNode* head){
    if(head==NULL) return 0;
    int length = 0;
    struct ListNode* temp = head;

    while(temp != NULL){
        length++;
        temp = temp->next;
    }

    return length;
}



struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int l = length(head);
    int remove = l - n + 1;
    struct ListNode* temp = head;
    struct ListNode* prev= NULL;

    if(remove==1){
        struct ListNode* newHead = head->next;
        free(head);
        return newHead;
    }

    for(int i = 1; i<remove; i++){
        prev = temp;
        temp=temp->next;
    }

    prev->next = temp->next;

    free(temp);


    return head;


}
