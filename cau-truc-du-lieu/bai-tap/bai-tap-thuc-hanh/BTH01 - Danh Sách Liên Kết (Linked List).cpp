/* Quản lý một danh sách có số phần tử khá lớn, biến động.
Mỗi phần tử có kiểu int. (Dùng cấu trúc Danh sách liên kết)*/

#include <iostream>
using namespace std;

// Khai báo cấu trúc danh sách.
struct node
{
	int info;
	node *link;
};

node *first;

// Khởi tạo danh sách rỗng.
void khoiTao()
{
	first = NULL;
}

// Xuất các phần tử trong danh sách.
void xuat()
{
	node *p = first;
	while(p != NULL)
	{
		cout << p->info << "\t";
		p = p->link;
	}
}

// Tìm một phần tử trong danh sách.
node *tim(int x)
{
	node *p = first;
	while((p != NULL) && (p->info != x))
	{
		p = p->link;
	}
	return p;
}

// Thêm một phần tử vào ĐẦU danh sách.
void themDau(int x)
{
	node *p = new node;
	p->info = x;
	p->link = first;
	first = p;
}

// Xoá phần tử ĐẦU danh sách.
int xoaDau()
{
	if(first != NULL)
	{
		node *p = first;
		first = first->link;
		delete p;
		return 1;
	}
	return 0;
}

// Thêm một phần tử vào CUỐI danh sách.
void themCuoi(int x)
{
	node *p = new node;
	p->info = x;
	p->link = NULL;

	if(first == NULL)
		first = p;
	else
	{
		node *q = first;
		while(q->link != NULL)
		{
			q = q->link;
		}
		q->link = p;
	}
}

// xoá phần tử CUỐI danh sách.
int xoaCuoi()
{
	if(first != NULL)
	{
		node *q, *p;
		p = first;
		while(p->link != NULL)
		{
			q = p;
			p = p->link;
		}
		if(p != first)
			q->link = NULL;
		else
			first = NULL;
		delete p;
		return 1;
	}
	return 0;
}

// Tìm một phần tử trong danh sách. Nếu tìm thấy, hãy xoá phần tử này.
int timVaXoa(node *x)
{
	node *p = first;
	while (p->link != x)
		p = p->link;
	p->link = x -> link;
	delete x;
	return 1;
}

// Menu
int menu()
{
	cout << "\n----------Lua chon----------";
	cout << "\n0. Thoat"
		 << "\n1. Khoi tao"
		 << "\n2. Xuat"
		 << "\n3. Tim 1 phan tu"
		 << "\n4. Them DAU"
		 << "\n5. Xoa DAU"
		 << "\n6. Them CUOI"
		 << "\n7. Xoa CUOI"
		 << "\n8. TIM va XOA";
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
	node *p;

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
			cout << "Cac phan tu trong danh sach:\n";
			xuat();
			cout << endl;
			break;

		case 3:
			cout << "Nhap phan tu can tim: ";
			cin >> x;
			if (tim(x) != NULL)
				cout << "\nDa tim thay phan tu co gia tri = " << x << endl;
			else
				cout << "\nKhong tim thay phan tu co gia tri = " << x << endl;
			break;

		case 4:
			cout << "Nhap gia tri muon them: ";
			cin >> x;
			cout << endl;
			themDau(x);
			cout << "Da them thanh cong!" << endl;
			break;

		case 5:
			if(xoaDau() != 0)
				cout << "Xoa thanh cong phan tu DAU danh sach" << endl;
			else
				cout << "Danh sach trong" << endl;
			break;

		case 6:
			cout << "Nhap gia tri muon them: ";
			cin >> x;
			cout << endl;
			themCuoi(x);
			cout << "Da them thanh cong!" << endl;
			break;

		case 7:
			if(xoaCuoi() != 0)
				cout << "Xoa thanh cong phan tu CUOI danh sach" << endl;
			else
				cout << "Danh sach trong" << endl;
			break;

		case 8:
			cout << "Chon so ban can xoa: ";
			cin >> x;
			p = tim(x);
			if (p == NULL)
				cout << "\nKhong tim thay phan tu co gia tri = " << x << endl;
			else
			{
				timVaXoa(p);
				cout << "\nDa xoa phan tu co gia tri = " << x << endl;
			}
			break;

		default:
			cout << "Gia tri chon khong hop le!" << endl;
			break;
		}
	}while(chon != 0);
	return 0;
}