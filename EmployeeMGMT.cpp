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

bool addEmployee()
{
    bool response;
    cout << "Would you like to add another employee?\nEnter 1 for yes\n enter 0 for no:\n";
    cin >> response;
    return response;
}

int main()
{

    Employee employeeOne;
    cout << "Enter employee name: ";
    getline(cin, employeeOne.name);
    cout << "Enter employee annual salary: ";
    cin >> employeeOne.salary;
    cout << "The first employee is " << employeeOne.name << "\nand their annual salary is " << employeeOne.salary;

    Employee employeeTwo;
    cout << "Enter employee name: ";
    //clear the cin buffer. See https://stackoverflow.com/questions/25475384/when-and-why-do-i-need-to-use-cin-ignore-in-c
    cin.ignore();
    getline(cin, employeeTwo.name);
    cout << "Enter employee annual salary: ";
    cin >> employeeTwo.salary;
    cout << "The second employee is " << employeeTwo.name << "\nand their annual salary is " << employeeTwo.salary;

    //if (addEmployee())
    //{
    //};

    return (0);
}