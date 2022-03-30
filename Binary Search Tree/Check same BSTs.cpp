// Questions: given 2 arrays, check if they represent same BSTs or not
"arrayOne": [10, 15, 8, 12, 94, 81, 5, 2, 11],
"arrayTwo": [10, 8, 5, 15, 2, 12, 11, 94, 81]
op: true
	10
        / \
       8   15
      /    / \
     5    12  94
    /     /   /
   2	 11  81
	
// Approach 1:
	
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

// Approach 2:

#include <vector>
using namespace std;

int rootIdxSmaller(vector<int> v,int idx, int lb){
	int rootIdx=-1;
	for(int i=idx+1;i<v.size();i++){
		if(v[i]<v[idx] && v[i]>=lb){
			rootIdx=i;
			break;
		}
	}
	return rootIdx;
}

int rootIdxGreaterOrEqual(vector<int> v,int idx, int ub){
	int rootIdx=-1;
	for(int i=idx+1;i<v.size();i++){
		if(v[i]>=v[idx] && v[i]<=ub){
			rootIdx=i;
			break;
		}
	}
	return rootIdx;
}

// i & j are root idx in corresponding arrays
bool check(vector<int> a, vector<int> b , int i, int j, int lb, int ub){
	if(i==-1 || j==-1) return (i==j);
	int n=a.size(), m=b.size();
	if(n==0 && m==0) return true;
	if(n!=m || a[i]!=b[j]) return false;
	
	int aleft=rootIdxSmaller(a,i,lb);
	int bleft=rootIdxSmaller(b,j,lb);
	int aright=rootIdxGreaterOrEqual(a,i,ub);
	int bright=rootIdxGreaterOrEqual(b,j,ub);
	
	return (check(a,b,aleft,bleft,lb,a[i]) && check(a,b,aright,bright,a[i],ub));
}

bool sameBsts(vector<int> a, vector<int> b) {
  return check(a,b,0,0,INT_MIN+1,INT_MAX-1);
}
