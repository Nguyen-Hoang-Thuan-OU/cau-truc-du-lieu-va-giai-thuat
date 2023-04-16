#include<iostream>
using namespace std;
#define max 100

int ss = 0, gan = 0, toan = 0;

struct node
{
	int info;
	node *link;
};

node *first[max];
int n;

void khoiTao()
{
	int i;
	for (gan++, i = 0; ss++, i < n; gan++, toan++, i++)
	{
		first[i] = NULL;
		gan++;
	}
}

void chenDau(node *&f, int x)
{
	node *p;
	p = new node;
	p->info = x;
	p->link = f;
	f = p;
	gan+=4;
}

void nhapMang()
{
	int d, x, m;
	cout << "So dinh cua do thi n: ";
	cin >> n;

	int i;
	for (gan++, i = 0; ss++, i < n; gan++, toan++, i++)
	{
		cout << "\nNhap dinh thu " << i + 1 << ": ";
		cin >> d;
		chenDau(first[i], d);
		cout << "Nhap so dinh ke cua " << d << ": ";
		cin >> m;

		int j;
		for (gan++, j = 0; ss++, j < m; gan++, toan++, j++)
		{
			cin >> x;
			chenDau(first[i], x);
		}
	}
}

void xuatDanhSach(node *f)
{
	if (ss++, f != NULL)
	{
		node *p = f;
		gan++;

		while (ss++, p != NULL)
		{
			cout << p->info << "  ";
			p = p->link;
			gan++;
		}
	}
}

void xuatMang()
{
	if (ss++, n > 0)
	{
		int i;
		for (gan++, i = 0; ss++, i < n; gan++, toan++, i++)
		{
			cout << "\nDanh sach thu " << i + 1 << ": ";
			xuatDanhSach(first[i]);
		}
		cout << endl;
	}

	else
		cout << "Rong!" << endl;

	cout << endl;
	cout << "So phep so sanh: " << ss << endl;
	cout << "So phep gan: " << gan << endl;
	cout << "So phep toan: " << toan << endl;
}

void main()
{
	khoiTao();
	nhapMang();
	xuatMang();
}