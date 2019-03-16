#include <bits/stdc++.h>
using namespace std;
#define sfor(ii,x) for(set<int> ::iterator ii = x.begin();ii != x.end();ii++)
#define mulfor(ii,x) for(multiset <int> ::iterator ii = x.begin();ii != x.end();ii++)
#define remulfor(ii,x) for(multiset<int>::reverse_iterator ii = x.rbegin(); ii!= x.rend(); ii++)
#define sync() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define For(i,x,y) for(int i=x; i<y; i++)
#define Rep(i,x,y) for(int i=y-1; i>=x; i--)
#define sc1(x) scanf("%d%",&x);
#define sc2(x,y) scanf("%d%d",&x,&y);
#define sc3(x,y,z) scanf("%d%d%d",&x,&y,&z);
#define prec(n) fixed<<setprecision(n)
#define ll long long
#define endl() printf("\n");
#define w first
#define val second
const int maxn = 1e4+7;
const int maxx = 5e5+7;
const int unlimit = 9e8+9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
void print_err(int *p,int x,int y){For(i,x,y) cout<<p[i]<<" ";cout<<"\n";}
void err(int pz){pz==1?puts("YES"):puts("NO");exit(0);}

//--------------------Chuyen de Dyamic Program---------------------------

int dp[maxn][maxn],n,m,b[maxx],s,p[maxn];
pair <int,int> a[maxn];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

//--------------- bài toán đồng xu
//Bắt đầu với bài toán con 0 ta có dp(0) = 0
//Với bài toán con 1, có 1 đồng xu (nặng 1) có thể thêm vào từ 0 đồng xu nào cả. Vậy dp(1) = dp(0) + 1 = 1.
//Với bài toán con 2, cũng chỉ có 1 đồng xu (nặng 1) có thể thêm vào từ 1 đồng xu. Vậy dp(2) = dp(1) + 1 = 2.
//Với bài toán con 3, chúng ta có thể thêm 1 đồng xu 3 vào 0 đồng xu hoặc thêm 1 đồng xu 1 vào 2 đồng xu.
//Rõ ràng là cách đầu tiên cho kết quả nhỏ hơn.
//Vậy dp(3) = min(dp(2) + 1, dp(0) + 1) = min(3, 1) = 1

    cin >> n >> s;
    For(i,0,n)  cin >> b[i];
    p[0] = 0;
    For(i,1,s+1){
        For(j,0,n)
        {
            if(b[j]<=i)
                p[i] = min(p[i-1]+1,p[i-b[j]]+1);
        }
    }
    For(i,0,s+1)  cout<<p[i]<<" ";
//# Nếu đầu vào như sau: n = 3, S = 11, w = [1, 3, 5]
//# Thì bảng lời giải cho các bài toán con sẽ lần lượt như sau:
//# P = 0 |1 |2 |3 |4 |5 |6 |7 |8 |9 |10|11
//# ------+--+--+--+--+--+--+--+--+--+--+--
//# k = 0 |1 |2 |1 |2 |1 |2 |3 |2 |3 |2 |3

//----------bai toán xóa và kiếm điểm-------------------------------------

//Cho một mảng số nguyên nums, bạn có thể thực hiện những thao tác sau đây trên mảng:Chọn một số nums[i] bất kỳ thì để kiếm được nums[i] điểm.Đồng thời cũng phải xóa đi tất cả các giá trị nums[i] - 1hoặc nums[i] + 1
// ngay sau đó.
//Ban đầu bạn có 0 điểm, cho biết số điểm cao nhất mà bạn có thể kiếm được.
//Ví dụ 1:
//Input: nums = [3, 4, 2]
//Output: 6
//Chọn 4 để kiếm 4 điểm, như vậy 3 sẽ bị xóa.
//Tiếp theo, chọn 2 để kiếm 2 điểm. Như vậy tổng cộng kiếm được 6 điểm.
//Ví dụ 2:
//Input: nums = [2, 2, 3, 3, 3, 4]
//Output: 9
//Đầu tiên, chọn 3 để kiếm được 9 điểm, như vậy tất cả các phần tử có giá trị 2 và 4 đều sẽ bị xóa.
//Lưu ý:
//Độ dài tối đa của nums là 20000 .Mỗi phần tử nums[i] là một số nguyên trong phạm vi [1,10000]
//công thức truy hồi. xét tử phần tử 10000 ta có
//F(10000) =  10000*n1 + 9998*n2; max(F(n)+ F(n-2)...,F(n-1)+F(n-3)+...,F(n-2)+F(n-4)...)
    int n,size=0;  cin >> n;
    For(i,0,n)
    {
        int x;  cin >> x;
        b[x]++;
        size=max(size,x);
    }
    ll ans = 0;
    for(int i = size; i>=1; i--)
    {
        ll sum = 0;
        for(int j = i; j>=1; j-=2){
            sum +=b[j]*j;
        }
        ans = max(ans,sum);
    }
    cout << ans << "\n";
////------------------------------cai ba lo-----------------------------
//nhập vào n số lượng đồ vật và m khối lượng tối đa cần tìm.
//n dòng tiếp theo nhập vào 2 giá trị là khối lượng w và giá trị val
//dựa vào bảng kết quả xd yêu cầu cần tìm.

    cin >> n >>m;
    For(i,1,n+1)  cin >> a[i].w >> a[i].val; // w la can nang----val gia tri--.

    int r=0;
    For(i,0,n+1){
        For(j,0,m+1){
            int k =0;
            if(j>=a[i].w) k=i; // kiem tra vs j la can nang
            dp[i][j] = max(dp[max(0,i-1)][j],a[k].val + dp[max(0,i-1)][max(0,j-a[i].w)]);
           cout<<dp[i][j]<<setw(3);
        }
        cout<<endl;
    }
    cout << dp[n][m];
//// -- input n la so can nang va gia tri tuong ung
//// -- m la so can nang toi da co the co'
//n = 5 , m = 15
//12 4
//2 2
//1 1
//1 2
//4 10
//công thức truy hồi:
//    nếu dp[i][j] = dp[i-1][j]               khi không chọn vật thứ i
//    nếu dp[i][j] = v[i] + dp[i-1][j-w[i]]   khi chọn vật thứ i khi w[i]<j;
    ////---------output------bang ket qua------------
//0  0  0  0  0  0   0  0  0  0   0  0  0  0  0  0
//0  0  0  0  0  0   0  0  0  0   0  0  4  4  4  4
//0  0  2  2  2  2   2  2  2  2   2  2  4  4  6  6
//0  1  2  3  3  3   3  3  3  3   3  3  4  5  6  7
//0  2  3  4  5  5   5  5  5  5   5  5  5  6  7  8
//0  2  3  4 10 12  13 14 15  15  15 15 15 15 15 15
//
// ans = 15

    return 0;
}



