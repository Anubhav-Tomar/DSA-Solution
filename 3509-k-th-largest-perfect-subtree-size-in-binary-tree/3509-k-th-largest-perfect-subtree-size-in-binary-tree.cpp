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
    vector<int> subtreeSizes;
    tuple<bool, int, int> solve(TreeNode* root){
        if(!root){
            return {true, 0, 0};
        }
        auto [left, leftHeight, leftSize] = solve(root->left);
        auto [right, rightHeight, rightSize] = solve(root->right);
        if(left && right && leftHeight == rightHeight){
            int size = leftSize + rightSize + 1;
            int height = leftHeight + 1;
            subtreeSizes.push_back(size);
            return {true, height, size};
        }
        return {false, 0, 0};
    }

    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        solve(root);
        sort(subtreeSizes.begin(), subtreeSizes.end(), greater<int>());
        if(subtreeSizes.size() >= k){
            return subtreeSizes[k-1];
        }
        else{
            return -1;
        }
    }
};