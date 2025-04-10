#include <iostream>
#include "cDSPhanSo.h"
int main()
{
	cDSPhanSo x;
	cin >> x;
	if (x.getN() <= 0)
	{
		cout << "Mang phan so khong co phan tu nao ca!";
		return 0;
	}
	cout << "Tong cac phan so la: " << x.Sum() << endl;
	cout << "Phan so lon nhat la: " << x.findMax()<<endl;
	cout << "Phan so nho nhat la: " << x.findMin()<<endl;
	cout << "Phan so co tu la so nguyen lon nhat la: ";
	if (x.findMaxTu().getMau() == 1) cout << x.findMaxTu() << "/1";
	else cout << x.findMaxTu();
	cout << endl;
	cout << "Mang phan so khi sap xep tang dan: " << endl;
	x.SapXepTangDan();
	cout << x;
	cout << endl;
	cout << "Mang phan so khi sap xep giam dan: " << endl;
	x.SapXepGiamDan();
	cout << x;
}
