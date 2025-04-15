#include "cListCandidate.h"

int main()
{
    cListCandidate x;
    x.Nhap();
    if (x.getN() == 0)
    {
        cout << "Khong co thi sinh nao!";
        return 0;
    }
    cout << "Thong tin cac thi sinh co tong diem lon hon 15: " << endl;
    x.Xuat1();
    cout << "--------------------------------------" << endl;
    cout << "Thi sinh co tong diem cao nhat la: "<<endl;
    x.diem_max().Xuat();
    cout << endl;
    cout << "--------------------------------------" << endl;
    cout << "Danh sach thi sinh giam dan theo tong diem: "<<endl;
    x.sap_xep();
    x.Xuat();
}
