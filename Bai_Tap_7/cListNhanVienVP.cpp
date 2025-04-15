#include "cListNhanVienVP.h"
#include <algorithm>
//Hàm kiểm tra và trả về giá trị bool xem năm truyền vào có phải năm nhuận không
bool NamNhuan(int nam)
{
	if (nam % 4 == 0 && nam % 100 != 0 || nam % 400 == 0) return 1;
	return 0;
}
//Hàm sử dụng switch case nhận thông tin tháng và năm và trả về số ngày tương ứng
int SoNgayTrongThang(int thang, int nam)
{
	switch (thang)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
		break;
	case 2:
		if (NamNhuan(nam)) return 29;
		else return 28;
		break;
	default:
		return -1;
	}
}
//Hàm constructor mặc định của lớp cNhanVienVP
cNhanVienVP::cNhanVienVP() {};
//Hàm constructor có truyền tham trị của lớp cNhanVienVP
cNhanVienVP::cNhanVienVP(string, string, int, int, int, long long)
{
	this->ma = ma;
	this->ten = ten;
	this->ngay = ngay;
	this->thang = thang;
	this->nam = nam;
	this->luong = luong;
}
//Hàm getter trả về giá trị mã nhân viên
string cNhanVienVP::getMa() const
{
	return ma;
}
//Hàm getter trả về giá trị họ và tên nhân viên
string cNhanVienVP::getTen() const
{
	return ten;
}
//Hàm getter trả về giá trị ngày sinh của nhân viên
int cNhanVienVP::getNgay() const
{
	return ngay;
}
//Hàm getter trả về giá trị tháng sinh của nhân viên
int cNhanVienVP::getThang() const
{
	return thang;
}
//Hàm getter trả về giá trị năm sinh của nhân viên
int cNhanVienVP::getNam() const
{
	return nam;
}
//Hàm getter trả về giá trị lương của nhân viên
long long cNhanVienVP::getLuong() const
{
	return luong;
}
//Hàm setter cho thuộc tính mã nhân viên
void cNhanVienVP::setMa(string ma)
{
	this->ma = ma;
}
//Hàm setter cho thuộc tính họ và tên nhân viên
void cNhanVienVP::setTen(string ten)
{
	this->ten = ten;
}
//Hàm setter cho thuộc tính ngày sinh của nhân viên
void cNhanVienVP::setNgay(int ngay)
{
	this->ngay = ngay;
}//Hàm setter cho thuộc tính tháng sinh của nhân viên
void cNhanVienVP::setThang(int thang)
{
	this->thang = thang;
}
//Hàm setter cho thuộc tính năm sinh của nhân viên
void cNhanVienVP::setNam(int nam)
{
	this->nam = nam;
}
//Hàm setter cho thuộc tính lương của nhân viên
void cNhanVienVP::setLuong(long long luong)
{
	this->luong = luong;
}
//Hàm nhập và kiểm tra điều kiện nhập của 1 nhân viên
void cNhanVienVP::Nhap()
{
	cout << "Nhap ma nhan vien: ";
	cin >> ma;
	cout << "Nhap ho ten nhan vien: ";
	cin.ignore();
	getline(cin, ten);
	cout << "Nhap ngay thang nam sinh: ";
	cin >> ngay >> thang >> nam;
	while (cin.fail() || ngay < 0 || ngay > 31 || thang < 0 || thang > 12 || nam < 0 || ngay > SoNgayTrongThang(thang, nam))
	{
		cin.clear();
		cin.ignore();
		cout << "Nhap ngay thang nam: ";
		cin >> ngay >> thang >> nam;
	}
	cout << "Nhap luong cua cua nhan vien: ";
	cin >> luong;
	while (luong < 0 || cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap luong cua cua nhan vien: " << endl;
		cin >> luong;
	}
}
//Hàm xuất thông tin của 1 nhân viên
void cNhanVienVP::Xuat() const
{
	cout << "- Ma nhan vien: ";
	cout << ma<<endl;
	cout << "- Ho va ten nhan vien: " << ten << endl;
	cout << "- Ngay thang nam sinh: ";
	if (ngay < 10) cout << 0;
	cout << ngay << "/";
	if (thang < 10) cout << 0;
	cout << thang << "/" << nam;
	cout << endl;
	cout << "- Luong: " << luong;
}
//Hàm constructor mặc định của cListNhanVien
cListNhanVien::cListNhanVien() {};
//Hàm constructor sao chép từ 1 vector nhân viên của cListNhanVien
cListNhanVien::cListNhanVien(vector<cNhanVienVP> x)
{
	this->n = x.size();
	for (int i = 0; i < n; i++)
	{
		nv.push_back(x[i]);
	}
}
//Hàm getter trả về giá trị số lượng nhân viên
int cListNhanVien::getN() const
{
	return n;
}
//Hàm nhập và kiểm tra dữ liệu nhập của 1 dãy nhân viên
void cListNhanVien::Nhap()
{
	cout << "Nhap so nhan vien: ";
	cin >> n;
	while (cin.fail() || n < 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap so nhan vien: ";
		cin >> n;
	}
	for (int i = 0; i < n; i++)
	{
		cout << "-----Nhap thong tin nhan vien " << i + 1 << ":-----" << endl;
		cNhanVienVP tmp;
		tmp.Nhap();
		nv.push_back(tmp);
	}
}
//Hàm xuất thông tin của từng nhân viên trong danh sách
void cListNhanVien::Xuat() const
{
	for (int i = 0; i < n; i++)
	{
		cout << "-----Thong tin nhan vien thu " << i + 1 << ":-----" << endl;
		nv[i].Xuat();
	}
}
//Hàm tìm kiếm và trả về thông tin nhân viên có lương cao nhất
cNhanVienVP cListNhanVien::luong_cao_nhat()
{
	long long res = 0;
	for (int i = 0; i < n; i++)
	{
		if (nv[i].getLuong() > res) res = nv[i].getLuong();
	}
	for (int i = 0; i < n; i++)
	{
		if (nv[i].getLuong() == res) return nv[i];
	}
}
//Hàm tính và trả về kết quả tổng lương của các nhân viên
long long cListNhanVien::tong_luong() const
{
	long long res = 0;
	for (int i = 0; i < n; i++)
	{
		res += nv[i].getLuong();
	}
	return res;
}
//Hàm tìm kiếm và trả về nhân viên có số tuổi cao nhất
cNhanVienVP cListNhanVien::nv_cao_tuoi_nhat() const
{
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		if ((2025 - nv[i].getNam()) > res) res = 2025 - nv[i].getNam();
	}
	for (int i = 0; i < n; i++)
	{
		if ((2025 - nv[i].getNam()) == res) return nv[i];
	}
}
//Hàm comparator cho hàm sort theo lương nhân viên tăng dần
bool cmp(cNhanVienVP a, cNhanVienVP b)
{
	return a.getLuong() < b.getLuong();
}
//Hàm sắp xếp nhân viên lương tăng dần bằng hàm sort trong thư viện algorithm
void cListNhanVien::sap_xep()
{
	sort(nv.begin(), nv.end(), cmp);
}