#include <bits/stdc++.h>
using namespace std;

BST *create(vector<int> &a, int s, int e){
	if(s>e) return NULL;
	int mid=(s+e)/2;
	BST *node = new BST(a[mid]);
	node->left=create(a,s,mid-1);
	node->right=create(a,mid+1,e);
	return node;
}

BST *minHeightBst(vector<int> a) {
  int n=a.size();
  return create(a,0,n-1);
}
