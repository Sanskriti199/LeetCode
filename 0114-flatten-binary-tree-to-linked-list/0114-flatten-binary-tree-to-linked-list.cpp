class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == NULL) return;

        flatten(root->right);
        flatten(root->left);

        TreeNode* temp = root->right;

        root->right = root->left;
        root->left = NULL;

        TreeNode* curr = root;

        while (curr->right != NULL) {
            curr = curr->right;
        }

        curr->right = temp;
    }
};