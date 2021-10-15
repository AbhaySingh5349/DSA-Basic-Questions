class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};

void solve(BST *root, int target, int &mind, BST* &node){
	if(root==NULL) return;
	
	if(abs(target-root->value)<mind){
		mind=abs(target-root->value);
		node=root;
	}
	if(target>root->value){
		solve(root->right,target,mind,node);
	}else if(target<root->value){
		solve(root->left,target,mind,node);
	}else{
		mind=0;
		return;
	}
}

int findClosestValueInBst(BST *root, int target) {
  int mind=INT_MAX;
	BST *node=NULL;
	solve(root,target,mind,node);
  return node->value;
}

