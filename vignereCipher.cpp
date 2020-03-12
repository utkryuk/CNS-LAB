/******************************************
* AUTHOR : UTKARSH GUPTA *
* NICK : not_a_cp_coder *
* INSTITUTION : BIT MESRA *
******************************************/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
string keyCalc(string pt,string key){
	int cnt = 0;
	for(int i=key.length()-1;i<pt.length();i++){
//		cout<<(int)(key[(cnt)%key.length()]-97)<<" ";
		key+=key[(cnt++)%key.length()];
	}
	return key;
}
string encrypt(string pt,string key){
	string ct="";
	for(int i=0;i<pt.length();i++){
//		cout<<((int)pt[i]-97+(int)key[i]-97)%26<<" ";
		ct+='a'+ ((int)pt[i]-97+(int)key[i]-97)%26;
	}
	return ct;
}
string decrypt(string ct,string key){
	string pt="";
	for(int i=0;i<ct.length();i++){
//		cout<<((int)ct[i]-97-(int)key[i]+97+26)%26<<" ";
		pt+='a'+((int)ct[i]-(int)key[i]+26)%26;
	}
	return pt;
}
int main() {
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//ios_base& scientific (ios_base& str);

	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("//home//ryuk//Desktop//cp//input.txt", "r", stdin);
    // for writing output to output.txt
    //this can be opted out if you want to print the output to the sublime console
    freopen("//home//ryuk//Desktop//cp//output.txt", "w", stdout);
	#endif
	string pt;
	getline(cin,pt);
	string key;
	getline(cin,key);
	key = keyCalc(pt,key);
	string ct = encrypt(pt,key);
	cout<<"Encrypted String:"<<ct<<"\n";
	string chk = decrypt(ct,key);
	cout<<"Decrypted String:"<<chk<<"\n";
	bool ans=true;
	rep(i,pt.length()){
		if(pt[i]!=chk[i]){
			ans=false;
			break;
		}
	}
	if(ans)
		cout<<"Encryption and Decryption done is right.\n";
	else
		cout<<"Encryption and Decryption done is wrong.\n";
	return 0;
}