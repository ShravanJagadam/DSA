/*


Check if the ith bit is set or not */

#include <bits/stdc++.h>
using namespace std; 
typedef long long int lli;


bool checkBit(int N , int i){

    return (N>>i & 1); //or (N & 1<<i  != 0)
}

int main(){


    int N = 8; 
    int i = 2; 
    cout<<checkBit(N,i)<<endl;


    return 0;
}