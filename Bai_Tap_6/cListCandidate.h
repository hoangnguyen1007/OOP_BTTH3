#pragma once
#include <iostream>
#include <vector>
using namespace std;
class cCandidate
{
private:
	string ma, ten;
	int ngay, thang, nam;
	double toan, van, anh;
public:
	cCandidate();
	cCandidate(string, string, int, int, int, double, double, double);
	void Nhap();
	void Xuat() const;
	int getTongDiem() const;
};
class cListCandidate
{
private:
	int n;
	vector<cCandidate> TS;
public:
	cListCandidate();
	cListCandidate(const vector<cCandidate>);
	void Nhap();
	void Xuat() const;
	void Xuat1() const;
	cCandidate diem_max() const;
	void sap_xep();
	int getN();
};

