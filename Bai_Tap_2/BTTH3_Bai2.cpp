#include <iostream>
#include "graphics.h"
#include "cDaGiac.h"
#include <vector>
#pragma comment(lib, "graphics.lib")
using namespace std;
int main()
{
	int choose;
	cDaGiac a;
	cin >> a;
	double x, y, p, k, c;
	system("cls");
	do
	{
		cout << "=============CHUONG TRINH==============" << endl;
		cout << "1. Xuat cac diem cua da giac" << endl;
		cout << "2. Phan loai da giac" << endl;
		cout << "3. Tinh chu vi da giac" << endl;
		cout << "4. Tinh dien tich da giac" << endl;
		cout << "5. Tinh tien da giac" << endl;
		cout << "6. Quay da giac" << endl;
		cout << "7. Phong to da giac" << endl;
		cout << "8. Thu nho da giac" << endl;
		cout << "0. Thoat chuong trinh" << endl;
		cout << "========================================" << endl;
		cout << "Lua chon cua ban la: ";
		cin >> choose;
		switch (choose)
		{
		case 1:
			cout << a;
			a.ve_da_giac();
			break;
		case 2:
			cout << "Da giac nay la " << a.PhanLoaiDaGiac();
			break;
		case 3:
			if (!a.Ktra())
			{
				cout << "Khong the tinh chu vi!";
				break;
			}
			cout << "Chu vi cua da giac bang " << a.ChuVi();
			break;
		case 4:
			if (!a.Ktra())
			{
				cout << "Khong the tinh dien tich!";
				break;
			}
			cout << "Dien tich cua da giac bang " << a.DienTich();
			break;
		case 5:
			if (!a.Ktra())
			{
				cout << "Da giac khong hop le!";
				break;
			}
			cout << "Nhap vector ban muon tinh tien theo: ";
			cin >> x >> y;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << "Khong hop le! Vui long nhap lai!" << endl;
				cout << "Nhap vector ban muon tinh tien theo: ";
				cin >> x >> y;
			}
			a.TinhTien(x, y);
			cout << "Tinh tien tam giac thanh cong!" << endl;
			cout << a;
			a.ve_da_giac();
			break;
		case 6:
			if (!a.Ktra())
			{
				cout << "Da giac khong hop le!";
				break;
			}
			cout << "Nhap diem ban muon tam giac quay quanh: ";
			cin >> x >> y;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << "Khong hop le! Vui long nhap lai!" << endl;
				cout << "Nhap diem ban muon tam giac quay quanh: ";
				cin >> x >> y;
			}
			cout << "Nhap goc ban muon quay: ";
			cin >> p;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << "Khong hop le! Vui long nhap lai!" << endl;
				cout << "Nhap goc ban muon quay: ";
				cin >> p;
			}
			a.Quay(x, y, p);
			cout << "Quay da giac quanh diem (" << x << ", " << y << ") mot goc " << p << " do thanh cong!" << endl;
			cout << a;
			a.ve_da_giac();
			break;
		case 7:
			if (!a.Ktra())
			{
				cout << "Da giac khong hop le!";
				break;
			}
			cout << "Nhap tam vi tu ban muon phong to: ";
			cin >> x >> y;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << "Khong hop le! Vui long nhap lai!" << endl;
				cout << "Nhap tam vi tu ban muon phong to: ";
				cin >> x >> y;
			}
			cout << "Nhap he so k (k > 1) ban muon phong to: ";
			cin >> k;
			while (cin.fail() || k < 1)
			{
				cin.clear();
				cin.ignore();
				cout << "Khong hop le! Vui long nhap lai!" << endl;
				cout << "Nhap he so k (k > 1) ban muon phong to: ";
				cin >> k;
			}
			a.PhongTo_ThuNho(x, y, k);
			cout << "Phong to tam giac thanh cong!" << endl;
			cout << a;
			a.ve_da_giac();
			break;
		case 8:
			if (!a.Ktra())
			{
				cout << "Da giac khong hop le!";
				break;
			}
			cout << "Nhap tam vi tu ban muon thu nho: ";
			cin >> x >> y;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << "Khong hop le! Vui long nhap lai!" << endl;
				cout << "Nhap tam vi tu ban muon thu nho: ";
				cin >> x >> y;
			}
			cout << "Nhap he so k (0 < k < 1) ban muon thu nho: ";
			cin >> k;
			while (cin.fail() || k < 0 || k > 1)
			{
				cin.clear();
				cin.ignore();
				cout << "Khong hop le! Vui long nhap lai!" << endl;
				cout << "Nhap he so k (0 < k < 1) ban muon thu nho: ";
				cin >> k;
			}
			a.PhongTo_ThuNho(x, y, k);
			cout << "Thu nho tam giac thanh cong!" << endl;
			cout << a;
			a.ve_da_giac();
			break;
		case 0:
			closegraph();
			cout << "Dang thoat chuong trinh !....";
			return 0;
		default:
			cout << "Khong hop le! " << endl;
		}
		cout << "\n------------------------------" << endl;
		cout << "Ban co muon tiep tuc khong ?" << endl;
		cout << "1.Co" << endl;
		cout << "0.Khong" << endl;
		cout << "Lua chon cua ban la: ";
		cin >> c;
		system("cls");
	} while (c != 0);
	closegraph();
	cout << "Dang thoat chuong trinh !....";
	return 0;
}
