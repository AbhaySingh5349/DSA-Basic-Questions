// time and space: O(h) = O(logn)

using namespace std;

class BST {
public:
  int value;
  BST *left = nullptr;
  BST *right = nullptr;

  BST(int value) { this->value = value; }
};

bool check(BST *root, BST *node){
	if(root==NULL) return false;
	if(root->value > node->value){
		if(check(root->left,node)) return true;
	}else if(root->value < node->value){
		if(check(root->right,node)) return true;
	}else{
		return true;
	}
	return false;
}

bool validateThreeNodes(BST *nodeOne, BST *nodeTwo, BST *nodeThree) {
  return ((check(nodeOne,nodeTwo) && check(nodeTwo,nodeThree)) ||
				  (check(nodeThree,nodeTwo) && check(nodeTwo,nodeOne)));
}
