// Quản lý một cây nhị phân, mỗi phần tử có kiểu int.

#include<iostream>
#include<fstream>
using namespace std;

// Khai báo cấu trúc cây nhị phân.
struct node
{
	int info;
	node *left, *right;
};

// Khởi tạo cây rỗng.
void khoiTao (node *&root)
{
	root = NULL;
}

// Thêm một phần tử vào cây.
int them (node *&root, int x)
{
	if (root == NULL)
	{
		node *p = new node;
		p->info = x;
		p->left = p->right = NULL;
		root = p;
		return 1;
	}
	else
	{
		if (x == root->info)
			return 0;
		else if (x < root->info)
			return them (root->left, x);
		else
			return them (root->right, x);
	}
}

// Tìm một phần tử trong cây. (Bình thường)
node *timThuong (node *p, int x)
{
	while (p != NULL)
	{
		if (p->info == x)
			return p;
		else
		{
			if (p->info > x)
				p = p->left;
			else
				p = p->right;
		}
	}
	return NULL;
}

// Tìm một phần tử trong cây. (Đệ quy)
node *timDeQuy (node *&p, int x)
{

	if (p == NULL)
		return NULL;
	else
	{
		if (p->info == x)
			return p;
		else 
			if (x > p->info)
				return timDeQuy(p->right, x);
			else
				return timDeQuy(p->left, x);
	}

}

// Tìm một phần tử trong cây. (Phần tử thế mạng)
void timTheMang (node *&p, node *&q)
{
	if (q->left == NULL)
	{
		p->info = q->info;
		p = q;
		q = q->right;
	}
	else
		timTheMang (p, q->left);
}

// Xoá một nút trong cây. (Bình thường)
int xoaThuong(node *&root, int x)
{
	while (root != NULL)
	{
		if (root->info == x)
		{
			node *p = root;
			if (root->left == NULL)
				root = root->right;
			else if (root->right == NULL)
				root = root->left;
			else
				timTheMang (p, root->right);
			delete p;
			return 1;
		}
		if (root->info < x)
			root = root->right;
		if (root->info > x)
			root = root->left;
	}
	return 0;
}

// Xoá một nút trong cây. (Đệ quy)
int xoaDeQuy (node *&p, int x)
{
	if (p == NULL)
		return 0;
	if (p->info == x)
	{
		node *q = p;
		if (p->left == NULL)
			p = p->right;
		else if (p->right == NULL)
			p = p->left;
		else
			timTheMang (q, p->right);
		delete q;
		return 1;
	}
	if (p->info < x)
		return xoaDeQuy (p->right, x);
	if (p->info > x)
		return xoaDeQuy (p->left, x);
}

// Duyệt cây theo thứ tự NLR (dùng đệ quy).
void NLR (node *root)
{
	if (root != NULL)
	{
		cout << root->info << "\t";
		NLR (root->left);
		NLR (root->right);
	}
}

// Duyệt cây theo thứ tự LNR (dùng đệ quy).
void LNR (node *root)
{
	if (root != NULL)
	{
		LNR (root->left);
		cout << root->info << "\t";
		LNR (root->right);
	}
}

// Duyệt cây theo thứ tự LRN (dùng đệ quy).
void LRN (node *root)
{
	if (root != NULL)
	{
		LRN (root->left);
		LRN (root->right);
		cout << root->info << "\t";
	}
}

// Đọc file từ máy
void docFile(char *fileName, node *&root)
{
	int n, x, i = 0;
	fstream f;
	f.open(fileName, ios::in);
	if(f.is_open())
	{
		f >> n;
		cout << n << ": [";
		while(!f.eof())
		{
			f >> x;
			them(root, x);
			i++;
			if(i != 1)
				cout << "  ";
			cout << x;
		}
		cout << "]" << endl;
			f.close();
	}
	else
		cout << "Mo file that bai!" << endl;
}

int menu()
{
	cout << "\n-----CAY NHI PHAN TIM KIEM-----";
	cout << "\n0. Thoat"
		 << "\n1. Khoi tao"
		 << "\n2. Duyet Node -> Left -> Right (NLR)"
		 << "\n3. Duyet Left -> Node -> Right (LNR)"
		 << "\n4. Duyet Left -> Right -> Node (LRN)"
		 << "\n5. Them"
		 << "\n6. Tim kiem (binh thuong)"
		 << "\n7. Tim kiem (de quy)"
		 << "\n8. Xoa (binh thuong)"
		 << "\n9. Xoa (de quy)"
		 << "\n10. Doc file";
	cout << "\n-------------------------------\n";

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
	int t;
	node *root, *temp;
	
	do{
MENU:
		chon = menu();
		switch(chon)
		{
		case 0:
			cout << "Nhan phim bat ky de thoat ->";
			break;

		case 1:
			khoiTao (root);
			cout << "Da khoi tao thanh cong!" << endl;
			break;

		case 2:
			NLR (root);
			cout << endl;
			break;

		case 3:
			LNR (root);
			cout << endl;
			break;

		case 4:
			LRN (root);
			cout << endl;
			break;

		case 5:
			cout << "Nhap gia tri can them: ";
			cin >> x;
			them (root, x);
			break;

		case 6:
			cout << "Nhap gia tri can tim: ";
			cin >> x;
			cout << endl;
			temp = timThuong (root, x);
			if (temp != NULL)
				cout << "Tim thay!" << endl;
			else
				cout << "Khong tim thay!" << endl;
			break;

		case 7:
			cout << "Nhap gia tri can tim: ";
			cin >> x;
			cout << endl;
			temp = timDeQuy (root, x);
			if (temp != NULL)
				cout << "Tim thay!" << endl;
			else
				cout << "Khong tim thay!" << endl;
			break;

		case 8:
			cout << "Nhap gia tri can xoa: ";
			cin >> x;
			cout << endl;
			t = xoaThuong (root, x);
			if (t == 1)
				cout << "Da xoa thanh cong gia tri " << x << "!" << endl;
			else
				cout << "Khong tim thay gia tri " << x << "!" << endl;
			break;

		case 9:
			cout << "Nhap gia tri can xoa: ";
			cin >> x;
			cout << endl;
			t = xoaDeQuy (root, x);
			if (t == 1)
				cout << "Da xoa thanh cong gia tri " << x << "!" << endl;
			else
				cout << "Khong tim thay gia tri " << x << "!" << endl;
			break;

		case 10:
			cout <<"Doc file: "<< endl;
			docFile("Data.txt", root);
			break;

		default:
			cout << "Gia tri nhap khong hop le!" << endl;
			break;
		}
	}while(chon != 0);
	return 0;
}