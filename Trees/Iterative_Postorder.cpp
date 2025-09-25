// #include<iostream>
// #include<vector>
// #include<stack>
// using namespace std ;

// class TreeNode{
// public:
//     int val;
//     TreeNode* left;
//     TreeNode* right;
    
//     TreeNode() : val(0) , left(nullptr) , right(nullptr){}
//     TreeNode(int x) : val(x) , left(nullptr) , right(nullptr){}
//     TreeNode(int x , TreeNode* left , TreeNode* right) : val(x) , left(left) , right(right){}


// };

// class Iterative_Postorder{
// public:
//     vector<int> postorderTraversal(TreeNode* root){
//         vector<int> result ;
//         if (!root) return result;

//         stack<TreeNode*> st;
//         TreeNode* curr = root ;
//         TreeNode* temp = nullptr;

//         while (curr || !st.empty()){
//             if (curr){
//                 st.push(curr);
//                 curr = curr->left;
//             }else{
//                 TreeNode* peekNode = st.top();
//                 if (peekNode->right && temp!= peekNode->right){
//                     curr = peekNode->right;
//                 }else{
//                     result.push_back(peekNode->val);
//                     temp = peekNode;
//                     st.pop();
//                 }
//             }
//         }
//         return result;
//     }
// };

// int main (){
//     TreeNode* root = new TreeNode(10);
//     root->left = new TreeNode(5);
//     root->right = new TreeNode(6);
//     root->left->left = new TreeNode(4);
//     root->right->left = new TreeNode(9);

//     cout << "Inorder Traversal" << endl;
//     Iterative_Postorder(root);
//     return 0 ;

// }



#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main (){
    int t ;
    cin >> t ;
    while (t--){
        int n ;
        cin >> n ;
        vector<int> a(n);
        for (int i=0 ; i<n ; i++){
            cin >> a[i];
        }
        sort(a.begin() , a.end());
        int diff = 0 ;
        int mx = 0 ;
        for (int i= 0 ; i < n ; i+=2){
            diff = abs(a[i] - a[i+1]);
        }
        mx = max (mx , diff);
        cout << mx << endl;
        
    }
}