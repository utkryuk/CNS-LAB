#include<bits/stdc++.h>
using namespace std;
//For small letters only
string keyGeneration(int len){
	srand(time(NULL));
	string key="";
	for(int i=0;i<len;i++){
		key+='a'+rand()%26;
	}
	return key;
}
string encode(string pt,string key){
	string ct="";
	for(int i=0;i<pt.length();i++){
		ct+='a'+ ((int)pt[i]-97+(int)key[i]-97)%26;
	}
	return ct;
}
string decode(string ct,string key){
	string pt="";
	for(int i=0;i<ct.length();i++){
		pt+='a'+((int)ct[i]-(int)key[i]+26)%26;
	}
	return pt;
}

bool check(string pt, string chk){
	if(pt.length()==chk.length()){
		for(int i=0;i<pt.length();i++){
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
	string key = keyGeneration(pt.length());
	cout<<"Key Used: "<<key<<"\n";
	string ct = encode(pt,key);
	cout<<"Cipher Text: "<<ct<<"\n";
	string chk = decode(ct,key);
	cout<<"Decoded Cipher Text: "<<chk<<"\n";
	if(check(pt,chk))
		cout<<"One Time Pad Cipher done correctly\n";
	else
		cout<<"One Time Pad Cipher done wrongly\n";
	return 0;
}