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

int issame(TreeNode* p , TreeNode* q){
        if (p==NULL && q==NULL) return true;

       if (p==NULL || q==NULL) return false;

       if (p->val != q->val) return false;

       return issame(p->left , q->left) && issame(p->right , q->right);
    
}

int main(){
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->left = new TreeNode(4);
    root2->left->right = new TreeNode(5);

    cout << issame(root1 , root2);
    
    return 0;
}

