Thuật toán của Kadane:

Khởi tạo:
    max_so_far = 0
    max_ending_here = 0

Vòng lặp cho mỗi phần tử của mảng
  (a) max_ending_here = max_ending_here + a [i]
  (b) if (max_ending_here <0)
            max_ending_here = 0
  (c) if (max_so_far <max_ending_here)
            max_so_far = max_ending_here
trả về max_so_far
Giải thích:
Ý tưởng đơn giản về thuật toán của Kadane là tìm kiếm tất cả các phân đoạn liền kề tích cực của mảng (max_ending_here được sử dụng cho việc này).
 Và theo dõi phân đoạn tiếp giáp tổng tối đa trong số tất cả các phân đoạn tích cực (max_so_far được sử dụng cho việc này).
 Mỗi lần chúng tôi nhận được một tổng dương so sánh nó với max_so_far và cập nhật max_so_far nếu nó lớn hơn max_so_far

    Hãy lấy ví dụ:
    {-2, -3, 4, -1, -2, 1, 5, -3}

    max_so_far = max_ending_here = 0

    cho i = 0, a [0] = -2
    max_ending_here = max_ending_here + (-2)
    Đặt max_ending_here = 0 vì max_ending_here <0

    cho i = 1, a [1] = -3
    max_ending_here = max_ending_here + (-3)
    Đặt max_ending_here = 0 vì max_ending_here <0

    cho i = 2, a [2] = 4
    max_ending_here = max_ending_here + (4)
    max_ending_here = 4
    max_so_far được cập nhật lên 4 vì max_ending_here lớn hơn
    hơn max_so_far là 0 cho đến nay

    cho i = 3, a [3] = -1
    max_ending_here = max_ending_here + (-1)
    max_ending_here = 3

    cho i = 4, a [4] = -2
    max_ending_here = max_ending_here + (-2)
    max_ending_here = 1

    cho i = 5, a [5] = 1
    max_ending_here = max_ending_here + (1)
    max_ending_here = 2

    cho i = 6, a [6] = 5
    max_ending_here = max_ending_here + (5)
    max_ending_here = 7
    max_so_far được cập nhật thành 7 vì max_ending_here là
    lớn hơn max_so_far

    cho i = 7, a [7] = -3
    max_ending_here = max_ending_here + (-3)
    max_ending_here = 4
#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000;
const int minx = -10000;
int a[maxn], n;

void maxSubArray()
{
    int max_so_far = minx,max_ending_now = 0 ;
    int idx_s = 0,idx_e=0,l=0;
    for(int i=0; i<n; i++)
    {
        max_ending_now +=a[i];
        if(max_so_far < max_ending_now)
        {
            max_so_far = max_ending_now;
            idx_s = l;
            idx_e = i;
        }
        if(max_ending_now < 0)
        {
            max_ending_now = 0;
            l = i+1;
        }
    }
    cout << "index stat and index end is "<<idx_s<<" "<<idx_e<<endl;
    cout<<"sum max is:"<<max_so_far;

}
int main()
{
    cin >> n;
    for(int i=0; i<n; i++)  cin >> a[i];
    maxSubArray();
    return 0;
}
