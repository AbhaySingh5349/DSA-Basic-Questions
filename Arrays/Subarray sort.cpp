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
