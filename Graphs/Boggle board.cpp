// Question: find list of all the words present in board from given list

#include <vector>
using namespace std;

// O(k*m*n * 7^(m*n))

int dxy[8][2]={{-1,0},{0,1},{1,0},{0,-1},{-1,1},{1,1},{1,-1},{-1,-1}};

bool solve(vector<vector<char>>& grid, int i, int j, string &s, int idx){
        int n=grid.size(), m=grid[0].size();
        if(idx==s.length()) return true;
        if(i<0 || j<0 || i==n || j==m || grid[i][j]!=s[idx]) return false;
        
        bool ans=false;
        char ch=grid[i][j];
        grid[i][j]='*';
        for(int k=0;k<8;k++){
            int x=i+dxy[k][0], y=j+dxy[k][1];
            ans |= solve(grid,x,y,s,idx+1);
        }
        grid[i][j]=ch; // backtrack
        
        return ans;
    }

vector<string> boggleBoard(vector<vector<char>> grid, vector<string> words) {
				vector<string> ans;
  			set<char> st;
        for(int k=0;k<words.size();k++){
            string s=words[k];
            char ch=s[0];
            st.insert(ch);
        } 
        map<char,vector<pair<int,int>>> mp;
        int n=grid.size(), m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char ch=grid[i][j];
                if(st.find(ch)!=st.end()) mp[ch].push_back({i,j});
            }
        }
        for(int k=0;k<words.size();k++){
            string s=words[k];
            char ch=s[0];
            vector<pair<int,int>> v=mp[ch];
            for(int i=0;i<v.size();i++){
                int x=v[i].first, y=v[i].second;
                bool found=solve(grid,x,y,s,0);
                if(found){
                    ans.push_back(s);
                    break;
                }
            }
        } 
        return ans;
}
