#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

void solve(vector<lli> &ar, lli N, lli idx, vector<lli> &temp,vector<vector<lli>> &ans){

    if(idx == N){

        if(temp.size() != 0)
            ans.push_back(temp);
        return;
    }

    solve(ar,N,idx+1,temp,ans);         //SKip the current element 

    temp.push_back(ar[idx]);            //Consider the current element
    solve(ar,N,idx+1,temp,ans);
    temp.pop_back();
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    lli t ; cin >> t;

    while(t--){

        lli N; cin >> N;
        vector<lli> ar(N);
        for(lli i =0;i<N; i++)  cin >> ar[i];

        sort(ar.begin(), ar.end());         //Sort the input array

        vector<lli> temp;
        vector<vector<lli>> ans;

        lli idx = 0;
        solve(ar,N, idx, temp,ans);     //Generate all the subsets and sort them in 2D vector

        sort(ans.begin(), ans.end());   //Sort the 2D vector & print 
        for(auto x : ans){

            for(auto c: x)
                cout<<c<<" ";
            cout<<endl;
        }


    }

    return 0;
}