#include<iostream>
using namespace std;

void nhapMang (int a[], int &n)
{
	do{
		cout << "So luong phan tu: ";
		cin >> n;
	}while(n <= 0 || n > 100);

	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]= ";
		cin >> a[i];
	}
	cout << endl;
}

void hoanVi (int &x, int &y)
{
	int tam = x;
	x = y;
	y = tam;
}

void quickSort (int a[], int left, int right, int &ss, int &hv, int &gan, int &toan)
{
	int i, j, x;
	x = a[(left + right) / 2];
	gan++;
	toan += 2;
	i = left;
	gan++;
	j = right;
	gan++;

	while (ss++, i <= j)
	{
		while (ss++, a[i] < x)
		{
			gan++;
			toan++;
			i++;
		}

		while (ss++, a[j] > x)
		{
			gan++;
			toan++;
			j--;
		}

		if (ss++, i <= j)
		{
			hoanVi(a[i], a[j]);
			hv++;
			gan +=3;
			i++;
			j--;
			gan += 2;
			toan += 2;
		}
	}

	if (ss++, left < j)
		quickSort (a, left, j, ss, hv, gan, toan);
	if (ss++, i < right)
		quickSort (a, i, right, ss, hv, gan, toan);
}

void xuatMang (int a[], int n, int ss, int hv, int gan, int toan)
{
	cout << "Mang sau khi giam la: ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "  ";
	}
	cout << endl;
	cout << "So phep so sanh: " << ss << endl;
	cout << "So phep hoan vi: " << hv << endl;
	cout << "So phep gan: " << gan << endl;
	cout << "So phep toan: " << toan << endl;
	cout << endl;
}

void main()
{
	int a[100], n, left, right;
	int ss = 0;
	int hv = 0;
	int gan = 0;
	int toan = 0;
	nhapMang(a, n);
	left = 0;
	right = n - 1;
	quickSort (a, left, right, ss, hv, gan, toan);
	xuatMang (a, n, ss, hv, gan, toan);
}