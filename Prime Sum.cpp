bool isPrime(int x){
    for(int i = 2 ; i <= sqrt(x) ; i++){
        if(!(x % i))
            return 0;
    }
    return 1;

}

vector<int> Solution::primesum(int A) {
    
    for(int i  = 2 ; i < A ; i++){
        if(isPrime(i) && isPrime(A-i))
            return {i , A-i};
    }

}


------------------------------------------------------------------------


vector<int> ans;

vector<int>sieve(int A) {
    vector<int> serial(A+1);
    vector<bool> visited(A+1 , 0);
    serial.clear();
    visited.clear();

    for(int i = 2 ; i <= A ; i++){
        serial[i] = i;
    }

    for(int i = 2 ; i <= A ; i++){
        if(visited[i])
            continue;
        
        for(int j = 2*i ; j <= A ; j += i)
            visited[j] = 1;
    }

    
    ans.clear();

    for(int i = 2 ; i <= A ; i++){
        if(!visited[i])
            ans.push_back(i);
    }

    serial.clear();
    visited.clear();
    return ans;

}


vector<int> Solution::primesum(int A) {
    ans.clear();
    vector<int> primes;
    primes.clear();
    primes = sieve(A);


    for(auto x:primes){
        bool val = binary_search(primes.begin() , primes.end() , A-x);
        if(val){
            primes.clear();
            ans.clear();
            return {x , A-x};
        }
    }

}


------------------------------------------------------------------------------------------------------------



// C++ program to find a prime number pair whose
// sum is equal to given number
// C++ program to print super primes less than
// or equal to n.
#include<bits/stdc++.h>
using namespace std;
 
// Generate all prime numbers less than n.
bool SieveOfEratosthenes(int n, bool isPrime[])
{
    // Initialize all entries of boolean array
    // as true. A value in isPrime[i] will finally
    // be false if i is Not a prime, else true
    // bool isPrime[n+1];
    isPrime[0] = isPrime[1] = false;
    for (int i=2; i<=n; i++)
        isPrime[i] = true;
 
    for (int p=2; p*p<=n; p++)
    {
        // If isPrime[p] is not changed, then it is
        // a prime
        if (isPrime[p] == true)
        {
            // Update all multiples of p
            for (int i=p*p; i<=n; i += p)
                isPrime[i] = false;
        }
    }
}
 
// Prints a prime pair with given sum
void findPrimePair(int n)
{
    // Generating primes using Sieve
    bool isPrime[n+1];
    SieveOfEratosthenes(n, isPrime);
 
    // Traversing all numbers to find first
    // pair
    for (int i=0; i<n; i++)
    {
        if (isPrime[i] && isPrime[n-i])
        {
            cout << i << " " << (n-i);
            return;
        }
    }
}
 
// Driven program
int main()
{
    int n = 74;
    findPrimePair(n);
    return 0;
}
