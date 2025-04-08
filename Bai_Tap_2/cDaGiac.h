#pragma once
#include<iostream>
#include<vector>
using namespace std;
class Diem
{
private:
	double x, y;
public:
	void Nhap();
	double KhoangCach(Diem d) const;
	void DiChuyen(int dx, int dy);
	void Xuat() const;
	void setX(double x);
	void setY(double y);
	double getX() const;
	double getY() const;
};
class cDaGiac
{
private:
	vector<Diem> dinh;
	int soDinh;
public:
	friend istream& operator>>(istream& is, cDaGiac &x);
	friend ostream& operator<<(ostream& os, cDaGiac x);
	bool Ktra() const;
	bool ktra_loi() const;
	bool ktra_deu() const;
	string PhanLoaiDaGiac() const;
	double ChuVi() const;
	double DienTich() const;
	void TinhTien(int x, int y);
	void Quay(int x, int y, int p);
	void PhongTo_ThuNho(double x, double y, double k);
	void ve_da_giac();
};