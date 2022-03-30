#include <vector>
using namespace std;

// This is the class of the input root. Do not edit it.
class BinaryTree {
public:
  int value;
  BinaryTree *left = nullptr;
  BinaryTree *right = nullptr;

  BinaryTree(int value);
};

BinaryTree *rightSiblingTree(BinaryTree *root) {
  queue<BinaryTree *> q;
	q.push(root);
	q.push(NULL);
	while(q.size()>0){
		int size=q.size();
		while(size--){
			BinaryTree *node=q.front();
			q.pop();
			if(node==NULL) continue;
			
			q.push(node->left);
			q.push(node->right);
			node->right=q.front();
		}
		if(q.size()) q.push(NULL);
	}
  return root;
}

