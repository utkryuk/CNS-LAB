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
int main(){
    int tt = clock();         
    file_in_out();
    cout<<"Enter the string to be encrypted using transposition cipher:\n";
    string s,d="";
    cin>>s;
    int n=s.size(),p;
    char a[100][100];
    cout<<"Enter the key for columnar transposition\n";
    cin>>p;
    for(int i=0;i<n;i++){
        a[i/p][i%p]=s[i];
    }
    for(int j=0;j<p;j++)
        for(int i=0;i<=(n-1)/p;i++)
            d+=a[i][j];
    cout<<"The Decrypted string:\n";
    cout<<d<<"\n";
    cerr << "TIME = " << (double) 1.0 * (clock() - tt) / CLOCKS_PER_SEC << " seconds" << endl;
    return 0;
}
