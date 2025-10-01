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

TreeNode* findMin(TreeNode* node){
    if (node && node->left !=nullptr){
        node= node->left;   
    }
    return node;
}

TreeNode* deleteNode(TreeNode* root , int key){
    if (!root) return nullptr;

    if (key < root->val){
        root->left = deleteNode(root->left , key);
    }
    else if (key > root->val){
        root->right = deleteNode(root->right , key);
    }else{
        if (!root->left){
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }else if (!root->right){
            TreeNode* temp = root->left;
            delete root ;
            return temp;
        }

        TreeNode* succ = findMin(root->right);
        root->val = succ->val;
        root->right = deleteNode(root->right , succ->val);
    }
    return root;
}
int main(){
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);


    int key = 2;   
root = deleteNode(root, key);

cout << endl;
}
