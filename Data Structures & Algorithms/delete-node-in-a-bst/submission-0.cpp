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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr)return nullptr;
        if(key<root->val){
            root->left=deleteNode(root->left,key);
        }
        else if(key>root->val){
            root->right=deleteNode(root->right,key);
        }
        else{
            // we found the node and it does not have left child
            if(root->left==NULL){
                return root->right;
            }
            if(root->right==nullptr){
                return root->left;
            }
            // two children

            TreeNode*temp=root->right;
            while(temp->left!=nullptr){
                temp=temp->left;
            }
            root->val=temp->val;
            root->right=deleteNode(root->right,temp->val);

        }
        return root;
    }
};