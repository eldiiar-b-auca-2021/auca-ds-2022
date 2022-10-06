#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    const string noDataMessage = "no data";
    const int width = 30;
    for (string name; cin >> name;)
    {

        int nGrades = 0;
        double sum = 0;
        int grade;
        while (cin >> grade)
        {
            nGrades++;
            sum += grade;
        }
        cout << setfill('.') << fixed << setprecision(2);
        if (sum == 0)
        {
            cout << left << setw(width) << name << "|" << right << setw(width) << noDataMessage << "\n";
        }
        else
        {
            cout << left << setw(width) << name << "|" << right << setw(width) << sum / nGrades << "\n";
        }
        cin.clear();
    }
}