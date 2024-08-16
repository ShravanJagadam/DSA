#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    lli t ; cin >> t;

    while(t--){

        lli N1; cin >> N1;
        vector<int> ar(N1);
        for(lli i =0; i<N1; i++)    cin >> ar[i];
        sort(ar.begin(), ar.end());

        lli N2; cin >> N2;
        vector<int> br(N2);
        for(lli i =0; i<N2; i++)    cin >> br[i];
        sort(br.begin(), br.end());

        lli N3; cin >> N3;
        vector<int> cr(N3);
        for(lli i =0; i<N3; i++)    cin >> cr[i];
        sort(cr.begin(), cr.end());

        lli p1 = 0, p2 =0, p3 = 0;

        //choose the array elements at p1,p2,p3
        lli ans = INT_MAX; 
        lli mx, mn;
        
        //In order to minimise the difference of mx - mn
        //1. either we have to decrease the max 
        //2.Or we have to increase the min, we can do this as arrays are sorted
        //each time we try to increase the min element among the choosen elements
        while(p1<N1 && p2<N2 && p3<N3){

            

            mx = max(ar[p1], max(br[p2], cr[p3]));
            mn = min(ar[p1], min(br[p2], cr[p3]));
            ans = min(ans,mx - mn);

            if(mn == ar[p1])    p1++;
            else if (mn == br[p2])  p2++;
            else    p3++;
        }
        cout<<ans<<endl;

    }

    return 0;
}