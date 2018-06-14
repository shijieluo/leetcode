/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
map<int,int> vst;
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        rightFirstPreOrder(root, 0, v);
        return v;
    }
    
    void rightFirstPreOrder(TreeNode* root, int h, vector<int> &v){
        if(!root) return;
        if(!vst[h]){
            v.push_back(root->val);
            vst[h] = 1;
        }
        rightFirstPreOrder(root->right, h+1, v);
        rightFirstPreOrder(root->left, h+1, v);
    }
};