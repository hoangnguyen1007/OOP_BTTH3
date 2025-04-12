#pragma once
#include<iostream>
class cArray
{
private:
	int *a;
	int n;
public:
	cArray();
	cArray(const cArray&);
	void Tao_mang();
	void Xuat() const;
	int so_lan_xuat_hien(int x);
	bool ktra_tang_dan();
	int tim_le_max();
	int tim_snt_max();
	void sap_xep_tang_dan();
	void sap_xep_giam_dan();
};

