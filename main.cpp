#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

string generatePESEL(int y, int m, int d, int g)
{
    string PESEL = "";
    int checksum = 0;
    int k;
    int rn[4];

    if (y > 2000)
    {
        m += 20;
    }

    string _y, _m, _d, tmp;
    tmp = to_string(y);
    _y += tmp[2];
    _y += tmp[3];
    tmp = to_string(m);
    if (m < 10)
    {
        _m = "0" + tmp;
    }
    else
    {
        _m = tmp;
    }
    tmp = to_string(d);
    if (d < 10)
    {
        _d = "0" + tmp;
    }
    else
    {
        _d = tmp;
    }

    PESEL += _y + _m + _d;

    rn[0] = rand() % 10;
    rn[1] = rand() % 10;
    rn[2] = rand() % 10;

    int even[] = {0, 2, 4, 6, 8};
    int odd[] = {1, 3, 5, 7, 9};

    if (g == 1)
    {
        rn[3] = odd[rand() % 5];
    }
    else
    {
        rn[3] = even[rand() % 5];
    }

    PESEL += to_string(rn[0]) + to_string(rn[1]) + to_string(rn[2]) + to_string(rn[3]);
    int w[10] = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3};

    for (int i = 0; i < 10; i++)
    {
        checksum += (PESEL[i] - '0') * w[i];
    }
    k = checksum % 10;
    if (k != 0)
        k = 10 - k;
    PESEL += char('0' + k);
    return PESEL;
}

int main()
{
    srand(time(0));
    int y, m, d, g, a;
    char b;
    cout << "PESEL GENERATOR v1.1 BY BOMBOCLAAT. " << endl;
    cout << "How many PESELs do you want to generate?" << endl;
    cout << "> ";
    cin >> a;
    if (a < 1)
    {
        cout << "Enter al least 1." << endl;
        exit(1);
    }
    string PESEL = "";
    bool leap_year;
    cout << "Year of birth: ";
    cin >> y;
    if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
    {
        leap_year = true;
    }
    else
    {
        leap_year = false;
    }
    cout << "Month of bitrh: ";
    cin >> m;
    cout << "Day of birth: ";
    cin >> d;
    cout << "1. Male" << endl
         << "2. Female" << endl;
    cout << "> ";
    cin >> g;
    if (y > 2099)
    {
        cout << "Please enter a real date of birth" << endl;
        exit(1);
    }
    else if (y < 1900)
    {
        cout << "The year of birth should be at least 1900" << endl;
        exit(1);
    }
    else if (m > 12)
    {
        cout << "Please enter a real date of birth" << endl;
        exit(1);
    }
    else if (d > 31 || (d > 28 && m == 2 && leap_year == false) || (d > 29 && m == 2 && leap_year == true) || (d > 30 && m == 4) || (d > 30 && m == 6) || (d > 30 && m == 9) || (d > 30 && m == 11))
    {
        cout << "Please enter a real date of birth" << endl;
        exit(1);
    }

    if (a < 2)
    {
        PESEL = generatePESEL(y, m, d, g);
        cout << "Your new PESEL: " << PESEL << endl;
    }
    else
    {
        vector<string> PESEL(a);
        cout << "Your new PESELs: " << endl;
        for (int i = 0; i < a; i++)
        {
            PESEL[i] = generatePESEL(y, m, d, g);
        }
        for (string x : PESEL)
        {
            cout << x << endl;
        }
        cout << "Save it to a file? [Y/N] ";
        cin >> b;
        if (b == 'y' || b == 'Y')
        {
            ofstream file("PESELs.txt");
            for (string x : PESEL)
            {
                file << x << endl;
            }
            file.close();
        }
        else
        {
            exit(0);
        }
    }

    return 0;
}
