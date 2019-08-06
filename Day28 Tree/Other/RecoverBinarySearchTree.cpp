/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void form_result(vector<int> &result,int val1,int val2){
    if(result.size()==0){
        result.emplace_back(val1);
        result.emplace_back(val2);
    }
    else{
        result[0] = val1;  
    }
}
void inorder(TreeNode* root,vector<int> &result,int &val){
    if(root==NULL) return;
    inorder(root->left,result,val);
    if(val<root->val) val = root->val;
    else form_result(result,root->val,val);
    inorder(root->right,result,val);
}
vector<int> Solution::recoverTree(TreeNode* A) {
    vector<int> result;
    int val = INT_MIN;
    inorder(A,result,val);
    return result;
}
