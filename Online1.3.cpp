#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <iomanip>
#include <string.h>

using namespace std;
class PHIEU;

class NhanVien
{
    char Tennv[20];
    char Chucvu[20];
public:
    void nhap();
    void xuat();
};

void NhanVien::nhap()
{
    cout << "Ten nhan vien: "; fflush(stdin); gets(Tennv);
    cout << "Chuc vu: "; fflush(stdin); gets(Chucvu);
}

void NhanVien::xuat()
{
    cout << setw(15) << "Nhan vien kiem ke: " << setw(15) << Tennv;
    cout << setw(15) << "Chuc vu: " << setw(15) << Chucvu << endl;
}

class Phong
{
    char MaP[10];
    char TenP[20];
    char TrP[20];
public:
    void nhap();
    void xuat();
};

void Phong::nhap()
{
    cout << "Ma phong: "; fflush(stdin); gets(MaP);
    cout << "Ten Phong: "; fflush(stdin); gets(TenP);
    cout << "Truong phong: "; fflush(stdin); gets(TrP);
}

void Phong::xuat()
{
    cout << setw(15) << "Kiem ke tai phong: " << setw(15) << TenP;
    cout << setw(10) << "Ma phong: " << setw(15) << MaP << endl;
    cout << setw(15) << "Truong Phong: " << setw(15) << TrP << endl;
}

class Taisan
{
    char Tents[20];
    int SL;
    char TT[20];
public:
    void nhap();
    void xuat();
    friend class PHIEU;
    friend void bonus1(PHIEU &a);
    friend void bonus2(PHIEU &a);
};

void Taisan::nhap()
{
    cout << "Ten tai san: "; fflush(stdin); gets(Tents);
    cout << "So luong: "; cin >> SL;
    cout << "Tinh trang: "; fflush(stdin); gets(TT);
}

void Taisan::xuat()
{
    cout << setw(15) << Tents << setw(15) << SL << setw(15) << TT << endl;
}

class PHIEU
{
    char MaPhieu[10];
    char Ngay[12];
    NhanVien x;
    Phong y;
    Taisan *z;
    int n;
public:
    void nhap();
    void xuat();
    friend void bonus1(PHIEU &a);
    friend void bonus2(PHIEU &a);
};

void PHIEU::nhap()
 {
     cout << "Ma phieu: "; fflush(stdin); gets(MaPhieu);
     cout << "Ngay kiem ke: "; fflush(stdin); gets(Ngay);
     x.nhap();
     y.nhap();
     cout << "so tai san: ";
     cin >> n;
     z = new Taisan[n];
     for(int i = 0; i < n; i++)
        z[i].nhap();
 }
 void PHIEU::xuat()
 {
     cout << setw(40) << "PHIEU KIEM KE TAI SAN" << endl;
     cout << endl;
     cout << setw(15) << "Ma phieu: " << setw(15) << MaPhieu;
     cout << setw(15) << "Ngay lap: " << setw(15) << Ngay << endl;
     x.xuat();
     y.xuat();
     cout << endl;
     cout << setw(15) << "Ten tai san" << setw(15) << "So luong" << setw(15) << "Tinh trang" << endl;
     for(int i = 0; i < n; i++)
        z[i].xuat();
     cout << endl;
     cout << "So tai san da kiem ke: " << n;
     float T = 0;
     int S = 0;
     for(int i = 0; i < n; i++)
        T = T + z[i].SL;
     cout << setw(20) << "Tong so luong:" << T << endl;
 }

 void bonus1(PHIEU &a)
 {
     cout << "\n-------------Bonus 1--------------" << endl;
     cout << endl;
     cout << setw(15) << "Ten tai san" << setw(15) << "So luong" << setw(15) << "Tinh trang" << endl;
     for(int i = 0; i < a.n; i++)
     {
        if(strncmp(a.z[i].Tents,"May vi tinh",2) == 0)
        {
            a.z[i].SL = 20;
        }
        a.z[i].xuat();
     }
 }

 void bonus2(PHIEU &a)
 {
     cout << "\n-----------Bonus 2------------" << endl;
     cout << endl;
     cout << setw(15) << "Ten tai san" << setw(15) << "So luong" << setw(15) << "Tinh trang" << endl;
     for(int i = 0; i < a.n; i++)
        for(int j = i + 1; j < a.n; j++)
            if(a.z[i].SL > a.z[j].SL)
                swap(a.z[i], a.z[j]);
     for(int i = 0; i < a.n; i++) a.z[i].xuat();
 }
int main()
{
    PHIEU a;
    a.nhap();
    a.xuat();

    bonus1(a);
    bonus2(a);
    return 0;
}
