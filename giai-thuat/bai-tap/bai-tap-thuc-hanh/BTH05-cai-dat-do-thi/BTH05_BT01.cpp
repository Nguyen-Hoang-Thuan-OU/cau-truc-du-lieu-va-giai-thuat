// Khai báo cấu trúc ma trận kề.

#include<iostream>
using namespace std;
#define MAX 20
int A[MAX][MAX]; // Mảng hai chiều.
int n; // Số đỉnh của đồ thị.

// Khởi tạo mảng rỗng.
void init()
{
	n = 0;
}

// Nhập ma trận.
void input()
{
	cout << "So dinh cua do thi: ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cout << "Nhap dong thu " << i + 1 << ": ";

		for (int j = 0; j < n; j++)
		{
			cin >> A[i][j];
		}
	}
}

// Xuất ma trận.
void output()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << A[i][j] << "  ";
		}
		cout << endl;
	}
}

void main()
{
	init();
	input();
	output();
}