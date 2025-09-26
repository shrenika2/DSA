#include <iostream>
#include <vector>
#include <climits>

using namespace std ;

struct TreeNode{
    int val;
    TreeNode * left ;
    TreeNode * right ;
    TreeNode() : val(0) , left(nullptr) , right(nullptr){}
    TreeNode(int x) : val(x) , left(nullptr) , right(nullptr){}
    TreeNode(int x , TreeNode* left , TreeNode * right) : val(x) , left(left) , right(right){}
};

int mx = INT_MIN;
int maxgain(TreeNode* root){
    if (root==0) return 0;
    int ls = max (0,maxgain(root->left));
    int rs = max (0,maxgain(root->right));
    
    mx = max (mx , root->val + ls + rs);
    return (root->val + max(ls , rs));
}

int mxsum(TreeNode* root){
    maxgain(root);
    return mx;
}

int main (){
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(9);

    
    cout << mxsum(root);
    return 0 ;

}