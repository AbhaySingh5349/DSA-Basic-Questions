using namespace std;

vector<int> spiralTraverse(vector<vector<int>> mat) {
  int n=mat.size(), m=mat[0].size();
	int minr=0, minc=0, maxr=n-1, maxc=m-1;
	int total=n*m;
	vector<int> v;
	while(total>0){
		// top wall
		for(int i=minr,j=minc;j<=maxc && total>0;j++){
			v.push_back(mat[i][j]);
			total--;
		}
		minr++;
		
		// right wall
		for(int i=minr,j=maxc;i<=maxr && total>0;i++){
			v.push_back(mat[i][j]);
			total--;
		} 
		maxc--;
		
		// bottom wall
		for(int i=maxr,j=maxc;j>=minc && total>0;j--){
			v.push_back(mat[i][j]);
			total--;
		}
		maxr--;
		
		// left wall
		for(int i=maxr,j=minc;i>=minr && total>0;i--){
			v.push_back(mat[i][j]);
			total--;
		}
		minc++;
	}
  return v;
}
