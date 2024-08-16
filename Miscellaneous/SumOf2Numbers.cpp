#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    lli t; cin >> t;
    while(t--){
        lli N ; cin >> N;
        vector<lli> ar(N); 
        lli sum = 0;
        for(lli i =0;i<N; i++){
            cin >> ar[i];
            sum += ar[i];
        } 
        string ans = "No";
        if(sum % 2 != 0)
        {
            cout<<"No"<<endl;
            continue;
        }
        lli k = sum/2;

        sort(ar.begin(), ar.end());
        lli p1 =0, p2 = N-1;
        while(p1<p2){

            lli h = ar[p1]+ar[p2];

            if(h > k)   
                p2--;
            else if(h<k)
                p1++;
            else    
                {
                    ans = "Yes";
                    break;
                }
        }
        cout<<ans<<endl;
    }
    return 0;
}



/*Approach : 
Another optimization is, a pair can exist only if the sum of whole 
array is even because we are basically dividing it into two parts 
with equal sum.
total sum of the array must be even
ar[i] + ar[j] = sum - ar[i] + ar[j]
2 * (ar[i] + ar[j] ) = sum 
ar[i] + ar[j] = sum/2;
use 2 ptr technique to find if there exists a
pair whose sum is sum/2;*/
