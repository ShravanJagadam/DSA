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


    string s;
    cin >> s;

    int k = s.find("Z");

    cout<<k<<endl;

   

    
}
static const int __ = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

