/*
Leetcode : 22
22. Generate Parentheses
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8
*/

class Solution {

public:
    void solve(int n, int op, int cl,string curr,vector<string> &res){

        if(op + cl == n){
            res.push_back(curr);
            return;
        }
        if(op < n/2){//always prioritize keeping and "(" until op<n/2;
            
            solve(n,op+1,cl,curr+"(",res);
        }
        if(cl <op){
            solve(n,op,cl+1,curr+")",res);
        }
    }
    vector<string> generateParenthesis(int n) {

        vector<string> res;
        int op =1, cl=0;// count of opening and count of closing
        solve(2*n,op,cl,"(",res);
        return res;
    }
};

/*
Approach : 
1.We prioritize keeping an opening brack until its count is less than n/2
2.Then whenever the count of closing is less than opening then we place a closing bracket
*/