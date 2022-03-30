// Approach 1:

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

// Approach 2:

using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
  int value;
  BinaryTree *left = nullptr;
  BinaryTree *right = nullptr;

  BinaryTree(int value) { this->value = value; }
};

// O(h) space

void knodes(BinaryTree *node, vector<int> &v, BinaryTree *blocker, int level){
	if(node==NULL || node==blocker) return;
	if(level==0){
		v.push_back(node->value);
		return;
	}
	
	knodes(node->left,v,blocker,level-1);
	knodes(node->right,v,blocker,level-1);
}

// using recursive stack to store answer
int check(BinaryTree *root, int target, int k, vector<int> &ans){
	if(root==NULL) return -1;
	
	if(root->value==target){
		knodes(root,ans,NULL,k);
		return 1; // current node distance from its parent
	} 
	
	int ld=check(root->left,target,k,ans);
	if(ld!=-1){
		knodes(root,ans,root->left,k-ld); // path to required node received from cuurent lies in left
		return ld+1; // how far current node from target
	}
	int rd=check(root->right,target,k,ans);
	if(rd!=-1){
		knodes(root,ans,root->right,k-rd); // path to required node received from cuurent lies in right
		return rd+1; // how far current node from target
	}
	return -1;
}

vector<int> findNodesDistanceK(BinaryTree *tree, int target, int k) {
  vector<int> ans;
	check(tree,target,k,ans);
  return ans;
}
