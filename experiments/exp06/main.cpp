#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;
class Student
{
    std::string mName;
    double mGpa;

public:
    Student(string name, double gpa)

    {
        mGpa = gpa;
        mName = name;
    }
    const double &getGpa() const
    {
        return mGpa;
    }
    const std::string &getStudent() const
    {
        return mName;
    }
};
int main()
{
    iostream::sync_with_stdio(false);
    // dereference
    vector<int> v = {1, 2, 3, 4, 5, 5};
    vector<int>::iterator t;
    t = v.begin();
    t += 4;
    cout << *t << endl;
    Student s("student01", 12.3);
    cout << s.getStudent() << " " << s.getGpa() << endl;
}
