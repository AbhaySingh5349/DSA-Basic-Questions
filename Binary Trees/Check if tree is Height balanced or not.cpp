using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
  int value;
  BinaryTree *left = nullptr;
  BinaryTree *right = nullptr;

  BinaryTree(int value) { this->value = value; }
};

int height(BinaryTree *root){
	if(root==NULL) return 0;
	
	return max(height(root->left),height(root->right))+1;
}

bool heightBalancedBinaryTree(BinaryTree *root) {
  if(root==NULL) return true;
	
	int lh=height(root->left);
	int rh=height(root->right);
	if(abs(lh-rh)>1) return false;
	
  return (heightBalancedBinaryTree(root->left) && heightBalancedBinaryTree(root->right));
}
