#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    lli t ; cin >> t;

    while(t--){

        lli N; cin >> N;
        vector<int> ar(N);
        lli sum = 0;
        for(lli i =0; i<N; i++){
            cin >> ar[i];
            sum += ar[i];
        }

        lli q; cin >> q;

        while(q--){

            lli i,j,x;
            cin >> i >> j >> x;

            sum += (j-i+1)*x;

        }
        cout<<sum<<endl;
    }

    return 0;
}