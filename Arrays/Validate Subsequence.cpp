#include <vector>
using namespace std;

bool isValidSubsequence(vector<int> a, vector<int> seq) {
  int n=a.size(), m=seq.size();
	int i=0, j=0;
	while(i<n && j<m){
		if(a[i]==seq[j]){
			i++, j++;
		}else{
			i++;
		}
	}
  return (j==m);
}
