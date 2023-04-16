// Khai báo cấu trúc danh sách cho 1 danh sách.

#include<iostream>
using namespace std;
#define max 100

struct node
{
	int info;
	node *link;
};

node *first[max]; // Mảng danh sách.
int n; // Số đỉnh trên đồ thị.

// Khởi tạo mảng danh sách rỗng.
void khoiTao()
{
	for (int i = 0; i < n; i++)
	{
		first[i] = NULL;
	}
}

// Thêm 1 phần tử vào đầu danh sách.
void chenDau(node *&f, int x)
{
	node *p;
	p = new node;
	p->info = x;
	p->link = f;
	f = p;
}

// Nhập mảng danh sách.
void nhapMang()
{
	int d, x, m;
	cout << "So dinh cua do thi n: ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap dinh thu " << i + 1 << ": ";
		cin >> d;
		chenDau(first[i], d);
		cout << "Nhap so dinh ke cua " << d << ": ";
		cin >> m;

		for (int j = 0; j < m; j++)
		{
			cin >> x;
			chenDau(first[i], x);
		}
	}
}

// Xuất thông tin 1 danh sách.
void xuatDanhSach(node *f)
{
	if (f != NULL)
	{
		node *p = f;

		while (p != NULL)
		{
			cout << p->info << "  ";
			p = p->link;
		}
	}
}

// Xuất thông tin mảng danh sách.
void xuatMang()
{
	if (n > 0)
	{
		for (int i = 0; i < n; i++)
		{
			cout << "\nDanh sach thu " << i + 1 << ": ";
			xuatDanhSach(first[i]);
		}
		cout << endl;
	}

	else
		cout << "Rong!" << endl;
}

void main()
{
	khoiTao();
	nhapMang();
	xuatMang();
}