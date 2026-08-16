/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int goodNodes(TreeNode* root, int maxVal){
        if(root==nullptr)return 0;
        int cnt=0;
        if(root->val>=maxVal)cnt=1;
        maxVal=max(maxVal,root->val);
        cnt+=goodNodes(root->left,maxVal);
        cnt+=goodNodes(root->right,maxVal);
        return cnt;


    }
    int goodNodes(TreeNode* root) {
        return goodNodes(root,root->val);
    }
};
