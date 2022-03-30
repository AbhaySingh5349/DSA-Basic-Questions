#include <vector>
using namespace std;

// left and right sub-tree must be matching

bool sameBsts(vector<int> a, vector<int> b) {
  int n=a.size(), m=b.size();
	if(n==0 && m==0) return true;
	if(n!=m || a[0]!=b[0]) return false;
	
	vector<int> lefta, leftb, righta, rightb;
	for(int i=1;i<n;i++){
		if(a[i]<a[0]){
			lefta.push_back(a[i]);
		}else{
			righta.push_back(a[i]);
		}
		if(b[i]<b[0]){
			leftb.push_back(b[i]);
		}else{
			rightb.push_back(b[i]);
		}
	}
	return (sameBsts(lefta,leftb) && sameBsts(righta,rightb));
}
