#include<iostream>
using namespace std ;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0) , left(nullptr) , right(nullptr){}
    TreeNode(int x) : val(x) , left(nullptr) , right(nullptr) {}
    TreeNode(int x , TreeNode* left , TreeNode* right) : val() , left(left) , right(right) {}


};

void preorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Preorder : " ;
    preorder(root); 
    return 0;
}