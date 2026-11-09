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
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        int sum = 0;
        dfs(root, 0, sum);
        return sum;
    }
private:
    void dfs(TreeNode* node, int num, int& sum) {
        num = num * 10 + node->val;
        if (!node->left && !node->right) {
            sum += num;
            return;
        }
        if (node->left) dfs(node->left, num, sum);
        if (node->right) dfs(node->right, num, sum);
    }
};


