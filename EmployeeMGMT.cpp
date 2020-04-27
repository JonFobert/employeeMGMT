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

class IndvContributer : public Employee
{
public:
    string jobFunction;
    IndvContributer();
    IndvContributer(string employeeName, int employeeSalary, string jobFunction);

    static bool askToAddContributer()
    {
        bool response;
        cout << "Would you like to add another individuaContributer?\nEnter 1 for yes\n enter 0 for no:\n";
        cin >> response;
        return response;
    }

    static void addIndvContributer()
    {
        IndvContributer IndvContributerOne;
        cout << "Enter individual contributer name: ";
        getline(cin, IndvContributerOne.name);
        cout << "Enter individual contributer annual salary: ";
        cin >> IndvContributerOne.salary;
        cin.ignore();
        cout << "Enter their job function: ";
        cin.ignore();
        cin >> IndvContributerOne.jobFunction;
        cout << "The first employee is " << IndvContributerOne.name << "\nand their annual salary is " << IndvContributerOne.salary << "\nand their job is " << IndvContributerOne.jobFunction;
    }
};

IndvContributer::IndvContributer()
{
    name = "noname";
    salary = 0;
    jobFunction = "nojob";
}

IndvContributer::IndvContributer(string employeeName, int employeeSalary, string theirJobFunction)
{
    name = employeeName;
    salary = employeeSalary;
    jobFunction = theirJobFunction;
}

class Executive : public Employee
{
public:
    string team;
    Executive();
    Executive(string employeeName, int employeeSalary, string team);

    static bool askToAddExecutive()
    {
        bool response;
        cout << "Would you like to add another Executive?\nEnter 1 for yes\n enter 0 for no:\n";
        cin >> response;
        return response;
    }

    static void addExecutive()
    {
        Executive ExecutiveOne;
        cout << "Enter Executive name: ";
        getline(cin, ExecutiveOne.name);
        cout << "Enter Executive annual salary: ";
        cin >> ExecutiveOne.salary;
        cin.ignore();
        cout << "Enter the team they lead: ";
        cin.ignore();
        cin >> ExecutiveOne.team;
        cout << "The first employee is " << ExecutiveOne.name << "\nand their annual salary is " << ExecutiveOne.salary << "\n and they lead this team: " << ExecutiveOne.team;
    }
};

Executive::Executive()
{
    name = "noname";
    salary = 0;
    team = "noteam";
}

Executive::Executive(string employeeName, int employeeSalary, string teamTheyLead)
{
    name = employeeName;
    salary = employeeSalary;
    team = teamTheyLead;
}

int main()
{

    bool moreEmployeesToAdd = true;

    while (moreEmployeesToAdd == true)
    {
        if (IndvContributer::askToAddContributer())
        {
            IndvContributer::addIndvContributer();
        }
        else if (Executive::askToAddExecutive())
        {
            Executive::addExecutive();
        }
        else
        {
            moreEmployeesToAdd = false;
        }
    }
    return (0);
}