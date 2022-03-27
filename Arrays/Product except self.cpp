"array": [5, 1, 4, 2]
op: [8,40,10,20]

// Approach 1:

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

// Approach 2:

#include <vector>

using namespace std;

vector<int> arrayOfProducts(vector<int> a) {
  int n=a.size();
	
	int left[n], right[n];
	
	left[0]=1;
	for(int i=1;i<n;i++) left[i]=left[i-1]*a[i-1];
	
	right[n-1]=1;
	for(int i=n-2;i>=0;i--) right[i]=right[i+1]*a[i+1];
	
	vector<int> v(n);
	for(int i=0;i<n;i++) v[i]=left[i]*right[i];
  return v;
}
