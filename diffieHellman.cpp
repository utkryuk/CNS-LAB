#include<bits/stdc++.h>
#define ll long long int
using namespace std;
class Diffie{
private:
	ll private_key;
	ll public_key;
public:
	Diffie(ll pr_key){
		private_key = pr_key;
	}
	static ll modExp(ll a,ll b, ll m);
	ll primitiveRoot(ll n);
	ll returnPublicKey(ll a, ll q){
		public_key =  modExp(a,private_key,q);
		return public_key;
	}
	ll secretKey(ll pub, ll q){
		return modExp(pub, private_key, q);
	}
};
ll Diffie::modExp(ll a, ll b, ll m){
	if(b==0)
		return 1;
	if(b%2==0)
		return modExp((a*a)%m, b/2, m);
	else
		return (a*modExp((a*a)%m, (b-1)/2, m))%m;
}
ll primitiveRoot(ll n){
	ll phi = n-1, store_phi = phi;
	vector<ll> fact;
	for(int i=2;i*i<=phi;i++){
		if(phi%i==0)
			fact.push_back(i);
		while(phi%i==0)
			phi = phi/i;
	}
	if(phi>1)
		fact.push_back(phi);
	for(int i=0;i<signed(fact.size());i++)
		fact[i] = store_phi/fact[i];

	for(int i=2;i<n;i++){
		bool chk = true;
		for(int j=0;j<signed(fact.size());j++){
			if(Diffie::modExp(i,fact[j],n) == 1){ //we need name of the class for calling the static function
				chk = false;
				break;
			}
		}
		if(chk)
			return i; //returns lowest primitive root
	}
	return -1;
}
int main(){
	freopen("..//input.txt","r",stdin);
	freopen("..//output.txt","w",stdout);
	srand(time(NULL));
	ll q,a;
	//q will always be a prime number
	cin>>q;
	a = primitiveRoot(q);
	Diffie* userA = new Diffie(1 + rand()%(q-1));
	Diffie* userB = new Diffie(1 + rand()%(q-1));
	ll publicA = userA->returnPublicKey(a,q);
	ll publicB = userB->returnPublicKey(a,q);
	ll secretKeyA = userA->secretKey(publicB, q);
	ll secretKeyB = userB->secretKey(publicA, q);
	cout<<"Public Key A = "<<publicA<<"\n";
	cout<<"Public Key B = "<<publicB<<"\n";
	cout<<"Secret Key A = "<<secretKeyA<<"\n";
	cout<<"Secret Key B = "<<secretKeyB<<"\n";
	if(secretKeyA==secretKeyB)
		cout<<"Key Exchange Algorithm is successful\n";
	else
		cout<<"Key Exhange Algorithm failed\n";
	return 0;
}