#include <iostream>
#include <string>

using namespace std;

int main()
{
    srand(time(0));
    int y, m, d, g, checksum, k;
    int rn[4];
    string PESEL = "";
    cout << "Year of birth: ";
    cin >> y;
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
        cout << "Please enter a real date of birth" << endl;
        exit(1);
    }
    else if (m > 12)
    {
        cout << "Please enter a real date of birth" << endl;
        exit(1);
    }
    else if (d > 31 || (d > 29 && m == 2) || (d > 30 && m == 4) || (d > 30 && m == 6) || (d > 30 && m == 9) || (d > 30 && m == 11))
    {
        cout << "Please enter a real date of birth" << endl;
        exit(1);
    }
    else if (y > 2000)
    {
        m += 20;
        string _y, _m, _d, tmp;
        tmp = to_string(y);
        _y += tmp[2];
        _y += tmp[3];
        tmp = to_string(m);
        if (m < 10)
        {
            _m = "0";
            _m += tmp;
        }
        else
        {
            _m = to_string(m);
        }
        tmp = to_string(d);
        if (d < 10)
        {
            _d = "0";
            _d += tmp;
        }
        else
        {
            _d = to_string(d);
        }
        PESEL += _y;
        PESEL += _m;
        PESEL += _d;
    }
    else
    {
        string _y, _m, _d, tmp;
        tmp = to_string(y);
        _y += tmp[2];
        _y += tmp[3];
        tmp = to_string(m);
        if (m < 10)
        {
            _m = "0";
            _m += tmp;
        }
        else
        {
            _m = to_string(m);
        }
        tmp = to_string(d);
        if (d < 10)
        {
            _d = "0";
            _d += tmp;
        }
        else
        {
            _d = to_string(d);
        }
        PESEL += _y;
        PESEL += _m;
        PESEL += _d;
    }
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
    PESEL += to_string(rn[0]);
    PESEL += to_string(rn[1]);
    PESEL += to_string(rn[2]);
    PESEL += to_string(rn[3]);

    checksum += (PESEL[0] - '0') * 1;
    checksum += (PESEL[1] - '0') * 3;
    checksum += (PESEL[2] - '0') * 7;
    checksum += (PESEL[3] - '0') * 9;
    checksum += (PESEL[4] - '0') * 1;
    checksum += (PESEL[5] - '0') * 3;
    checksum += (PESEL[6] - '0') * 7;
    checksum += (PESEL[7] - '0') * 9;
    checksum += (PESEL[8] - '0') * 1;
    checksum += (PESEL[9] - '0') * 3;

    k = 10 - (checksum % 10);
    PESEL += to_string(k);

    cout << "Your fake PESEL number: " << PESEL << endl;
}
