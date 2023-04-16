#include<iostream>
using namespace std;

void nhapMang (int a[], int &n)
{
	do{
		cout << "So luong phan tu: ";
		cin >> n;
	}while(n <= 0 || n >100);

	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]= ";
		cin >> a[i];
	}
	cout << endl;
}

void xuatMang (int a[], int n)
{
	cout << "Mang sau khi sap xep giam dan la: ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "  ";
	}
	cout << endl;
}

void shift (int a[], int i, int n)
{
	int j = 2 * i + 1;

	if (j >= n)
		return;
	if (j + 1 < n)
		if (a[j] > a[j + 1]) //
			j++;
	if (a[i] <= a[j]) //
		return;
	else
	{
		int x = a[i];
		a[i] = a[j];
		a[j] = x;
		shift (a, j, n);
	}
}

void heapSort (int a[], int n)
{
	int i = n / 2;

	while (i >= 0)
	{
		shift (a, i, n - 1);
		i--;
	}

	int right = n - 1;

	while (right > 0)
	{
		if (a[0] < a[right]) //
			swap (a[0], a[right]);
		right--;
		if (right > 0)
			shift (a, 0, right);
	}
}

void main()
{
	int a[100], n;
	nhapMang (a, n);
	heapSort (a, n);
	xuatMang (a, n);
}