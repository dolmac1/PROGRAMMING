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
    vector<int> result;
    vector<int> inorderTraversal(TreeNode* root) {
        inorderTraversal2(root);
        return result;
    }
    
    void inorderTraversal2(TreeNode* tree){
        if(tree == NULL){
            
        }
        else{ 
            inorderTraversal2(tree->left);
            result.push_back(tree->val);
            inorderTraversal2(tree->right);
        }
    }
};

//https://leetcode.com/problems/binary-tree-inorder-traversal/
