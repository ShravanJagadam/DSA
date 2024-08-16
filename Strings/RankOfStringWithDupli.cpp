/*Rank of String with Duplicates 
Given a string that can have duplicate characters, find its rank (position) in all the permutations of the string when sorted lexicographically.



Input Format

The first line of input contains T - the number of test cases. It's followed by T lines, each containing a single string consisting of only lowercase English alphabets.



Output Format

For each test case, print the rank of the given string, separated by a new line.



Constraints

30 points

1 <= T <= 100

1 <= len(str) <= 10



120 points

1 <= T <= 1000

1 <= len(str) <= 20



Example

Input

2

data

structures



Output

8

120333



Explanation



Self Explanatory */

#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    lli t ; cin >> t;
    lli fact[20];
    fact[0] = 1;
    for(lli i =1; i<20; i++)
        fact[i] = fact[i-1] * i;

    while(t--){

        string s ; cin >> s;

        unordered_map<char,lli> mp;

        for(int i = 0; i < s.size(); i++)
            mp[s[i]]++;
        lli res  = 0;

        for(lli i =0;i<s.size(); i++){

            
            
            //get the no of smaller char than current char on the right side
            lli ans = 0;
            int c  = 0;
            for(int j = i+1; j < s.size(); j++){
                if(s[j] < s[i])
                    c++;
            }

            ans = (c * fact[s.size()-i-1]);
            //iterate over the map and handle the duplicates
            lli fac  = 1;
            for(auto it : mp){

                int val = it.second;
                fac = fac   * fact[val];
            }

            ans = ans/fac;
            res += ans;
            mp[s[i]]--;
            if(mp[s[i]] == 0)   mp.erase(s[i]);

        }
        cout<<res+1<<endl;
    }

    return 0;
}




/*
Approach : 
for each character s[i], we compute the no of characters less than s[i],
on the right side, say "k"

Hence no of permuatations which can have a smaller character at index "i"

k * (N-i-1)!

But there are duplicates also on the right of index "i"(inclduign character at index "i")

Say we have 3 duplicate characters with frequency f1,f2,f3

Hence no of permuatations will decrease by a factor f1! * f2! * f3!

for index "i", ans is ( k * (n-i-1)!  )/(f1! * f2! * f3!)

*/















