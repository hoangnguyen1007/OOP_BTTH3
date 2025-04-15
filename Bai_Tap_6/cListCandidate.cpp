#include "cListCandidate.h"
#include <algorithm>
#include <string>
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
//Hàm constructor mặc định
cCandidate::cCandidate() {};
//Hàm constructor có truyền tham số để định nghĩa lớp cCandidate
cCandidate::cCandidate(string ten, string ma, int ngay, int thang, int nam, double toan, double van, double anh)
{
	this->ten = ten;
	this->ma = ma;
	this->ngay = ngay;
	this->thang = thang;
	this->nam = nam;
	this->toan = toan;
	this->van = van;
	this->anh = anh;
}
//Hàm nhập và kiểm tra đầu vào của 1 thí sinh
void cCandidate::Nhap()
{
	cout << "Nhap ma thi sinh: ";
	cin >> ma;
	cout << "Nhap ten thi sinh: ";
	cin.ignore();
	getline(cin, ten);
	cout << "Nhap ngay thang nam: ";
	cin >> ngay >> thang >> nam;
	while (cin.fail() || ngay < 0 || ngay > 31 || thang < 0 || thang > 12 || nam < 0 || ngay > SoNgayTrongThang(thang, nam))
	{
		cin.clear();
		cin.ignore();
		cout << "Nhap ngay thang nam: ";
		cin >> ngay >> thang >> nam;
	}
	cout << "Nhap diem mon toan: ";
	cin >> toan;
	while (cin.fail() || toan < 0 || toan > 10)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap diem mon toan: ";
		cin >> toan;
	}
	cout << "Nhap diem mon van: ";
	cin >> van;
	while (cin.fail() || van < 0 || van > 10)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap diem mon van: ";
		cin >> van;
	}
	cout << "Nhap diem mon anh: ";
	cin >> anh;
	while (cin.fail() || anh < 0 || anh > 10)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap diem mon anh: ";
		cin >> anh;
	}
}
//Hàm xuất thông tin của 1 thí sinh, đảm bảo đúng chuẩn
void cCandidate::Xuat() const
{
	cout << "Ma thi sinh: " << ma << endl;
	cout << "Ten thi sinh: " << ten << endl;
	cout << "Ngay thang nam sinh: ";
	if (ngay < 10) cout << 0;
	cout << ngay << "/";
	if (thang < 10) cout << 0;
	cout << thang << "/" << nam;
	cout << endl;
	cout << "Diem toan van anh: " << toan << " | " << van << " | " << anh << endl;
	cout << "Tong diem 3 mon: " << toan + van + anh;
}
//Hàm trả về tổng điểm của ba môn
int cCandidate::getTongDiem() const
{
	return toan + van + anh;
}
//Hàm constructor mặc định của cListCandidate
cListCandidate::cListCandidate() {};
//Hàm constructor sao chép nhận vào 1 vector thí sinh để sao chép
cListCandidate::cListCandidate(const vector<cCandidate> x)
{
	this->n = x.size();
	for (int i = 0; i < n; i++)
	{
		this->TS.push_back(x[i]);
	}
}
//Hàm nhập n thí sinh và kiểm tra dữ liệu nhập
void cListCandidate::Nhap()
{
	cout << "Nhap so thi sinh: ";
	cin >> n;
	while (cin.fail() || n < 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Khong hop le! Vui long nhap lai!" << endl;
		cout << "Nhap so thi sinh: ";
		cin >> n;
	}
	for (int i = 0; i < n; i++)
	{
		cout << "--------Nhap thi sinh " << i + 1 << ": ---------" << endl;
		cCandidate tmp;
		tmp.Nhap();
		TS.push_back(tmp);
	}
}
//Hàm xuất thông tin của n thí sinh
void cListCandidate::Xuat() const
{
	int dem = 1;
	for (int i = 0; i < n; i++)
	{
		cout << "-------Thong tin thi sinh thu " << dem << ":-------" << endl;
		TS[i].Xuat();
		cout << endl;
		dem++;
	}
}
//Hàm xuất thông tin của các thí sinh có tổng điểm trên 15
void cListCandidate::Xuat1() const
{
	int dem = 1;
	for (int i = 0; i < n; i++)
	{
		if (TS[i].getTongDiem() >= 15)
		{	
			cout << "-------Thong tin thi sinh thu " << dem << ":------- " << endl;
			TS[i].Xuat();
			cout << endl;
			dem++;
		}
	}
}
//Hàm tìm kiếm thông tin và trả về thông tin của thí sinh có điểm tổng cao nhất
//Bằng thuật toán tìm kiếm số lớn nhất thông thường
cCandidate cListCandidate::diem_max() const
{
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (TS[i].getTongDiem() > max) max = TS[i].getTongDiem();
	}
	for (int i = 0; i < n; i++)
	{
		if (TS[i].getTongDiem() == max) return TS[i];
	}
}
//Hàm comparator hỗ trợ cho hàm sort theo tổng điểm giảm dần
bool cmp(cCandidate a, cCandidate b)
{
	return a.getTongDiem() > b.getTongDiem();
}
//Hàm sắp xếp các thí sinh theo tồng điểm giảm dần bằng hàm sort trong thư viện algorithm
void cListCandidate::sap_xep()
{
	sort(TS.begin(), TS.end(), cmp);
}
//Hàm getter trả về giá trị của số thí sinh
int cListCandidate::getN()
{
	return n;
}