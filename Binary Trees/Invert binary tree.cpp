#include <vector>
using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value);
  void insert(vector<int> values, int i = 0);
  void invertedInsert(vector<int> values, int i = 0);
};

BinaryTree *solve(BinaryTree *root){
	if(root==NULL) return NULL;
	
	BinaryTree *oleft=solve(root->left);
	BinaryTree *oright=solve(root->right);
	
	root->left=oright;
	root->right=oleft;
	
	return root;
}

void invertBinaryTree(BinaryTree *root) {
  solve(root);
}
