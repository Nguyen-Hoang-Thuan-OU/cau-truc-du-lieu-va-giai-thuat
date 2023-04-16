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

void selectionSort (int a[], int n, int &ss, int &hv, int &gan, int &toan)
{
	int min;
	int i, j;
	for (gan++, i = 0; ss++, i < n - 1; toan++, i++)
	{
		min = i;
		gan++;
		for (gan++, toan++, j = i + 1; ss++, j < n; toan++, j++)
		{
			ss++;
			if (a[j] < a[min])
			{
				min = j;
				gan++;
			}
		}

		ss++;
		if (min != i)
		{
			hoanVi (a[min], a[i]);
			hv++;
			gan+=3;
		}
	}
}

void xuatMang (int a[], int n, int ss, int hv, int gan, int toan)
{
	cout << "\nMang sau khi sap xep tang dan: ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	cout << "Tong so phep so sanh= " << ss << endl;
	cout << "Tong so phep hoan vi= " << hv << endl;
	cout << "Tong so phep gan= " << gan << endl;
	cout << "Tong so phep toan= " << toan << endl;
}

void main()
{
	int ss, hv, gan, toan;
	ss = hv = gan = toan = 0;

	int a[100], n;
	nhapMang (a, n);
	selectionSort (a, n, ss, hv, gan, toan);
	xuatMang (a, n, ss, hv, gan, toan);
}