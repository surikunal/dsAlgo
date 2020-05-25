/* CODE BY KUNAL SURI FOR THE INTERNSHIP PURPOSE */

#include<iostream>
using namespace std;

void caseChange(string str) {
    string ans;
    for (int i = 0; i < str.size(); i++) {
        int x = (int)(str[i]);
        if (x >= 97 && x <= 122) {
            ans[i] = (char)(x - 32);
        }
        if (x >= 65 && x <= 90) {
            ans[i] = (char)(x + 32);
        }
    }
    
    for (int i = 0; i < str.size(); i++) {
        cout << ans[i];
    }
    cout << endl;
}

int main(int args, char **argv) {
    string str;
    cin >> str;
    caseChange(str);
    return 0;
}
