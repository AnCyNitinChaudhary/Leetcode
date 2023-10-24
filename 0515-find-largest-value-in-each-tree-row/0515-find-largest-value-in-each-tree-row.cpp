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
    void dfs(TreeNode* root,int level,map<int,int>&um){
        if(root==NULL)return;
        if(um.find(level)==um.end())um[level]=root->val;
        else um[level]=max(um[level],root->val);
        dfs(root->left,level+1,um);
        dfs(root->right,level+1,um);
    }
    vector<int> largestValues(TreeNode* root) {
        map<int,int>um;
        dfs(root,0,um);
        vector<int>ans;
        for(auto i:um)ans.push_back(i.second);
        return ans;
    }
};