// Question: given blocks with index [0,n-1] and presence of requirements on that block, find index of block such that max. distance of any requirement is minimized.
"blocks": [
    {
      "gym": false,
      "school": true,
      "store": false
    },
    {
      "gym": true,
      "school": false,
      "store": false
    },
    {
      "gym": true,
      "school": true,
      "store": false
    },
    {
      "gym": false,
      "school": true,
      "store": false
    },
    {
      "gym": false,
      "school": true,
      "store": true
    }
  ],
  "reqs": ["gym", "school", "store"]
}
op: 3 // from index 3, max. distance we need to travel is 1 to find any requirement

// Approach 1:

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

// Approach 2:

#include <bits/stdc++.h>
using namespace std;

// we can pre compute how far each Requirement we have to go from idx
// take max for each idx we know how far we to go for each requirement
// idx corresponding to min of these max is answer

closest distance: Gym:   [1,0,0,1,2]
		  School:[0,1,0,0,0]
		  Store: [4,3,2,1,0]

int apartmentHunting(vector<unordered_map<string, bool>> blocks,vector<string> reqs) {
  int n=blocks.size(), m=reqs.size();
	map<string,vector<int>> closestDist;
	for(int i=0;i<m;i++){
		string s=reqs[i];
		int pos=n+1;
		vector<int> v(n,n+1);
		closestDist[s]=v;
		
		for(int j=0;j<n;j++){
			unordered_map<string,bool> mp=blocks[j];
			if(mp[s]==true) pos=j;
			closestDist[s][j]=abs(j-pos);
		}
		
		for(int j=n-1;j>=0;j--){
			unordered_map<string, bool> mp=blocks[j];
			if(mp[s]==true) pos=j;
			closestDist[s][j]=min(closestDist[s][j],abs(j-pos));
		}
	}
	
	int ans=n+1, idx=-1;
	for(int i=0;i<n;i++){
		int d=0;
		for(int j=0;j<m;j++){
			string s=reqs[j];
			d=max(closestDist[s][i],d);
		}
		if(ans>d){
			ans=d;
			idx=i;
		}
	}
  return idx;
}


// Approach 3:

#include <vector>
#include <unordered_map>

using namespace std;

int apartmentHunting(vector<unordered_map<string, bool>> blocks,
                     vector<string> reqs) {

  int n=blocks.size();
  
  vector<unordered_map<string, int>> left(n); // [idx,req] --> nearest left position
  for(string s:reqs){
    if(blocks[0][s]==true){
      left[0][s]=0;
    }else{
      left[0][s]=-1;
    }
  }
  
  for(int i=1;i<n;i++){
    for(string s:reqs){
      if(blocks[i][s]==true){
        left[i][s]=i;
      }else{
        left[i][s]=left[i-1][s];
      }
    }
  }

  vector<unordered_map<string, int>> right(n); // [idx,req] --> nearest right position
  for(string s:reqs){
    if(blocks[n-1][s]==true){
      right[n-1][s]=n-1;
    }else{
      right[n-1][s]=n;
    }
  }

  for(int i=n-2;i>=0;i--){
    for(string s:reqs){
      if(blocks[i][s]==true){
        right[i][s]=i;
      }else{
        right[i][s]=right[i+1][s];
      }
    }
  }

  int maxd=n+1, idx=-1;
  for(int i=0;i<n;i++){
    int curd=-1;
    for(string s:reqs){
      
      int d1 = (left[i][s]==-1 ? INT_MAX/2:abs(i-left[i][s]));
      int d2 = (right[i][s]==n ? INT_MAX/2:abs(right[i][s]-i));

      curd=max(curd,min(d1,d2));
    }

    if(curd<maxd){
      idx=i;
      maxd=curd;
    }
  }
  return idx;
}
