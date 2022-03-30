// Question: given 3 nodes, check if nodeOne is ancestor of nodeTwo, then nodeThree is descendent or vice versa.

// Approach 1: time and space: O(h)

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

// Approach 2: time O(h), space O(1)

using namespace std;

class BST {
public:
  int value;
  BST *left = nullptr;
  BST *right = nullptr;

  BST(int value) { this->value = value; }
};

bool check(BST *root, BST *node){
	while(root!=NULL && root!=node){
		if(root->value > node->value){
			root = root->left;
		}else if(root->value < node->value){
			root = root->right;
		}
	}
 return (root==node);
}

bool validateThreeNodes(BST *nodeOne, BST *nodeTwo, BST *nodeThree) {
  return ((check(nodeOne,nodeTwo) && check(nodeTwo,nodeThree)) ||
				  (check(nodeThree,nodeTwo) && check(nodeTwo,nodeOne)));
}

// Approach 3:

using namespace std;

class BST {
public:
  int value;
  BST *left = nullptr;
  BST *right = nullptr;

  BST(int value) { this->value = value; }
};

// time: O(d) where d = distance(nodeOne,nodeThree)
// checking if nodeTwo lies on path nodeOne <--> nodeTwo

bool findDescendent(BST *ancestor, BST *descendent){
	if(ancestor==NULL) return false;
	if(ancestor->value > descendent->value){
		if(findDescendent(ancestor->left,descendent)) return true;
	}else if(ancestor->value < descendent->value){
		if(findDescendent(ancestor->right,descendent)) return true;
	}else{
		return true;
	}
	return false;
}

bool check(BST *ancestor, BST *node, BST *descendent, bool &foundNode, bool &foundDescendent){
	if(ancestor==NULL) return false;
	if(ancestor->value==descendent->value) foundDescendent=true;
	if(foundDescendent && foundNode==false) return false; // pruning 
	
	if(ancestor->value > node->value){
		if(check(ancestor->left,node,descendent,foundNode,foundDescendent)) return true;
	}else if(ancestor->value < node->value){
		if(check(ancestor->right,node,descendent,foundNode,foundDescendent)) return true;
	}else{
		foundNode=true;
		if(findDescendent(ancestor,descendent)) return true;
	}
	return false;
}

bool validateThreeNodes(BST *nodeOne, BST *nodeTwo, BST *nodeThree) {
	bool foundNode=false, foundDescendent=false;
  return ((check(nodeOne,nodeTwo,nodeThree,foundNode,foundDescendent)) || 
					(check(nodeThree,nodeTwo,nodeOne,foundNode,foundDescendent)));
}
