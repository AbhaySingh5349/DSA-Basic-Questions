#include <vector>
using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> intervals) {
  int n=intervals.size();
	vector<vector<int>> ans;
	sort(intervals.begin(),intervals.end());
	int s=intervals[0][0], e=intervals[0][1];
	
	for(int i=1;i<n;i++){
		int si=intervals[i][0], ei=intervals[i][1];
		if(si>e){
			vector<int> v;
			v.push_back(s);
			v.push_back(e);
			ans.push_back(v);
			s=si, e=ei;
		}else{
			e=max(e,ei);
		}
	}
	vector<int> v;
	v.push_back(s);
	v.push_back(e);
	ans.push_back(v);
  return ans;
}
