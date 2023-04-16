// Khai báo cấu trúc ma trận kề.

#include<iostream>
#include<queue>
using namespace std;
#define MAX 20
queue<int> z;
int A[MAX][MAX]; // Mảng hai chiều.
int n; // Số đỉnh của đồ thị.
int C[100]; // Lưu trữ đỉnh chưa xét.
// 1 = chưa xét, 0 = đã xét.
int bfs[100]; // Lưu danh sách phần tử đã duyệt.
int nbfs = 0; // Chỉ số lưu đỉnh đã xét.
int ndfs = 0; // Chỉ số lưu đỉnh đã xét.

// Khởi tạo mảng rỗng.
void khoiTao()
{
	n = 0;
}

// Nhập ma trận.
void nhapMaTran()
{
	cout << "Nhap so dinh cua do thi: ";
	cin >> n;

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
	cout << endl;
}

// Hàm khởi tạo đỉnh chưa xét = 1.
void khoiTaoDinhChuaXet()
{
	for (int i = 0; i < n; i++)
	{
		C[i] = 1;
	}
}

// Thuật giải BFS sử dụng QUEUE.
void BFS (int v)
{
	int w, p;
	z.push(v);
	C[v] = 0;

	while (z.front() != NULL)
	{
		z.pop();
		bfs[nbfs] = p;
		nbfs++;

		for (w = 0; w < n; w++)
		{
			if (C[w] == 1 && A[p][w] == 1)
			{
				z.push(w);
				C[w] = 0;
			}
		}
	}
}

// Hàm xuất BFS.
void xuatBFS()
{
	for (int i = 0; i < nbfs; i++) // n = số đỉnh của đồ thị.
	{
		cout << bfs[i] << "  ";
	}
	cout << endl;
}

// Hàm tìm x.
void timBangBFS (int x, int v) // v = đỉnh bắt đầu.
{
	int w, p;
	z.push(v);
	C[v] = 0;
	while(z.front() != NULL)
	{
		z.pop();
		if (x == p)
		{
			cout << x << "ton tai";
			return;
		}
	}

	for (w = 0; w < n; w++)
	{
		if (C[w] == 1 && A[p][w] == 1)
		{
			z.push(w);
			C[w] = 0;
		}
	}
}

void main()
{
	int x;
	cout << "Nhap gia tri dinh can tim: ";
	cin >> x;
	khoiTao();
	nhapMaTran();
	xuatMaTran();
	khoiTaoDinhChuaXet();
	BFS(0);
	xuatBFS();
	timBangBFS(x, 0);
}