#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define N 100

int c[N][N];
int n;
int x[N];       // model solution: x[1] -> x[2] ->...-> x[N] -> x[1]
int f;          // partial distance, accumulated overtime;
int f_best;     // min distance
int visited[N]; // 1 means that the city has been visited
int cm;

void input()
{
    cm = -1000000000; // min value in cost matrix
    scanf("%d", &n);  // number of cities
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &c[i][j]);
            if (i != j && c[i][j] > cm)
                cm = c[i][j];
        }
    }
}
// after input(): we got a n x n cost matrix and cm is the min value in the matrix

void print()
{
    // print cost matrix
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            printf("%3d", c[i][j]);
        printf("\n");
    }
}

void updateBest()
{
    if (f > f_best) // get back to city 1
    {
        f_best = f; // update f_best
        printf("Update Best: ");
        for (int i = 1; i <= n; i++)
            printf("%d -> ", x[i]);        // print solution                   // print
        printf("\nf_best = %d\n", f_best); // print f_best
    }
}

void Try(int k)
{
    for (int v = 1; v <= n; v++)
    {
        if (visited[v] == 0)
        {
            x[k] = v;
            visited[v] = 1;
            f = f + c[x[k - 1]][x[k]]; // accumulated after visiting
            if (k == n)
                updateBest(); // complete
            else
                Try(k + 1);
            visited[v] = 0;
            f -= c[x[k - 1]][x[k]];
        }
    }
}

// void Try_B_B(int k)
// {
//     for (int v = 1; v <= n; v++)
//     {
//         if (visited[v] == 0)
//         {
//             x[k] = v;
//             visited[v] = 1;
//             f = f + c[x[k - 1]][x[k]];
//             if (k == n - 1)
//                 updateBest();
//             else
//             {
//                 // g function
//                 int g = f + cm * (n - k);
//                 if (g < f_best)
//                     Try(k + 1);
//             }
//             visited[v] = 0;
//             f -= c[x[k - 1]][x[k]];
//         }
//     }
// }

int main()
{
    int choice;
    char *filename;
    do
    {
        printf("Chon dau vao\n");
        printf("1. Ban phim\n");
        printf("2. File\n");
        printf("3. Sinh ngau nhien\n");
        printf("4. Thoat\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // userInput();
            break;
        case 2:
            fflush(stdin);
            printf("Nhap ten file\n");
            gets(filename);
            fflush(stdin);
            freopen(filename, "r", stdin);
            input();
            break;
        case 3:
            // randomInput();
            break;
        case 4:
            printf("Goodbye\n");
            exit(1);
            break;
        default:
            printf("Wrong Choice. Enter again\n");
            break;
        }
    } while (!(choice == 1 || choice == 2 || choice == 3 || choice == 4));
    printf("Ma tran chi phi: \n");
    print();
    for (int v = 1; v <= n; v++)
        visited[v] = 0;
    f = 0;
    f_best = -1000000;
    x[1] = 1;
    visited[1] = 1;
    printf("Algorithm flow: \n");
    Try(2);
    return 0;
}