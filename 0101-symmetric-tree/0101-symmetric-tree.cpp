class Solution {
public:
    bool checkMirror(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL)
            return true;

        if (left == NULL || right == NULL)
            return false;

        if (left->val != right->val)
            return false;

        return checkMirror(left->left, right->right) &&
               checkMirror(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        return checkMirror(root->left, root->right);
    }
};

