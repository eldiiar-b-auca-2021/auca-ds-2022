#include <algorithm>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

#include "../../au/algol.hpp"

using namespace std;

struct Student
{
    string mName;
    double mGpa;
    Student(const string &name, double gpa)
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
            auto it = find(begin(a), end(a), e);
            if (it != end(a))
            {
                cout << e << " found. Its index is " << it - begin(a) << "\n";
            }
            else
            {
                cout << e << " not found\n";
            }
        }
    }

    {
        vector<int> a = {3, 1, 20, 4, 7, 0, 5};
        for (auto e : n)
        {
            auto it = find(begin(a), end(a), e);
            if (it != end(a))
            {
                cout << e << " found. Its index is " << it - begin(a) << "\n";
            }
            else
            {
                cout << e << " not found\n";
            }
        }
    }
}

bool isEven(int n)
{
    return n % 2 == 0;
}

// functor, function object
struct IsEven
{
    bool operator()(int n) const
    {
        return n % 2 == 0;
    }
};

void p0102()
{
    vector<int> n = {3, 20, 100, -5, 4};
    {
        int a[] = {3, 1, 20, 4, 7, 0, 5};
        for (auto e : n)
        {
            auto it = auFind(begin(a), end(a), e);
            if (it != end(a))
            {
                cout << e << " found. Its index is " << it - begin(a) << "\n";
            }
            else
            {
                cout << e << " not found\n";
            }
        }
    }

    {
        vector<int> a = {3, 1, 20, 4, 7, 0, 5};
        for (auto e : n)
        {
            auto it = auFind(begin(a), end(a), e);
            if (it != end(a))
            {
                cout << e << " found. Its index is " << it - begin(a) << "\n";
            }
            else
            {
                cout << e << " not found\n";
            }
        }
    }
}

void p0201()
{
    vector<int> a = {3, 1, 20, 4, 7, 0, 5};

    auto it = find_if(begin(a), end(a), IsEven());
    if (it != end(a))
    {
        cout << *it << " found. Its index is " << it - begin(a) << "\n";
    }
    else
    {
        cout << "No even number are found\n";
    }
}

void p0202()
{
    vector<int> a = {3, 1, 20, 4, 7, 0, 5};

    auto it = find_if(begin(a), end(a),
                      [](auto n) // lambda expression
                      { return n % 2 == 0; });

    if (it != end(a))
    {
        cout << *it << " found. Its index is " << it - begin(a) << "\n";
    }
    else
    {
        cout << "No even number are found\n";
    }
}

struct GreaterThan
{
    int mX;
    GreaterThan(int x) : mX(x){};
    bool operator()(int n) const
    {
        return n > mX;
    }
};

void p03()
{
    vector<int> a = {3, 1, 20, 4, 7, 0, 5};

    cout << "Enter x: ";
    int x;
    cin >> x;

    auto it = find_if(begin(a), end(a),
                      [x](auto n)
                      { return n > x; });

    if (it != end(a))
    {
        cout << *it << " found. Its index is " << it - begin(a) << "\n";
    }
    else
    {
        cout << "No even number are found\n";
    }

    auto it2 = find_if(begin(a), end(a), GreaterThan(x));

    if (it2 != end(a))
    {
        cout << *it2 << " found. Its index is " << it2 - begin(a) << "\n";
    }
    else
    {
        cout << "No even number are found\n";
    }
}

