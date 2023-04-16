// Dùng cấu trúc bảng băm – phương pháp kết nối trực tiếp,
// quản lý 5000 phần từ kiểu số int.

#include<iostream>
using namespace std;

#define MAX 101

// Khai báo cấu trúc bảng băm.
struct node
{
	int key;
	node *next;
};

node *heads[MAX];
node *z;

// Khởi tạo bảng băm rỗng.
void khoiTao()
{
	z = new node;
	z->next = z;
	for (int i = 0; i < MAX; i++)
	{
		heads[i] = z;
	}
}

// Thêm một phần tử vào bảng băm.
node *chen(int k)
{
	node *p;
	node *t = heads[k % MAX];

	node *x = new node;
	x->key = k;
	z->key = k;

	if(t->key >= k)
	{
		x->next = t;
		heads[k % MAX] = x;
	}
	else
	{
		p = t->next;
		while(p->key < k)
		{
			t = t->next;
			p = t->next;
		}
		t->next = x;
		x->next = p;
	}
	return x;
}

// Tìm kiếm một phần tử trong bảng băm.
node *tim(int k)
{
	node *t = heads[k % MAX];
	z->key = k;
	while (k > t->key)
	{
		t = t->next;
	}
	if (k != t->key)
		return z;
	return t;
}

// Xuất
void xuat()
{
	for (int i = 0; i < MAX; i++)
	{
		if (heads[i] != z)
		{
			cout << "Heads[" << i << "]= ";
			node *firsti = heads[i];
			while (firsti != z)
			{
				cout << firsti->key << "\t";
				firsti = firsti->next;
			}
			cout << endl;
		}
	}
}

int menu()
{
	cout << "\n----------BANG BAM----------\n";
	cout << "0. Thoat\n"
		 << "1. Khoi tao\n"
		 << "2. Chen\n"
		 << "3. Tim kiem\n"
		 << "4. xuat\n";
	cout << "----------------------------\n";

	int chon = 0;
	cout << "Chon: ";
	cin >> chon;
	cout << endl;
	return chon;
}

int main()
{
	int chon = 0;
	int k = 0;
	int x = -1;
	node *tmp;
	do{
MENU:
		chon = menu();
		switch(chon)
		{
		case 0:
			cout << "Nhan phim bat ky de thoat --> ";
			break;

		case 1:
			khoiTao();
			cout << "Da khoi tao thanh cong!\n";
			break;

		case 2:
			cout << "Nhap so can chen: ";
			cin >> k;
			cout << endl;
			chen(k);
			cout << "Da them thanh cong!" << endl;
			break;

		case 3:
			cout << "Nhap gia tri can tim: ";
			cin >> x;
			cout << endl;
			tmp = tim(x);
			if (tmp != z)
				cout << "Tim thay " << tmp->key << endl;
			else
				cout << "Khong tim thay!\n";
			break;

		case 4:
			xuat();
			break;

		default:
			cout << "Gia tri nhap khong hop le!\n";
			goto MENU;
		}
	}while(chon != 0);
	return 0;
}