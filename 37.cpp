#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <optional>
using namespace std;

// Tree node definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Build a tree from a level-order array (nullopt = null)
TreeNode* buildTree(const vector<optional<int>>& v) {
    if (v.empty() || !v[0]) return nullptr;

    TreeNode* root = new TreeNode(*v[0]);
    queue<TreeNode*> q;
    q.push(root);
    size_t i = 1;

    while (!q.empty() && i < v.size()) {
        TreeNode* node = q.front();
        q.pop();

        if (i < v.size()) {
            if (v[i]) {
                node->left = new TreeNode(*v[i]);
                q.push(node->left);
            }
            i++;
        }
        if (i < v.size()) {
            if (v[i]) {
                node->right = new TreeNode(*v[i]);