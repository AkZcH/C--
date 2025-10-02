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
    ListNode* sortList(ListNode* head) {
        if(head==NULL) return head;
        int n = 0;
        ListNode* temp=head;

        vector<int> array;

        while(temp != NULL){
            array.push_back(temp->val);
            n++;
            temp=temp->next;
        }

        sort(array.begin(), array.end());

        temp = head;
        int i = 0;
        while(temp != NULL && i<n){
            temp->val= array[i];
            i++;
            temp=temp->next;
        }

        return head;

    }
};
