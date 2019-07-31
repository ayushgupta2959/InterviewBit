/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode* A) {
    stack<pair<TreeNode*,char>> s;
    vector<int> result;
    if(A!=NULL) s.push({A,'g'});
    pair<TreeNode*,char> t;
    while(!s.empty()){
        t = s.top();
        s.pop();
        if(t.second=='g'){
            t.second = 'p';
            s.push(t);
            if(t.first->left!=NULL){
                s.push({t.first->left,'g'});
            }
        }
        else{
            result.emplace_back(t.first->val);
            if(t.first->right!=NULL) s.push({t.first->right,'g'});
        }
    }
    return result;
}
