/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* left_rotate(TreeNode* root){
    TreeNode* temp = root->right;
    root->right = temp->left;
    temp->left = root;
    return temp;
}
TreeNode* right_rotate(TreeNode* root){
    TreeNode* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    return temp;
}
void findNextConfig(TreeNode* temp,TreeNode* root,vector<TreeNode*> &result){
    //if(temp==NULL) return;
    if(temp->right!=NULL){
        temp = left_rotate(temp);
        
        findNextConfig(temp,root,result);
        temp = right_rotate(temp);
    }
    if(temp->left!=NULL){
        temp = right_rotate(temp);
        findNextConfig(temp,root,result);
        temp = left_rotate(temp);
    }
    return;
}
vector<TreeNode*> Solution::generateTrees(int A) {
    vector<TreeNode*> result;
    TreeNode* root = new TreeNode(1);
    TreeNode* temp = root;
    for(int i=2;i<=A;++i){
        TreeNode* node = new TreeNode(i);
        temp->right = node;
        temp = node;
    }
    
    
    temp = root;
    result.emplace_back(temp);
    for(int i=1;i<A;++i){
        findNextConfig(temp,root,result);
        prev = temp;
        temp = temp->right;
    }
    
    return result;
}
