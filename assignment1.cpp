#include <bits/stdc++.h>

using namespace std;

class PHIEU;

class NCC
{
    char Mancc[10];
    char Tenncc[20];
    char Diachi[20];
    int SDT;
    friend class PHIEU;
public:
    void nhap();
    void xuat();
};

class SANPHAM
{
    char Masp[10];
    char Tensp[20];
    int SL;
    float DG;
public:
    void nhap();
    void xuat();
    friend class PHIEU;
    friend void bonus1(PHIEU a);
    friend void bonus2(PHIEU a);
};

class PHIEU
{
    char Maphieu[10];
    char Ngaylap[12];
    NCC x;
    SANPHAM *y;
    int n;
public:
    void nhap();
    void xuat();
    friend void bonus1(PHIEU a);
    friend void bonus2(PHIEU a);
};

void NCC::nhap()
{
    cout << "Ma nha cung cap: "; fflush(stdin); gets(Mancc);
    cout << "Ten nha cung cap: "; fflush(stdin); gets(Tenncc);
    cout << "Dia chi: "; fflush(stdin); gets(Diachi);
    cout << "So dien thoai: "; cin >> SDT;
}

void NCC::xuat()
{
    cout << "Ma nha cung cap: " << setw(10) << Mancc;
    cout << setw(30) << "Ten nha cung cap: " << setw(5) << Tenncc << endl;
    cout << "Dia chi: " << Diachi;
    cout << setw(15) << "SDT: " << SDT;
}

void SANPHAM::nhap()
{
    cout << "Ma san pham: "; fflush(stdin); gets(Masp);
    cout << "Ten san pham: ";fflush(stdin); gets(Tensp);
    cout << "So luong: "; cin >> SL;
    cout << "Don gia: "; cin >> DG;
}

void SANPHAM::xuat()
{
    cout << Masp << setw(15) << Tensp << setw(20) << SL << setw(15) << DG << setw(15) << SL*DG << endl;
}

void PHIEU::nhap()
{
    cout << "Ma phieu: "; fflush(stdin); gets(Maphieu);
    cout << "Ngay lap: "; fflush(stdin); gets(Ngaylap);
    x.nhap();
    cout << "Nhap so luong san pham: "; cin >> n;
    y = new SANPHAM[n];
    for(int i = 0; i < n; i++)
    {
        cout << "Nhap san pham thu " << i+1 << endl;
        y[i].nhap();
    }
}

void PHIEU::xuat()
{
    cout << "Dai hoc Victory" << endl;
    cout << setw(50) << "PHIEU NHAP VAN PHONG PHAM" << endl;
    cout << endl << "Ma phieu: " << setw(15) << Maphieu;
    cout << setw(25) << "Ngay lap: " << Ngaylap << endl;
    x.xuat();
    cout << endl << endl << setw(5) << "Ma SP" << setw(15) << "Ten san pham" << setw(20) << "So luong" << setw(15) << "Don gia" << setw(15) << "Thanh tien" << endl;
    for(int i = 0; i < n; i++)
        y[i].xuat();
    float tong = 0;
    for(int i = 0; i < n; i++)
        tong += y[i].SL*y[i].DG;
    cout << setw(50) <<"TONG" << setw(20) << tong << endl;
    cout << setw(20) << "Hieu truong" << setw(25) << "Phong tai chinh" << setw(15) << "Nguoi lap" << endl;
}

void bonus1(PHIEU a)
{
    int dem = 0;
    for(int i = 0; i < a.n; i++)
        if(a.y[i].SL < 80) dem ++;
    cout << endl << "So san pham co so luong nhap nho hon 80: " << dem;
}

void bonus2(PHIEU a)
{
    for(int i = 0; i < a.n; i++)
        for(int j = i + 1; j < a.n; j++)
            if(a.y[i].DG > a.y[j].DG)
            {
                SANPHAM temp = a.y[i];
                a.y[i] = a.y[j];
                a.y[j] = temp;
            }
    a.xuat();
}
int main()
{
    PHIEU a;
    cout << "---------NHAP PHIEU----------" << endl;
    a.nhap();
    cout << endl << "----------IN PHIEU---------\n" << endl;
    a.xuat();
    cout << endl << "---------BONUS 1----------" << endl;
    bonus1(a);
    cout << endl << "---------BONUS 2----------" << endl;
    bonus2(a);
    return 0;
}
