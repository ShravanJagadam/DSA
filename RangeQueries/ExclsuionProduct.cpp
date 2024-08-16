#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli k = 1e9+7;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    lli t ; cin >> t;

    while(t--){

        lli N; cin >> N;
        vector<int> ar(N);
        lli prod = 1;
        lli cnt0 = 0;
        for(lli i =0;i<N; i++) {
            cin >> ar[i];
            if(ar[i] > 0)
                prod = (prod * ar[i])%k;
            else 
                cnt0++;
        }

        vector<lli> prefProd(N,1);
        vector<lli> suffProd(N,1);


        prefProd[0] = ar[0];
        for(lli i =1;i<N; i++)
            prefProd[i] = (prefProd[i-1]*ar[i])%k;
        
        
        
        

        suffProd[N-1] = ar[N-1];
        for(lli i =N-2;i>=0; i--)
            suffProd[i] = (suffProd[i+1]*ar[i])%k;

        

        //At each idx we can do prod /ar[i], but this doesnt work when 
        //ar[i] = 0;
        //If there is 1 zero in the given array 
        //All the elements become 0 , after updating, expect this element 
        //2.If there are more than 1 zeroes 
        //All the elements become zero after updating
        if(cnt0 == 1){
            for(lli i =0;i<N; i++){
                if(ar[i] == 0)
                    cout<<prod<<" ";
                else    
                    cout<<0<<" ";
            }

        } else if(cnt0 > 1){
            for(lli i =0;i<N; i++){
                cout<<0<<" ";
            }

        }else
        {
            cout<<suffProd[1]<<" ";
            for(lli i =1; i<N-1; i++){
                //cout<< prod/ar[i]<<" ";//division over mod is complex hence we used prefix prod and suff prod
                cout<<(prefProd[i-1] * suffProd[i+1])%k<<" ";
            }
            cout<<prefProd[N-2]<<" ";
        }  
        cout<<endl;
    }
    return 0;
}