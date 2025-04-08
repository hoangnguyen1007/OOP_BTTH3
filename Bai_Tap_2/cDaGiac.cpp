#include "cDaGiac.h"
#include <iostream>
#include <vector>
#include "graphics.h"
#pragma comment(lib, "graphics.lib")
using namespace std;
constexpr double PI = 3.14159265358979323846;
//Ham tinh va tra ve tich co huong cua ba diem 
float tich_co_huong(Diem a,  Diem b,  Diem c)
{
	float x1 = a.getX() - b.getX(), y1 = b.getY() - a.getY();
	float x2 = c.getX() - a.getX(), y2 = c.getY() - a.getY();
	return x1 * y2 - y1 * x2;
}
//Ham kiem tra va tra ve gia tri bool xem 3 diem co thang hang khong
bool thang_hang(Diem a, Diem& b, Diem& c) 
{
	return fabs(tich_co_huong(a, b, c)) < 1e-6;
}
//Ham kiem tra va tra ve gia tri bool xem co duong thang tich co huong nao giao nhau khong
bool giao_nhau(Diem a, Diem b, Diem c, Diem d)
{
	float d1 = tich_co_huong(c, d, a);
	float d2 = tich_co_huong(c, d, b);
	float d3 = tich_co_huong(a, b, c);
	float d4 = tich_co_huong(a, b, d);
	return (d1 * d2 < 0) && (d3 * d4 < 0);
}
//Ham nhap diem va kiem tra du lieu dau vao
void Diem::Nhap()
{
	cin >> x;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cin >> x;
	}
	cin >> y;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cin >> y;
	}
}
//Ham xuat thong tin diem duoc nhap
void Diem::Xuat() const
{
	cout << "(" << x << ", " << y << ")";
}
//Ham tinh va tra ve khoang cach tu diem this den diem d duoc truyen vao
double Diem::KhoangCach(Diem d) const
{
	return sqrt(pow(x - d.x, 2) + pow(y - d.y, 2));
}
//Ham nhan vao 2 gia tri dx dy de thay doi gia tri cua 1 diem
void Diem::DiChuyen(int dx, int dy)
{
	x += dx;
	y += dy;
}
//Ham getter tra ve gia tri cua toa do x
double Diem::getX() const
{
	return x;
}
//Ham getter tra ve gia tri cua toa do y
double Diem::getY() const
{
	return y;
}
//Ham setter dung de thay doi gia tri cua toa do x
void Diem::setX(double x)
{
	this->x = x;
}
//Ham setter dung de thay doi gia tri cua toa do y
void Diem::setY(double y)
{
	this->y = y;
}
//Ham nap chong toan tu nhap va kiem tra du lieu 
istream& operator>>(istream& is, cDaGiac& x)
{
	cout << "Nhap so dinh cua da giac: ";
	cin >> x.soDinh;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le vui long nhap lai!" << endl;
		cout << "Nhap so dinh cua da giac: ";
		cin >> x.soDinh;
	}
	cout << "Nhap " << x.soDinh << " dinh cua da giac: ";
	for (int i = 0; i < x.soDinh; i++)
	{
		Diem tmp;
		tmp.Nhap();
		x.dinh.push_back(tmp);
	}
	return is;
}
//Ham nap chong toan tu xuat
ostream& operator<<(ostream& os, cDaGiac x)
{
	cout << "Da giac co " << x.soDinh << " dinh bao gom:" << endl;
	for (auto x : x.dinh)
	{
		x.Xuat();
		cout << endl;
	}
	return os;
}
//Ham kiem tra va tra ve gia tri bool xem co phai da giac khong
bool cDaGiac::Ktra() const
{
	int n = dinh.size();
	if (n < 3) return false;
	for (int i = 0; i < n; ++i)
	{
		Diem a = dinh[i];
		Diem b = dinh[(i + 1) % n];
		Diem c = dinh[(i + 2) % n];
		if (thang_hang(a, b, c)) return false;
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (abs(i - j) <= 1 || (i == 0 && j == n - 1)) continue;
			const Diem& a = dinh[i];
			const Diem& b = dinh[(i + 1) % n];
			const Diem& c = dinh[j];
			const Diem& d = dinh[(j + 1) % n];
			if (giao_nhau(a, b, c, d)) return false;
		}
	}
	return true;
}
//Ham kiem tra va tra ve gia tri bool xem co phai da giac loi khong
bool cDaGiac::ktra_loi() const
{
	int n = dinh.size();
	if (n < 3) return false;
	bool sign = false;
	for (int i = 0; i < n; ++i)
	{
		float cp = tich_co_huong(dinh[i], dinh[(i + 1) % n], dinh[(i + 2) % n]);
		if (fabs(cp) < 1e-6) continue;
		if (i == 0) sign = cp > 0;
		else if ((cp > 0) != sign)
			return false;
	}
	return true;
}
//Ham kiem tra va tra ve gia tri bool xem co phai da giac deu khong
bool cDaGiac::ktra_deu() const
{
	int n = dinh.size();
	if (n < 3) return false;
	double d = dinh[0].KhoangCach(dinh[1]);
	for (int i = 1; i < n; ++i)
	{
		if (fabs(dinh[i].KhoangCach(dinh[(i + 1) % n]) - d) > 1e-6)
			return false;
	}
	return true;
}
//Ham kiem tra va tra ve chuoi ten loai da giac
string cDaGiac::PhanLoaiDaGiac() const
{
	int n = dinh.size();
	if (n < 3 || !Ktra()) return "Khong phai da giac!";
	if (ktra_deu()) return "Da giac deu!";
	if (ktra_loi()) return "Da giac loi!";
	return "Da giac lom!";
}
//Ham tinh chu vi da giac
double cDaGiac::ChuVi() const
{
	double chuvi = 0;
	int n = dinh.size();
	for (int i = 0; i < n; ++i)
	{
		chuvi += dinh[i].KhoangCach(dinh[(i + 1) % n]);
	}
	return chuvi;
}
//Ham tinh dien tich da giac
double cDaGiac::DienTich() const
{
	double sum = 0;
	int n = dinh.size();
	for (int i = 0; i < n; ++i)
	{
		const Diem& a = dinh[i];
		const Diem& b = dinh[(i + 1) % n];
		sum += (a.getX() * b.getY() - b.getX() * a.getY());
	}
	return fabs(sum) / 2.0;
}
//Ham tinh tien da giac theo 1 vector
void cDaGiac::TinhTien(int x, int y)
{
	for (int i = 0; i < dinh.size(); i++)
	{
		dinh[i].DiChuyen(x, y);
	}
}
//Ham quay da giac theo tam (x, y) mot goc p do
void cDaGiac::Quay(int x, int y, int p)
{
	double rad = p * PI / 180.0;
	Diem tam;
	tam.setX(x);
	tam.setY(y);
	for (auto& d : dinh)
	{
		double dx = d.getX() - tam.getX();
		double dy = d.getY() - tam.getY();
		double x_new = dx * cos(rad) - dy * sin(rad);
		double y_new = dx * sin(rad) + dy * cos(rad);
		d.setX(x_new + tam.getX());
		d.setY(y_new + tam.getY());
	}
}
//Ham phong to, thu nho da giac theo tam vi tu mot he so k
void cDaGiac::PhongTo_ThuNho(double x, double y, double k)
{
	for (auto& d : dinh)
	{
		d.setX( x + k * (d.getX() - x));
		d.setY ( y + k * (d.getY() - y));
	}
}
//Ham ve da giac trong cua so 800x600 bang cach dung thu vien graphics.h
void cDaGiac::ve_da_giac()
{
	initwindow(800, 600);
	int offsetX = 800 / 2;
	int offsetY = 600 / 2;
	for (int i = 0; i < dinh.size(); ++i)
	{
		int next = (i + 1) % dinh.size(); 
		line(dinh[i].getX() * 10 + offsetX, dinh[i].getY() * 10 + offsetY, dinh[next].getX() * 10 + offsetX, dinh[next].getY() * 10 + offsetY);
	}
}