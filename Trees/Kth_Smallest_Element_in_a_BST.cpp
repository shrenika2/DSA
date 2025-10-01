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

class Solution {
    int cnt = 0 ; 
    int ans = -1 ;
public:
    int Kthsmallest(TreeNode* root , int k){
        inorder(root , k);
        return ans;
    }
    void inorder(TreeNode* node , int k){
        if (!node) return ;
        inorder(node->left , k);
        cnt ++;
        if (cnt == k ){
            ans = node->val;
            return ;
        }
        inorder(node->right , k);
    }

};

int main(){
    Solution s;
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);


    int k = 2;   

    cout << s.Kthsmallest(root, k);

cout << endl;
}
