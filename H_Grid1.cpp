#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int Path(vector<vector<char>> &grid) {
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<int> > dp(m,vector<int>(n,0));
    dp[0][0]=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='#'){
                dp[i][j]=0;
            }else{
                if(i-1>=0) dp[i][j]=(dp[i][j]+dp[i-1][j])%MOD;
                if(j-1>=0) dp[i][j]=(dp[i][j]+dp[i][j-1])%MOD;
            }
        }
    }
    return dp[m-1][n-1];
}
int main(){
    int t=1;
    while(t--){
        int n,m;
	    cin>>n>>m;
	    vector<vector<char> > grid(n,vector<char>(m));
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
    	        char a;
    	        cin>>a;
    	        grid[i][j]=a;
	        }
	    }
    
        cout<<Path(grid)<<endl;
    }
    return 0;
}
