#include <bits/stdc++.h>

using namespace std;

class PS
{
    int a,b;
public:
    PS()
    {
        a = b = 0;
    }
    PS(int x, int y)
    {
        a = x;
        y = b;
    }
    PS operator*(PS y);
    double operator--();
    friend istream& operator>>(istream& x, PS &y);
    friend ostream& operator<<(ostream& x,PS y);
};

PS PS::operator*(PS y)
{
    PS k;
    k.a = a * y.a;
    k.b = b * y.b;
    return k;
}

double PS::operator--()
{
    return (double) a/b;
}
istream& operator>>(istream& x, PS &y)
{
    cout << "Nhap tu so: ";
    x >> y.a;
    cout << "Nhap mau so: ";
    x >> y.b;
    return x;
}

ostream& operator<<(ostream& x,PS y)
{
    x << y.a << "/" << y.b;
    return x;
}
int main()
{
    PS a, b;
    cout << "Nhap phan so thu nhat: " << endl;
    cin >> a;
    cout << endl << "Nhap phan so thu hai: " << endl;
    cin >> b;

    cout << "Hai phan so vua nhap la: " << endl << a << endl << b << endl;
    cout << "Tich cua hai phan so la: " << a*b << " = " << --(a*b) << endl;

    ofstream f("D:/Practice/LTHDT/assignment3/PHANSO.txt",ios::app);
    f << "Tich cua hai phan so la: " << a*b << " = " << --(a*b) << endl;
    f.close();
    cout << endl << "Ket qua da duoc xuat vao tep PHANSO.txt";
    return 0;
}
