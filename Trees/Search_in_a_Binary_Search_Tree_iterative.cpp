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

TreeNode* BST(TreeNode* root , int val){
    if (root==nullptr || root->val == val){
        return root;
    }
    if (val < root->val){
        root = root->left;
    }else{
        root = root->right;
    }
    return root;
}

int main(){
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);


    int val = 4 ;
    TreeNode* result =  BST(root , val );
    if (result != nullptr)
    cout << "Found: " << result->val << endl;
    else
        cout << "Not Found" << endl;

    return 0;
}