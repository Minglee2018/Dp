#include <bits/stdc++.h>




với một mảng arr [] của N số nguyên và một số nguyên K .
Nhiệm vụ là tìm tổng mảng phụ tối đa bằng cách lật các dấu hiệu của hầu hết các phần tử mảng K.

Ví dụ:

Đầu vào: Array [] = {-6, 2, -1, -1000, 2}, k = 2
Kết quả: 1009
Chúng ta có thể lật các dấu của -6 và -1000, để có được tổng số phụ tối đa là 1009

Đầu vào: Array [] = {-1, -2, -100, -10}, k = 1
Đầu ra: 100
Chúng ta chỉ có thể lật dấu -100 để nhận 100

Đầu vào: {1, 2, 100, 10}, k = 1
Đầu ra: 113
Chúng ta không cần phải lật bất kỳ yếu tố nào
Cách tiếp cận: Vấn đề có thể được giải quyết bằng Lập trình động . Đặt dp [i] [j] là tổng mảng con tối đa từ chỉ số i với j flips.
Một hàm đệ quy có thể được viết để giải quyết vấn đề và
chúng ta có thể ghi nhớ nó để tránh nhiều lệnh gọi hàm. Hàm DP đệ quy (findSubarraySum (ind, flips)) sẽ được gọi từ mọi chỉ mục với số lần lật ban đầu là 0.

ans = max (0, a [ind] + findSubarraySum (ind + 1, flips, n, a, k))
ans = max (ans, -a [ind] + findSubarraySum (ind + 1, flips + 1, n, a, k))
Nếu giá trị âm, chúng ta sẽ thay thế nó bằng 0, tương tự như chúng ta làm trong thuật toán của Kadane.

Hàm đệ quy sẽ có hai trạng thái, một trạng thái sẽ là nếu chúng ta lật chỉ số thứ i.
Cái thứ hai nếu chúng ta không lật chỉ số thứ i. Các trường hợp cơ bản là nếu ind == n, khi chúng ta đã hoàn thành một giao dịch cho đến chỉ mục cuối cùng.
Chúng ta có thể sử dụng ghi nhớ để lưu trữ các kết quả có thể được sử dụng sau này để tránh nhiều lệnh gọi cùng chức năng.
Tối đa của tất cả dp [i] [0] sẽ là câu trả lời của chúng tôi.

using namespace std;
const int N = 10101;
const int K = 50;
int dp[N][K];

int Findsubarray(int i,int flips, int n, int a[],int k)
{
    if(flips > k)
        return -1e9;
    if(i == n)
        return 0;

    if(dp[i][flips]!=-1)
        return dp[i][flips];

    int ans = 0;
    ans = max(0, a[i] + Findsubarray( i+1, flips, n, a, k));
    ans = max(ans, -a[i]+ Findsubarray( i+1, flips+1, n, a, k));
    return dp[i][flips] = ans;
}
void FindMax(int a[], int n, int k)
{
    memset(dp, -1, sizeof(dp));
    int sum = -1e9;
    for(int i=0; i<n; i++)
    {
        sum = max(sum , Findsubarray( i, 0, n, a, k));
    }
    cout <<" \n "<< sum << "\n ";
}

int main()
{
    int n,k;
    cin >> n >> k;
    int a[n+1];
    for(int i=0; i<n; i++)  cin >> a[i];

    FindMax(a,n,k);

    return 0;
}
