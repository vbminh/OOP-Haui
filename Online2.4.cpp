#include <bits/stdc++.h>

using namespace std;

class BENHNHAN;

class NGUOI
{
protected:
    char Hoten[20];
    int Tuoi;
public:
    void nhap();
    void xuat();
    friend void bonus1(BENHNHAN *a, int n);
    friend void bonus2(BENHNHAN *a, int n);
};

class BENHVIEN
{
    char Tenbenhvien[20];
    char Diachi[20];
    char Giamdoc[20];
    friend class BENHNHAN;
};

class BENHNHAN:public NGUOI
{
    char Ma[10];
    char TienSu[20];
    char Chuandoan[20];
    BENHVIEN x;
public:
    void nhap();
    void xuat();
    friend void bonus1(BENHNHAN *a, int n);
    friend void bonus2(BENHNHAN *a, int n);
};

void NGUOI::nhap()
{
    cout << "Ho ten: "; fflush(stdin); gets(Hoten);
    cout << "Tuoi: "; cin >> Tuoi;
}
void NGUOI::xuat()
{
    cout << Hoten << setw(10) << Tuoi;
}

void BENHNHAN::nhap()
{
    NGUOI::nhap();
    cout << "Ma: ";fflush(stdin); gets(Ma);
    cout << "Tien su: ";fflush(stdin); gets(TienSu);
    cout << "Chuan doan: ";fflush(stdin); gets(Chuandoan);
    cout << "Ten benh vien: "; fflush(stdin); gets(x.Tenbenhvien);
    cout << "Dia chi: ";fflush(stdin); gets(x.Diachi);
    cout << "Giam doc: ";fflush(stdin); gets(x.Giamdoc);
}

void BENHNHAN::xuat()
{
    NGUOI::xuat();
    cout << setw(10) << Ma << setw(10) << TienSu << setw(20) << Chuandoan << setw(20) << x.Tenbenhvien << setw(20) << x.Diachi << setw(20) << x.Giamdoc << endl;
}

void bonus1(BENHNHAN *a, int n)
{
    int dem = 0;
    for(int i = 0; i < n; i++)
        if(a[i].Tuoi > 30) dem++;
    cout << endl << "So benh nhan co tuoi lon hon 30 la: " << dem << endl;
}

void bonus2(BENHNHAN *a, int n)
{
    for(int i = 0; i < n; i++)
        if(stricmp(a[i].Ma,"BN01") == 0)
        {
            a[i].Tuoi = 20;
            a[i].xuat();
        }
}

int main()
{
    BENHNHAN *a; int n;
    cout << "Nhap so benh nhan: "; cin >> n;
    a = new BENHNHAN[n];
    for(int i = 0; i < n; i++)
    {
        cout << "Nhap thong tin benh nhan " << i+1 << endl;
        a[i].nhap();
    }
    cout << endl << "Thong tin benh nhan vua nhap" << endl;
    cout << endl << "Ho ten" << setw(10) << "Tuoi" << setw(10) << "Ma" << setw(10) << "Tien Su" << setw(20) << "Chuan doan" << setw(20) << "Ten benh vien" << setw(20) << "Dia chi" << setw(20) << "Giam doc" << endl;
    for(int i = 0; i < n; i++)
        a[i].xuat();
    cout << endl << "------------bonus 1------------" << endl;
    bonus1(a,n);
    cout << endl << "------------bonus 2------------" << endl;
    cout << endl << "Ho ten" << setw(10) << "Tuoi" << setw(10) << "Ma" << setw(10) << "Tien Su" << setw(20) << "Chuan doan" << setw(20) << "Ten benh vien" << setw(20) << "Dia chi" << setw(20) << "Giam doc" << endl;
    bonus2(a,n);
    return 0;
}
