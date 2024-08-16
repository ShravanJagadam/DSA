#include<bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define ff first
#define all(x) begin(x), end(x)// (a.begin(),a.end())


int main(){

    pair<int,int> p = {2,3};

    cout<<p.ff<<endl;
    vector<int> a = {1,7,9,8,2,5,9,3,4,5,6};

    rep(i,0,a.size())
        cout<<a[i]<<" ";
    cout<<endl;

    //sort(all(a));
    sort(begin(a),end(a));
    
    rep(i,0,a.size())
        cout<<a[i]<<" ";
    cout<<endl;


    return 0;


}




