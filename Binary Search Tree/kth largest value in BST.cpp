using namespace std;

// This is an input class. Do not edit.
class BST {
public:
  int value;
  BST *left = nullptr;
  BST *right = nullptr;

  BST(int value) { this->value = value; }
};

// O(h+k)
void find(BST *root, int &k, int &val){
	if(root==NULL || k<1) return;
	find(root->right,k,val);
	if(k==1) val=root->value;
	k--;
	find(root->left,k,val);
}

int findKthLargestValueInBst(BST *root, int k) {
  int val=-1;
	find(root,k,val);
  return val;
}
