#include<iostream>
#include<vector>
using namespace std ;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0) , left(nullptr) , right(nullptr){}
    TreeNode(int x) : val(x) , left(nullptr) , right(nullptr) {}
    TreeNode(int x , TreeNode* left , TreeNode* right) : val(x) , left(left) , right(right) {}
};


int i= 0;
TreeNode* Build(vector<int> &pre , int bound){
   if (i== pre.size() || pre[i] > bound) return nullptr;
   TreeNode* root = new TreeNode(pre[i++]);
   root -> left = Build(pre , root->val);
   root -> right = Build(pre , bound);
   return root;
}

TreeNode* bst(vector<int>&pre){
    return Build(pre , INT_MAX);
}
int main(){
   vector<int> preorder = {8, 5, 1, 7, 10, 12}; // sample input
    TreeNode* root = bst(preorder);

    return 0;
}
