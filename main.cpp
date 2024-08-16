#include <bits/stdc++.h>
using namespace std;
// to set precision use fixed,setprecision(number_of_points_after_decimal)
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto &a : x)
#define all(x) begin(x), end(x)
#define mod 1000000007
#define sz(x) (int)(x).size()
#define ff first
#define ss second
#define pb push_back
#define debugvector(h) \
  for (auto &l : h)    \
  cout << l << " "
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef map<int, int> mii;
typedef long double ld;



int main()
{
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);



    ll t, N,A, B;
     cin >> t ;


    while(t--){

        cin >>N >> A >> B;
        vector<ll> ar(N);
        cout<<"***"<<endl;
        for(int i =0; i<N; i++){
            cin >> ar[i];
        }

        for(ll i =0; i<N ; i++)
            cout<<ar[i]<<endl;

        sort(ar.begin(), ar.end());
        
        int count = 0;

        for(int i =0;i<N; i++){
            ll sum = 0;
            for(int j =i;j<N; i++){
                sum += ar[j];
                if(sum >= A && sum <= B)
                    count++;
            }
        }
        cout<<count<<endl;

    }
}

static const int __ = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();