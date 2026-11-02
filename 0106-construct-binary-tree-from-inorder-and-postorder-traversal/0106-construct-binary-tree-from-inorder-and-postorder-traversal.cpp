
class Solution {
public:
    unordered_map<int, int> position;
    int index;

    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,
                    int left, int right) {

        if (left > right) {
            return nullptr;
        }

        // Last element of postorder is the root
        int rootValue = postorder[index--];
        TreeNode* root = new TreeNode(rootValue);

        // Find root position in inorder
        int mid = position[rootValue];

        // Build right subtree first, then left subtree
        root->right = solve(inorder, postorder, mid + 1, right);
        root->left = solve(inorder, postorder, left, mid - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        int n = inorder.size();

        for (int i = 0; i < n; i++) {
            position[inorder[i]] = i;
        }

        index = n - 1;

        return solve(inorder, postorder, 0, n - 1);
    }
};


