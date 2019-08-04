/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* clone_tree_helper(TreeNode* root){
    if(root==NULL) return NULL;
    TreeNode* new_root = new TreeNode(root->val);
    new_root->left = clone_tree_helper(root->left);
    new_root->right = clone_tree_helper(root->right);
    return new_root;
}
void clone_tree(TreeNode* root,vector<TreeNode*> &result){
    TreeNode* new_root = new TreeNode(root->val);
    new_root->left = clone_tree_helper(root->left);
    new_root->right = clone_tree_helper(root->right);
    result.emplace_back(new_root);
}
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
void findNextConfig(TreeNode* temp,TreeNode* parent,bool lc,bool rc,TreeNode* root,vector<TreeNode*> &result){
    //if(temp==NULL) return;
    if(temp->right!=NULL){
        temp = left_rotate(temp);
        if(lc) parent->left = temp;
        else parent->right = temp;
        clone_tree(root,result);
        if(temp->left!=NULL) findNextConfig(temp->left,temp,true,false,root,result);
        if(temp->right!=NULL) findNextConfig(temp->right,temp,false,true,root,result);
        temp = right_rotate(temp);
        if(lc) parent->left = temp;
        else parent->right = temp;
    }
    if(temp->left!=NULL){
        temp = right_rotate(temp);
        if(lc) parent->left = temp;
        else parent->right = temp;
        clone_tree(root,result);
        if(temp->left!=NULL) findNextConfig(temp->left,temp,true,false,root,result);
        if(temp->right!=NULL) findNextConfig(temp->right,temp,false,true,root,result);
        temp = left_rotate(temp);
        if(lc) parent->left = temp;
        else parent->right = temp;
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
    
    //TreeNode* t;
    //TreeNode* parent=NULL;
    for(int i=0;i<A;++i){
        clone_tree(root,result);
        if(root->right!=NULL) findNextConfig(root->right,root,false,true,root,result);
        if(root->left!=NULL) findNextConfig(root->left,root,true,false,root,result);
        if(root->right!=NULL){
            root = left_rotate(root);
        }
    }
    
    return result;
}
