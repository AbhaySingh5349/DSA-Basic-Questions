// Question: find start and end index of smallest subarray which if sorted in-place, complete array is sorted in ascending order

"array": [1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19]
op: [3,9]

// Approach 1:

#include <vector>
using namespace std;

vector<int> subarraySort(vector<int> a) {
  int n=a.size();
	vector<int> v=a;
	sort(a.begin(),a.end());
	
	int l=-1, r=-1;
	for(int i=0;i<n;i++){
		if(v[i]!=a[i]){
			if(l==-1){
				 l=i;
			}else{
				r=i;
			}
		}
	}
  return {l,r};
}

// Approach 2:

#include <vector>
using namespace std;

vector<int> subarraySort(vector<int> a) {
  int n=a.size();
	
	int l=-1, curmin=a[n-1];
	for(int i=n-2;i>=0;i--){
		if(a[i]>curmin) l=i;
		curmin = min(curmin,a[i]);
	}
	
	int r=-1, curmax=a[0];
	for(int i=1;i<n;i++){
		if(a[i]<curmax) r=i;
		curmax=max(curmax,a[i]);
	}
  return {l,r};
}
