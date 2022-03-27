#include <vector>

using namespace std;

vector<int> arrayOfProducts(vector<int> a) {
  int n=a.size();
	
	vector<int> v(n);
	for(int i=0;i<n;i++){
		int p=1;
		for(int j=0;j<n;j++){
			if(i==j) continue;
			p*=a[j];
		}
		v[i]=p;
	}
	
  return v;
}
