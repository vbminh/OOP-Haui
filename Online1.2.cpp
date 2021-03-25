#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <iomanip>

using namespace std;
class PHIEU;

class SinhVien
{
    char MaSV[10];
    char TenSV[20];
    char Lop[10];
    char Khoa[10];
public:
    void nhap();
    void xuat();
};

void SinhVien::nhap()
{
    cout << "Ma sinh vien: "; fflush(stdin); gets(MaSV);
    cout << "Ten sinh vien: "; fflush(stdin); gets(TenSV);
    cout << "Lop: "; fflush(stdin); gets(Lop);
    cout << "Khoa: "; fflush(stdin); gets(Khoa);
}

void SinhVien::xuat()
{
    cout << setw(15) << "Ma sinh vien: " << setw(5) << MaSV;
    cout << setw(20) << "Ten sinh vien: " << setw(5) << TenSV << endl;
    cout << setw(15) << "Lop: " << setw(5) << Lop;
    cout << setw(20) << "Khoa:" << setw(5) << Khoa << endl;
}

class BangDiem
{
    char TenM[20];
    float Diem;
    int SoTr;
public:
    void nhap();
    void xuat();
    friend class PHIEU;
    friend void bonus2(PHIEU a);
};

void BangDiem::nhap()
{
    cout << "Ten mon: "; fflush(stdin); gets(TenM);
    cout << "So trinh: "; cin >> SoTr;
    cout << "Diem: "; cin >> Diem;
}

void BangDiem::xuat()
{
    cout << setw(15) << TenM << setw(20) << SoTr << setw(10) << Diem << endl;
}

class PHIEU
{
    SinhVien x;
    BangDiem *y;
    int n;
public:
    void nhap();
    void xuat();
    friend  void bonus2(PHIEU a);
};

void PHIEU::nhap()
 {
     x.nhap();
     cout << "nhap so luong mon: ";
     cin >> n;
     y = new BangDiem[n];
     for(int i = 0; i < n; i++)
        y[i].nhap();
 }
 void PHIEU::xuat()
 {
     cout << setw(40) << "PHIEU BAO DIEM" << endl;
     cout << endl;
     x.xuat();
     cout << endl;
     cout << setw(15) << "Ten mon" << setw(20) << "So trinh" << setw(10) << "Diem" << endl;
     for(int i = 0; i < n; i++)
        y[i].xuat();
     float T = 0;
     int S = 0;
     for(int i = 0; i < n; i++)
     {
         S = S + y[i].SoTr;
         T = T + y[i].SoTr*y[i].Diem;
     }
     cout << setw(35) << "Diem trung binh:" << setw(10) << setprecision(2) << T/S << endl;
     cout << endl;
     cout << "\n----------bonus 1------------" << endl;
     cout << "Ten mon co so trinh lon hon 3: " <<endl;
     for(int i = 0; i < n; i++)
        if(y[i].SoTr > 3)
                cout << y[i].TenM << endl;
 }

 void bonus2(PHIEU a)
 {
     cout << "\n-------------bonus 2-------------" << endl;
     int pos;
     cout << "Nhap vi tri chen: ";
     do {
        cin >> pos;
        if(pos < 1 || pos > a.n)
            cout << "Nhap lai vi tri: ";
     }while(pos < 1 || pos > a.n);
     BangDiem b;
     b.nhap();
     a.n++;
     for(int i = a.n - 1; i >= pos-1; i--)
        a.y[i] = a.y[i-1];
     a.y[pos -1] = b;

     a.xuat();
 }

int main()
{
    PHIEU a;
    a.nhap();
    a.xuat();

    bonus2(a);
    return 0;
}
