#include <vector>
using namespace std;

// Question: given unique elements, find all pairs with given target sum

vector<int> twoNumberSum(vector<int> a, int target) {
  	vector<int> v;
	sort(a.begin(),a.end());
	int n=a.size();
	int i=0, j=n-1;
	while(i<j){
		int x=a[i]+a[j];
		if(x<target){
			i++;
		}else if(x>target){
			j--;
		}else{
			v.push_back(a[i]);
			v.push_back(a[j]);
			i++, j--;
		}
	}
  return v;
}
