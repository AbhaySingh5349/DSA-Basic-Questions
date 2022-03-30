#include <bits/stdc++.h>
using namespace std;

int apartmentHunting(vector<unordered_map<string, bool>> blocks, vector<string> reqs){
  int n=blocks.size(), m=reqs.size();
	int ans=n+1, idx=-1;
	for(int i=0;i<n;i++){
		int maxd=0;
		for(int j=0;j<m;j++){
			string s=reqs[j];
			int d=n+1;
			for(int k=0;k<n;k++){
				unordered_map<string, bool> mp=blocks[k];
				if(mp[s]==true) d=min(d,abs(k-i));
			}
			maxd=max(maxd,d);
		}
		if(ans>maxd){
			ans=maxd;
			idx=i;
		}
	}
  return idx;
}
