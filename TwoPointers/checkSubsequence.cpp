#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli k = 1e9+7;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    //string hashing 

    lli t ; cin >>t; 

    while(t--){

        string a,b; cin >> a >> b;

        lli n = a.size(); 
        lli m = b.size();

        //2 ptrs
        lli p1 = 0, p2 = 0;//p1 on A and p2 on b

        while(p1<n && p2<m){

            if(a[p1] == b[p2]){
                p1++;
                p2++;
            }
            else
                p2++;
        }
        if(p1 == n)
            cout<<"Yes"<<endl;
        else    
            cout<<"No"<<endl;

    }
    return 0;
}
/*1.Given 2 strings A and B, check if A is present as a subsequence in B.
Use 2 ptrs
if the characters matched increment both pointers 
else
increment only p2*/