#include <vector>
using namespace std;

class AncestralTree {
public:
  char name;
  AncestralTree *ancestor;

  AncestralTree(char name) {
    this->name = name;
    this->ancestor = nullptr;
  }

  void addAsAncestor(vector<AncestralTree *> descendants);
};

int findDepth(AncestralTree *root, AncestralTree *child){
	int d=0;
	while(child!=root){
		child=child->ancestor;
		d++;
	}
	return d;
}

AncestralTree *lca(AncestralTree *root, AncestralTree *nodeOne, AncestralTree *nodeTwo, int d){
	while(d!=0){
		nodeOne=nodeOne->ancestor;
		d--;
	}
	while(nodeOne!=nodeTwo){
		nodeOne=nodeOne->ancestor;
		nodeTwo=nodeTwo->ancestor;
	}
	return nodeOne;
}

AncestralTree *getYoungestCommonAncestor(AncestralTree *root,
                                         AncestralTree *nodeOne,
                                         AncestralTree *nodeTwo) {
  int d1=findDepth(root,nodeOne);
	int d2=findDepth(root,nodeTwo);
	int d=abs(d1-d2);
	if(d2>d1) swap(nodeOne,nodeTwo);
  return lca(root,nodeOne,nodeTwo,d);
}
