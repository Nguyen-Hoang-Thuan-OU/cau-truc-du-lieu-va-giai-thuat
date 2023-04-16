#include<iostream>
using namespace std;

void nhapMang (int a[], int &n, int &k)
{
	do{
		cout << "Nhap so luong phan tu: ";
		cin >> n;
	}while (n <= 0 || n > 100);

	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]= ";
		do{
			cin >> a[i];

			if (a[i] < 0)
				cout << endl;
		}while (a[i] < 0);
	}

	for (int i = 0; i < n; i++)
	{
		if (k < a[i])
			k = a[i];
	}
}

void countingSort (int a[], int b[], int k, int n, int &kt, int &ss, int &gan, int &toan)
{
	int i, j;
	int c[100];

	for (gan++, i = 0; ss++, i <= k; gan++, toan++, i++)
	{
		c[i] = 0;
		gan++;
	}

	for (gan++, j = 0; ss++, j < n; gan++, toan++, j++)
	{
		c[a[j]]++;
		gan++;
		toan++;
	}

	kt = 0;
	gan++;

	for (gan++, j = 0; ss++, j <= k; gan++, toan++, j++)
	{
		while (ss++, c[j] > 0)
		{
			b[kt++] = j;
			gan+=2;
			toan++;
			c[j]--;
			gan++;
			toan++;
		}
	}
}

void xuatMang (int b[], int kt, int ss, int gan, int toan)
{
	cout << "\nMang sap xep tang: ";
	for (int i = 0; i < kt; i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;

	cout << "Tong so phep so sanh:" << ss << endl;
	cout << "Tong so phep gan:" << gan << endl;
	cout << "Tong so phep toan:" << toan << endl;
}

void main()
{
	int ss, gan, toan;
	ss = gan = toan = 0;

	int n, k = 0, kt;
	int a[100];
	int b[100];
	nhapMang(a, n, k);
	countingSort(a, b, k, n, kt, ss, gan, toan);
	xuatMang(b, kt, ss, gan, toan);
}