void p0401()
{
    vector<int> v;
    for (int x; cin >> x;)
    {
        v.push_back(x);
    }

    auto p = min_element(begin(v), end(v));
    if (p != end(v))
    {
        cout << "Min value: " << *p << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
}

void p0402()
{
    vector<int> v;
    for (int x; cin >> x;)
    {
        v.push_back(x);
    }

    auto p = auMinElement(begin(v), end(v));
    if (p != end(v))
    {
        cout << "Min value: " << *p << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
}

void p0501()
{
    vector<Student> students;
    string name;
    double gpa;
    while (cin >> name >> gpa)
    {
        students.emplace_back(name, gpa);
    }

    auto iterToMinGpa = min_element(begin(students), end(students),
                                    [](const Student &s1, const Student &s2)
                                    { return s1.mGpa < s2.mGpa; });

    if (iterToMinGpa != end(students))
    {
        cout << "with min gpa: " << iterToMinGpa->mName << " " << iterToMinGpa->mGpa << endl;
    }
    else
    {
        cout << "not found" << endl;
    }

    auto iterToMinName = min_element(begin(students), end(students),
                                     [](const Student &s1, const Student &s2)
                                     { return s1.mName < s2.mName; });

    if (iterToMinName != end(students))
    {
        cout << "with min name: " << iterToMinName->mName << " " << iterToMinName->mGpa << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
}

void p0502()
{
    vector<Student> students;
    string name;
    double gpa;
    while (cin >> name >> gpa)
    {
        students.emplace_back(name, gpa);
    }

    auto iterToMinGpa = auMinElement(begin(students), end(students),
                                     [](const Student &s1, const Student &s2)
                                     { return s1.mGpa < s2.mGpa; });

    if (iterToMinGpa != end(students))
    {
        cout << "with min gpa: " << iterToMinGpa->mName << " " << iterToMinGpa->mGpa << endl;
    }
    else
    {
        cout << "not found" << endl;
    }

    auto iterToMinName = auMinElement(begin(students), end(students),
                                      [](const Student &s1, const Student &s2)
                                      { return s1.mName < s2.mName; });

    if (iterToMinName != end(students))
    {
        cout << "with min name: " << iterToMinName->mName << " " << iterToMinName->mGpa << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
}

void p06()
{
    vector<Student> students;
    string name;
    double gpa;
    while (cin >> name >> gpa)
    {
        students.emplace_back(name, gpa);
    }

    sort(begin(students), end(students),
         [](const Student &s1, const Student &s2)
         { return s1.mName < s2.mName; });

    cout << "---" << endl;
    cout << fixed << showpoint << setprecision(2);
    for (const auto &s : students)
    {
        cout << s.mName << ", " << s.mGpa << endl;
    }

    sort(begin(students), end(students),
         [](const Student &s1, const Student &s2)
         { return s1.mGpa > s2.mGpa; });

    cout << "---" << endl;
    for (const auto &s : students)
    {
        cout << s.mName << ", " << s.mGpa << endl;
    }
}

void p07()
{
    vector<Student> students = {
        {"StudentD", 2.7},
        {"StudentA", 4.0},
        {"StudentX", 3.2},
        {"StudentC", 4.0},
        {"StudentK", 4.0},
        {"StudentE", 2.0},
        {"StudentR", 4.0},
        {"StudentD", 2.7},
        {"StudentA", 4.0},
        {"StudentX", 3.2},
        {"StudentC", 4.0},
        {"StudentK", 4.0},
        {"StudentE", 2.0},
        {"StudentR", 4.0},
        {"StudentR", 4.0},
        {"StudentD", 2.7},
        {"StudentA", 4.0},
        {"StudentX", 3.2},
        {"StudentC", 4.0},
        {"StudentK", 4.0},
        {"StudentE", 2.0},
        {"StudentR", 4.0}};

    cout << "--- regular sort by name ---" << endl;

    sort(begin(students), end(students), [](const Student &s1, const Student &s2)
         { return s1.mName < s2.mName; });

    for (const auto &s : students)
    {
        cout << s.mName << ", " << s.mGpa << endl;
    }

    cout << "--- regular sort by gpa ---" << endl;

    sort(begin(students), end(students),
         [](const Student &s1, const Student &s2)
         { return s1.mGpa < s2.mGpa; });

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
                { return s1.mGpa < s2.mGpa; });

    for (const auto &s : students)
    {
        cout << s.mName << ", " << s.mGpa << endl;
    }
}

void p08()
{
    vector<pair<string, double>> students;
    string name;
    double gpa;
    while (cin >> name >> gpa)
    {
        // students.push_back(make_pair(name, gpa))
        students.emplace_back(name, gpa);
    }

    sort(begin(students), end(students));

    cout << "---" << endl;
    cout << fixed << showpoint << setprecision(2);
    for (const auto &p : students)
    {
        cout << p.first << ", " << p.second << endl;
    }
}

void p09()
{
    vector<tuple<string, int, double>> employes;
    string name;
    int age;
    double salary;
    while (cin >> name >> age >> salary)
    {
        employes.emplace_back(name, age, salary);
    }

    sort(begin(employes), end(employes),
         [](const auto &e1, const auto &e2)
         { return get<1>(e1) < get<1>(e2); });

    cout << "---" << endl;
    cout << fixed << showpoint << setprecision(2);
    for (const auto &e : employes)
    {
        cout << get<0>(e) << ", " << get<1>(e) << ", " << get<2>(e) << endl;
    }
}

void p1001()
{
    vector<int> v = {0, 4, 5, 10, 12, 20, 25, 40};

    for (int x; cin >> x;)
    {
        cout << (binary_search(begin(v), end(v), x) ? "Yes\n" : "No\n");
    }
}

void p1002()
{
    vector<int> v = {0, 4, 5, 10, 12, 20, 25, 40};

    for (int x; cin >> x;)
    {
        cout << (auBinarySearch(begin(v), end(v), x) ? "Yes\n" : "No\n");
    }
}

void p11()
{
    vector<int> v = {0, 4, 5, 10, 12, 20, 25, 40};

    for (int x; cin >> x;)
    {
        auto it = lower_bound(begin(v), end(v), x);
        // no elements equal or greater than x
        if (it == end(v))
        {
            cout << "no elements equal or greater than " << x << endl;
        }
        // there is an element equal to x
        else if (*it == x)
        {
            cout << "first element equal to " << x << " has index: " << it - begin(v) << endl;
        }
        else
        {
            cout << "there are no elements equal to " << x << endl;
            cout << "first element greater than " << x << " has index: " << it - begin(v) << endl;
        }
    }
}

void p12()
{
    vector<int> v = {0, 0, 4, 5, 10, 10, 10, 12, 20, 25, 35, 25, 25, 40};

    for (int x; cin >> x;)
    {
        auto p = equal_range(begin(v), end(v), x);
        if (p.first == p.second)
        {
            cout << "there are no elements equal to " << x << endl;
        }
        else
        {
            cout << "number of elements equal to x is: " << p.second - p.first << endl;
        }
    }
}

int main()
{
    // p0101();
    // p0102();
    // p0201();
    // p0202();
    // p03();
    // p0401();
    // p0402();
    // p0501();
    // p0502();
    // p06();
    // p07();
    // p08();
    // p09();
    // p1001();
    // p1002();
    // p11();
    // p12();
}