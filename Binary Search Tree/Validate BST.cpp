#include <bits/stdc++.h>
using namespace std;

// root > all left childrens, root <= all right children

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};

struct NodeInfo{
	int submin, submax;
	bool isBST;
};

NodeInfo check(BST *root){
	if(root==NULL){
		NodeInfo leaf={INT_MAX,INT_MIN,true};
		return leaf;
	}
	int x=root->value;
	NodeInfo leftInfo=check(root->left);
	NodeInfo rightInfo=check(root->right);
	
	bool curBST=((leftInfo.isBST && rightInfo.isBST) && (x>leftInfo.submax && x<=rightInfo.submin));
	int curmin=min(x,min(leftInfo.submin,rightInfo.submin));
	int curmax=max(x,max(rightInfo.submax,leftInfo.submax));
	
	NodeInfo curInfo={curmin,curmax,curBST};
	return curInfo;
} 

bool validateBst(BST *root) {
  if(root==NULL) return true;
  return check(root).isBST;
}
