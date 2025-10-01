#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x , TreeNode* left , TreeNode * right) : val(x), left(left), right(right){}
};

class Solution{
public:
    bool isvalid(TreeNode* root){
        return validate(root , LONG_MIN , LONG_MAX);
    }
    bool validate(TreeNode* root , long mn , long mx){
        if (!root) return true;
        if (root->val >= mx || root->val <= mn) return false;

        return validate(root->left , mn , root->val) && validate(root->right , root->val , mx);
    }
};

int main (){
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(6); 
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(9);
    
    Solution sol;
    bool d = sol.isvalid(root);
    cout <<  d << endl;

    return 0;
}
