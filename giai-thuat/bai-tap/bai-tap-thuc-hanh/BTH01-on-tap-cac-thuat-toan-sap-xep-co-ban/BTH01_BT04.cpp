#include<iostream>
using namespace std;

void nhapMang (int a[], int &n)
{
	do{
		cout << "Nhap so luong phan tu: ";
		cin >> n;
	}while(n <= 0 || n > 100);

	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]= ";
		cin >> a[i];
	}
}

void hoanVi (int &x, int &y)
{
	int tam = x;
	x = y;
	y = tam;
}

void bubbleSort (int a[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = n - 1; j > i; j--)
		{
			if (a[j] < a[j - 1])
				hoanVi (a[j], a[j - 1]);
		}
	}
}

void xuatMang (int a[], int n)
{
	cout << "\nMang sau khi sap xep tang dan la: ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "  ";
	}
	cout << endl;
}

void main()
{
	int a[100], n;
	nhapMang(a, n);
	bubbleSort(a, n);
	xuatMang(a, n);
}
