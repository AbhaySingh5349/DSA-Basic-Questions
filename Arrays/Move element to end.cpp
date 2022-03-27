#include <bits/stdc++.h>
using namespace std;

vector<int> moveElementToEnd(vector<int> a, int toMove) {
  int n=a.size();
	int i=0, j=0;
	while(j<n){
		while(i<n && a[i]!=toMove) i++;
		j=max(i,j);
		j++;
		if(j<n && a[j]!=toMove) swap(a[i],a[j]);
	}
  return a;
}
