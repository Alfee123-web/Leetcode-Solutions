/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    unordered_map<int, int> inorderMap;
    TreeNode* build(vector<int>& inorder, int inStart, int inEnd,
                    vector<int>& postorder, int postStart, int postEnd) {
        if (inStart > inEnd || postStart > postEnd)
            return NULL;

        int rootVal = postorder[postEnd];
        TreeNode* root = new TreeNode(rootVal);

        int inIndex = inorderMap[rootVal];
        // inIndex means the index position where the current root value lives
        // inside the original inorder array.
        int numsLeft = inIndex - inStart;

        root->left = build(inorder, inStart, inIndex - 1, postorder, postStart,
                           postStart + numsLeft - 1);
        root->right = build(inorder, inIndex + 1, inEnd, postorder,
                            postStart + numsLeft, postEnd - 1);
        // Everything to the left of inIndex belongs entirely to the Left
        // Subtree.

        // Everything to the right of inIndex belongs entirely to the Right
        // Subtree.
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        return build(inorder, 0, inorder.size() - 1, postorder, 0,
                     postorder.size() - 1);
    }
};
// Left Subtree
// Inorder Range => inStart to inIndex - 1
// Postorder Range postStart to postStart + numsLeft - 1

// Right Subtree
// Inorder Range  => inIndex + 1 to inEnd
// Postorder Range => postStart + numsLeft to postEnd - 1
