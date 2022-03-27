// Question: check if array is monotonic or not (non-increasing or non-decreasing)

"array": [-1, -5, -10, -1100, -1100, -1101, -1102, -9001]
op: true

using namespace std;

bool isMonotonic(vector<int> a) {
  int n=a.size();
	if(n<=2) return true;
	
	int i=0;
	while(i<n-1 && a[i]==a[i+1]) i++;
	
	i++; // we need to do this : [2,2,2,3,3,4,5] 
	int curmax=a[i], curmin=a[i];
	
	if(a[i]>a[i-1]){
		while(a[i]>=curmax && i<n){
			curmax=a[i];
			i++;
		}
	}else{
		while(a[i]<=curmin && i<n){
			curmin=a[i];
			i++;
		}
	}
	
  return (i==n);
}
