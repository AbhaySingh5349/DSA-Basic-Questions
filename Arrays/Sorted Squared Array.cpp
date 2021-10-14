#include <vector>
using namespace std;

void merge(vector<int> &v, int s, int e){
	vector<int> temp;
	int m=s+(e-s)/2;
	int i=s, j=m+1;
	while(i<=m && j<=e){
		if(v[i]<=v[j]){
			temp.push_back(v[i]);
			i++;
		}else{
			temp.push_back(v[j]);
			j++;
		}
	}
	while(i<=m){
		temp.push_back(v[i]);
		i++;
	}
	while(j<=e){
		temp.push_back(v[j]);
		j++;
	}
	
	for(int i=s;i<=e;i++) v[i]=temp[i-s];
}

void mergesort(vector<int> &v, int s, int e){
	if(s==e) return;
	
	int m=s+(e-s)/2;
	mergesort(v,s,m);
	mergesort(v,m+1,e);
	merge(v,s,e);
}

vector<int> sortedSquaredArray(vector<int> a) {
  int n=a.size();
	vector<int> v;
	for(int i=0;i<n;i++){
		int x=a[i]*a[i];
		v.push_back(x);
	}
	mergesort(v,0,n-1);
  return v;
}
