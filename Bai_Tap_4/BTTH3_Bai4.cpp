#include "cArray.h"
using namespace std;
int main()
{
    cArray x;
    x.Tao_mang();
    if (x.getN() == 0)
    {
        cout << "Mang rong!";
        return 0;
    }
    cout << "Mang sau khi khoi tao: ";
    x.Xuat();
    cout << endl;
    cout << "Nhap so muon dem so lan xuat hien: ";
    int k;
    cin >> k;
    cout << "So " << k << " xuat hien " << x.so_lan_xuat_hien(k) << " lan"<<endl;
    if (x.ktra_tang_dan())
    {
        cout << "Mang nay la mang tang dan";
    }
    else
    {
        cout << "Mang nay khong la mang tang dan";
    }
    cout << endl;
    if (x.tim_le_max() == -2)
    {
        cout << "Khong co phan tu le nao trong mang";
    }
    else
    {
        cout << "Phan tu le lon nhat co trong mang la: " << x.tim_le_max();
    }
    cout << endl;
    if (x.tim_snt_max() == -2)
    {
        cout << "Khong co so nguyen to nao trong mang";
    }
    else
    {
        cout << "So nguyen to lon nhat co trong mang la: " << x.tim_snt_max();
    }
    cout << endl;
    x.sap_xep_tang_dan();
    cout << "Mang sau khi sap xep tang dan: ";
    x.Xuat();
    cout << endl;
    x.sap_xep_giam_dan();
    cout << "Mang sau khi sap xep giam dan: ";
    x.Xuat();
}