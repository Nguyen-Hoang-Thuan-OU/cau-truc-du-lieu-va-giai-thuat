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
	cout << "Mang sau khi sap xep tang dan la: ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "  ";
	}
	cout << endl;
}

void shift (int a[], int i, int n)
{
	int j = 2 * i + 1;

	// Nếu vị trí j không tồn tại trong danh sách đang xét thì thoát khỏi chương trình.
	if (j >= n)
		return;

	// Nếu tồn tại vị trí j+1 trong danh sách đang xét thì thoát khỏi chương trình.
	if (j + 1 < n)

		// Nếu vị trí j không tồn tại phần tử a[j] <a[j+1].
		if (a[j] < a[j + 1])
			j++;
	if (a[i] >= a[j])
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

	// Tạo heap ban đầu.
	while (i >= 0)
	{
		shift (a, i, n - 1);
		i--;
	}


	// Right là vị trí cuối heap đang xét.
	int right = n - 1;

	while (right > 0)
	{
		if (a[0] > a[right])
			// Hoán vị phần tử a[0] cho phần tử cuối Heap đang xét.
			swap (a[0], a[right]);
		// Giới hạn lại phần tử cuối đang xét.
		right--;

		// Kiểm tra dãy đang xét còn nhiều hơn 1 phần.
		if (right > 0)
			// Tạo Heap lại tại vị trí 0.
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