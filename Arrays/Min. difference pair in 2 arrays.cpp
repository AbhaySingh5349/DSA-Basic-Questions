#include <vector>
using namespace std;

vector<int> smallestDifference(vector<int> a, vector<int> b) {
  int n=a.size(), m=b.size();
	int mind=INT_MAX, f,s;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int d=abs(a[i]-b[j]);
			if(d<mind){
				mind=d;
				f=a[i];
				s=b[j];
			}
		}
	}
	vector<int> v;
	v.push_back(f);
	v.push_back(s);
  return v;
}
