
#include"stdfax.h"
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       if(preorder.size()==0){
           return nullptr;
       }
       int middle=preorder[0];
       int i=0;
       for(;i<inorder.size();i++){
           if(inorder[i]==middle){
               break;
           }
       }
       vector<int>leftInorder(inorder.begin(),inorder.begin()+i);
       vector<int>rightInorder(inorder.begin()+i+1,inorder.end());

       vector<int>leftPreorder(preorder.begin()+1,preorder.begin()+1+int(leftInorder.size()));
       vector<int>rightPreorder(preorder.begin()+int(leftInorder.size())+1,preorder.end());

       TreeNode* res=new TreeNode(middle);
       res->left=buildTree(leftPreorder,leftInorder);
       res->right=buildTree(rightPreorder,rightInorder);
       return res;
    }
};