#include <iostream>
#include <vector>

using namespace std ;

struct TreeNode{
    int val;
    TreeNode * left ;
    TreeNode * right ;
    TreeNode() : val(0) , left(nullptr) , right(nullptr){}
    TreeNode(int x) : val(x) , left(nullptr) , right(nullptr){}
    TreeNode(int x , TreeNode* left , TreeNode * right) : val(x) , left(left) , right(right){}
};

int height(TreeNode* root){
    if (root==0) return 0;
    int ls = height(root->left);
    if (ls == -1 ) return -1;
    int rs = height(root->right);
    if (rs == -1) return -1;
    if (abs(ls-rs)>1) return -1;
    return (1+ max(ls , rs));
}

bool isbanlance(TreeNode* root){
    return height(root) != -1;
}

int main (){
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(9);

    
    cout << isbanlance(root);
    return 0 ;

}