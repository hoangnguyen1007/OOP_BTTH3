#pragma once
#include<iostream>
#include<vector>
using namespace std;
class PhanSo
{
private:
	int tu, mau;
public:
	PhanSo();
	PhanSo(int, int);
	void Nhap();
	void Xuat();
	friend istream& operator>>(istream&, PhanSo&);
	friend ostream& operator<<(ostream&, PhanSo);
	void rut_gon();
	friend PhanSo operator +(PhanSo, PhanSo);
	friend PhanSo operator +(PhanSo, int);
	friend PhanSo operator +(int, PhanSo);
	int getTu();
	int getMau();
};
class cDSPhanSo
{
private:
	int n;
	vector<PhanSo> p;
public:
	void Nhap();
	void Xuat();
	friend istream& operator>>(istream&, cDSPhanSo&);
	friend ostream& operator<<(ostream&, cDSPhanSo);
	PhanSo Sum();
	PhanSo findMax();
	PhanSo findMin();
	PhanSo findMaxTu();
	void SapXepTangDan();
	void SapXepGiamDan();
	int getN();
};

