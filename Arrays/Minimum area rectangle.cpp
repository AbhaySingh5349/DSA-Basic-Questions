#include <bits/stdc++.h>
using namespace std;

int minimumAreaRectangle(vector<vector<int>> points) {
  int n=points.size();
	int ans=INT_MAX;
	set<pair<int,int>> st;
	for(int i=0;i<n;i++){
		int x1=points[i][0], y1=points[i][1];
		set<pair<int,int>> :: iterator it;
		for(it=st.begin();it!=st.end();it++){
			int x2=it->first, y2=it->second;
			if(x1==x2 && y1==y2) continue;
			if(st.find({x1,y2})!=st.end() && st.find({x2,y1})!=st.end()){
				int area=abs(y2-y1)*abs(x2-x1);
				ans=min(ans,area);
			}
		}
		st.insert({x1,y1});
	}
  return (ans==INT_MAX ? 0:ans);
}
