


struct ListNode* create(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}



struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode result;           
    struct ListNode* pointer = &result;
    result.next = NULL;

int carry=0;


    while(l1!=NULL || l2!=NULL || carry>0){

            int sum=carry;

        if(l1!=NULL){
            sum = sum + l1->val;
            l1=l1->next;
        }

        if(l2!=NULL){
            sum = sum + l2->val;
            l2=l2->next;
        }

        carry=sum/10;
        sum=sum%10;

    pointer->next= create(sum);
    pointer=pointer->next;
    }

    return result.next;





}
