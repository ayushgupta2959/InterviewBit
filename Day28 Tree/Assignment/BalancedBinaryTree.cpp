/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool solve(TreeNode* A,int &height){
    if(A == NULL){
        height = 0;
        return true;
    }

    int lh;
    int rh;
    bool is_bal_left = solve(A->left,lh);
    bool is_bal_right = solve(A->right,rh);
    height = max(lh,rh)+1;
    if(!is_bal_left || !is_bal_right) return false;
    if(abs(lh-rh)>1) return false;
    else return true;
}
int Solution::isBalanced(TreeNode* A) {
    int height = 0;
    if(solve(A,height)) return 1;
    else return 0;
}

