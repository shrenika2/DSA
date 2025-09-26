#include <iostream>
#include <algorithm>
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
    int diameter = 0;

    int height(TreeNode* root){
        if (root == NULL) return 0;

        int lh = height(root->left);
        int rh = height(root->right);

        diameter = max(diameter , lh + rh);

        return 1 + max(lh , rh);
    }

    int diameterOfBinaryTree(TreeNode* root){
        height(root);
        return diameter;
    }
};

int main (){
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(9);

    Solution sol;
    int d = sol.diameterOfBinaryTree(root);
    cout << "Diameter: " << d << endl;

    return 0;
}
