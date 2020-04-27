#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Employee
{
public:
    string name;
    int salary;

    //Constructor function for the class. Doesn't need a return type.
    Employee();
    Employee(string, int);
    int monthlySalary()
    {
        return salary / 12;
    }
};

Employee::Employee()
{
    name = "noname";
    salary = 0;
}

Employee::Employee(string employeeName, int employeeSalary)
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
    cout << "The first employee is " << employeeOne.name << "\nand their annual salary is " << employeeOne.salary << "\n";

    if (addEmployee())
    {
        Employee employeeTwo;
        cout << "Enter employee name: ";
        //clear the cin buffer. Seehttps://www.geeksforgeeks.org/problem-with-scanf-when-there-is-fgetsgetsscanf-after-it/ and  https://stackoverflow.com/questions/25475384/when-and-why-do-i-need-to-use-cin-ignore-in-c
        cin.ignore();
        getline(cin, employeeTwo.name);
        cout << "Enter employee annual salary: ";
        cin >> employeeTwo.salary;
        cout << "The second employee is " << employeeTwo.name << "\nand their annual salary is " << employeeTwo.salary;
    };
    return (0);
}