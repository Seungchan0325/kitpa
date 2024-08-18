#include <bits/stdc++.h>

using namespace std;

string board[10][10];

int main()
{
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cin >> board[i][j];
        }
    }
    
    for(int i = 0; i < 10; i++) {
        bool flag = true;
        for(int j = 0; j < 10; j++) {
            if(board[i][j] != board[i][0]) {flag = false; break;}
        }
        if(flag) goto SUCCESS;
    }

    for(int i = 0; i < 10; i++) {
        bool flag = true;
        for(int j = 0; j < 10; j++) {
            if(board[j][i] != board[0][i]) {flag = false; break;}
        }
        if(flag) goto SUCCESS;
    }

    cout << 0;
    return 0;
SUCCESS:
    cout << 1;
    return 0;
}