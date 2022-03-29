#include <vector>
using namespace std;

vector<int> largestRange(vector<int> a) {
  int n=a.size();
	map<int,bool> m;
	for(int i=0;i<n;i++) m[a[i]]=true;
	
	for(int i=0;i<n;i++){
		int x=a[i]-1;
		if(m.find(x)!=m.end()) m[a[i]]=false;
	}
	int maxlen=0, l=-1, r=-1;
	map<int,bool> :: iterator it;
	for(it=m.begin();it!=m.end();it++){
		int x=it->first;
		if(m[x]==true){
			int c=0;
			int val=x;
			while(m.find(x)!=m.end()){
				c++;
				x++;
			}
			if(c>maxlen){
				maxlen=c;
				l=val;
				r=l+c-1;
			}
		}
	}
  return {l,r};
}
