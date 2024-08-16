#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    lli t ; cin >> t;

    while(t--){

        lli N; cin >> N;
        vector<lli> ar(N);
        for(lli i =0;i<N; i++) cin >> ar[i];

        //Approach1 : for each index find the left max and right max 
        //Water stored at index i is min(leftmax,right max ) - ar[i];
        //If the current element is the lmax element then water store is 0


        vector<lli> lmax(N);
        vector<lli> rmax(N);

        lmax[0] = ar[0];
        for(lli i =1;i<N; i++)
            lmax[i] = max(lmax[i-1], ar[i]);

        rmax[N-1] = ar[N-1];
        for(lli i = N-2; i>=0; i--){
            rmax[i] = max(rmax[i+1], ar[i]);
        }

        lli ans = 0;

        for(lli i = 1; i<N-1; i++){//skip 1st and last element
            ans += min(lmax[i],rmax[i])- ar[i]; 
            //we take lmax with current element included
            //we take rmax with the current element included
             
        }
        cout<<ans<<endl;
    }

    return 0;
}