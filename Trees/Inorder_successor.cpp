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

TreeNode* succesor(TreeNode* root , TreeNode* p){
    TreeNode* succesor = NULL;

    while (root!= NULL){
        if (p->val >= root->val){
            root = root->right;
        }else{
            succesor = root;
            root=root->left;
        }
    }
    return succesor;
}


int main (){
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(9);
    TreeNode* key = root->left->left;
    
    TreeNode* succ = succesor(root , key);
    cout << succ->val ;
    return 0 ;

}