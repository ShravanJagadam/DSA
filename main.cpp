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
typedef long long int lli;

int jump(vector<int> &A) {
    
    
    if(A.size() ==1 && A[0] == 0)    
        return 0;
    int n1 = A.size();
    int v[n1];
    fill(v,v+n1,INT_MAX);
    
    v[0] = 0;
    
    for(int i =0; i<n1; i++){
        if(v[i] != INT_MAX){
            for(int j = 1; j <= A[i] && i+j < n1; j++ )
                v[i+j] = min(v[i+j], v[i]+1);
        } 
    }
    
    return (v[n1-1] == INT_MAX ? -1 : v[n1-1]);
}
long long GCD(int a, int b){
    if(a == 0) return b; 
    return GCD(b%a,a);
}




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

    //**************************************************************************************
    //start you code here
        vector<int> nums = {3};
        int n = nums.size(); 
        if(n == 0) return 0;
        if(n == 1) return nums[0] * nums[0];
        int gdc = GCD(nums[0],nums[1]);
        for(int i =2; i<n; i++){
            gdc = GCD(gdc,nums[i]);
        }
        cout<<"GCD is "<<gdc<<endl;
        bool flag = false;
        long long int p = 1;
        int val;
        for(int i=0;i<n; i++)
        {
            if(nums[i] == gdc){
                val = nums[i];
                flag = true; 
                break;                
            }
            
        }
        for(int x : nums )
            p = p*x;
        cout<<" prod is "<<p<<endl;
        long long int lmc = p/gdc;
        cout<<"lcm is "<<lmc<<endl;

        if(flag == true)
            cout<< (lmc /n );
        else 
            cout<< p;
    



    //end your code her 
    //*************************************************************************************
}
static const int __ = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

