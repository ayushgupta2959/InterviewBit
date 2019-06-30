/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool sumTree(TreeNode* root,int &sum){
    if(root==NULL){
        sum = 0;
        return true;
    }
    if(root->left==NULL && root->right==NULL){
        sum=root->val;
        return true;
    }
    int lsum;
    int rsum;
    bool lresult = sumTree(root->left,lsum);
    bool rresult = sumTree(root->right,rsum);
    sum = root->val + lsum + rsum;
    if(!lresult || !rresult) return false;
    if(lsum+rsum==root->val) return true;
    else return false;
}
int Solution::solve(TreeNode* A) {
    if(A==NULL) return 1;
    int sum=0;
    if(sumTree(A,sum)){
        return 1;
    }
    else{
        return 0;
    }
}

