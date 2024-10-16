/*
Detect Cycle in Undirected Graph 
You are given an undirected, unweighted simple graph. Check whether the graph contains any cycles.



Input Format

The first line of input contains an integer T - number of test cases. The first line of each test case contains N - number of vertices and M - number of edges in the graph.

Its followed by M lines, each contains a pair (u,v) - denoting an undirected edge between node u and node v.



Output Format

For each test case, print "True" if the graph contains a cycle, else "False" separated by newline.



Constraints

1 <= T <= 100

1 <= N <= 105

0 <= M <= 105

1 <= u, v <= N



Example

Input

2

4 3

1 2

2 3

3 1

5 4

1 2

2 3

3 4

4 5



Output

True

False

There is no cycle in the above Graph.*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

//Using not parent logic
bool dfs1(int u,int par,vector<vector<int>> &G,vector<bool> &vis){

    vis[u] = true; 

    for(auto ngbr : G[u]){
        if(vis[ngbr] == false)
        {
            if(dfs(ngbr,u,G,vis) == true)
                return true;
        }
        else if(ngbr != par)
            return true;
    }
    return false;
}

//Using the count of >=2 visited neighbours

bool dfs2(int u,int par,vector<vector<int>> &G,vector<bool> &vis){

    vis[u] = true; 
    int c  = 0;
    for(int v : G[u]){
        if(vis[v] == true)
            c++;
    }
    if(c >= 2)
        return true;

    for(auto ngbr : G[u]){
        if(vis[ngbr] == false)
        {
            if(dfs(ngbr,u,G,vis) == true)
                return true;
        }
    }
    return false;
}

//Using not parent logic
bool BFS(int i,vector<vector<int>> &G,vector<bool> &vis){

    queue<pair<int,int>> q; 
    q.push({i,-1});//{node,parent}
    vis[i] = true;

    while(q.size() != 0){

        int u = q.front().first;
        int par = q.front().second;
        q.pop();

        for(int v : G[u]){
            
            if(vis[v] == true){
                if(par != v)
                     return true;
            }  
            else{
                q.push({v,u});
                vis[v] = true;
            }
        }
    }
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
            G[v].push_back(u);
        }

        vector<bool> vis(n+1,false);
        int st = 1; 
        int par  = -1;
        string ans = "False";
        for(int i =1;i<=n; i++){        //the graph may be disconnected
            if(vis[i] == false && dfs(i,par,G,vis) == true){
                ans = "True";
                break;
            }   
        }
        cout<<ans<<endl;
            
    }

    return 0;
}
