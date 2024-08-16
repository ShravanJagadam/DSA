#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    lli t ; cin >> t;

    while(t--){

        lli N; cin >> N;
        vector<int> ar(N);
        //replace all 0's with -1's
        for(lli i =0;i<N; i++) {
            cin >> ar[i];
            if(ar[i] == 0)
                ar[i] = -1;
        }

        
        //compute the presum 

        for(lli i =1;i<N; i++)
            ar[i] = ar[i] + ar[i-1];
        //If there are any multiple occurance of the presum values then 
        //the sum between those elements is 0
        //which implies the no of 1's and -1's(0's) are same

        unordered_map<lli,lli> mp;//{presum,firstOccurence}
        mp[0] = -1;
        lli ans = 0;

        for(lli i=0; i<N; i++){

            if(mp.find(ar[i]) == mp.end()){//first occurence of an element   
                mp[ar[i]] = i;
            }
            else{//element is already present 
                ans = max(ans, i - mp[ar[i]]);                 
            }
        }
        
        cout<<ans<<endl;
    }
    

    return 0;
}