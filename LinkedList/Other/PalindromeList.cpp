/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* A) {
    if(A==NULL) return 1;
    ListNode* slow = A;
    ListNode* fast = A->next;
    ListNode* prev = NULL;
    ListNode* temp;
    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        temp = slow;
        slow = slow->next;
        if(prev!=NULL){
            temp->next = prev;
            prev = temp;
        }
        else{
            prev = temp;
            prev->next = NULL;
        }
    }
    temp = slow->next;
    slow->next = prev;
    if(fast==NULL) slow = slow->next;
    while(temp!=NULL && slow!=NULL){
        if(temp->val!=slow->val) return 0;
        temp = temp->next;
        slow = slow->next;
    }
    if(slow==NULL && temp==NULL) return 1;
    else return 0;
}
