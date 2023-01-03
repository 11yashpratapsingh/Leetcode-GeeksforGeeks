//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	using ll = long long int;
	ll mod = 1e9+7;
	
	ll modpow(ll a, ll b){
	    ll x = 1%mod;
	    a %= mod;
	    while(b){
	        if(b&1){
	            x = (x*a)%mod;
	        }
	         a = (a*a)%mod;
	         b >>= 1;
	    }
	    return x;
	}
	
	ll modinv(ll a){
	    return modpow(a,mod-2);
	}
	
	int compute_value(int n)
	{
	    // Code here
	    ll ncr = 1;
	    ll ans = 2;             // 2 will always be your answer
	    for(int r=1;r<n;r++){
	        ncr = (ncr%mod*(n-r+1)%mod)%mod;
	        ll x = modinv(r);
	        ncr = (ncr%mod*x%mod)%mod;
	        ans = (ans%mod + (ncr%mod*ncr%mod)%mod)%mod;
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.compute_value(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends