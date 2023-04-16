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

void shift (int a[], int i, int n, int &ss, int &hv, int &gan, int &toan)
{
	int j = 2 * i + 1;
	gan++;

	ss++;
	if (j >= n)
		return;

	ss++;
	if (j + 1 < n)
	{
		ss++;
		if (a[j] < a[j + 1])
		{
			gan++;
			j++;
		}
	}

	ss++;
	if (a[i] >= a[j])
		return;
	else
	{
		hv++;
		gan+=3;
		int x = a[i];
		a[i] = a[j];
		a[j] = x;
		shift (a, j, n, ss, hv, gan, toan);
	}
}

void heapSort (int a[], int n, int &ss, int &hv, int &gan, int &toan)
{
	int i = n / 2;
	gan++;

	while (i >= 0)
	{
		ss++;
		shift (a, i, n - 1, ss, hv, gan, toan);
		i--;
		gan++;
	}
	ss++;

	int right = n - 1;
	gan++;

	while (right > 0)
	{
		ss++;
		if (a[0] > a[right])
		{
			swap (a[0], a[right]);
			hv++;
			gan+=3;
		}
		right--;
		gan++;

		ss++;
		if (right > 0)
		{
			shift (a, 0, right, ss, hv, gan, toan);
		}
	}
	ss++;
}

void xuatMang (int a[], int n, int ss, int hv, int gan, int toan)
{
	cout << "Mang sau khi sap xep tang dan la: ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "  ";
	}
	cout << endl;

	cout << "Tong so phep so sanh=" << ss << endl;
	cout << "Tong so phep hoan vi=" << hv << endl;
	cout << "Tong so phep gan=" << gan << endl;
	cout << "Tong so phep toan=" << toan << endl;
}

void main()
{
	int ss, hv, gan, toan;
	ss = hv = gan = toan = 0;

	int a[100], n;
	nhapMang (a, n);
	heapSort (a, n, ss, hv, gan, toan);
	xuatMang (a, n, ss, hv, gan, toan);
}