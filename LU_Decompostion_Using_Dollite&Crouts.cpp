#include<bits/stdc++.h>
#include<unordered_set>
#include<cstring>
using namespace std;
#define int            long long int
#define F              first
#define S              secon
#define pb             push_back
#define endl           "\n"
#define print(a)       for(auto x : a) cout << x << " "; cout << endl
#define cin(a,n)       for(int i=0;i<n;i++)cin>>a[i];

int mod=1e9+7;


void solve(){
  int n;
  cin>>n;
  char method;
  cin>>method;
  vector<vector<double>> mat(n,vector<double>(n));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>mat[i][j];
    }
  }
  vector<vector<double>> l(n,vector<double>(n,0)),u(n,vector<double>(n,0));
  for(int i=0;i<n;i++){
    if(method=='L')l[i][i]=1;
    if(method=='U')u[i][i]=1;
  }
  if(method=='L')u[0][0]=(double)mat[0][0]/l[0][0];
  else l[0][0]=(double)mat[0][0]/u[0][0];
  for(int j=1;j<n;j++){
    u[0][j]=(double)mat[0][j]/l[0][0];
    l[j][0]=(double)mat[j][0]/u[0][0];
  }
  for(int i=1;i<n-1;i++){
    double sum=0;
    for(int k=0;k<=i-1;k++){
      sum+=l[i][k]*u[k][i];
    }
    if(mat[i][i]==sum){
      cout<<"DECOMPOSITION NO POSSIBLE"<<endl;
      return;
    }
    if(method=='L')u[i][i]=mat[i][i]-sum;
    else l[i][i]=mat[i][i]-sum;

    for(int j=i+1;j<n;j++){
      double sum1=0,sum2=0;
      for(int k=0;k<=i-1;k++){
          sum1+=l[i][k]*u[k][j];
          sum2+=l[j][k]*u[k][i];
      }
      u[i][j]=(mat[i][j]-sum1)/l[i][i];
      l[j][i]=(mat[j][i]-sum2)/u[i][i];
    }
  }
  double temp=0;
  for(int k=0;k<n-1;k++){
    temp+=l[n-1][k]*u[k][n-1];
  }
  if(method=='L')u[n-1][n-1]=mat[n-1][n-1]-temp;
  else l[n-1][n-1]=mat[n-1][n-1]-temp;

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout<<l[i][j]<<" ";
    }
    cout<<endl;
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout<<u[i][j]<<" ";
    }
    cout<<endl;
  }
 }

int32_t main(){
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  int t=1;
  // cin>>t;
  while(t--){solve();}
}
