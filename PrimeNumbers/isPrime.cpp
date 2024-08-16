    #include<bits/stdc++.h>
    using namespace std;
    typedef long long int lli;

    bool isPrime(lli N){

        if(N <= 1) return false;

        if(N == 2 || N == 3) return true;

        if(N % 2  == 0 || N%3 == 0) return false;


        //start from five and go till root N ;
        //At each iteartion check for i and i+2    
        //say i = 5, check for 5 & 7 and increment i by 6 at each itearation,
        //essentially we are checking for all prime numbers less than equal to root N,
        //can they be divisors of N
        // 5(i) 7, 11(i+6) 13, 17 19,
        lli i = 5; 

        while(i * i <= N){

            if(N% i == 0 || N%(i+2) == 0)  return false;
            
            i = i+6;
                
        }
        return true;
    }


    int main(){
        
        lli t; cin >> t;

        while(t--){

            
            lli N; cin >> N;

            if(isPrime(N))
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }

    }
    //This approach ensures that you check divisibility only for potential prime factors,
    //making it efficient even for large numbers close to 

    