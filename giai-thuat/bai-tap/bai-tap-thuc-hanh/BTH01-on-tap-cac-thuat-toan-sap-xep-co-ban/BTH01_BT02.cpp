#include<iostream>
using namespace std;

void nhapMang (int a[], int &n)
{
	do{
		cout << "Nhap so luong phan tu: ";
		cin >> n;
	}while(n <= 0 || n > 100);

	for (int i = 0; i < n; i ++)
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

void selectionSort (int a[], int n)
{
	int min;
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[min])
				min = j;
		}

		if (min != i)
			hoanVi (a[min], a[i]);
	}
}

void xuatMang (int a[], int n)
{
	cout << "\nMang sau khi sap xep tang dan: ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void main()
{
	int a[100], n;
	nhapMang (a, n);
	selectionSort (a, n);
	xuatMang (a, n);
}