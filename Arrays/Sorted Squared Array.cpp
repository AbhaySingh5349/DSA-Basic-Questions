// Question: given a sorted array, return new array with squares of original integers arranged in ascending order

"array": [-7, -3, 1, 9, 22, 30]
op: [1,9,21,81,484,900]

// Approach 1: using merge sort after squaring element: O(nlogn)

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



#include <bits/stdc++.h>
using namespace std;

vector<int> sortedSquaredArray(vector<int> a) {
  int n=a.size();
	int i=0, j=n-1;
	int idx=n-1;
	vector<int> v(n,0);
	while(i<j){
		if(abs(a[j])>abs(a[i])){
			int x=a[j]*a[j];
			v[idx]=x;
			idx--;
			j--;
		}else if(abs(a[j])<abs(a[i])){
			int x=a[i]*a[i];
			v[idx]=x;
			idx--;
			i++;
		}else{
			int x=a[i]*a[i];
			int y=a[j]*a[j];
			v[idx]=x;
			v[idx-1]=y;
			idx-=2;
			i++, j--;
		}
	}
	if(i==j) v[idx]=a[i]*a[i];
  return v;
}
