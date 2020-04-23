#include<bits/stdc++.h>
using namespace std;
//For small letters only
//Extended euclid algo
int d, x, y;
void extendedEuclid(int A, int B) {
    if(B == 0) {
        d = A;
        x = 1;
        y = 0;
    }
    else {
        extendedEuclid(B, A%B);
        int temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}
int modInverse(int A, int M){
    extendedEuclid(A,M);
    return (x%M+M)%M;    //x may be negative
}
string encode(string pt,int k){
	string ct = "";
	for(int i=0;i<signed(pt.length());i++){
		if(pt[i]!=' ')
			ct.push_back('a'+ ((pt[i]-97)*k)%26);
		else
			ct.push_back(pt[i]);
	}
	return ct;
}
string decode(string ct,int k){
	string chk = "";
	int modI = modInverse(k,26);
	cout<<modI<<endl;
	for(int i=0;i<signed(ct.length());i++){
		if(ct[i]!=' ')
			chk.push_back('a' + ((ct[i]-97)*modI)%26);
		else
			chk.push_back(ct[i]);
	}
	return chk;
}
bool check(string pt, string chk){
	if(pt.length()==chk.length()){
		for(int i=0;i<signed(pt.length());i++){
			if(pt[i]!=chk[i]){
				return false;
			}
		}
	}
	else
		return false;

	return true;

}
int main(){
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("//home//ryuk//Desktop//cp//input.txt", "r", stdin);
    // for writing output to output.txt
    //this can be opted out if you want to print the output to the sublime console
    freopen("//home//ryuk//Desktop//cp//output.txt", "w", stdout);
	#endif
	string pt;
	getline(cin>>ws,pt);
	int k;
	cin>>k;
	string ct = encode(pt,k);
	cout<<"Cipher Text: "<<ct<<"\n";
	string chk = decode(ct,k);
	cout<<"Decoded Cipher Text: "<<chk<<"\n";
	if(check(pt,chk))
		cout<<"Multiplicative Cipher done correctly\n";
	else
		cout<<"Multiplicative Cipher done wrongly\n";
	return 0;
}