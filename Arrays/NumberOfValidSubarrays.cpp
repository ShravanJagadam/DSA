#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    lli t ; cin >> t;

    while(t--){

        lli N; cin >> N;
        vector<lli> ar(N);
        for(lli i =0;i<N ;i++){
            cin >> ar[i];
            if(ar[i] == 0)
                ar[i] = -1;
        } 

        //map to store the (presum,freq)
        vector<lli> presum(N);
        presum[0] = ar[0];
        unordered_map<lli, lli> mp; 
        
        mp[0] = 1;//this is mandatory
        mp[presum[0]] = 1;//we dont need to check for single element i.e first element(length = 1 odd)

        lli ans   = 0;

        for(lli i = 1; i<N; i++)
        {
            presum[i] = presum[i-1] + ar[i];

            if(mp.find(presum[i]) != mp.end())
                ans += mp[presum[i]];
            mp[presum[i]]++;

        }
        cout<<ans<<endl; 

    }

    return 0;
}