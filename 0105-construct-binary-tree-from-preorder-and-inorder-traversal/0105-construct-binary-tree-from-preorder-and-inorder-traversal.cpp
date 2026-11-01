class Solution {
public:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& index, int start, int end) {
        if (start > end)
            return NULL;

        int rootValue = preorder[index];
        index++;

        TreeNode* root = new TreeNode(rootValue);

        int pos = start;
        while (inorder[pos] != rootValue) {
            pos++;
        }

        root->left = build(preorder, inorder, index, start, pos - 1);
        root->right = build(preorder, inorder, index, pos + 1, end);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        return build(preorder, inorder, index, 0, inorder.size() - 1);
    }
};
