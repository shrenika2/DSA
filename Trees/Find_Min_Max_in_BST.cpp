#include<iostream>
using namespace std ;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0) , left(nullptr) , right(nullptr){}
    TreeNode(int x) : val(x) , left(nullptr) , right(nullptr) {}
    TreeNode(int x , TreeNode* left , TreeNode* right) : val(x) , left(left) , right(right) {}


};

TreeNode* BST_low(TreeNode* root){
   if (root == nullptr ){
    return nullptr;
   }
   while (root->left != nullptr){
    root= root->left;
   }
   return root;
}

TreeNode* BST_high(TreeNode* root){
   if (root == nullptr ){
    return nullptr;
   }
   while (root->right != nullptr){
    root= root->right;
   }
   return root;
}

int main(){
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);


    TreeNode* minNode = BST_low(root);
    TreeNode* maxNode = BST_high(root);

    if (minNode != nullptr)
        cout << "Minimum value in BST: " << minNode->val << endl;
    if (maxNode != nullptr)
        cout << "Maximum value in BST: " << maxNode->val << endl;

    return 0;
}