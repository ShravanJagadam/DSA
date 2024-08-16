#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    lli t ; cin >> t;

    while(t--){

        lli N; cin >> N;
        vector<int> ar(N);
        for(lli i =0;i<N; i++) cin >> ar[i];

        lli q; cin >> q;

        vector<lli> pref(N,0);
        
        lli maxi = INT_MIN;
        while(q--){
            lli i, j, x;
            cin >> i >> j >>x;
            
            pref[i] += x; 

            if(j !=  N-1)
                pref[j+1] -= x;
            
        }
        for(lli i =1;i<N ; i++)
                pref[i] = pref[i-1]+pref[i];
        for(lli i =0; i<N; i++){
                maxi = max(maxi,pref[i]+ar[i]);
        }
        
        cout<<maxi<<endl;
    }

    return 0;
}