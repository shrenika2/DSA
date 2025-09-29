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

TreeNode* insertBST(TreeNode* root , int key){
    if (root == nullptr){
        return new TreeNode(key);
    }
    if (key < root->val){
        root->left = insertBST(root->left , key);
    }else{
        root->right = insertBST(root->right , key);
    }
    return root ;
}
void inorder(TreeNode* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
int main(){
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);


    int key = 90;
     root = insertBST(root , key);

    inorder(root);
    cout << endl;

    return 0;
}