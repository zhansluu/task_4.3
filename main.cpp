#include <iostream>
#include "compound_quadrature_formulas.h"

using namespace std;

int main()
{
    setlocale(0, "Russian");
    cout << "������� 4.3. ����������� ���������� ��������� �� ��������� ������������ �������� � ����� ������ �������." << endl << endl;

    double a, b, l, step, w = 0, q = 0;
    size_t n;
    cout << "������� ������ ������ ��������������: � = ";
    cin >> a;
    cout << "������� ������� ������ ��������������: b = ";
    cin >> b;
    cout << "������� ����� ����������� ������� [a,b]: n = ";
    cin >> n;
    while (n <= 0)
    {
        cout << endl << "������� ������������ �������� n! ��������� �������.";
        cin >> n;
    }
    cout << "������� �� ������� ��� �� ������ ��������� ����� ������� [a,b]: l = ";
    cin >> l;
    while(l <= 0)
    {
        cout << endl << "������� ������������ �������� l! ��������� �������.";
        cin >> l;
    }
    n = n*l;
    step = (b-a)/n;
    cout << "��� ������� h = " << step << endl;

    cout << "�������� �������, � ������� ������ ��������:" << endl
         << "0-3 - ��������� ��������������� �������;" << endl
         << "4 - ������� f(x)=6*x^2+cos(x)*exp(4x)" << endl
         << "5 - ������� f(x)=1.27*x^5+2.04*x" << endl
         << "6 - ����� ������" << endl;
    size_t num;
    cin >> num;
    while (num != 0 && num != 1 && num != 2 && num != 3 && num != 4 && num!= 5 && num != 6)
    {
        cout << "������� �������� ��������! ��������� �������.";
        cin >> num;
    }

    double J, leftJ, rightJ, middleJ, trapJ, simpsJ;
    while (num != 6){
        switch (num){
        case 0:
            cout << "�������� � ����������� f(x)=12" << endl;
            w = (n-1)*polinom0degree();
            q = n*polinom0degree();
            J = integralOfPolinom0degree(b) - integralOfPolinom0degree(a);
            leftJ = leftRectangles(0, w, step, a);
            rightJ = rightRectangles(0, w, step, n, a);
            middleJ = middleRectangles(0, q, step);
            trapJ = trapeze(0, w, step, n, a);
            simpsJ = simpson(0, w, q, step, n, a);
            break;
        case 1:
            cout << "�������� � ����������� f(x)=x-4" << endl;
            w = 0; q = 0;
            for (size_t i = 1; i < n; i++)
            {
                w += polinom1degree(a+i*step);
                q += polinom1degree((2*a+2*i*step+step)/2);
            }
            q += polinom1degree((2*a+step)/2);
            J = integralOfPolinom1degree(b) - integralOfPolinom1degree(a);
            leftJ = leftRectangles(1, w, step, a);
            rightJ = rightRectangles(1, w, step, n, a);
            middleJ = middleRectangles(1, q, step);
            trapJ = trapeze(1, w, step, n, a);
            simpsJ = simpson(1, w, q, step, n, a);
            break;
        case 2:
            cout << "�������� � ����������� f(x)=3x^2+4x-3" << endl;
            w = 0; q = 0;
            for (size_t i = 1; i < n; i++)
            {
                w += polinom2degree(a+i*step);
                q += polinom2degree(a+i*step+step/2);
            }
            q += polinom2degree(a+step/2);
            J = integralOfPolinom2degree(b) - integralOfPolinom2degree(a);
            leftJ = leftRectangles(2, w, step, a);
            rightJ = rightRectangles(2, w, step, n, a);
            middleJ = middleRectangles(2, q, step);
            trapJ = trapeze(2, w, step, n, a);
            simpsJ = simpson(2, w, q, step, n, a);
            break;
        case 3:
            cout << "�������� � ����������� f(x)=4x^3-6x^2+7x-10" << endl;
            w = 0; q = 0;
            for (size_t i = 1; i < n; i++)
            {
                w += polinom3degree(a+i*step);
                q += polinom3degree((2*a+2*i*step+step)/2);
            }
            q += polinom3degree((2*a+step)/2);
            J = integralOfPolinom3degree(b) - integralOfPolinom3degree(a);
            leftJ = leftRectangles(3, w, step, a);
            rightJ = rightRectangles(3, w, step, n, a);
            middleJ = middleRectangles(3, q, step);
            trapJ = trapeze(3, w, step, n, a);
            simpsJ = simpson(3, w, q, step, n, a);
            break;
        case 4:
            cout << "�������� � �������� f(x)=6x^2+cos(x)*exp(4x)" << endl;
            w = 0; q = 0;
            for (size_t i = 1; i < n; i++)
            {
                w += func(a+i*step);
                q += func((2*a+2*i*step+step)/2);
            }
            q += func((2*a+step)/2);
            J = integralOfFunc(b) - integralOfFunc(a);
            leftJ = leftRectangles(4, w, step, a);
            rightJ = rightRectangles(4, w, step, n, a);
            middleJ = middleRectangles(4, q, step);
            trapJ = trapeze(4, w, step, n, a);
            simpsJ = simpson(4, w, q, step, n, a);
            break;
        case 5:
            cout << "�������� � �������� f(x)=1.27*x^5+2.04x" << endl;
            w = 0; q = 0;
            for (size_t i = 1; i < n; i++)
            {
                w += f(a+i*step);
                q += f((2*a+2*i*step+step)/2);
            }
            q += f((2*a+step)/2);
            J = F(b) - F(a);
            leftJ = leftRectangles(5, w, step, a);
            rightJ = rightRectangles(5, w, step, n, a);
            middleJ = middleRectangles(5, q, step);
            trapJ = trapeze(5, w, step, n, a);
            simpsJ = simpson(5, w, q, step, n, a);
            break;
        case 6:
            return 0;
        }
        cout << "������ �������� ���������: J = " << J << endl << endl;
        cout << "�� ����� ��������������� (���=0): J(h/l) = " << leftJ << endl
             << "���������� ����������� �����������: |J - J(h/l)| = " << fabs(J-leftJ) << endl
             << "���������� ����������� ����������� ��� ����������� �������� J(h/l): " << Runge(l, 0, step, J, leftJ) << endl
             << "------------------------------------------" << endl
             << "�� ������ ��������������� (���=0): J(h/l) = " << rightJ << endl
             << "���������� ����������� �����������: |J - J(h/l)| = " << fabs(J-rightJ) << endl
             << "���������� ����������� ����������� ��� ����������� �������� J(h/l): " << Runge(l, 0, step, J, rightJ) << endl
             << "------------------------------------------" << endl
             << "�� ������� ��������������� (���=1): J(h/l) = " << middleJ << endl
             << "���������� ����������� �����������: |J - J(h/l)| = " << fabs(J-middleJ) << endl
             << "���������� ����������� ����������� ��� ����������� �������� J(h/l): " << Runge(l, 0, step, J, middleJ) << endl
             << "------------------------------------------" << endl
             << "�� �������� (���=1): J(h/l) = " << trapJ << endl
             << "���������� ����������� �����������: |J - J(h/l)| = " << fabs(J-trapJ) << endl
             << "���������� ����������� ����������� ��� ����������� �������� J(h/l): " << Runge(l, 0, step, J, trapJ) << endl
             << "------------------------------------------" << endl
             << "�� �������� (���=3): J(h/l) = " << simpsJ << endl
             << "���������� ����������� �����������: |J - J(h/l)| = " << fabs(J-simpsJ) << endl
             << "���������� ����������� ����������� ��� ����������� �������� J(h/l): " << Runge(l, 0, step, J, simpsJ) << endl
             << "------------------------------------------" << endl << endl << endl;
        cin >> num;
        while (num != 0 && num != 1 && num != 2 && num != 3 && num != 4 && num!= 5 && num != 6)
        {
            cout << "������� �������� ��������! ��������� �������.";
            cin >> num;
        }

    }
    return 0;
}
