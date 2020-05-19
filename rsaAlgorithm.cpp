#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define rep(i, n) for(ll i = 0; i < n; i++)
class RSA{
private:
	ll p,q,e,d;
public:
	RSA(ll P,ll Q){
		p = P;
		q = Q;
	}
	ll gcd(ll a,ll b){
		if(a==0)
			return b;
		else
			return gcd(b%a, a);
	}
	ll inv(ll a, ll m){ 
	    ll m0 = m, t, q; 
	    ll x0 = 0, x1 = 1;
	    if (m == 1) 
	       return 0; 
	    while (a > 1){
	        q = a / m;   
	        t = m;
	        m = a % m, a = t;
	        t = x0;
	        x0 = x1 - q * x0;
	        x1 = t; 
	    } 
	    if (x1 < 0)
	       x1 += m0;  
	    return x1; 
	}
	ll modularExponentiation(ll x,ll n,ll m){
    if(n==0)
        return 1;
    else if(n%2 == 0)
        return modularExponentiation((x*x)%m,n/2,m);
    else
        return (x*modularExponentiation((x*x)%m,(n-1)/2,m))%m;
}
	void calcEAndD(){
		ll phi = (p-1)*(q-1);
		for(ll i=2;i<phi;i++){
			if(gcd(i,phi)==1){
				e = i;
				break;
			}
		}
		d = inv(e,phi);
	}
	ll publicKey(){
		return e;
	}
	ll privateKey(){
		return d;
	}
	ll encoder(ll msg){
		return modularExponentiation(msg, e, p*q);
	}
	ll decoder(ll msg){
		return modularExponentiation(msg, d, p*q);
	}
};
void file_in_out(){    
    #ifndef ONLINE_JUDGE
    freopen("//home//ryuk//Documents//cp//input.txt", "r", stdin);
    freopen("//home//ryuk//Documents//cp//output.txt", "w", stdout);
    #endif
}
int main(){
	file_in_out();
	cout<<"Key Generation in RSA Algorithm:\n";
	ll p,q;
	//p,q must be prime
	cin>>p>>q;
	RSA* obj = new RSA(p,q);
	obj->calcEAndD();
	ll e,d, n = p*q;
	e = obj->publicKey();
	d = obj->privateKey();
	cout<<"Public Key = {"<<e<<", "<<n<<"}\n";
	cout<<"Private Key = {"<<d<<", "<<n<<"}\n";
	cout<<"Key Generation Complete\n";
	ll msg, ct;
	cin>>msg;
	cout<<"Message: "<<msg<<"\n";
	ct = obj->encoder(msg);
	cout<<"Encrypted Message: "<<ct<<"\n";
	cout<<"Decrypted Message: "<<obj->decoder(ct)<<"\n";
	return 0;
}