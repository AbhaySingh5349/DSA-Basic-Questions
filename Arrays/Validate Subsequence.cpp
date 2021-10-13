// Question: valiate if 2nd array is subsequence of 1st array

"array": [5, 1, 22, 25, 6, -1, 8, 10],
"sequence": [1, 6, -1, 10]
o/p: true

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
