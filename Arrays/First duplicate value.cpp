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
