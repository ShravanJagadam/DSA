#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

void reverse(vector<lli> &ar, lli p1, lli p2){

    while(p1 < p2){

        lli x = ar[p1];
        ar[p1] = ar[p2];
        ar[p2] = x;
        p1++; 
        p2--;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    lli t ; cin >> t;

    while(t--){

        lli N,K; cin >> N >>K;
        vector<lli> ar(N);
        for(lli i = 0; i<N; i++) cin >> ar[i];
    
        //reverse last K elements
        //reverse first (N-K) elements 
        //reverse the entire array 
        K = K % N; // handle if the rotations are more than the number of elements
        reverse( ar,0,N-K-1);
        reverse( ar,N-K,N-1);
        reverse( ar,0, N-1 );

        for(int k : ar)
            cout<<k<<" ";
        cout<<endl;
    }

    return 0;
}

/*The above order can be reversed
        
        reverse the entire array 
        reverse first K elements
        reverse last N-K elements 
*/