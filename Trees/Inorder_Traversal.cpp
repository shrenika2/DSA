#include<iostream>
using namespace std ;

struct TreeNode{
    int val;
    TreeNode* left ;
    TreeNode* right;

    TreeNode(): val(0) , left(nullptr) , right(nullptr){}
    TreeNode(int x) : val(x) , left(nullptr) , right(nullptr){}
    TreeNode(int x , TreeNode* left , TreeNode* right) : val(x) , left(left) , right(right){}

};

void Inorder_Traversal(TreeNode* root){
    if (!root) return ;
    Inorder_Traversal(root->left);
    cout << root->val << " ";
    Inorder_Traversal(root->right);
}

int main (){
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(9);

    cout << "Inorder Traversal" << endl;
    Inorder_Traversal(root);
    return 0 ;

}