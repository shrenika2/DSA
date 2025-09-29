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

pair<int , int> floor_ceil(TreeNode* root , int key){
    int flr = -1  , cl = -1;

    while (root != nullptr){
        if (root->val == key){
            flr = cl = root->val;
            break;
        }else if (root->val > key){
            cl = root -> val ;
            root = root -> left;
        }else{
            flr = root -> val ;
            root = root -> right;
        }
    }
    return {flr , cl};
}



int main(){
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(4);
    root->right = new TreeNode(12);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(14);
    
    int key = 11;
    auto ans = floor_ceil(root , key);
    cout << "floor = " << ans.first << "Ceil = " << ans.second << endl;
    
    key = 15 ;
    ans = floor_ceil(root , key);
    cout << "floor = " << ans.first << "Ceil = " << ans.second << endl;

    return 0;
}