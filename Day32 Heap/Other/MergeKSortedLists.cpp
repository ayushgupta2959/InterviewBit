/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class comparator{
    public:
    bool operator()(ListNode* a, ListNode* b){
        if(a->val < b->val){
            return false;
        }
        else return true;
    }
};
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    priority_queue<ListNode*,vector<ListNode*>,comparator> pq;
    for(auto x:A){
        pq.push(x);
    }
    ListNode* result = NULL;
    ListNode* curr;
    ListNode* t;
    while(!pq.empty()){
        t = pq.top();
        pq.pop();
        if(result!=NULL){
            curr->next = t;
            if(t->next!=NULL) pq.push(t->next);
            curr = t;
        }
        else{
            result = t;
            curr = t;
            if(t->next!=NULL) pq.push(t->next);
        }
    }
    return result;
}
