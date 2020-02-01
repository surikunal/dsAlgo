// #include <cmath>
// #include <cstdio>
// #include <vector>
// #include <iostream>
// #include <algorithm>
// using namespace std;


// int main() {
//     int n , c=1 , odd=0 , even=0;
//     cin>>n;
//     if(-10^18<=n && n>=10^18){
//         n=n;
//     }
//     while(n!=0){
//         if(c%2==0){
//             odd+=n%10;
//         }
//         else{
//             even+=n%10;
//         }
//         n/=10;
//         c++;
//     } 
//     cout<<odd<<" "<<even;
//     return 0;
// }
There are few problems with your code like the recursion termination condition:

if(n == 1 && i == 1 )
which is not correct and lead to recurse the function forever and ultimately the program will terminate abnormally.

Moreover, if you fix this condition, you are not going to get the Pascal triangle as output because both the for loops in main() is initializing the loop variable with 1 which will eat up the first column of every row of pascal triangle.

For the terminating condition of recursive function paskal() -

In the function long paskal( int n , int i ), the n is representing the row whereas the i represent the column in that particular row and pascal() function is supposed to calculate the element at a particular location.

A couple of points, in Pascal triangle:

The leftmost and rightmost element of every row is 1.

Every row contains the number of columns same as the row number.

So, I can say -

if(n == i || i == 0) //i.e. if ((row == col) || (col == 0)) return 1;
    return 1;
could be terminating condition of the recursive function.

Collectively, your program will be something like this:

#include <stdio.h>

long paskal(int, int);

int main() {
   int n = 0;
   int m = 0;
   int k = 0;
   int s = 0;
   printf ("Enter number of rows:\n");
   scanf("%d", &n);

   for(k = 0; n >= k; k++) {
            for(s = 0; s < n-k; s++) //Add spaces before each row
                    printf(" ");
            for(m = 0; k >= m; m++) {
                    long f = paskal(k, m);
                    printf("%ld ", f);
            }
            printf("\n");
    }
    return 0;
}

long paskal(int n, int i) {
        if(n == i || i == 0)
                return 1;
        else
                return paskal(n-1, i) + paskal(n-1, i-1);
}