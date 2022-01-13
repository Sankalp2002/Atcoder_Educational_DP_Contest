#include <bits/stdc++.h>
using namespace std;
#define MOD = 1e9+7;

int main(){
    int t=1;
    while(t--){
        string s,r;
	    cin>>s>>r;
	    int m=s.size();
        int n=r.size(); 
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==r[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max({dp[i-1][j],dp[i][j-1]});
                }
            }
        }
        int len=dp[m][n];
        int i = m, j = n;
        string lcs="";
  while (i > 0 && j > 0){
    if (s[i-1] == r[j-1]){
      lcs+= s[i-1]; 
      i--; j--;     
    }

    else if (dp[i-1][j] > dp[i][j-1])
      i--;
    else
      j--;
  }
  reverse(lcs.begin(),lcs.end());
  cout<<lcs<<"\n";
    }
    return 0;
}
