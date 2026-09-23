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
    bool check(TreeNode* root,long long minValue,long long maxValue){
        if(root==nullptr)return true;

        if(root->val<=minValue|| root->val>=maxValue){
            return false;
        }

        bool left=check(root->left,minValue,root->val);
        bool right=check(root->right,root->val,maxValue);

        return left && right;
    }
    bool isValidBST(TreeNode* root) {
        return check(root,LLONG_MIN,LLONG_MAX);
    }
};
