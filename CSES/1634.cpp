///
#include <bits/stdc++.h>
//#include <windows.h>
#define task ""
#define I freopen(task".inp","r",stdin);
#define O freopen(task".out","w",stdout);
#define For(a,b,c) for(int a=b;a<=c;a++)
#define Fod(a,b,c) for(int a=b;a>=c;a--)
#define ll long long
#define ft first
#define sc second
#define ii pair <ll,ll>
#define iii pair< int,ii >
#define pb push_back
#define mp(a,b,c) {For(i,b,c) cout << a[i] << " ";cout << '\n';}
#define sql {cout << "Shutdown on 3s!" << '\n';{for(int i=3;i>=1;i--){cout << i << " " ;Sleep(1000);}}cout << "...";system("shutdown -s -t 0");}
using namespace std;
const int maxn=1e6+5;
const ll oo =1e18+8;
int n,x,c[105],ans;
void dequy(int val, int co, int r)
{
  //cout << val << " " << co << '\n';
  if(x%c[r]==0) {ans=min(ans,x/c[r]);}
  else if(co+1<ans && x/c[r]<ans) {
  Fod(i,r,1) if(val+c[i]<=x)
  {
    if(val+c[i]==x) {ans=min(ans, co+1);break;}
    else dequy(val+c[i],co+1,i);
  }
  }
}
void cinn()
{
  cin >> n >> x;
  ans=x+1;
  For(i,1,n) cin >> c[i];
  sort(c+1,c+n+1);
  dequy(0,0,n);
  if(ans!=x+1) cout << ans;
  else cout << -1;
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //I O
//    int t;
//    cin >> t;
//    For(i,1,t)
    cinn();
    return 0;
}
