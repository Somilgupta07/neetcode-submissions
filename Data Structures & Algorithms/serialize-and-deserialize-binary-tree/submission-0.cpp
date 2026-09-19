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

class Codec {
public:
    void serializeHelper(TreeNode*root,string& s){
        if(root==NULL){
            s+="N,";
            return;
        }
        s+=to_string(root->val)+",";
        serializeHelper(root->left,s);
        serializeHelper(root->right,s);

    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        serializeHelper(root,s);
        return s;
    }

    TreeNode* deserializeHelper(string& s, int& index) {
        int start=index;
        while(index<s.size() &&s[index]!=','){
            index++;
        }

        string value=s.substr(start,index-start);
        index++;
        if(value=="N"){
            return nullptr;
        }
        TreeNode*root=new TreeNode(stoi(value));
        root->left=deserializeHelper(s,index);
        root->right=deserializeHelper(s,index);

        return root;


    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int idx=0;
        return deserializeHelper(data,idx);
    }
};
