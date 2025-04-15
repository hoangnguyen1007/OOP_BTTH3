#include <iostream>
#include "cListNhanVienVP.h"
int main()
{
    cListNhanVien  x;
    x.Nhap();
    if (x.getN() == 0)
    {
        cout << "Khong co nhan vien nao!";
        return 0;
    }
    cout << "DANH SACH NHAN VIEN: " << endl;
    x.Xuat();
    cout << endl;
    cout << "THONG TIN NHAN VIEN CO LUONG CAO NHAT: "<<endl;
    x.luong_cao_nhat().Xuat();
    cout << endl;
    cout << "TONG LUONG TRA CHO CAC NHAN VIEN LA: " << x.tong_luong() << endl;
    cout << "THONG TIN NHAN VIEN CAO TUOI NHAT: " << endl;
    x.nv_cao_tuoi_nhat().Xuat();
    cout << endl;
    cout << "DANH SACH NHAN VIEN VOI MUC LUONG GIAM DAN: " << endl;
    x.sap_xep();
    x.Xuat();
}
