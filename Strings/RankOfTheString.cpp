/*
Rank of String 
Given a string without duplicates, find its rank (position) in all the permutations of the string when sorted lexicographically.



Input Format

The first line of input contains T - the number of test cases. It's followed by T lines, each containing a single string consisting of only lowercase English alphabets.



Output Format

For each test case, print the rank of the given string, separated by a new line.



Constraints

30 points

1 <= T <= 100

1 <= len(str) <= 10



70 points

1 <= T <= 1000

1 <= len(str) <= 20



Example

Input

3

cba

smart

algorithms



Output

6

79

123523



Explanation



Self Explanatory*/


#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    lli t ; cin >> t;
    lli fact[20];

    fact[0] = 1;
    for(lli i = 1; i<20; i++)
        fact[i] = fact[i-1] * i;
    while(t--){

        string s; cin >> s;
        lli N = s.size();
        lli ans  = 1,c;

        for(lli i =0; i<N; i++){
            c = 0;
            for(lli j = i+1; j < N ; j++){
                
                if(s[i] > s[j] && j != i){
                    c++;
                }
                    
            }
            ans += c * fact[N-i-1];
        }
        cout<<ans<<endl;

    }

    return 0;
}

/*

string s  = graphic ;len = 7

no of strings which have 1st character than g => (a,c)*6!==>2 * 6!

there are strings which starts with g and still less than given string "graphic"

Assume string as "raphic"

count of such strings ==> (a,p,h,i,c) ==>5 * 5!

there may be strings that start with "gr" and still less than givens string graphic 

Assume strings as "aphic "

count of such strings -->0(since there are no character after a which are less than "a")

.
.
.
.
.
.





*/