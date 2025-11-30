class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // Create a map for quick lookup of indices in inorder
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        
        int postIndex = postorder.size() - 1;
        return build(inorder, postorder, 0, inorder.size() - 1, 
                     postIndex, inorderMap);
    }
    
private:
    TreeNode* build(vector<int>& inorder, vector<int>& postorder,
                    int inStart, int inEnd, int& postIndex,
                    unordered_map<int, int>& inorderMap) {
        // Base case
        if (inStart > inEnd) {
            return nullptr;
        }
        
        // The last element in postorder is the root
        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);
        
        // Find root position in inorder
        int inIndex = inorderMap[rootVal];
        
        // Build right subtree first (postorder: left, right, root)
        // So we process from right to left
        root->right = build(inorder, postorder, inIndex + 1, inEnd, 
                           postIndex, inorderMap);
        root->left = build(inorder, postorder, inStart, inIndex - 1, 
                          postIndex, inorderMap);
        
        return root;
    }
};