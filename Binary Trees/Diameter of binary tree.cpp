// Question: max. edges b/w any 2 nodes 

using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }
};

struct node{
    int NTL; // node to leaf path for current node
    int LTL; // maximum leaf to leaf distance 
};
    
struct node solve(BinaryTree* root){
    if(root==NULL) return {-1,-1};
        
    struct node leftNode=solve(root->left);
    struct node rightNode=solve(root->right);
        
    int curNTL = max(leftNode.NTL,rightNode.NTL)+1;
    int curLTL = max(leftNode.NTL+rightNode.NTL+2,max(leftNode.LTL,rightNode.LTL));
        
    struct node curNode = {curNTL,curLTL};
    return curNode;
}

int binaryTreeDiameter(BinaryTree *tree) {
  if(tree->left==NULL && tree->right==NULL) return 0;
  return solve(tree).LTL;
}
