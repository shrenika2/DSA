#include<iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
    if (!root) return nullptr;

    if (p->val < root->val && q->val < root->val)
        return lca(root->left, p, q);
    if (p->val > root->val && q->val > root->val)
        return lca(root->right, p, q);

    return root;
}

int main(){
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    TreeNode* pNode = root->left; 
    TreeNode* qNode = root->right; 

    TreeNode* ancestor = lca(root, pNode, qNode);

    cout << "LCA: " << ancestor->val << endl;

    return 0;
}
