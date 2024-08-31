#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    lli t ; cin >> t;
    int k = 1;
    while(t--){

        lli N; cin >> N;
        cout<<"Case #"<<k++<<":"<<endl;
        for(int i =0; i<2*N; i++){
            for(int j =0; j<2*N; j++){
                if( (i/2+j/2)%2 == 0)
                    cout<<"*";
                else
                    cout<<"-";
            }
            cout<<endl;
        }
    }

    return 0;
}