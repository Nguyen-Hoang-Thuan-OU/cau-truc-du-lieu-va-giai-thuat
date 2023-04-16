#include<iostream>
using namespace std;

void nhapMang (int a[], int &n, int &k)
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

	for (int i = 0; i < n; i++)
	{
		if (k < a[i])
			k = a[i];
	}
}

void xuatMang (int b[], int kt)
{
	cout << "\nMang sap xep tang: ";
	for (int i = 0; i < kt; i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;
}

void countingSort (int a[], int b[], int k, int n, int &kt)
{
	int i, j;
	int c[100];

	for (i = 0; i <= k; i++)
	{
		c[i] = 0;
	}

	for (j = 0; j < n; j++)
	{
		c[a[j]]++;
	}

	kt = 0;

	for (j = 0; j <= k; j++)
	{
		while (c[j] > 0)
		{
			b[kt++] = j;
			c[j]--;
		}
	}
}

void main()
{
	int n, k = 0, kt;
	int a[100];
	int b[100];
	nhapMang(a, n, k);
	countingSort(a, b, k, n, kt);
	xuatMang(b, kt);
}