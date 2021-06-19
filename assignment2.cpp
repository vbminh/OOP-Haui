#include <bits/stdc++.h>

using namespace std;

class LOPHOC;

class NGUOI
{
protected:
    char Hoten[20];
    char Ngaysinh[20];
    char Quequan[30];
public:
    void nhap();
    void xuat();
};

class SINHVIEN:public NGUOI
{
    char Masv[10];
    char Nganh[10];
    int Khoahoc;
public:
    void nhap();
    void xuat();
    friend class LOPHOC;
    friend void bonus1(LOPHOC a);
    friend void bonus2(LOPHOC &a);
};

class LOPHOC
{
    char MaLH[10];
    char TenLH[20];
    char Ngaymo[10];
    SINHVIEN *x;
    int n;
    char Giaovien[20];
public:
    void nhap();
    void xuat();
    friend void bonus1(LOPHOC a);
    friend void bonus2(LOPHOC &a);
};

void NGUOI::nhap()
{
    cout << "Ho ten: "; fflush(stdin); gets(Hoten);
    cout << "Ngay sinh: "; fflush(stdin); gets(Ngaysinh);
    cout << "Que quan: "; fflush(stdin); gets(Quequan);
}

void NGUOI::xuat()
{
    cout << Hoten << setw(20) << Ngaysinh << setw(15) << Quequan;
}

void SINHVIEN::nhap()
{
    NGUOI::nhap();
    cout << "Ma sing vien: "; fflush(stdin); gets(Masv);
    cout << "Nganh: "; fflush(stdin); gets(Nganh);
    cout << "Khoa hoc: "; cin >> Khoahoc;
}

void SINHVIEN::xuat()
{
    NGUOI::xuat();
    cout << setw(20) << Masv << setw(15) << Nganh << setw(15) << Khoahoc << endl;
}

void LOPHOC::nhap()
{
    cout << "Ma lop hoc: "; fflush(stdin); gets(MaLH);
    cout << "Ten lop hoc: "; fflush(stdin);gets(TenLH);
    cout << "Ngay mo: "; fflush(stdin); gets(Ngaymo);
    cout << "Giao vien: "; fflush(stdin); gets(Giaovien);
    cout << "Nhap so sv: "; cin >> n;
    x = new SINHVIEN[n];
    for(int i = 0; i < n; i++)
    {
        cout << "Nhap thong tin sinh vien thu " << i+1 << endl;
        x[i].nhap();
    }
}
void LOPHOC::xuat()
{
    cout << setw(50) << "THONG TIN LOP HOC" << endl;
    cout << endl << "Ma lop hoc: " << MaLH;
    cout << setw(30) << "Ten lop hoc: " << TenLH << endl;
    cout << "Ngay mo: " << Ngaymo << endl;
    cout << "Giao vien: " << Giaovien << endl;
    cout << endl << "Ho ten" << setw(20) << "Ngay sinh" << setw(15) << "Que quan" << setw(20) << "Ma sv" << setw(15) << "Nganh" << setw(15) << "Khoa hoc" << endl;
    for(int i = 0; i < n; i++)
        x[i].xuat();
}

void bonus1(LOPHOC a)
{
    int dem = 0;
    for(int i = 0; i < a.n; i++)
        if(a.x[i].Khoahoc == 11) dem++;
    cout << "So sinh vien khoa 11 la: " << dem << endl;
}

void bonus2(LOPHOC &a)
{
    for(int i = 0; i < a.n; i++)
        for(int j = i + 1; j < a.n; j++)
            if(a.x[i].Khoahoc > a.x[j].Khoahoc)
                swap(a.x[i],a.x[j]);
    a.xuat();
}
int main()
{
    LOPHOC a;
    a.nhap();
    a.xuat();
    bonus1(a);
    bonus2(a);
    return 0;
}
