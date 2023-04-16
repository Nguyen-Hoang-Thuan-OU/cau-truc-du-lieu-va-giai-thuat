// Dùng cấu trúc danh sách đặc quản lý một đa thức
#include <iostream>
using namespace std;

struct donThuc
{
	int heSo;
	int soMu;
};

// Khai báo cấu trúc danh sách.
struct node
{
	donThuc info;
	node * link;
};

node *first;

// Nhập đơn thức.
donThuc nhapDonThuc()
{
	donThuc dt;
	cout << "Nhap he so: ";
	cin >>	dt.heSo;

	cout << "Nhap so mu: ";
	cin >>	dt.soMu;

	return dt;
}

// Xuất đơn thức.
void xuatDonThuc(donThuc dt)
{
	if (dt.soMu == 1)
		cout << dt.heSo << "x";
	else
		if (dt.heSo != 0)
		{
			if (dt.soMu == 0)
				cout << dt.heSo;
			else
				cout << dt.heSo << "x^" << dt.soMu;
		}
}

// Khởi tạo
void khoiTao()
{
	first = NULL;
}

// Chèn ĐẦU
void chenDau(node *&first, donThuc dt)
{
	node *p = new node;
	p->info = dt;
	p->link = first;
	first = p;
}

// Chèn CUỐI
void chenCuoi(node *&first, donThuc dt)
{
	node *p = new node;
	p->info = dt;
	p->link = NULL;
	if(first == NULL)
		first = p;
	else
	{
		node *q = first;                                                                                                                                                                                     
		while(q->link != NULL)
			q = q->link;
		q->link = p;
	}
}

// Xuất đa thức
void xuat()
{
	if (first != NULL)
	{
		node *p = first;

		while (p->link != NULL)
		{
			xuatDonThuc(p->info);
			cout << " + ";
			p = p->link;
		}
		xuatDonThuc(p->info);
	}
}

// Tính giá trị của đa thức
int gtdt(int x)
{
	int s = 0;
	node *p = first;
	while (p != NULL)
	{
		s = s + p->info.heSo * pow((double)x, (double)p->info.soMu);
		p = p->link;
	}
	return s;
}

// Đạo hàm của f(x)
void daoHam()
{
	node *p = first;

	while (p != NULL)
	{
		if (p->info.soMu == 0)
			p->info.heSo = 0;
		else
		{
			p->info.heSo = p->info.heSo * p->info.soMu;
			p->info.soMu = p->info.soMu -1;
		}
		p = p->link;
	}
}

// Cộng hai đa thức.

// Trừ hai đa thức.

// Nhân hai đa thức.

// Chia hai đa thức.

// Menu
int menu()
{
	cout << "\n----------Lua chon----------";
	cout << "\n0. Thoat"
		 << "\n1. Khoi tao"
		 << "\n2. Xuat"
		 << "\n3. Chen DAU"
		 << "\n4. Chen CUOI"
		 << "\n5. Tinh gia tri cua da thuc"
		 << "\n6. Dao ham f(x)"
		 << "\n7. Cong da thuc"
		 << "\n8. Tru da thuc"
		 << "\n9. Nhan da thuc"
		 << "\n10. Chia da thuc";
	cout << "\n----------------------------" << endl;

	int chon = 0;
	cout << "\nNhap lua chon: ";
	cin >> chon;
	cout << endl;

	return chon;
}

int main()
{
	int chon = 0;
	int x;

	do{
		chon = menu();
		switch(chon)
		{
			case 0:
				cout << "Nhan phim bat ky de thoat chuong trinh -> ";
				break;

			case 1:
				khoiTao();
				cout << "Da khoi tao danh sach thanh cong!" << endl;
				break;

			case 2:
				cout << "f(x) = ";
				xuat();
				break;

			case 3:
				{
					donThuc dt = nhapDonThuc();
					chenDau(first, dt);
					cout << "Da chen thanh cong!" << endl;
					break;
				}

			case 4:
				{
					donThuc dt = nhapDonThuc();
					chenCuoi(first, dt);
					cout << "Da chen thanh cong!" << endl;
					break;
				}

			case 5:
				{
					cout << "Nhap x: ";
					cin >> x;
					cout << "Voi x = " << x << ", f(x) = " << gtdt(x) << endl;
					break;
				}

			case 6:
				{
					daoHam();
					cout << "Dao ham co dang: f'(x) = ";
					xuat();
					cout << endl;
					break;
				}

			default:
				cout << "Gia tri chon khong hop le!" << endl;
			break;
		}
	}while(chon != 0);
	return 0;
}