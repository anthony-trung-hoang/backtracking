#include <bits/stdc++.h>
using namespace std;
#define N 100

int n;
int x[N]; // x[i]: con hau duoc xep o cot thu i, hang thu x[i]
int flag[N];
int chessBoard[N][N];
const char BLACK = 219;
const char WHITE = 32;
const int SIZE = 8;
const int BLOCK = 5;

int count_sol = 1;

void printChessboard()
{
    cout << "Solution " << count_sol << ":" << endl
         << endl;
    count_sol++;
    for (int i = 1; i <= n; i++) // set ban co ve toan so 0
        for (int j = 1; j <= n; j++)
            chessBoard[i][j] = 0;

    for (int i = 1; i <= n; i++)
        chessBoard[x[i]][i] = 1; // cho nao dat hau thi danh so 1

    for (int i = 1; i <= n; i++)
    {
        for (int u = 1; u <= 3; u++)
        {
            for (int j = 1; j <= n; j++)
            {
                int c = (i + j) & 1;
                if (c == 1)
                {
                    for (int k = 1; k <= 7; k++)
                    {
                        if ((chessBoard[i][j]) == 1)
                        {
                            if (u == 2 && (k == 4))
                                cout << "Q";
                            else
                            {
                                cout << BLACK;
                            }
                        }
                        else
                        {
                            cout << BLACK;
                        }
                    }
                }
                else
                {
                    for (int k = 1; k <= 7; k++)
                    {
                        if ((chessBoard[i][j]) == 1)
                        {
                            if (u == 2 && (k == 4))
                                cout << "Q";
                            else
                            {
                                cout << WHITE;
                            }
                        }
                        else
                        {
                            cout << WHITE;
                        }
                    }
                }
            }
            cout << endl;
        }
    }

    cout << "-----------------------------" << endl;
}

int check(int v, int k)
{
    for (int i = 1; i < k; i++) // check nhung quan hau o cot 1 -> k-1
        if ((v == x[i]) || (fabs(v - x[i]) == k - i))
            return 0;
    return 1;
}

void Try(int k)
{
    for (int v = 1; v <= n; v++)
    {
        if (check(v, k))
        {
            x[k] = v;
            if (k == n)
                printChessboard();
            else
                Try(k + 1);
        }
    }
}

int main()
{
    cout << "Nhap kich co ban co: " << endl;
    cin >> n;
    cout << "-----------------------------" << endl;
    Try(1);
}
