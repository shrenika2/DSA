#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ;

struct TreeNode{
    int val ;
    TreeNode * left ;
    TreeNode* right;

    TreeNode() : val() , left(nullptr) , right(nullptr) {}
    TreeNode (int x) : val(x) , left(nullptr) , right(nullptr){}
    TreeNode (int x , TreeNode* left , TreeNode* right) : val(x) , left(left) , right(right){}


};

int maxDept(TreeNode* root){
    if (root == NULL) return 0;

    int lh = maxDept(root->left);
    int rh = maxDept(root->right);

    return 1 + max(lh , rh);
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    cout << maxDept(root); 
    return 0;
}

//Time Complexity: O(n)

//Space Complexity: O(h) (worst case O(n), best case O(log n))