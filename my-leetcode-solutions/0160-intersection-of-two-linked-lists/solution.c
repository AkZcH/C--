/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *tempA = headA;
    struct ListNode *tempB = headB;



    if(headA==NULL || headB==NULL){
        return NULL;
    }

    int length1=0;
    int length2=0;

    while(tempA!=NULL){
        length1++;
        tempA=tempA->next;
    }

    while(tempB!=NULL){
        length2++;
        tempB=tempB->next;
    }

    tempA = headA;
    tempB = headB;

    int difference = abs(length2 - length1);

    if(length1>length2){
        while(difference!=0 && length1>length2){
            tempA=tempA->next;
            difference--;
        }
    }
    else{
        while(difference!=0 && length2>length1){
            tempB = tempB->next;
            difference--;
        }
    }

    while(tempA != NULL && tempB != NULL){
        if(tempA==tempB){
            return tempA;
        }
        tempA=tempA->next;
        tempB=tempB->next;

       
    }

    return NULL;
}
