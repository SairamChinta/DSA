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
 */class Solution {
public:
    vector<TreeNode*> generate(int start, int end) {
        if (start > end) return {nullptr};
        vector<TreeNode*> trees;

        for (int root = start; root <= end; root++) {
            vector<TreeNode*> left = generate(start, root - 1);
            vector<TreeNode*> right = generate(root + 1, end);
            for (auto l : left) {
                for (auto r : right) {
                    TreeNode* node = new TreeNode(root);
                    node->left = l;
                    node->right = r;
                    trees.push_back(node);
                }
            }
        }
        return trees;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return generate(1, n);
    }
};
