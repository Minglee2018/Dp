#include <bits/stdc++.h>
using namespace std;
#define sfor(ii,x) for(set<int> ::iterator ii = x.begin();ii != x.end();ii++)
#define For(i,x,y) for(int i=x; i<y; i++)
#define Rep(i,x,y) for(int i=y-1; i>=x; i--)
#define sc1(x) scanf("%d%",&x);
#define sc2(x,y) scanf("%d%d",&x,&y);
#define sc3(x,y,z) scanf("%d%d%d",&x,&y,&z);
#define prec(n) fixed<<setprecision(n)
#define ll long long
#define endl() printf("\n");
const int maxn = 5e3+7;
const int unlimit = 9e8+9;
int a[maxn][maxn], c[maxn][maxn], d[maxn];
bool oke[maxn];
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
void print_err(int *p,int x,int y){For(i,x,y) cout<<p[i]<<" ";cout<<"\n";}
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int T,cnt=1;  sc1(T);
    while(T--)
    {

        int n,m,F;  sc2(n,m);
        For(u,0,n) For(v,0,n) c[u][v] = c[v][u] = 0,a[u][v] = a[v][u] = 0;
        For(i,1,m+1)
        {
            int u,v,w;
            sc3(u,v,w);
            if(a[u][v]==1)
            {
                c[u][v] = min(c[u][v],w);
                c[v][u] = c[u][v];
            }
            else
            {
                c[u][v]=w;
                c[v][u]=w;
            }
            a[u][v] = 1;
            a[v][u] = 1;
        }
        sc1(F);
        For(u,0,n)
        {
            if(a[u][F]==1)  d[u] = c[u][F];
            else
                d[u] = unlimit;
        }
        d[F]=0;
        For(i,0,n)  oke[i] = true;
        //print_err(d,0,n);

        For(u,0,n)
        {
            int now = 0,x = unlimit;
            For(v,0,n)
            {
                if(d[v]<x && d[v]!=unlimit && oke[v] && v!=F)
                    now = v,x = d[v];
            }
            oke[now] = false;
            //cout<<"ver "<<now<<" val->"<<d[now]<<"\n";
            if(now == F)    break;
            For(v,0,n)
            {
                if(d[v] > max(d[now],c[v][now]) && oke[v] && a[now][v] == 1)
                    //cout<<d[v]<<" "<<d[now]<<" "<<c[v][now]<<" "<<v<<"\n",
                    d[v] = max(d[now],c[v][now]);
            }
        }
        //print_err(d,0,n);
        printf("Case %d:\n",cnt++);
        For(v,0,n)
        {
            if(d[v] != unlimit)
                printf("%d",d[v]);
            else
                printf("Impossible");
            endl();
            d[v] = unlimit;
        }
    }
    return 0;
}
