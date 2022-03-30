using namespace std;

// This is the class of the input root. Do not edit it.
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

void solve(BinaryTree *root, int sum, vector<int> &v){
	if(root==NULL) return;
	
	sum += root->value;
	if(root->left==NULL && root->right==NULL) v.push_back(sum);
	
	solve(root->left,sum,v);
	solve(root->right,sum,v);
}

vector<int> branchSums(BinaryTree *root) {
  vector<int> v;
	solve(root,0,v);
	
  return v;
}
