#include<iostream>
using namespace std;
#define MAX 100

// Nhập danh sách.
void nhap(int a[], int n)
{
	if (n > MAX)
		n = MAX;
	for (int i = 0; i < n; i++)
	{
		/*cout << "a[" << i << "] = ";
		cin >> a[i];*/
		a[i] = rand()%100 + 1;
	}
}

// Xuất danh sách.
void xuat(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (i % 10 == 0 && i > 0)
			cout << endl;
		cout << a[i] << " ";
	}
	cout << endl;
}

// Sắp xếp chọn trực tiếp.
void selectionSort(int a[], int n)
{
	 int min_pos, i, j;
	 for (i = 0; i < n - 1; i++)
	 {
		 min_pos = i;
		 for (j = i + 1; j < n; j++)
		 {
			 if (a[j] < a[min_pos])
				 min_pos = j;
			 swap(a[min_pos], a[i]);
		 }
	 }
}

// Sắp xếp chèn trực tiếp.
void insertionSort(int a[], int n)
{
	int x, i, j;
	for (i = 1; i < n; i++)
	{
		x = a[i];
		j = i - 1;
		while(0 <= j && x < a[j])
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}

// Sắp xếp nổi bọt.
void bubbleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (a[j - 1] > a[j])
				swap(a[j], a[j - 1]);
		}
	}
}

// Sắp xếp đổi chỗ trực tiếp.
void interchangeSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n ; j++)
		{
			if (a[i] > a[j])
				swap (a[i], a[j]);
		}
	}
}

// Tìm kiếm tuần tự / tuyến tính.
int linearSearch(int a[], int n, int x)
{
	int i = 0;
	while (i < n && a[i] != x)
		i++;
	if (i < n)
		return i;
	return -1;
}

// Tìm kiếm nhị phân.
int binarySearch(int a[], int n, int x)
{
	int left = 0;
	int right = n - 1;
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (x == a[mid])
			return mid;
		else
			if (x > a[mid])
				left = mid + 1;
			else
				right = mid - 1;
	}
	return -1;
}

int menu()
{
	cout << "\n----------MENU----------" << endl;
	cout << "0. Thoat.\n"
		 << "1. Nhap\n"
		 << "2. Xuat\n";
	cout << "~~~~~~~~~~SORT~~~~~~~~~~" << endl;
	cout << "3. Chon lua truc tiep (Selection Sort)\n"
		 << "4. Chen truc tiep (Insertion Sort)\n"
		 << "5. Noi bot (Bubble Sort)\n"
		 << "6. Doi cho truc tiep (Interchange Sort)\n";
	cout << "~~~~~~~~~SEARCH~~~~~~~~~" << endl;
	cout << "7. Tim kiem tuan tu/tuyen tinh (Linear Search)\n"
		 << "8. Tim kiem nhi phan (Binary Search)\n";
	cout << "------------------------" << endl;

	int chon = 0;
	cout << "Chon: ";
	cin >> chon;
	cout << endl;
	return chon;
}

int main()
{
	int a[MAX];
	int chon = 0;
	int n, x, vt;

	do{
		chon = menu();

		switch(chon)
		{
		case 0:
			cout << "Nhan phim bat ky de thoat chuong trinh -> ";
			break;

		case 1:
			cout << "Nhap so phan tu cua mang (0 -> 100): ";
			cin >> n;
			cout << endl;
			nhap (a, n);
			cout << "Da nhap thanh cong!" << endl;
			break;

		case 2:
			cout << "Cac gia tri cua mang: " << endl;
			xuat (a, n);
			break;

		// Sắp xếp chọn trực tiếp.
		case 3:
			cout << "Mang TRUOC khi sap xep: ";
			xuat (a, n);
			selectionSort (a, n);
			cout << "Mang SAU khi sap xep: ";
			xuat (a, n);
			break;

		// Sắp xếp chèn trực tiếp.
		case 4:
			cout << "Mang TRUOC khi sap xep: ";
			xuat (a, n);
			insertionSort (a, n);
			cout << "Mang SAU khi sap xep: ";
			xuat (a, n);
			break;

		// Sắp xếp nổi bọt.
		case 5:
			cout << "Mang TRUOC khi sap xep: ";
			xuat (a, n);
			bubbleSort (a, n);
			cout << "Mang SAU khi sap xep: ";
			xuat (a, n);
			break;

		// Sắp xếp đổi chỗ trực tiếp.
		case 6:
			cout << "Mang TRUOC khi sap xep: ";
			xuat (a, n);
			interchangeSort (a, n);
			cout << "Mang SAU khi sap xep: ";
			xuat (a, n);
			break;

		// Tìm kiếm tuần tự / tuyến tính.
		case 7:
			cout << "Nhap gia tri can tim: ";
			cin >> x;
			cout << endl;
			vt = linearSearch(a, n, x);
			if (vt == -1)
				cout << "Khong tim thay gia tri " << x << endl;
			else
				cout << "Tim thay gia tri " << x << " tai vi tri " << vt << endl;
			break;

		// Tìm kiếm nhị phân.
		case 8:
			cout << "Nhap gia tri can tim: ";
			cin >> x;
			cout << endl;
			vt = binarySearch(a, n, x);
			if (vt == -1)
				cout << "Khong tim thay gia tri " << x << endl;
			else
				cout << "Tim thay gia tri " << x << " tai vi tri " << vt << endl;
			break;

		default:
			cout << "Gia tri chon khong hop le!" << endl;
			break;
		}
	}while(chon != 0);
	return 0;
}