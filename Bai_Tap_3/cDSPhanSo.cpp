#include "cDSPhanSo.h"
#include <cmath>
#include<algorithm>
//Hàm constructor mặc đinh để khởi tạo phân số
PhanSo::PhanSo() {};
//Ham constructor có truyền tham số để khởi tạo phân số
PhanSo::PhanSo(int tu, int mau)
{
	this->tu = tu;
	this->mau = mau;
}
//Ham tính ước chung lớn nhất, sử dụng đệ quy và trả về kết quả
int ucln(int a, int b)
{
	if (b == 0) return a;
	return ucln(b,a % b);
}
//Hàm getter trả về giá trị của tử số
int PhanSo::getTu()
{
	return tu;
}
//Hàm getter trả về giá trị của mẫu số
int PhanSo::getMau()
{
	return mau;
}
//Hàm rút gọn phân số bằng cách chia cả tử và mẫu cho ucln
void PhanSo::rut_gon()
{
	int u = ucln(tu, mau);
	if (u == 0) return;
	tu /= u;
	mau /= u;
}
//Ham nhập và kiểm tra dữ liệu nhập
void PhanSo::Nhap()
{
	cout << "Nhap tu so: ";
	cin >> tu;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap tu so: ";
		cin >> tu;
	}
	cout << "Nhap mau so: ";
	cin >> mau;
	while (cin.fail() || mau == 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap mau so: ";
		cin >> mau;
	}
}
//Hàm xuất phân số đảm bảo đúng logic
void PhanSo::Xuat()
{
	if (tu % mau == 0) cout << tu / mau;
	else if (tu < 0 && mau < 0) cout << -tu << "/" << -mau;
	else if (tu < 0 || mau < 0) cout << -abs(tu) << "/" << abs(mau);
	else cout << tu << "/" << mau;
}
//Nạp chồng toán tử cộng hai phân số, trả về phân số kết quả
PhanSo operator +(PhanSo p1, PhanSo p2)
{
	PhanSo p;
	p.tu = p1.tu * p2.mau + p2.tu * p1.mau;
	p.mau = p1.mau * p2.mau;
	return p;
}
//Hàm nạp chồng toán tử cộng phân số với số nguyên, trả về phân số kết quả
PhanSo operator +(PhanSo p1, int x)
{
	PhanSo p;
	p.tu = p1.mau * x + p1.tu;
	p.mau = p1.mau;
	return p;
}
//Hàm nạp chồng toán tử cộng số nguyên với phân số, trả về phân số kết quả
PhanSo operator +(int x, PhanSo p1)
{
	PhanSo p;
	p.tu = p1.mau * x + p1.tu;
	p.mau = p1.mau;
	return p;
}
//Hàm nạp chồng toán tử nhập bằng cách gọi hàm nhập và return luồng nhập
istream& operator>>(istream& is, PhanSo& x)
{
	x.Nhap();
	return is;
}
//Hàm nạp chồng toán tử xuất bằng cách gọi hàm xuất và return luồng xuất
ostream& operator<<(ostream& os, PhanSo x)
{
	x.Xuat();
	return os;
}
//Hàm getter trả về giá trị n
int cDSPhanSo::getN()
{
	return n;
}
//Hàm nhập mảng phân số
void cDSPhanSo::Nhap()
{
	cout << "Nhap so phan so: ";
	cin >> n;
	if (n == 0) return;
	for (int i = 0; i < n; i++)
	{
		cout << "-----Nhap phan so thu " << i + 1 << "------" << endl;
		PhanSo tmp;
		cin >> tmp;
		tmp.rut_gon();
		p.push_back(tmp);
	}
}
//Hàm xuất mảng phân số theo thứ tự
void cDSPhanSo::Xuat()
{
	for(int i = 0; i < n - 1; i++)
	{
		cout << p[i] << "; ";
	}
	cout << p[n - 1];
}
//Hàm nạp chồng toán tử nhập bằng cách gọi hàm nhập danh sách và trả về luồng nhập
istream& operator>>(istream& is, cDSPhanSo& x)
{
	x.Nhap();
	return is;
}
//Hàm nạp chồng toán tử xuất bằng cách gọi hàm xuất danh sách và trả về luồng xuất
ostream& operator<<(ostream& os, cDSPhanSo x)
{
	x.Xuat();
	return os;
}
//Hàm tính tổng các phân số, trả về phân số kết quả
PhanSo cDSPhanSo::Sum()
{
	PhanSo kq = p[0];
	for(int i =1;i < n; i++)
	{
		kq = kq + p[i];
		kq.rut_gon();
	}
	return kq;
}
//Comparator để phục vụ việc sắp xếp mảng tăng dần cho hàm sort
bool cmp_tang_dan(PhanSo p1, PhanSo p2)
{
	return (double)p1.getTu() / p1.getMau() < (double)p2.getTu() / p2.getMau();
}
//Comparator để phục vụ việc sắp xếp mảng giảm dần cho hàm sort
bool cmp_giam_dan(PhanSo p1, PhanSo p2)
{
	return (double)p1.getTu() / p1.getMau() > (double)p2.getTu() / p2.getMau();
}
//Hàm sắp xếp tăng dần bằng cách gọi hàm sort từ đầu tới cuối mảng với phép so sánh cmp tăng dần
void cDSPhanSo::SapXepTangDan()
{
	sort(p.begin(), p.end(), cmp_tang_dan);
}
//Hàm sắp xếp giảm dần bằng cách gọi hàm sort từ đầu tới cuối mảng với phép so sánh cmp giảm dần
void cDSPhanSo::SapXepGiamDan()
{
	sort(p.begin(), p.end(), cmp_giam_dan);
}
//Hàm tìm phân số lớn nhất bằng cách trả về giá trị đầu tiên của mảng đã sắp xếp giảm dần
PhanSo cDSPhanSo::findMax()
{
	this->SapXepGiamDan();
	return p[0];
}
//Hàm tìm phân số nhỏ nhất bằng cách trả về giá trị đầu tiên của mảng đã sắp xếp tăng dần
PhanSo cDSPhanSo::findMin()
{
	this->SapXepTangDan();
	return p[0];
}
//Hàm tìm phân số có tử số lớn nhất bằng cách duyệt hai vòng lặp và trả về phân số kết quả
PhanSo cDSPhanSo::findMaxTu()
{
	if (p.empty()) return PhanSo();
	int max_tu = p[0].getTu();
	PhanSo kq;
	for (int i = 0; i < n; i++)
	{
		if (p[i].getTu() > max_tu)
			max_tu = p[i].getTu();
	}
	for (int i = 0; i < n; i++)
	{
		if (p[i].getTu() == max_tu)
			return p[i];
	}
}
