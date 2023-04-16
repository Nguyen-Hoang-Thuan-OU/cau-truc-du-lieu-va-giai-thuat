// Khai báo cấu trúc ma trận kề.

#include<iostream>
#include<stack>
#define MAX 20
using namespace std;
stack<int> x;
int A[MAX][MAX]; // Mảng hai chiều.
int n; // Số đỉnh của đồ thị.
int C[100]; // Lưu trữ đỉnh chưa xét.
// 1 = chưa xét, 0 = đã xét.
int dfs[100]; // Lưu trữ danh sách phần tử đã duyệt.
int ndfs = 0; // Chỉ số lưu đỉnh đã xét.

// Khởi tạo mảnh rỗng.
void khoiTao()
{
	n = 0;
}

// Nhập ma trận.
void nhapMaTran()
{
	cout << "Nhap so dinh cua do thi: ";
	cin >> n;
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "Nhap dong thu " << i + 1 << ": ";
		for (int j = 0; j < n; j++)
			cin >> A[i][j];
	}
	cout << endl;
}

// Xuất ma trận.
void xuatMaTran()
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

// Hàm khỏi tạo đỉnh chưa xét = 1.
void khoiTaoDinhChuaXet()
{
	for (int i = 0; i < n; i++) // n = số đỉnh của đồ thị.
	{
		C[i] = 1;
	}
}

// Thuật giải DFS sử dụng STACK.
void DFS(int s) // s = đỉnh bắt đầu.
{
	x.push(s);
	dfs[ndfs] = s;
	ndfs++;
	C[s] = 0;
	int v = -1, u = s;

	while (!x.empty())
	{
		if (v == n)
			x.pop();
		for (v = 0; v < n; v++)
		{
			if (A[u][v] != 0 && C[v] == 1)
			{
				x.push(u);
				x.push(v);
				dfs[ndfs] = v;
				ndfs++;
				C[v] = 0;
				u = v;
				break;
			}
		}
	}
}

// Hàm xuất DFS.
void xuatDFS()
{
	for (int i = 0; i < ndfs; i++)
	{
		cout << dfs[i] << "  ";
	}
}

void main()
{
	khoiTao();
	nhapMaTran();
	xuatMaTran();
	khoiTaoDinhChuaXet();
	DFS(0);
	xuatDFS();
}