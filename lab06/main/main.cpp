#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#include <iomanip>
#include "../../au/algor.hpp"
using namespace std;

struct Student
{
    string mName;
    double mGpa;
    Student(string name, double gpa)
        : mName(name), mGpa(gpa)
    {
    }
};
void p0101()
{
    vector<int> n = {3, 20, 100, -5, 4};
    {
        int a[] = {3, 1, 20, 4, 7, 0, 5};
        for (auto e : n)
        {
            auto r = find(begin(a), end(a), e);
            if (r != end(a))
            {
                cout << e << " is found. Its index is " << r - begin(a) << endl;
            }
            else
            {
                cout << e << " is not found\n";
            }
        }
    }
    {
        vector<int> a = {3, 1, 20, 4, 7, 0, 5};
        for (auto e : n)
        {
            auto r = find(a.begin(), a.end(), e);
            if (r != a.end())
            {
                cout << e << " is found. Its index is " << r - a.begin() << "\n";
            }
            else
            {
                cout << e << " is not found.\n";
            }
        }
    }
}
void p0102()
{
    vector<int> n = {3, 20, 100, -5, 4};

    {
        int a[] = {3, 1, 20, 4, 7, 0, 5};
        for (auto e : n)
        {
            auto r = auFind(begin(a), end(a), e);
            if (r != end(a))
            {
                cout << e << " is found. Its index is " << r - begin(a) << endl;
            }
            else
            {
                cout << e << " is not found." << endl;
            }
        }
    }
    {
        vector<int> a = {3, 1, 20, 4, 7, 0, 5};
        for (auto e : n)
        {
            auto r = auFind(a.begin(), a.end(), e);
            if (r != a.end())
            {
                cout << e << " is found. Its index is " << r - a.begin() << endl;
            }
            else
            {
                cout << e << " is not found." << endl;
            }
        }
    }
}
struct IsEven
{
    bool operator()(int n) const
    {
        return n % 2 == 0;
    }
};
void p0201()
{
    vector<int> a = {3, 1, 20, 20, 4, 7, 0, 5};
    // IsEven pred;
    auto it = find_if(a.begin(), a.end(), IsEven());

    if (it != a.end())
    {
        cout << *it << " is found. Its index is " << it - a.begin() << "\n";
    }
    else
    {
        cout << "No even number are found\n";
    }
}
void p0202()
{
    vector<int> a = {3, 1, 20, 20, 4, 7, 0, 5};
    // IsEven pred;
    auto it = find_if(a.begin(), a.end(), [](int n)
                      { return n % 2 == 0; });
    if (it != a.end())
    {
        cout << *it << " is found. Its index is " << it - a.begin() << "\n";
    }
    else
    {
        cout << "No even number are found\n";
    }
}
void p06()
{
    vector<Student> students;
    string name;
    double gpa;
    while (cin >> name >> gpa)
    {
        students.emplace_back(name, gpa); // push_back(Student(name, gpa));
    }
    cout << fixed << showpoint << setprecision(2);
    cout << "-----" << endl;
    sort(begin(students), end(students), [](const Student &s1, const Student &s2)
         { return s1.mName < s2.mName; });
    for (auto &s : students)
    {
        cout << s.mName << ", " << s.mGpa << "\n";
    }

    sort(begin(students), end(students), [](const Student &s1, const Student &s2)
         { return s1.mGpa > s2.mGpa; });
    cout << "-----" << endl;

    for (auto &s : students)
    {
        cout << s.mName << ", " << s.mGpa << "\n";
    }
}
struct GreaterThan
{
    int mX;
    GreaterThan(int aX) : mX(aX){};
    bool operator()(int n) const
    {
        return mX < n;
    }
};
void p03()
{
    vector<int> a = {3, 1, 20, 4, 7, 0, 5};
    cout << "Enter x: ";
    int x;
    cin >> x;
    auto it = find_if(a.begin(), a.end(), [x](int n)
                      { return x < n; });
    if (it != a.end())
    {
        cout << *it << " is found. Its index is " << it - a.begin() << "\n";
    }
    else
    {
        cout << "Not found"
             << "\n";
    }
    auto it2 = find_if(a.begin(), a.end(), GreaterThan(x));
    if (it2 != a.end())
    {
        cout << *it2 << " is found. Its index is " << it2 - a.begin() << "\n";
    }
    else
    {
        cout << "Not found"
             << "\n";
    }
}
void p07()
{
    vector<Student> students =
        {
            {"StudentD", 2.7},
            {"StudentA", 4.0},
            {"StudentX", 3.2},
            {"StudentC", 4.0},
            {"StudentK", 4.0},
            {"StudentE", 2.0},
            {"StudentR", 4.0},
            {"StudentD", 2.7},
            {"StudentA", 4.0}};
    cout << fixed << setprecision(2) << endl;
    cout << "--- regular sort by name ---\n";
    sort(begin(students), end(students), [](const Student &s1, const Student &s2)
         { return s1.mName < s2.mName; });
    for (const auto &s : students)
    {
        cout << s.mName << ", " << s.mGpa << endl;
    }
    cout << "---regular sort by gpa ---" << endl;
    sort(begin(students), end(students), [](const Student &s1, const Student &s2)
         { return s1.mGpa > s2.mGpa; });
    for (const auto &s : students)
    {
        cout << s.mName << ", " << s.mGpa << endl;
    }
    cout << "--- stable sort by name ---" << endl;
    stable_sort(begin(students), end(students), [](const Student &s1, const Student &s2)
                { return s1.mName < s2.mName; });
    for (const auto &s : students)
    {
        cout << s.mName << ", " << s.mGpa << endl;
    }
    cout << "--- stable sort by gpa ---" << endl;
    stable_sort(begin(students), end(students), [](const Student &s1, const Student &s2)
                { return s1.mGpa > s2.mGpa; });
    for (const auto &s1 : students)
    {
        cout << s1.mName << ", " << s1.mGpa << endl;
    }
}
// void p08()
// {
//     vector<pair<string, double>> students;
//     string name;
//     double gpa;
//     while (cin >> name >> gpa)
//     {
//         students.emplace_back(name, gpa); // push_back(Student(name, gpa)); when use emplace back we just pass arguments
//     }
//     cout << fixed << showpoint << setprecision(2);
//     cout << "-----" << endl;
//     sort(begin(students), end(students)); // pair support < operator
//     for (const auto &[name, gpa] : students)
//     {
//         cout << name << ", " << gpa << "\n";
//     }
// }
void p09()
{
    vector<tuple<string, int, double>> employees;
    string name;
    int age;
    double salary;
    while (cin >> name >> age >> salary)
    {
        employees.emplace_back(name, age, salary); // push_back(Student(name, gpa)); when use emplace back we just pass arguments
    }
    cout << fixed << showpoint << setprecision(2);
    cout << "-----" << endl;
    sort(begin(employees), end(employees), [](const auto &e1, const auto &e2)
         { return get<1>(e1) < get<1>(e2); }); // pair support < operator
    for (const auto &e : employees)
    {
        cout << get<0>(e) << ", " << get<1>(e) << ", " << get<2>(e) << "\n";
    }
}
int main()
{
    // p0101();
    // p0102();
    // p0201();
    // p0202();
    // p06();
    // p03();
    // p07();
    // p08();
    p09();
}