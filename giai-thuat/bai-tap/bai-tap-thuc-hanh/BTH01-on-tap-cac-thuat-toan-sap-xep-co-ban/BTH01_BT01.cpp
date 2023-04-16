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

void xuatMang (int a[], int n)
{
	cout << "\nMang a: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]= " << a[i] << endl;
	}
}

void main()
{
	int a[100], n;
	nhapMang(a, n);
	xuatMang(a, n);
}