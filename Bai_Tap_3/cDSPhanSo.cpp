#include "cDSPhanSo.h"
#include <cmath>
#include<algorithm>
PhanSo::PhanSo() {};
PhanSo::PhanSo(int tu, int mau)
{
	this->tu = tu;
	this->mau = mau;
}
int ucln(int a, int b)
{
	if (b == 0) return a;
	return ucln(b,a % b);
}
int PhanSo::getTu()
{
	return tu;
}
int PhanSo::getMau()
{
	return mau;
}
void PhanSo::rut_gon()
{
	int u = ucln(tu, mau);
	if (u == 0) return;
	tu /= u;
	mau /= u;
}
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
void PhanSo::Xuat()
{
	if (tu % mau == 0) cout << tu / mau;
	else if (tu < 0 && mau < 0) cout << -tu << "/" << -mau;
	else if (tu < 0 || mau < 0) cout << -abs(tu) << "/" << abs(mau);
	else cout << tu << "/" << mau;
}
PhanSo operator +(PhanSo p1, PhanSo p2)
{
	PhanSo p;
	p.tu = p1.tu * p2.mau + p2.tu * p1.mau;
	p.mau = p1.mau * p2.mau;
	return p;
}
PhanSo operator +(PhanSo p1, int x)
{
	PhanSo p;
	p.tu = p1.mau * x + p1.tu;
	p.mau = p1.mau;
	return p;
}
PhanSo operator +(int x, PhanSo p1)
{
	PhanSo p;
	p.tu = p1.mau * x + p1.tu;
	p.mau = p1.mau;
	return p;
}
istream& operator>>(istream& is, PhanSo& x)
{
	x.Nhap();
	return is;
}
ostream& operator<<(ostream& os, PhanSo x)
{
	x.Xuat();
	return os;
}
int cDSPhanSo::getN()
{
	return n;
}
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
void cDSPhanSo::Xuat()
{
	for(int i = 0; i < n - 1; i++)
	{
		cout << p[i] << "; ";
	}
	cout << p[n - 1];
}
istream& operator>>(istream& is, cDSPhanSo& x)
{
	x.Nhap();
	return is;
}
ostream& operator<<(ostream& os, cDSPhanSo x)
{
	x.Xuat();
	return os;
}
PhanSo cDSPhanSo::Sum()
{
	PhanSo kq = p[0];
	for(int i =1;i < n; i++)
	{
		kq = kq + p[i];
	}
	kq.rut_gon();
	return kq;
}
bool cmp_tang_dan(PhanSo p1, PhanSo p2)
{
	return (double)p1.getTu() / p1.getMau() < (double)p2.getTu() / p2.getMau();
}
bool cmp_giam_dan(PhanSo p1, PhanSo p2)
{
	return (double)p1.getTu() / p1.getMau() > (double)p2.getTu() / p2.getMau();
}
void cDSPhanSo::SapXepTangDan()
{
	sort(p.begin(), p.end(), cmp_tang_dan);
}
void cDSPhanSo::SapXepGiamDan()
{
	sort(p.begin(), p.end(), cmp_giam_dan);
}
PhanSo cDSPhanSo::findMax()
{
	this->SapXepGiamDan();
	return p[0];
}
PhanSo cDSPhanSo::findMin()
{
	this->SapXepTangDan();
	return p[0];
}
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
