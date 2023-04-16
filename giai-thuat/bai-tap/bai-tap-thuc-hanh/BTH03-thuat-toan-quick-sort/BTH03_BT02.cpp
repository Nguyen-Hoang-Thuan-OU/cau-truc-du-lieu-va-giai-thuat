#include<iostream>
using namespace std;

void nhapMang (int a[], int &n)
{
	do{
		cout << "So luong phan tu: ";
		cin >> n;
	}while (n <= 0 || n > 100);

	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]= ";
		cin >> a[i];
	}
	cout << endl;
}

void xuatMang (int a[], int n)
{
	cout << "Mang sau khi giam la: ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "  ";
	}
	cout << endl;
}

void hoanVi (int &x, int &y)
{
	int tam = x;
	x = y;
	y = tam;
}

void quickSort (int a[], int left, int right)
{
	int i, j, x;
	x = a[(left + right) / 2];
	i = left;
	j = right;

	while (i <= j)
	{
		while (a[i] > x) //
		{
			i++;
		}

		while (a[j] < x) //
		{
			j--;
		}

		if (i <= j)
		{
			hoanVi(a[i], a[j]);
			i++;
			j--;
		}
	}

	if (left < j)
		quickSort (a, left, j);
	if (i < right)
		quickSort (a, i, right);
}

void main()
{
	int a[100], n, left, right;
	nhapMang(a, n);
	left = 0;
	right = n - 1;
	quickSort (a, left, right);
	xuatMang (a, n);
}