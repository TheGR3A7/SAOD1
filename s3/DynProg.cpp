#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


bool canFormIncreasingSeq(int** sets, int m, int n) 
{
    bool** dp = (bool**)malloc(m * sizeof(bool*));
    for (int i = 0; i < m; i++) {
        dp[i] = (bool*)malloc(n * sizeof(bool));
    }

   
    for (int j = 0; j < n; j++) {
        dp[0][j] = true; 
    }

    for (int i = 1; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            dp[i][j] = false;
            for (int k = 0; k < n; k++) 
            {
                if (sets[i][j] > sets[i - 1][k] && dp[i - 1][k]) 
                {
                    dp[i][j] = true;
                    break;
                }
            }
        }
    }


    for (int j = 0; j < n; j++) {
        if (dp[m - 1][j]) {
            free(dp);
            return true;
        }
    }

    free(dp);
    return false;
}

int main2() 
{ 
    system("chcp 1251");
    int m, n;

    do {
        printf("������� ���������� ������� (m): "); scanf("%d", &m);
    } while (m < 2);

    do {
        printf("������� ���������� ����� � ������ ������ (n): "); scanf("%d", &n);
    } while (n < 2);

    int** sets = (int**)malloc(m * sizeof(int*));

    for (int i = 0; i < m; i++) {
        sets[i] = (int*)malloc(n * sizeof(int));
        printf("������� ����� ������ %d:\n", i + 1);
        for (int j = 0; j < n; j++) {
            scanf("%d", &sets[i][j]);
        }
    }

    if (canFormIncreasingSeq(sets, m, n)) {
        printf("����� ������������ ������������ ������������������.\n");
    }
    else {
        printf("������ ������������ ������������ ������������������.\n");
    }

    for (int i = 0; i < m; i++) {
        free(sets[i]);
    }

    free(sets);

    return 0;
}



//���� �������� ���������� ������������ ���������������� ��� �����������, ����� �� ������������ 
//������������ ������������������ �� ������� �����. ��������� ����� ��������� ���������� O(m * n^2),
//��� m - ���������� �������, � n - ���������� ����� � ������ ������.