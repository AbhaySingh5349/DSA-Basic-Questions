//Approach 1:

using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
  int value;
  BinaryTree *left = nullptr;
  BinaryTree *right = nullptr;
  BinaryTree *parent = nullptr;

  BinaryTree(int value) { this->value = value; }
};

void inorder(BinaryTree *root, BinaryTree *node, vector<BinaryTree *> &v){
	if(root==NULL) return;
	
	inorder(root->left,node,v);
	v.push_back(root);
	inorder(root->right,node,v);
}

BinaryTree *findSuccessor(BinaryTree *root, BinaryTree *node) {
	vector<BinaryTree *> v;
	inorder(root,node,v);
	for(int i=0;i<v.size();i++){
		BinaryTree *cur=v[i];
		if(cur==node && i<v.size()-1) return v[i+1];
	}
  return NULL;
}

// Approach 2:

using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
  int value;
  BinaryTree *left = nullptr;
  BinaryTree *right = nullptr;
  BinaryTree *parent = nullptr;

  BinaryTree(int value) { this->value = value; }
};

BinaryTree *suc;
bool found;

void inorder(BinaryTree *root, BinaryTree *node){
	if(root==NULL) return;
	
	inorder(root->left,node);
	
	if(found==true){
		suc=root;
		found=false;
	}
	if(node==root) found=true;
	
	inorder(root->right,node);
}

BinaryTree *findSuccessor(BinaryTree *root, BinaryTree *node) {
  suc=NULL;
	found=false;
	inorder(root,node);
  return suc;
}
