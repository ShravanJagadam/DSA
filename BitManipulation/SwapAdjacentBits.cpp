#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    lli t ; cin >> t;

    while(t--){

        lli N; cin >> N;

        lli ans  = 0;
        
        for(int b = 0; b<=30; b= b+2){
            
            int k =  N & (1<<b);//bth bit
            int l = N & (1<<(b+1));//b+1 th bit

            ans += (1<<b) * l;
            cout<<"**"<<ans;
            ans += (1<<(b+1)) * k;
            cout<<"**"<<ans<<endl;
        }
        cout<<ans<<endl; 
    }

    return 0;
}

//consider two adjacent bits and swap them