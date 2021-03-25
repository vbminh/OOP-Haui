#include <bits/stdc++.h>

using namespace std;

class TRUONGDH;

class TRUONG
{
protected:
    char Matruong[10];
    char Tentruong[20];
    char Diachi[20];
public:
    void nhap();
    void xuat();
};

class KHOA
{
    char Makhoa[10];
    char Tenkhoa[20];
    char Truongkhoa[20];
    friend class TRUONGDH;
    friend void bonus1(TRUONGDH &a);
};

class BAN
{
    char Maban[10];
    char Tenban[20];
    char Ngaythanhlap[12];
    friend class TRUONGDH;
};

class TRUONGDH:private TRUONG
{
    KHOA *x;
    int n;
    BAN *y;
    int m;
public:
    void nhap();
    void xuat();
    friend void bonus1(TRUONGDH &a);
};

void TRUONG::nhap()
{
    cout << "Ma truong: "; fflush(stdin); gets(Matruong);
    cout << "Ten truong: "; fflush(stdin); gets(Tentruong);
    cout << "Dia chi: "; fflush(stdin); gets(Diachi);
}

void TRUONG::xuat()
{
    cout << "Ma truong: " << Matruong << endl;
    cout << "Ten truong: " << Tentruong << endl;
    cout << "Dia chi: " << Diachi << endl;
}

void TRUONGDH::nhap()
{
    TRUONG::nhap();
    cout << "Nhap so khoa: "; cin >> n;
    x = new KHOA[n];
    for(int i = 0; i < n; i++)
    {
        cout << "Nhap khoa thu " << i+1 << endl;
        cout << "Ma khoa: "; fflush(stdin); gets(x[i].Makhoa);
        cout << "Ten khoa: "; fflush(stdin); gets(x[i].Tenkhoa);
        cout << "Truong khoa: "; fflush(stdin); gets(x[i].Truongkhoa);
    }
    cout << "Nhap so ban: "; cin >> m;
    y = new BAN[m];
    for(int i = 0; i < m; i++)
    {
        cout << "Nhap ban thu " << i + 1 << endl;
        cout << "Ma ban: "; fflush(stdin); gets(y[i].Maban);
        cout << "Ten khoa: "; fflush(stdin); gets(y[i].Tenban);
        cout << "Ngay thanh lap: "; fflush(stdin); gets(y[i].Ngaythanhlap);
    }
}

void TRUONGDH::xuat()
{
    TRUONG::xuat();
    cout << endl << "Ma khoa" << setw(20) << "Ten khoa" << setw(20) << "Truong khoa" << endl;
    for(int i = 0; i < n; i++)
        cout << x[i].Makhoa << setw(20) << x[i].Tenkhoa << setw(20) << x[i].Truongkhoa << endl;
    cout << endl << "Ma ban" << setw(20) << "Ten ban" << setw(20) << "Ngay thanh lap" << endl;
    for(int i = 0; i < m; i++)
        cout << y[i].Maban << setw(20) << y[i].Tenban << setw(20) << y[i].Ngaythanhlap << endl;
}

void bonus1(TRUONGDH &a)
{
    if(stricmp(a.x->Makhoa,"KH01") == 0)
    {
        strcpy(a.x->Makhoa," ");
        strcpy(a.x->Tenkhoa," ");
        strcpy(a.x->Truongkhoa," ");
    }
}
int main()
{
    TRUONGDH a;
    a.nhap();
    cout << endl << "Thong tin truong dh vua nhap: " << endl << endl;
    a.xuat();
    cout << endl << "--------bonus 1--------" << endl;
    bonus1(a);
    a.xuat();
    return 0;
}
