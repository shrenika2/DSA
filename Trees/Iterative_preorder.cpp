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

vector<int> Iterative_Preorder(TreeNode* root){
    vector<int>preorder;
    if (!root) return preorder;

    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        root = st.top();
        st.pop();
        preorder.push_back(root->val);
        if (root->right != NULL){
            st.push(root->right);
        }
        if (root->left != NULL){
            st.push(root->left);
        }
    }
    return preorder;


}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Preorder : " ;
    vector <int> ans = Iterative_Preorder(root); 

    for (int val: ans){
        cout << val << " ";
    }
    return 0;
}