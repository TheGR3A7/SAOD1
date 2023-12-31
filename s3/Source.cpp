#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <malloc.h>


//���� m �������, ������ �� ������� ������� �� n �����. � ������ ������ ����� ������������ ����� ������������ �������, ������� ��� ���� ��������� �����.���������� ���������, �����
//�� ������������ �� ���� ������� ������������ ������������������ �����

void sortDigits(int* num, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (num[j] > num[j + 1])
			{
				int temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;
			}
		}
	}
} 

bool canFormIncreasingSequence(int** sets, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		sortDigits(sets[i], n);
	}
	int currentMin = sets[0][0];

	for (int i = 1; i < m; i++)
	{
		int j = 0;
		while (j < n && sets[i][j] <= currentMin)
		{
			j++;
		}
		if (j == n)
		{
			return false; 
		}
		currentMin = sets[i][j];
	}

	return true; 
}

int main()
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

	for (int i = 0; i < m; i++)
	{
		printf("������� ����� ������ %d:\n", i + 1);
		sets[i] = (int*)malloc(n * sizeof(int));
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &sets[i][j]);
		}
	}

	if (canFormIncreasingSequence(sets, m, n)) {
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



//���������� ���� ������ ������� ����� � ������ ������: ���� ��� �������� � ���� ��� ��������� �����, ��� n - ���������� ����� � ������ ������. 
//������� ��������� ����� ���� ���������� O(m * n^2), ��� m - ���������� �������, � n - ���������� ����� � ������ ������.
//�������� �� ����������� ������������ ������������ ������������������ : ���� ��� �������� � ���� ���� ������� ����, ������� ���������� ��� ������.
//������ ����� ����� ����������� ��� ���� ����, ������� ���������� ����� ������ ������.��������� ����� ���� ���������� O(m* n), 
//��� m - ���������� �������, � n - ���������� ����� � ������ ������.
//�������� ��������� ��������� : O(m * n ^ 2 + m * n).
//�������� ����� ������������ ���������(O(n ^ 2)) �� ���������� ����� ������ ������� ������ � �������� ���������(O(m)) �� ���������� �������.
