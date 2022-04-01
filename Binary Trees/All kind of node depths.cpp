using namespace std;

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

// worst time complexity is O(n^2) for skewed tree
// for perfect tree is O(nlogn)

int nodeDepth(BinaryTree *root, int level){
	if(root==NULL) return 0;
	return level+nodeDepth(root->left,level+1)+nodeDepth(root->right,level+1);
}

int allKindsOfNodeDepths(BinaryTree *root) {
	if(root==NULL) return 0;
  return nodeDepth(root,0) + allKindsOfNodeDepths(root->left)+allKindsOfNodeDepths(root->right);
}
