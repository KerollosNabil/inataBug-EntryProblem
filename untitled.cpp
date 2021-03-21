// Example program
#include <iostream>
#include <string>
 using namespace std;
 
 bool prime[1000090 + 1];
 
void SieveOfEratosthenes(int n)
{
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true) 
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }    
}
 
int main()
{
	
	freopen("entry_problem_input.txt", "r", stdin);
	freopen("output.txt", "w", stdout); 
    int n = 1000090;
    
    SieveOfEratosthenes(n);
    prime[1] = false;
    
    int nt ;
    cin >> nt;
    int count = 1;
    string ans = "";
    long long  lastnum ;
    for (int i= 0; i < nt; i++){
        long long num ;
        cin >> num ;
        if (i == 0) {
            lastnum = num;
            continue;
        }
        if (prime[num] == prime[lastnum]){
            count++;
        }
        else{
            ans += to_string(count);
            count = 1;
            if (prime[lastnum] == 1){
                ans += "y";
            }else{
                ans += "n";
            }
        }
        lastnum = num;
    }
    ans += to_string(count);
    count = 1;
    if (prime[lastnum] == 1){
        ans += "y";
    }else{
        ans += "n";
    }
    cout << ans << endl;
    return 0;
}


