/*LeetCode : 99 
99. Recover Binary Search Tree
You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

Example 1:

Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
Example 2:


Input: root = [3,1,4,null,null,2]
Output: [2,1,4,null,null,3]
Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.
 

Constraints:

The number of nodes in the tree is in the range [2, 1000].
-231 <= Node.val <= 231 - 1
*/
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
    int idx = 0;
public:
    void InOrder(TreeNode* root, vector<int> &v){
        if(root == NULL)    return;
        InOrder(root->left,v);
        v.push_back(root->val);
        InOrder(root->right,v);
    }

    void InOrder2(TreeNode* root, vector<int> &v){
        if(root == NULL)    return;
        InOrder2(root->left,v);
        if(root->val != v[idx]){
            //cout<<"Replcaing "<<root->val<<" with "<<v[idx]<<endl;
            root->val = v[idx];
        }
        idx++;
        InOrder2(root->right,v);
    }








    void recoverTree(TreeNode* root) {
        vector<int> v; 
        InOrder(root,v);
        
        cout<<endl;
        sort(v.begin(), v.end()); 
        
        InOrder2(root,v);
    }
};

/*
Approach : Used the fact that the InOrder traversal of the BST will give the sorted array of BST*/