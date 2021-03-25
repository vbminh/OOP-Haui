#include <bits/stdc++.h>

using namespace std;

class HANG;
class TIVI;

class NSX
{
    char TenNSX[20];
    char DiaChi[20];
public:
    void nhap();
    void xuat();
    friend class HANG;
};

class DATE
{
    int D, M, Y;
public:
    void nhap();
    void xuat();
    friend class TIVI;
};

class HANG
{
protected:
    char Tenhang[20];
    NSX x;
    float Dongia;
public:
    void nhap();
    void xuat();
    HANG();
};

class TIVI:public HANG
{
    float Kichthuoc;
    DATE Ngaynhap;
public:
    void nhap();
    void xuat();
    TIVI();
};

void NSX::nhap()
{
    cout << "Ten nha san xuat: "; fflush(stdin); gets(TenNSX);
    cout << "Dia chi: "; fflush(stdin); gets(DiaChi);
}

void NSX::xuat()
{
    cout << "Ten nha san xuat: " << TenNSX << endl;
    cout << "Dia chi: " << DiaChi << endl;
}

void DATE::nhap()
{
    cout << "Ngay: "; cin >> D;
    cout << "Thang: "; cin >> M;
    cout << "Nam: "; cin >> Y;
}

void DATE::xuat()
{
    cout << "Ngay nhap: " << D << "/" << M << "/" << Y << endl;
}

void HANG::nhap()
{
    cout << "Ten hang: "; fflush(stdin); gets(Tenhang);
    x.nhap();
    cout << "Don gia: "; cin >> Dongia;
}

void HANG::xuat()
{
    cout << "Ten hang: " << Tenhang << endl;
    x.xuat();
    cout << "Don gia: " << Dongia << endl;
}

void TIVI::nhap()
{
    HANG::nhap();
    cout << "Kich thuoc: "; cin >> Kichthuoc;
    Ngaynhap.nhap();
}

void TIVI::xuat()
{
    HANG::xuat();
    cout << "Kich thuoc: " << Kichthuoc << endl;
    Ngaynhap.xuat();
}
HANG::HANG()
{
    strcpy(Tenhang,"");
    strcpy(x.TenNSX,"");
    strcpy(x.DiaChi,"");
    Dongia = 0;
}

TIVI::TIVI():HANG()
{
    Kichthuoc = 0;
    Ngaynhap.D = Ngaynhap.M = Ngaynhap.Y = 0;
}

int main()
{
    TIVI a;
    a.nhap();
    cout << endl << "Thong tin tivi vua nhap: " << endl;
    a.xuat();
    return 0;
}
