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

TreeNode* Predecessor (TreeNode* root , TreeNode* p){
    TreeNode* Predecessor  = NULL;

    while (root!= NULL){
        if (p->val >= root->val){
            Predecessor  = root;
            root = root->right;
        }else{
            
            root=root->left;
        }
    }
    return Predecessor ;
}
int main (){
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(9);
    TreeNode* key = root->left->left;
    
    TreeNode* pred = Predecessor(root , key);
    cout << pred->val ;
    return 0 ;

}