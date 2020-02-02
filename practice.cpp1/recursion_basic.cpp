// // #include <iostream>
// // #include <vector>
// // #include <string>
// // #include <climits>
// // using namespace std;
// // int fact(int n)
// // {
// //     if (n <= 1)
// //         return 1;

// //     else
// //     {
// //         return n * fact(n - 1);
// //     }
// // }
// // void incDec(int a, int b)
// // {
// //     if (b == a)
// //     {
// //         cout << a << endl;
// //         return;
// //     }

// //     cout << a << endl;
// //     incDec(a + 1, b);
// //     cout << a << endl;
// // }
// // void incDec1(int a, int b)
// // {
// //     if (b == a)
// //     {
// //         cout << a << endl;
// //         return;
// //     }
// //     if (a % 2 != 0)
// //         cout << a << endl;

// //     incDec1(a + 1, b);

// //     if (a % 2 == 0)
// //         cout << a << endl;
// // }
// // int fibo(int n)
// // {
// //     if (n <= 1)
// //         return n;

// //     int ans = fibo(n - 1) + fibo(n - 2);
// //     return ans;
// // }
// // int power1(int a, int b)
// // {
// //     if (b == 0)
// //         return 1;

// //     int ans = power1(a, b - 1);
// //     return ans * a;
// // }

// // int power2(int a, int b)
// // {
// //     if (b == 0)
// //         return 1;

// //     int ans = power2(a, b / 2);
// //     ans *= ans;

// //     if (b % 2 != 0)
// //         ans *= a;

// //     return ans;
// // }
// // bool find(vector<int> &arr, int idx, int data)
// // {

// //     if (idx == arr.size())
// //         return false;

// //     if (arr[idx] == data)
// //         return true;

// //     bool ans = find(arr, idx + 1, data);
// //     return ans;
// // }
// // int mini(vector<int> &arr, int idx)
// // {
// //     if (idx == arr.size())
// //         return INT_MIN;

// //     if (idx == arr.size() - 1)
// //         return arr[idx];

// //     int ans = mini(arr, idx + 1);
// //     return min(arr[idx], ans);
// // }
// // int maxi(vector<int> &arr, int idx)
// // {
// //     if (idx == arr.size())
// //         return INT_MAX;

// //     if (idx == arr.size() - 1)
// //         return arr[idx];

// //     int ans = maxi(arr, idx + 1);
// //     return max(arr[idx], ans);
// // }
// // int lastidx(vector<int> &arr, int idx, int data)
// // {
// //     if (arr.size() == idx)
// //     {
// //         return -1;
// //     }

// //     int recans = lastidx(arr, idx + 1, data);

// //     if (recans != -1)
// //     {
// //         return recans;
// //     }
// //     else
// //     {
// //         return arr[idx] == data ? idx : -1;
// //     }
// // }
// // vector<int> allidx(vector<int> &arr, int idx, int data, int count)
// // {
// //     if (idx == arr.size())
// //     {
// //         vector<int> base(count);
// //         return base;
// //     }
// //     if (arr[idx] == data)
// //         count++;

// //     vector<int> recans = allidx(arr, idx + 1, data, count);

// //     if (arr[idx] == data)
// //     {
// //         recans[count - 1] = idx;
// //     }
// //     return recans;
// // }
// // void allindex()
// // {
// //     vector<int> arr = {10, 20, 30, 40, 50, 60, 70, 21, 1, 4, 7, 8, 9, 4, 0, 5, 4, 2, 56};
// //     vector<int> ans = allidx(arr, 0, 4, 0);
// //     for (int i : ans)
// //         cout << i << " ";
// // }
// // int nqueenCombi(vector<int> &boxes, int idx, int tnq, int q, string ans)
// // {
// //     if (q == tnq + 1)
// //     {
// //         cout << ans << " ";
// //         return 1;
// //     }
// //     int count = 0;
// //     for (int i = idx; i < boxes.size(); i++)
// //     {
// //         count += nqueenCombi(boxes, idx + 1, tnq, )
// //     }
// // }
// // void setQuestion()
// // {
// //     // cout<<fact(5)<<" ";
// //     // incDec(1,5);
// //     // incDec1(1,10);
// //     // cout<<fibo(4);
// //     // cout<<eular
// //     // cout<<power1(2,5);
// //     // cout<<power2(2,7);
// //     // vector<int> arr={10,20,30,40,50,60,70,21,56};
// //     // cout<<find(arr , 0 , 3);
// //     // cout<<mini(arr,0);
// //     // cout<<maxi(arr,0);
// //     // cout<<lastidx(arr , 0 , 8);
// //     // allindex();
// //     cout << nqueenCombi();
// // }
// // void solve()
// // {
// //     setQuestion();
// // }
// // int main(int args, char **argv)
// // {
//     // solve();
//     // return 0 ;
// // }

// #include <iostream>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     string str;
//     cin >> str;
//     int q;
//     int num;
//     cin >> q;
//     int m, p, l, k;
//     for (int i = 0; i < q; i++)
//     {
//         cin >> m;
//         if (m == 1)
//         {
//             cin >> k;

//             if (str[k] == '0')
//             {
//                 str[k] = '1';
//             }

//             num = stoi(str);
//         }

//         if (m == 0)
//         {
//             cin >> p >> l;
//             string fans;
//             fans = std::string(str.begin() + p, str.begin() + l + 1);

//             cout << fans << endl;
//             num = stoi(fans);
//             int ans;
//             int dec_value = 0;

//             int base = 1;

//             int temp = num;
//             while (temp)
//             {
//                 int last_digit = temp % 10;
//                 temp = temp / 10;

//                 dec_value += last_digit * base;

//                 base = base * 2;
//             }
//             cout << (dec_value % 3) << endl;
//         }
//     }
// }
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string str;
    cin >> str;
    double i;
    cin >> i;
    double num = stoi(str);
    cout << (num / 10);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

