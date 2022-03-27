// Question: 
"array": [2, 1, 5, 3, 3, 2 , 4]
op: 3

// Approach 1:

#include <vector>
using namespace std;

int firstDuplicateValue(vector<int> a) { 
	int n=a.size();
	int idx=n+1, num=-1;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[j]==a[i] && j<idx){
				idx=j;
				num=a[j];
			}
		}
	}
	return (idx==n+1 ? -1:num); 
}

// Approach 2:

#include <vector>
using namespace std;

int firstDuplicateValue(vector<int> a) { 
	int n=a.size();
	for(int i=0;i<n;i++){
		int idx=abs(a[i])-1;
		if(a[idx]>0){
			a[idx]*=-1;
		}else{
			return abs(a[i]);
		}
	}
	return -1; 
}
