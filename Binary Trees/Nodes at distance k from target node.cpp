using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
  int value;
  BinaryTree *left = nullptr;
  BinaryTree *right = nullptr;

  BinaryTree(int value) { this->value = value; }
};

// node --> root path
bool check(BinaryTree *root, int target, vector<BinaryTree *> &path){
	if(root==NULL) return false;
	
	if(root->value==target){
		path.push_back(root);
		return true;
	} 
	
	if(check(root->left,target,path)){
		path.push_back(root);
		return true;
	}
	if(check(root->right,target,path)){
		path.push_back(root);
		return true;
	}
	return false;
}

void knodes(BinaryTree *node, vector<int> &v, BinaryTree *blocker, int level){
	if(node==NULL || node==blocker) return;
	if(level==0){
		v.push_back(node->value);
		return;
	}
	
	knodes(node->left,v,blocker,level-1);
	knodes(node->right,v,blocker,level-1);
}

vector<int> findNodesDistanceK(BinaryTree *root, int target, int k) {
  vector<int> v;
	vector<BinaryTree *> path; 
	if(check(root,target,path)){
		BinaryTree *blocker=NULL;
		for(int i=0;i<path.size();i++){
			BinaryTree *cur = path[i];
			knodes(cur,v,blocker,k-i);
			blocker=cur;
		}
	}
  return v;
}
