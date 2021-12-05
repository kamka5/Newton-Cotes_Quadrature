#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

float calka1(int x)
{
    return sin(x)*sin(x)+2;
}

float calka2(int x)
{
    return exp(x)*2*x*x*x;
}

float trapez(int m, float a, float b, bool flag)
{
    float h = (b - a)/(m*1.0);
    float T = 0;

    if(flag) T = h*(1/2.0*calka1(a));
    else T = h*(1/2.0*calka2(a));
    for(int i = 1; i < m; i++)
    {
        if(flag) T += h*(calka1(a+i*h));
        else T += h*(calka2(a+i*h));
    }
    if(flag) T += h*(1/2.0*calka1(a+(m)*h));
    else T += h*(1/2.0*calka2(a+(m)*h));

    return T;
}

float Simpson(int m, float a, float b, bool flag)
{
    float h = (b - a)/(m*1.0);
    float T = 0;

    if(flag) T = h*(calka1(a));
    else T = h*(calka2(a));

    for(int i = 1; i < m; i+=2)
    {
        if(flag) T += 4*h*(calka1(a+i*h));
        else T += 4*h*(calka2(a+i*h));
    }

    for(int i = 2; i < m; i+=2)
    {
        if(flag) T += 2*h*(calka1(a+i*h));
        else T += 2*h*(calka2(a+i*h));
    }

    if(flag) T += h*calka1(a+(m)*h);
    else T += h*calka2(a+(m)*h);

    T /= 3;

    return T;
}

int main()
{
    bool isTrue = 1, Calka1_czy_Calka2;
    int choice = 0, choice2 = 0, liczba_przedzialow;
    while(isTrue){
        cout << "1) Calka 1. \n2) Calka 2. \n3) Wyjscie\n";
        cin >> choice;
        if(choice == 1){
            Calka1_czy_Calka2 = true;
            cout << "1) Trapez \n2) Simpson\n";
            cin >> choice2;
            if(choice2 == 1) {
                cout << "Podaj liczbe przedzialow: ";
                cin >> liczba_przedzialow;
                cout << trapez(liczba_przedzialow, 0, 2*M_PI, Calka1_czy_Calka2) << endl;
            }
            else if(choice2 == 2){
                cout << "Podaj liczbe przedzialow: ";
                cin >> liczba_przedzialow;
                cout << Simpson(liczba_przedzialow, 0, 2*M_PI, Calka1_czy_Calka2) << endl;
            }
            else {
                cout << "Nie ma takiej opcji!\n";
                cout << "1) Trapez \n2) Simpson\n3) Wyjscie\n";
                cin >> choice2;
            }
        }
        else if(choice == 2) {
            Calka1_czy_Calka2 = false;
            cout << "1) Trapez \n2) Simpson\n";
            cin >> choice2;
            if(choice2 == 1) {
                cout << "Podaj liczbe przedzialow: ";
                cin >> liczba_przedzialow;
                cout << trapez(liczba_przedzialow, 0, 2, Calka1_czy_Calka2) << endl;
            }
            else if(choice2 == 2){
                cout << "Podaj liczbe przedzialow: ";
                cin >> liczba_przedzialow;
                cout << Simpson(liczba_przedzialow, 0, 2, Calka1_czy_Calka2) << endl;
            }
            else {
                cout << "Nie ma takiej opcji!\n";\
                cout << "1) Trapez \n2) Simpson\n";
                cin >> choice2;
            }
        }
        else if(choice == 3) isTrue = 0;
        else {
            cout << "Nie ma takiej opcji!\n";
            cout << "1) Calka 1. \n2) Calka 2. \n";
            cin >> choice;
        }
    }
    return 0;
}
