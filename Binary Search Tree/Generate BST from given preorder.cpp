using namespace std;

class BST {
public:
  int value;
  BST *left = nullptr;
  BST *right = nullptr;

  BST(int value) { this->value = value; }
};

BST *create(vector<int> &pre, int s, int e){
	if(s>e) return NULL;
	BST *node;
	node = new BST(pre[s]);
	int idx=-1;
	for(int i=s+1;i<=e;i++){
		if(pre[i]>=pre[s]){
			idx=i;
			break;
		}
	}
	if(idx!=-1){
		node->left=create(pre,s+1,idx-1);
		node->right=create(pre,idx,e);
	}else{
		node->left=create(pre,s+1,e);
		node->right=NULL;
	}
	return node;
}

BST *reconstructBst(vector<int> pre) {
  int n=pre.size();
  return create(pre,0,n-1);
}

