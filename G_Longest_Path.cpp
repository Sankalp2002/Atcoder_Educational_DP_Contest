#include <bits/stdc++.h>
using namespace std;
#define MOD = 1e9+7;
void dfs(int source,vector<vector<int> > &v,vector<int> &dp){    
    int maxx = -1;
    for(auto i:v[source]){
        if(dp[i] == -1)
            dfs(i,v,dp);
        maxx = max(maxx , dp[i]);
    }
    dp[source] = maxx+1;
    return;
}
int main(){
    int t=1;
    while(t--){
        int n,m;
	    cin>>n>>m;
	    vector<vector<int> > graph(n);
	    vector<int> dp(n,-1);
	    for(int i=0;i<m;i++){
	        int a,b;
	        cin>>a>>b;
	        graph[a-1].push_back(b-1);
	    }
	    int maxx = 0;
        for(int i=0;i<n;++i){
            if(dp[i] == -1)
                dfs(i,graph,dp);
            maxx = max(maxx, dp[i]);
        }
    
        cout<<maxx<<endl;
    }
    return 0;
}
