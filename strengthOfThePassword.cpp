#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define rep(i, n) for(ll i = 0; i < n; i++)
void file_in_out(){    
    #ifndef ONLINE_JUDGE
    freopen("//home//ryuk//Documents//cp//input.txt", "r", stdin);
    freopen("//home//ryuk//Documents//cp//output.txt", "w", stdout);
    #endif
}
string _tolower(string s){
	string temp = "";
	rep(i,s.length()){
		if((int)s[i]>=65 && (int)s[i]<=90)
			temp += (s[i]-'A') + 'a';
		else
			temp += s[i];
 	}
 	return temp;
}
void strength(string s){
	s = _tolower(s);
	bool special = false, num = false, alpha = false;
	rep(i,s.length()){
		if((int)s[i]<=122 &&(int)s[i]>=97) alpha = true;
		else if((int)s[i]>=48 && (int)s[i]<=57) num = true;
		else special = true;
	}
	int ans = 0;
	if(special) ans++;
	if(num) ans++;
	if(alpha) ans++;
	if(ans==1)
		cout<<"Password Strength: Weak\n";
	else if(ans==2)
		cout<<"Password Strength: Medium\n";
	else
		cout<<"Password Strength: Strong\n";
}
int main(){
	int tt = clock(); 		
	file_in_out();
	string pt;
	cin>>pt;
	strength(pt);
	cerr << "TIME = " << (double) 1.0 * (clock() - tt) / CLOCKS_PER_SEC << " seconds" << endl;
	return 0;
}