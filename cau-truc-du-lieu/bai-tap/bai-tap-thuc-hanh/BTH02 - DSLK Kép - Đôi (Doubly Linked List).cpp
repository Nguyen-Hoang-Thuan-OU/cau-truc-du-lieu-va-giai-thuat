/*Quản lý một danh sách có số phần tử khá lớn, biến động.
Mỗi phần tử có kiểu int. Thường có nhu cầu truy suất
phần tử đứng trước và phần tử đứng sau phần tử đang truy xuất.
(Danh sách liên kết kép)
*/

#include<iostream>
using namespace std;


// Khai báo cấu trúc danh sách.
struct node
{
	int info;
	node *next, *pre;
};

node *first, *last;

// Khai báo danh sách rỗng.
void khoiTao()
{
	first = last = NULL;
}

// Xuất các phần tử trong danh sách.
void xuat()
{
	node *p = first;
	while(p != NULL)
	{
		cout << p->info << "\t";
		p = p->next;
	}
}

// Xuất nghịch (từ dưới lên)
void xuatNghich()
{
	node *p = last;
	while (p != NULL)
	{
		cout << p->info << "\t";
		p = p->pre;
	}
}

// Thêm phần tử vào ĐẦU danh sách
void chenDau(int x)
{
	node *p= new node;
	p->info = x;
	p->next = first;
	p->pre = NULL;

	if(first != NULL)
		first->pre = p;
	else
		last = p;
	first = p;
}

// Thêm phần tử vào CUỐI danh sách.
void chenCuoi(int x)
{
	node *p = new node;
	p->info = x;
	p->next = NULL;
	p->pre = last;

	if (last != NULL)
		last->next = p;
	else
		first = p;
	last = p;
}

// Xoá phần tử ĐẦU danh sách.
int xoaDau()
{
	if (first != NULL)
	{
		node *p = first;
		first = first->next;
		delete p;
		if (first != NULL)
			first->pre = NULL;
		else
			last = NULL;
		return 1;
	}
	return 0;
}

// Xoá phần tử CUỐI danh sách.
int xoaCuoi()
{
	if (last != NULL)
	{
		node *p = last;
		last = last->pre;
		delete p;
		if (last != NULL)
			last->next = NULL;
		else
			first = NULL;
		return 1;
	}
	return 0;
}

// TÌM và XÓA một phần tử trong danh sách.

// Tìm.
node *tim(int x)
{
	node *p = first;
	while (p != NULL && p->info != x)
		p = p->next;
	return p;
}

// Xóa.
void timVaXoa(node *x)
{
	if (first == x)
		xoaDau();
	else 
		if(last == x)
			xoaCuoi();
		else
		{
			node *p = first;
			while (p->next != x)
				p = p->next;
			p->next = x->next;
			node *q = x->next;
			q->pre = x->pre;
			delete x;
		}
}

/* Tìm một phần tử có giá trị bằng với giá trị x hoặc gần nhất và
lớn hơn phần tử x nhập vào; Thêm một phần tử trước phần tử tìm thấy.*/

void chenBatKy(int x, int y)
{
	int min = INT_MAX, diaChi;
	node *p = first;
	while(p != NULL)
	{
		if(p->info - x < min && p->info - x >= 0)
		{
			min = p->info - x;
			diaChi = p->info;
		}
		p = p->next;
	}
	p = first;
	while(p->info != diaChi)
		p = p->next;

	if(p != first)
	{
		node *q = new node;
		q->info = y;
		q->next = p;
		q->pre = p->pre;
		
		node *k = p->pre;
		q->pre = k;
		k->next = q;
	}
	else
		chenDau(y);
}

// Tính tổng.
int tinhTong()
{
	int tong = 0;
	node *p = first;
	while (p != NULL)
	{
		tong  = tong + p->info;
		p = p->next;
	}
	return tong;
}

// Menu
int menu()
{
	cout << "\n----------Lua chon----------";
	cout << "\n0. Thoat"
		 << "\n1. Khoi tao"
		 << "\n2. Xuat"
		 << "\n3. Xuat nghich"
		 << "\n4. Chen DAU"
		 << "\n5. Chen CUOI"
		 << "\n6. Xoa DAU"
		 << "\n7. Xoa CUOI"
		 << "\n8. Tim va xoa"
		 << "\n9. Them truoc 1 phan tu co gia tri x (gan dung)"
		 << "\n10. Tinh tong.";
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
	int x, y;
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
			xuat();
			break;

		case 3:
			xuatNghich();
			break;

		case 4:
			cout << "Nhap gia tri muon them: ";
			cin >> x;
			cout << endl;
			chenDau(x);
			cout << "Da them thanh cong!" << endl;
			break;

		case 5:
			cout << "Nhap gia tri muon them: ";
			cin >> x;
			cout << endl;
			chenCuoi(x);
			cout << "Da them thanh cong!" << endl;
			break;

		case 6:
			if(xoaDau() != 0)
				cout << "Xoa thanh cong phan tu DAU danh sach" << endl;
			else
				cout << "Danh sach trong" << endl;
			break;

		case 7:
			if(xoaCuoi() != 0)
				cout << "Xoa thanh cong phan tu CUOI danh sach" << endl;
			else
				cout << "Danh sach trong" << endl;
			break;

		case 8:
			cout << "Nhap so can xoa: ";
			cin >> x;
			cout << endl;
			p = tim(x);
			if (p == NULL)
				cout << "Khong tim thay gia tri can xoa." << endl;
			else
			{
				timVaXoa (p);
				cout << "Da xoa gia tri ban can xoa." << endl;
			}
			break;

		case 9:
			cout << "Nhap vi tri: ";
			cin >> x;
			cout << "Nhap gia tri: ";
			cin >> y;
			chenBatKy(x, y);
			cout << "Chen thanh cong.";
			break;

		case 10:
			cout << "Tong = " << tinhTong() << endl;
			break;

		default:
			cout << "Gia tri chon khong hop le!" << endl;
			break;
		}
	}while(chon != 0);
	return 0;
}