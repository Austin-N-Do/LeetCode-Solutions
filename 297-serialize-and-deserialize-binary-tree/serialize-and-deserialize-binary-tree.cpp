/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        serializeHelper(root, result);
        return result;
    }
    
private:
    void serializeHelper(TreeNode* node, string& result) {
        if (node == nullptr) {
            result += "null,";
            return;
        }
        
        result += to_string(node->val) + ",";
        serializeHelper(node->left, result);
        serializeHelper(node->right, result);
    }
    
public:
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> nodes;
        string token;
        
        // Split string by comma
        for (char c : data) {
            if (c == ',') {
                nodes.push(token);
                token = "";
            } else {
                token += c;
            }
        }
        
        return deserializeHelper(nodes);
    }
    
private:
    TreeNode* deserializeHelper(queue<string>& nodes) {
        string val = nodes.front();
        nodes.pop();
        
        if (val == "null") {
            return nullptr;
        }
        
        TreeNode* node = new TreeNode(stoi(val));
        node->left = deserializeHelper(nodes);
        node->right = deserializeHelper(nodes);
        
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));