#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

/*Given 4 arrays 
choose  quadraplets such that each element belongs to one arrays and the 
XOR of the choosen quadraplets must be zero
*/

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    lli t ; cin >> t;

    while(t--){

        lli N; cin >> N;
        vector<int> ar(N);
        vector<int> br(N);
        vector<int> cr(N);
        vector<int> dr(N);

        for(lli i =0;i<N; i++)  cin >> ar[i];
        for(lli i =0;i<N; i++)  cin >> br[i];
        for(lli i =0;i<N; i++)  cin >> cr[i];
        for(lli i =0;i<N; i++)  cin >> dr[i];

        

        unordered_map<int,int> mp;
        for(int i =0;i<N; i++){

            for(int j=0; j<N; j++)
            {
                lli xors = ar[i] ^ br[j];
                mp[xors]++;
                    
                    
            }
        }

        //for(auto it : mp)
            //cout<<it.first<<"**"<<it.second<<endl;


        lli ans  = 0;
        for(int i =0;i<N; i++){

            for(int j=0; j<N; j++)
            {
                lli xors = cr[i] ^ dr[j];
                 //cout<<"curr xor iss "<<xors<<endl;
                if(mp.find(xors) != mp.end()){
                    ans += mp[xors];
                   
                }
                    
            }
        }
        cout<<ans<<endl;


        
        






    }

    return 0;
}