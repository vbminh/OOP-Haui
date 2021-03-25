#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <iomanip>

using namespace std;

class NCC
{
    char MaNCC[10];
    char TenNCC[20];
    char DCNCC[30];
public:
    void nhap();
    void xuat();
};

void NCC::nhap()
{
    cout << "Ma nha cung cap: "; fflush(stdin); gets(MaNCC);
    cout << "Ten nha cung cap: "; fflush(stdin); gets(TenNCC);
    cout << "Dia chi: "; fflush(stdin); gets(DCNCC);
}

void NCC::xuat()
{
    cout << setw(15) << "Ma NCC: " << setw(5) << MaNCC;
    cout << setw(15) << "Ten NCC: " << setw(5) << TenNCC << endl;
    cout << setw(15) << "Dia chi: " << setw(5) << DCNCC << endl;
}

class HANG
{
    char TenH[20];
    float DG;
    int SL;
public:
    void nhap();
    void xuat();
    friend class PHIEU;
};

void HANG::nhap()
{
    cout << "Ten hang: "; fflush(stdin); gets(TenH);
    cout << "Don gia: "; cin >> DG;
    cout << "So luong: "; cin >> SL;
}

void HANG::xuat()
{
    cout << setw(10) << TenH << setw(20) << DG << setw(20) << SL << setw(20) << DG*SL << endl;
}

class PHIEU
{
    char MaP[10];
    char Ngay[10];
    NCC x;
    HANG *y;
    int n;
public:
    void nhap();
    void xuat();
};

void PHIEU::nhap()
 {
     cout << "Ma phieu: "; fflush(stdin); gets(MaP);
     cout << "Ngay lap: "; fflush(stdin); gets(Ngay);
     x.nhap();
     cout << "nhap so luong hang: ";
     cin >> n;
     y = new HANG[n];
     for(int i = 0; i < n; i++)
        y[i].nhap();
 }
 void PHIEU::xuat()
 {
     cout << setw(40) << "PHIEU NHAP HANG" << endl;
     cout << setw(15) << "Ma phieu: " << setw(5) << MaP;
     cout << setw(15) << "Ngay lap: " << setw(5) << Ngay << endl;
     x.xuat();
     cout << setw(10) << "Ten hang" << setw(20) << "Don gia" << setw(20) << "So luong" << setw(20) << "Thanh tien" << endl;
     for(int i = 0; i < n; i++)
        y[i].xuat();
     float T = 0;
     for(int i = 0; i < n; i++)
        T = T + y[i].DG*y[i].SL;
     cout << setw(55) << "Cong thanh tien" << setw(15) << T;
 }
int main()
{
    PHIEU a;
    a.nhap();
    a.xuat();
    return 0;
}
