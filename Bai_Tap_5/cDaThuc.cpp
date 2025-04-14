#include "cDaThuc.h"
#include <cmath>
//Hàm constructor mặc định gán số hệ số bằng 0
cDaThuc::cDaThuc()
{
	n = 0;
}
//Ham constructor sao chép, sao chép số hệ số và giá trị của từng hệ số 
cDaThuc::cDaThuc(const vector<double> x)
{
	n = x.size();
	for (int i = 0; i < n; i++)
	{
		this->he_so.push_back(x[i]);
	}
}
//Hàm getter trả về giá trị của số hệ số
int cDaThuc::getN()
{
	return n;
}
//Hàm nhập và kiểm tra dữ liệu nhập
void cDaThuc::Nhap()
{
	cout << "Nhap so phan tu: ";
	cin >> n;
	while (n < 0 || cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap so phan tu: ";
		cin >> n;
	}
	if (n == 0) return;
	he_so.clear();
	cout << "Nhap lan luot he so cua da thuc: ";
	for (int i = 0; i < n; i++)
	{
		double tmp;
		cin >> tmp;
		he_so.push_back(tmp);
	}
}
//Hàm xuất đa thức đúng chuẩn, đảm bảo đúng logic
void cDaThuc::Xuat()
{
	for (int i = 0; i < n; i++)
	{
	    if (he_so[i] < 0) cout << he_so[i];
		else if(i != 0 && he_so[i] > 0) cout <<"+ " << he_so[i];
		else if(he_so[i] != 0) cout << he_so[i];
		if (n - i - 1 == 0 || he_so[i] == 0) continue;
		else if (n - i - 1 == 1) cout << "x ";	
		else cout << "x^" << n - i - 1<<" ";
	}
}
//Hàm tính đa thức khi truyền giá trị vào bằng cách thay giá trí x vào biến x
long long cDaThuc::tinhX(int x)
{
	long long res = 0;
	for (int i = 0; i < n; i++)
	{
		res += he_so[i] * pow(x, n - i - 1);
	}
	return res;
}
//Hàm cộng hai đa thức và trả về kết quả của 1 đa thức kết quả
cDaThuc cDaThuc::cong(cDaThuc x)
{
	int size;
	if (this->he_so.size() > x.n) size = this->he_so.size();
	else size = x.n;
	vector <double> he_soA = this->he_so;
	vector <double> he_soB = x.he_so;
	while (he_soA.size() < size) he_soA.insert(he_soA.begin(), 0);
	while (he_soB.size() < size) he_soB.insert(he_soB.begin(), 0);
	vector <double> he_so_kq(size);
	for (int i = 0; i < size; i++)
	{
		he_so_kq[i] = he_soA[i] + he_soB[i];
	}
	cDaThuc kq;
	kq.he_so = he_so_kq;
	kq.n = size;
	return kq;
}
//Hàm trừ hai đa thức và trả về kết quả của 1 đa thức kết quả
cDaThuc cDaThuc::tru(cDaThuc x)
{
	int size;
	if (this->he_so.size() > x.n) size = this->he_so.size();
	else size = x.n;
	vector <double> he_soA = this->he_so;
	vector <double> he_soB = x.he_so;
	while (he_soA.size() < size) he_soA.insert(he_soA.begin(), 0);
	while (he_soB.size() < size) he_soB.insert(he_soB.begin(), 0);
	vector <double> he_so_kq(size);
	for (int i = 0; i < size; i++)
	{
		he_so_kq[i] = he_soA[i] - he_soB[i];
	}
	cDaThuc kq;
	kq.he_so = he_so_kq;
	kq.n = size;
	return kq;
}