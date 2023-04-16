// Quản lý một stack có số phần tử khá lớn, biến động.
// Mỗi phần tử có kiểu int (danh sách liên kết đơn).

#include<iostream>
using namespace std;

// Khai báo cấu trúc stack.
struct node
{
	int info;
	node *link;
};

node *sp;

// Khởi tạo stack rỗng.
void khoiTao()
{
	sp = NULL;
}

// Xét stack rỗng
int rong()
{
	if (sp == NULL)
		return 1;
	return 0;
}

// Thêm một phần tử vào stack.
void them(int x)
{
	node *p = new node;
	p->info = x;
	p->link = sp;
	sp = p;
}

// Xoá một phần tử trong stack.
int xoa(int &x)
{
	if (sp != NULL)
	{
		node *p = sp;
		x = p->info;
		sp = sp->link;
		delete p;
		return 1;
	}
	return 0;
}

// Đổi số hệ thập (10) sang hệ nhị phân (2).
void decToBin(int dec)
{
	int d = dec;
	while(d != 0)
	{
		them(d % 2);
		d = d / 2;
	}

	cout << "So nhi phan cua " << dec << " la: ";

	while(!rong())
	{
		int x;
		if(xoa(x))
			cout << x;
	}
}

// Đổi số hệ nhị phân (2) sang hệ thập (10).
double luyThua(int coSo, int soMu)
{
	if (soMu == 0)
		return 1;
	else
		if (soMu < 0)
			return 1.0/coSo * luyThua(coSo, soMu + 1);
		else
			return coSo * luyThua(coSo, soMu -1);
}

double binToDec(int np, int soMu)
{
	
	if (np == 0)
		return 0;
	else
		return (np % 10) * luyThua(2, soMu) + binToDec(np/10, soMu +1);
}

// Đổi số hệ thập (10) sang hệ bát phân (8).
int decToOct(int n)
{
	if(n == 0)
		return 0;
	else
		return n % 8 + decToOct(n/8) * 10;
}

// Đổi số hệ thập (10) sang hệ thập lục phân (16).
int decToHex(int n)
{
	if(n == 0)
		return 0;
	else
		return n % 16 + decToHex(n/16) * 10;
}

int menu()
{
	cout << "\n----------NGAN XEP----------" << endl;
	cout << "0. Thoat.\n"
		 << "1. Khoi tao.\n"
		 << "2. Them vao dau (Push).\n"
		 << "3. Xoa (Pop).\n"
		 << "4. Rong (Is empty) hay khong?\n"
		 << "5. Thap phan (10) sang nhi phan (2).\n"
		 << "6. Nhi phan (2) sang thap phan (10).\n"
		 << "7. Thap phan (10) sang bat phan (8).\n"
		 << "8. Thap phan (10) sang thap luc phan (16).\n";
	cout << "----------------------------" << endl;

	int chon = 0;
	cout << "Chon: ";
	cin >> chon;
	cout << endl;

	return chon;
}

int main()
{
	int chon = 0;
	int x = 0;
	do{
		menu:
		chon = menu();
		switch(chon)
		{
		case 0:
			cout << "Nhan phim bat ky de thoat chuong trinh -> ";
			break;

		case 1:
			khoiTao();
			cout << "Da khoi tao thanh cong!" << endl;
			break;

		case 2:
			cout << "Nhap gia tri can them: ";
			cin >> x;
			cout << endl;
			them(x);
			cout << "Da them thanh cong!" << endl;
			break;

		case 3:
			if(xoa(x))
				cout << "Da xoa gia tri [" << x << "] tai dinh cua ngan xep!" << endl;
			else
				cout << "Khong the lay gia tri tai dinh cua ngan xep!" << endl;
			break;

		case 4:
			if(rong())
				cout << "Ngan xep rong!" << endl;
			else
				cout << "Ngan xep khong rong!" << endl;
			break;

		case 5:
			cout << "Nhap so can doi: ";
			cin >> x;
			decToBin(x);
			cout << endl;
			break;

		case 6:
			cout << "Nhap so can doi: ";
			cin >> x;
			cout << "So thap phan cua " << x << " la: " << binToDec(x,0) << endl;
			break;
			
		case 7:
			cout << "Nhap so can doi: ";
			cin >> x;
			cout << "So bat phan cua " << x << " la: " << decToOct(x) << endl;
			break;

		case 8:
			cout << "Nhap so can doi: ";
			cin >> x;
			cout << "So thap luc phan cua " << x << " la: " << decToHex(x) << endl;
			break;

		default:
			cout << "Chuc nang ban chon hien tai khong co!" << endl;
			goto menu;
		}
	}while(chon != 0);
	return 0;
}