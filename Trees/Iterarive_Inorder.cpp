#include<iostream>
#include<vector>
#include<stack>

using namespace std ;

struct TreeNode{
    int val ;
    TreeNode* left ;
    TreeNode* right ;

    TreeNode(): val(0) , left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x) , left(nullptr) , right(nullptr){}
    TreeNode(int x , TreeNode* left , TreeNode* right) : val(x) , left(left) , right(right){}
};

vector <int> Iterative_inorder(TreeNode* root){
    stack<TreeNode*> st;
    TreeNode* node = root ;
    vector <int> inorder;
    while (true){
        if (node!= NULL){
            st.push(node);
            node = node->left;
        }else{
            if (st.empty()==true) break;
            node = st.top();
            st.pop();
            inorder.push_back(node->val);
            node=node->right;
        }
    }
    return inorder;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Preorder : " ;
    vector <int> ans = Iterative_inorder(root); 

    for (int val: ans){
        cout << val << " ";
    }
    return 0;
}