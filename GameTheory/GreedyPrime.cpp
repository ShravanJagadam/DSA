#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli k = 1e5;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector<bool> sieve(k+1,true);

    sieve[0] = false;
    sieve[1] = false;


    for(lli i = 2; i*i <= k; i++){
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


    lli idx  = 0;// pointing to the prime number "2"
    for(lli i = 3; i<=k; i++){
        
        //subtract the max p ; p is the prime number <=i;
        //maintain an index of the list of prime number for each time to 
        //find the max prime number <= i
        if( idx+1 < prime.size() && i - prime[idx+1]>=0){ //check the index and then access it 
            gameTable[i] = gameTable[i - prime[idx+1] ] ^ 1;//he wins 
            idx++;
        }
        else
            gameTable[i] = gameTable[ i - prime[idx] ] ^ 1;

    }


    /*for(lli i = 0; i<=10; i++)
        cout<<( (gameTable[i] == 1)?"W":"L");
    cout<<endl;*/
    lli t ; cin >> t;

    while(t--){

        lli N; cin >> N;

        cout<<( (gameTable[N] == 1)?"First":"Second" )<<endl;


    }

    return 0;
}