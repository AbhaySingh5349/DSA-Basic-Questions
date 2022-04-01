// Question: find sum of all subtrees node depths
		1
	       / \
	      2   3
	     / \ / \
	    4  5 6  7
	   / \
	  8   9
op: 26 // sum of root trees node depth = 16, rooted at 2s node = 6, rooted at 3s node = 2, rooted at 4s node = 2

// Approach 1:

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

// Approach 2:

#include <bits/stdc++.h>
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

// depth of left and right child relative to sub-tree rooted at itself is 1 less than sub-tree rooted at parent
// similarly, depth of each node w.r.t left & right if +1, we get depth w.r.t root
// adding +1 to each node = number of nodes in sub-tree
// sub-tree size of leaf nodes=1 & depth w.r.t itself =0
// nodeDepth = (nodeDepthLeft + #leftSub-tree) + (nodeDepthRight + #rightSub-tree)

int subtreeNodeCount(BinaryTree *root, map<BinaryTree*,int> &count){
	if(root==NULL) return 0;
	
	int lc=subtreeNodeCount(root->left,count);
	int rc=subtreeNodeCount(root->right,count);
	return count[root]=lc+rc+1;
}

// sum of node depths w.r.t cuurent root at each call 
int getNodeDepths(BinaryTree *root, map<BinaryTree*,int> &depth, map<BinaryTree*,int> &count){
	if(root==NULL) return 0;
	int ld=getNodeDepths(root->left,depth,count);
	int rd=getNodeDepths(root->right,depth,count);
	return depth[root]=ld+rd+count[root]-1; // sub-tree count except itself
}

int sumOfDepths(BinaryTree *root, map<BinaryTree*,int> depth){
	if(root==NULL) return 0;
	return sumOfDepths(root->left,depth)+sumOfDepths(root->right,depth)+depth[root];
}

int allKindsOfNodeDepths(BinaryTree *root) {
	if(root==NULL) return 0;
  map<BinaryTree*,int> count;
	subtreeNodeCount(root,count);
	
	map<BinaryTree*,int> depth;
	getNodeDepths(root,depth,count);
  return sumOfDepths(root,depth);
}
