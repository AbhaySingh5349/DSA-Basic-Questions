#include <vector>
using namespace std;

// Approach 1: O(n^2)

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

// Approach: O(nlogn)

vector<int> smallestDifference(vector<int> a, vector<int> b) {
  int n=a.size(), m=b.size();
	int mind=INT_MAX, f,s;
	
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	int i=0, j=0;
	while(i<n && j<m){
		int d=abs(a[i]-b[j]);
		if(d<mind){
				mind=d;
				f=a[i];
				s=b[j];
			}
		if(a[i]<b[j]){
			i++;
		}else if(a[i]>b[j]){
			j++;
		}else{
			break;
		}
	}
	
  vector<int> v;
	v.push_back(f);
	v.push_back(s);
  return v;
}
