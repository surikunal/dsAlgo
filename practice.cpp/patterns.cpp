// #include<iostream>
// #include<vector>
// #include<string>
// using namespace std;
// int fiboPattern(int n)
// {
//     int a=0 , b=1 , sum =0 ;
//     for(int i=0 ; i<n ; i++){
//         for(int j=0 ; j<i ; j++)
//         {
//             a=b;
//             b=sum ;
//             sum=a;
//         }
//     }

// }
// void setQuestion()
// {
//     fiboPattern(5);
// }
// void solve()
// {
//     setQuestion();
// }
// int main(int args , char** argv)
// {
//     solve();
//     return 0 ;
// }
// #include <iostream>
// #include <string>
// using namespace std;

// void towerOfHanoi(int N, char from_rod, char to_rod, char aux_rod)
// {
//     if (N == 1)
//     {
//         cout<<"move disk 1 from "<<from_rod<<" to "<<to_rod<<endl;
//         return;
//     }

//     towerOfHanoi(N - 1, from_rod, aux_rod, to_rod);
//     cout<<"move disk "<<N<<" from "<<from_rod<<" to "<<to_rod<<endl;
//     towerOfHanoi(N - 1, aux_rod, to_rod, from_rod);
// }

// int main(int args, char **argv)
// { //common syntex upto this line
//     // cout<<"hello world\n";
//     // cout<<"whatever";
//     int N = 3;
//     towerOfHanoi(N, 'A', 'C', 'B');
//     return 0;
// }

// #include<stdio.h>

// int main()
// {
//     int i,j,n;

//     printf("Enter the number till which you want prime numbers\n");
//     scanf("%d",&n);

//     printf("Prime numbers are:-\n");
//     for(i=2;i<=n;i++)
//     {
//         int c=0;
//         for(j=1;j<=i;j++)
//         {
//             if(i%j==0)
//             {
//                 c++;
//             }
//         }

//        if(c==2)
//         {
//             printf("%d ",i);
//         }
//     }
// }

// #include <iostream>
// using namespace std;
// int main()
// {
//     // int n=0, m=0;
//     // if(n>0)
//     // if(m>0)
//     // printf("true");
//     // else
//     // printf("false");
//     int n = 5;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= (2 * n); j++)
//         {
//             if (i < j)
//             {
//                 cout << " ";
//             }
//             else
//             {
//                 cout << "*";
//             }
//             if (i <= (2 * n) - j)
//             {
//                 cout << " ";
//             }
//             else
//             {
//                 cout << "*";
//             }
//         }
//         cout << endl;
//     }

//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;
void pattern1(int n)
{
    int i, j, space;
    for (i = 1; i <= n; i++)
    {
        int count = 1;
        for (j = n; j >= i; j--)
        {
            cout << count << " ";
            count++;
        }
        for (space = 2; space < 2 * i - 1; space++)
        {
            cout << "  ";
        }
        if (i == 1)
        {
            count -= 2;
            for (j = n; j > i; j--)
            {
                cout << count << " ";
                count--;
            }
        }
        else
        {
            count--;
            for (j = n; j >= i; j--)
            {
                cout << count << " ";
                count--;
            }
        }
        cout << endl;
    }
}
void pattern2(int n)
{
    int i, j, space;
    for (i = 1; i <= n; i++)
    {
        int count = 1;
        for (j = 1; j <= i; j++)
        {
            cout << count << " ";
            count++;
        }
        for (space = n+2; space >= 2 * i - 1; space--)
        {
            cout << "  ";
        }
        if (i == n)
        {
            count -= 2;
            for (j = 1; j < i; j++)
            {
                cout << count << " ";
                count--;
            }
        }
        else
        {
            count--;
            for (j = 1; j <= i; j++)
            {
                cout << count << " ";
                count--;
            }
        }
        cout << endl;
    }
}
void zeroAndOnes(vector<int>& arr){
    int pt=0;
    int itr=0;

    while(itr<arr.size()){
        if(arr[itr]!=0){
            swap(arr[itr],arr[pt]);     //in cpp , swap function is inbuilt
            pt++;                       //but we have to make it in java
        }
        itr++;
    }
}
int main(){
    vector<int> arr={0, 1, 0, 3, 12};
    zeroAndOnes(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
