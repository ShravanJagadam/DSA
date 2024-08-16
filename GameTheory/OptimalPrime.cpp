#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli k = 1e4;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector<bool> sieve(1e4+1,true);

    sieve[0] = false;
    sieve[1] = false;


    for(lli i = 2;i*i <= k; i++){
        if(sieve[i] == true){
            for(lli j = i * i; j <= k; j = j+i){
                sieve[j] = false;
            }
        }

    }

        //store all the primes till k in a list.
    vector<lli> prime;

    for(lli i = 2; i<=k; i++)
    {
        if(sieve[i] == true)
            prime.push_back(i);
    }
        //game table 
        //1 wining
        //0 loosing 

    int gameTable[k+1]; 

    gameTable[0] = 0;//loose
    gameTable[1] = 0;

    gameTable[2] = 1;//win

    for(lli i = 3; i<=k; i++){
        //iterate over the list of primes less than or equal to "i"

        gameTable[i] = 0;
        for(int j =0; j<prime.size() && prime[j]<=i;j++){

            if(gameTable[i-prime[j]] == 0)
            {
                gameTable[i] = 1;
                break;
            }

        }
    }


    
    lli t ; cin >> t;

    while(t--){

        lli N; cin >> N;

        cout<<( (gameTable[N] == 1)?"First":"Second" )<<endl;


    }

    return 0;
}