#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;


bool dfs(vector<vector<int>> &G,vector<bool> &vis, int u,vector<bool> &recS){

    vis[u] = true;
    recS[u] = true;//push it into recStack
    for(int v : G[u]){
        if(vis[v] == false){
            if(dfs(G,vis,v,recS) == true)
                return true;
        }
        else if(recS[v] == true)    //if node v is already visited and it is present in the recStack ,u->v is the back edge, which forms the cycle
            return true;
    }
    recS[u] = false;//pushing out from the recursion stack
    return false;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    lli t ; cin >> t;

    while(t--){

        lli n,m; cin >> n>>m; 
        vector<vector<int>> G(n+1); //graph 

        int u,v;
        for(int i =0;i<m; i++){
            cin >> u>>v; 
            G[u].push_back(v);
        }

        vector<bool> vis(n+1,false); 
        vector<bool> recS(n+1,false);
        string ans = "False";
        for(int i =1; i<=n; i++){
            if(vis[i] == false)
            {
                if(dfs(G,vis,i,recS) == true){
                    ans = "True";
                    break;
                }
            }
        }
        cout<<ans<<endl;
        
            
    }

    return 0;
}