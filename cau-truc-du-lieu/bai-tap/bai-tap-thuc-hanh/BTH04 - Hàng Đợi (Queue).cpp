// Quản lý một queue có số phần tử khá lớn, biến động.
// Mỗi phần tử có kiểu int (danh sách liên kết đơn).

#include<iostream>
using namespace std;

// Khai báo cấu trúc queue.
struct node
{
	int info;
	node *link;
};

node *front, *rear;

// Khởi tạo queue rỗng.
void khoiTao()
{
	front = rear = NULL;
}

// Xét queue rỗng.
int rong()
{
	if(front == NULL)
		return 1;
	return 0;
}

// Thêm một phần tử vào queue.
void them(int x)
{
	node *p = new node;
	p->info = x;
	p->link = NULL;

	if (rear == NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
}

// Xoá một phần tử trong queue.
int xoa(int &x)
{
	if(front != NULL)
	{
		node *p = front;
		front = p->link;
		x = p->info;

		if(front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}

int menu()
{
	cout << "\n----------HANG DOI----------" << endl;
	cout << "0. Thoat.\n"
		 << "1. Khoi tao.\n"
		 << "2. Them (EnQueue).\n"
		 << "3. Xoa (DeQueue).\n"
		 << "4. Rong (Is empty) hay khong?\n";
	cout << "----------------------------" << endl;

	int chon = 0;
	cout << "Chon (0 - 4): ";
	cin >> chon;
	cout << endl;

	return chon;
}

int main()
{
	int chon = 0;
	int x;
	do{
menu:
		chon = menu();
		switch(chon)
		{
		case 0:
			cout << "Nhan phim bat ky de thoat -> ";
			break;

		case 1:
			khoiTao();
			cout << "Da khoi tao thanh cong!" << endl;
			break;

		case 2:
			cout << "Nhap gia tri can them: ";
			cin >> x;
			them(x);
			break;

		case 3:
			if(xoa(x))
				cout << "Da xoa gia tri [" << x << "] tai dau hang doi!" << endl;
			else
				cout << "Khong the lay gia tri tai dau hang doi!" << endl;
			break;

		case 4:
			if(rong())
				cout << "Hang doi rong!" << endl;
			else
				cout << "Hang doi khong rong!" << endl;
			break;

		default:
			cout << "Chuc nang ban chon khong co!" << endl;
			break;
		}
	}while(chon != 0);
	return 0;
}