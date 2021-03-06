题目描述

Given preorder and inorder traversal of a tree, construct the binary tree. 

Note:
 You may assume that duplicates do not exist in the tree. 

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 时间复杂度O（n）,空间复杂度O（logn）
class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTree(begin(preorder), end(preorder), begin(inorder), end(inorder));
    }
    template<typename InputIterator>
    TreeNode *buildTree(InputIterator pre_first, InputIterator pre_last,
                       InputIterator in_first, InputIterator in_last){
        if(pre_first == pre_last) return nullptr;
        if(in_first == in_last) return nullptr;
        auto root = new TreeNode(*pre_first);
        auto inRootPos = find(in_first, in_last, *pre_first);
        auto leftSize = distance(in_first, inRootPos);
        
        root->left = buildTree(next(pre_first), next(pre_first, leftSize+1),
                              in_first, next(in_first, leftSize));
        root->right = buildTree(next(pre_first, leftSize+1), pre_last,
                               next(inRootPos), in_last);
        return root;
    }
};
