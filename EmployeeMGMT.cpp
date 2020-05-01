#include <iostream>
#include <string>
#include <sstream>
#include <vector>
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
        cout << "\nWould you like to add another individuaContributer?\nEnter 1 for yes\n enter 0 for no:\n";
        cin >> response;
        return response;
    }

    static void addIndvContributer(int numOfIndvContrToAdd, IndvContributer allContributers[])
    {
        IndvContributer IndvContributerOne;
        cout << "Enter individual contributer name: ";
        cin.ignore();
        getline(cin, IndvContributerOne.name);
        cout << "Enter individual contributer annual salary: ";
        cin >> IndvContributerOne.salary;
        cin.ignore();
        cout << "Enter their job function: ";
        cin.ignore();
        cin >> IndvContributerOne.jobFunction;
        cout << "The first employee is " << IndvContributerOne.name << "\nand their annual salary is " << IndvContributerOne.salary << "\nand their job is " << IndvContributerOne.jobFunction;
        allContributers[(numOfIndvContrToAdd - 1)] = IndvContributerOne;
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
        cout << "\nWould you like to add another Executive?\nEnter 1 for yes\n enter 0 for no:\n";
        cin >> response;
        return response;
    }

    static void addExecutive(int numOfExec, Executive allExecs[])
    {
        Executive ExecutiveOne;
        cout << "Enter Executive name: ";
        cin.ignore();
        getline(cin, ExecutiveOne.name);
        cout << "Enter Executive annual salary: ";
        cin >> ExecutiveOne.salary;
        cin.ignore();
        cout << "Enter the team they lead: ";
        cin.ignore();
        cin >> ExecutiveOne.team;
        cout << "The first employee is " << ExecutiveOne.name << "\nand their annual salary is " << ExecutiveOne.salary << "\n and they lead this team: " << ExecutiveOne.team;
        allExecs[(numOfExec - 1)] = ExecutiveOne;
    }
};

/* Replaced by new function that 
static void addExecutive()
{
    Executive ExecutiveOne;
    cout << "Enter Executive name: ";
    cin.ignore();
    getline(cin, ExecutiveOne.name);
    cout << "Enter Executive annual salary: ";
    cin >> ExecutiveOne.salary;
    cin.ignore();
    cout << "Enter the team they lead: ";
    cin.ignore();
    cin >> ExecutiveOne.team;
    cout << "The first employee is " << ExecutiveOne.name << "\nand their annual salary is " << ExecutiveOne.salary << "\n and they lead this team: " << ExecutiveOne.team;
}
}
*/
;

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

    int numIndvContrib = 0;
    IndvContributer allContributers[50];

    int numExecs = 0;
    Executive allExecs[50];

    vector<Employee *> employeesVec;

    bool moreEmployeesToAdd = true;
    while (moreEmployeesToAdd == true)
    {
        if (IndvContributer::askToAddContributer())
        //if (true)
        {
            numIndvContrib++;
            IndvContributer::addIndvContributer(numIndvContrib, allContributers);
            for (int i = 0; i < numIndvContrib; i++)
            {
                cout << "\n\n"
                     << allContributers[(numIndvContrib - 1)].name;
            }
        }
        else if (Executive::askToAddExecutive())
        {
            numExecs++;
            Executive::addExecutive(numExecs, allExecs);
            for (int i = 0; i < numExecs; i++)
            {
                cout << "\n\n"
                     << allExecs[(numExecs - 1)].name;
            }
        }
        else
        {
            moreEmployeesToAdd = false;
        }
    }
    return (0);
}