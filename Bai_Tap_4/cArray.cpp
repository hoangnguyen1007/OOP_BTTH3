#include "cArray.h"
#include <iostream>
#include <algorithm>
using namespace std;
//Hàm constructor mặc định
cArray::cArray() {};
//Hàm sao constructor sao chép mảng
cArray::cArray(const cArray& m)
{
	if (m.n == 0)
	{
		a = NULL;
		this->n = 0;
	}
	else
	{
		a = new int[m.n];
		for (int i = 0; i < n; i++)
		{
			this->a[i] = m.a[i];
		}
	}
}
//Hàm getter trả về giá trị của biến n
int cArray::getN()
{
	return n;
}
//Hàm tạo mảng bằng cách sử dụng hàm random từ 1 đến 100
void cArray::Tao_mang()
{
	cout << "Nhap so phan tu trong mang: ";
	cin >> n;
	srand(time(NULL));
	a = new int[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100;
	}
}
//Hàm xuất các phần tử trong mảng theo thứ tự
void cArray::Xuat() const
{
	for (int i = 0; i < n; i++)
	{
		cout << *(a + i) <<" ";
	}
}
//Hàm đếm và trả về số lần xuất hiện của phần tử x có trong mảng bằng cách tăng biến đếm mỗi lần gặp
int cArray::so_lan_xuat_hien(int x)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x) dem++;
	}
	return dem;
}
//Hàm kiểm tra và trả về giá trị bool bằng cách kiểm tra phần tử hiện tại và đằng sau có bé hơn không
bool cArray::ktra_tang_dan()
{
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] > a[i + 1]) return 0;
	}
	return 1;
}
//Hàm tìm số lẻ lớn nhất bằng cách cập nhật biến max mỗi khi gặp số lẻ lớn hơn và trả về -2 nếu không có sổ lẻ nào trong mảng
int cArray::tim_le_max()
{
	int max = -2; //-2 vi mang random tu 1 den 100
	for (int i = 0; i < n; i++)
	{
		if ((a[i] % 2 != 0) && a[i] > max) max = a[i];
	}
	return max;
}
//Hàm kiểm tra xem x có phải là 1 số nguyên tố không
bool snt(int x)
{
	if (x < 2) return 0;
	for (int i = 2; i * i < x; i++)
	{
		if (x % i == 0) return 0;
	}
	return 1;
}
//Hàm tìm và trả về SNT lớn nhất bằng cách cập nhật biến max mỗi khi gặp SNT lớn hơn và trả về -2 nếu không có SNT nào
int cArray::tim_snt_max()
{
	int max = -2;
	for (int i = 0; i < n; i++)
	{
		if (snt(a[i]) && a[i] > max) max = a[i];
	}
	return max;
}
//Hàm heapify để thay đổi vị trí các phần tử để phần tử cha lớn hơn con
void heapify_max(int *a, int n, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < n && a[largest] < a[left]) largest = left;
	if (right < n && a[largest] < a[right]) largest = right;
	if (largest != i)
	{
		swap(a[largest], a[i]);
		heapify_max(a, n, largest);
	}
}
//Hàm heapify để thay đổi vị trí các phần tử để phần tử cha nhỏ hơn con
void heapify_min(int* a, int n, int i)
{
	int min = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < n && a[min] > a[left]) min = left;
	if (right < n && a[min] > a[right]) min = right;
	if (min != i)
	{
		swap(a[min], a[i]);
		heapify_min(a, n, min);
	}
}
//Hàm sắp xếp tăng dần dùng thuật toán heap sort
void heap_sort_tang(int *a, int n)
{
	for (int i = (n - 1) / 2; i >= 0; i--)
	{
		heapify_max(a, n, i);
	}
	for (int i = n - 1; i >= 0; i--)
	{
		swap(a[i], a[0]);
		heapify_max(a, i, 0);
	}
}
//Hàm sắp xếp giảm dần bằng thuật toán heap sort
void heap_sort_giam(int* a, int n)
{
	for (int i = (n - 1) / 2; i >= 0; i--)
	{
		heapify_min(a, n, i);
	}
	for (int i = n - 1; i >= 0; i--)
	{
		swap(a[i], a[0]);
		heapify_min(a, i, 0);
	}
}
//Hàm gọi thuật toán heap sort để sắp xếp mảng tăng dần
void cArray::sap_xep_tang_dan()
{
	heap_sort_tang(a, n);
}
//Hàm gọi thuật toán heap sort để sắp xếp mảng giảm dần
void cArray::sap_xep_giam_dan()
{
	heap_sort_giam(a, n);
}