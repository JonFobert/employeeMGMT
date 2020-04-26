#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Employee
{
public:
    string name;
    int salary;

    void set_values(string, int);
    int monthlySalary()
    {
        return salary / 12;
    }
};
void Employee::set_values(string employeeName, int employeeSalary)
{
    name = employeeName;
    salary = employeeSalary;
}

int main()
{
    Employee employeeOne;
    cout << "Enter employee name: ";
    getline(cin, employeeOne.name);
    cout << "Enter employee annual salary: ";
    cin >> employeeOne.salary;
    cout << "The first employee is " << employeeOne.name << "\n and their annual salary is " << employeeOne.salary;
    return (0);
}