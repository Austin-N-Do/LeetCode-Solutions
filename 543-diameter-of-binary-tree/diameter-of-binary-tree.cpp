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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
    
private:
    int height(TreeNode* node, int& diameter) {
        // Base case: null node has height 0
        if (node == nullptr) {
            return 0;
        }
        
        // Recursively get heights of left and right subtrees
        int leftHeight = height(node->left, diameter);
        int rightHeight = height(node->right, diameter);
        
        // Update diameter: path through current node
        // is left height + right height
        diameter = max(diameter, leftHeight + rightHeight);
        
        // Return height of current node
        return 1 + max(leftHeight, rightHeight);
    }
};