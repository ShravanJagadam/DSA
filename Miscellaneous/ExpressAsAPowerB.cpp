/*
Express as a Power b 
Given a number, check if the number can be expressed as pow(a, b) where both a and b should be greater than 1.



Input Format

The first line of input contains T - the number of test cases. It's followed by T lines, each line contains a single integer N.



Output Format

For each test case, print "Yes" if N can be expressed as pow(a, b), and print "No" otherwise, separated by a new line.



Constraints

30 points

1 <= T <= 104

1 <= N <= 106



70 points

1 <= T <= 106

1 <= N <= 108



Example

Input

5

2

16

31

8880

961



Output

No

Yes

No

No

Yes



Explanation



Self Explanatory*/

/*Below we are pre-computing and then check if the value "N" is a valid or not 

N <= 10^8
N = a^b

"a" have to lie in the range [2,10^4] since (10^4)^2 is 10^8

N = a^b ==> log(N) = b log(a)==> b = log(N)/log(a)
hence max value of b can be log(N)approxx
log(N) ->log(10^8)->30
'since 10^3 = 2^10'
    10^9 = 2^30
Pre-cpmoute all possible a^b and store them 
*/



#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;



int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    unordered_set<lli> st; 
    for(lli a = 2; a * a <= 1e8; a++){

        lli k = a; 
        for(lli b = 2; b <= 30; b++){

            k = k * a;
            if(k > 1e8) break;
            st.insert(k);
        }
    }

    lli t ; cin >>t ;

    while(t--){

        lli N; cin >> N;

        if(st.find(N) != st.end())
            cout<<"Yes"<<endl;
        else 
            cout<<"No"<<endl;
    }

    return 0;
}






































/*
Naive Approach : 
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    Enter your code here. Read input from STDIN. Print output to STDOUT 
    lli t ; cin >> t;

    while(t--){

        lli N; cin >> N;
        

        string ans = "No";
        for(int a =2; a* a <= N; a++){

            
            lli k = a ; 
            
            while(1){

                k = k * a;
                if(k == N){
                    ans = "Yes";
                    break;
                }
                else if (k>N)
                    break;
            }
            if(ans == "Yes")
                break;
        }
        cout<<ans<<endl;
    }

    return 0;
}
*/