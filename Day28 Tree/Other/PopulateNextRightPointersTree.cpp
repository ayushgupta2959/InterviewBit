/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 
void Solution::connect(TreeLinkNode* A) {
    TreeLinkNode* cl0 = NULL;
    TreeLinkNode* fl1 = NULL;
    TreeLinkNode* pl1 = NULL; 
    // means current node at level 0, 
    //first node at level 1, previous node at level 1
    cl0 = A;
    while(cl0!=NULL){
        pl1 = NULL;
        while(cl0!=NULL){
            if(cl0->left!=NULL){
                pl1=cl0->left;
                break;
            }
            if(cl0->right!=NULL){
                pl1=cl0->right;
                break;
            }
            cl0 = cl0->next;
        }
        //if(pl1==NULL) break;
        fl1 = pl1;
        while(cl0!=NULL){
            if(cl0->left!=NULL){
                pl1->next = cl0->left;
                pl1 = cl0->left;
            }
            if(cl0->right!=NULL){
                pl1->next = cl0->right;
                pl1 = cl0->right;
            }
            cl0 = cl0->next;
        }
        if(pl1!=NULL) pl1->next = NULL; //imp check might cause loop if a level contains only 1 node
        cl0 = fl1;
    }
}

/*
//smart approach but causes extra space overhead equal to height of tree
// if tree is like singly linked i.e all node have only 1 child the height of tree equals n and
// so is the space complexity
void Solution::connect(TreeLinkNode* root) {
    
         while(root)
         {
             TreeLinkNode* t=new TreeLinkNode(0);
             TreeLinkNode* c=t;
             
             while(root)
             {
                 if(root->left)
                 {
                     c->next=root->left;
                     c=c->next;
                 }
                 if(root->right)
                 {
                     c->next=root->right;
                     c=c->next;
                 }
                 root=root->next;
             }
             
             root=t->next;
             
         }
}
