#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class cNhanVienVP
{
private:
	string ma, ten;
	int ngay, thang, nam;
	long long luong;
public:
	cNhanVienVP();
	cNhanVienVP(string, string, int, int, int, long long);
	string getMa() const;
	string getTen() const;
	int getNgay() const;
	int getThang() const;
	int getNam() const;
	long long getLuong() const;
	void setMa(string ma);
	void setTen(string ten);
	void setNgay(int ngay);
	void setThang(int thang);
	void setNam(int nam);
	void setLuong(long long luong);
	void Nhap();
	void Xuat() const;

};
class cListNhanVien
{
private:
	int n;
	vector<cNhanVienVP> nv;
public:
	cListNhanVien();
	cListNhanVien(vector<cNhanVienVP>);
	int getN() const;
	void Nhap();
	void Xuat() const;
	cNhanVienVP luong_cao_nhat();
	long long tong_luong() const;
	cNhanVienVP nv_cao_tuoi_nhat() const; 
	void sap_xep();
};

