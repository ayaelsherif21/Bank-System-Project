#include<iostream>
#include<string>
#include<cctype>
using namespace std;
class Validation
{
public:
    /*Function to check if the name is validated*/
    static bool validateName(const string& name) {
        for (int i = 0; i < name.size(); i++) {
            if (!(isalpha(name[i])) && name[i] != ' ') {
                return false;
            }
        }
        return (name.size() >= 5 && name.size() <= 20);
    }
    /*Function to check if the password is validated*/
    static bool validatePassword(const string& password) {
        return(password.size() >= 8 && password.size() <= 20);
    }
    /*Function to check if the balance is validated*/
    static bool validateBalance(double balance) {
        return(balance >= 0);
    }
    /*Function to check if the salary is validated*/
    static bool validateSalary(double salary) {
        return (salary >= 5000);
    }
};

class Person {
    string name;
    string password;
    int id;
public:
    Person() {}
    Person(string name, string password, int id) {
        setName(name);
        setPassword(password);
        setId(id);
    }
    /*Setters*/
    bool setName(string name) {
        if (Validation::validateName(name))
        {
            this->name = name;
            return true;
        }
        else {
            cout << "Invalid Name!!!" << endl;
            return false;
        }
    }
    bool setPassword(string password) {
        if (Validation::validatePassword(password)) {
            this->password = password;
            return true;
        }
        else {
            cout << "Invalid Password!!!" << endl;
            return false;
        }
    }
    void setId(int id) {
        this->id = id;
    }
    /*Getters*/
    string getName()const {
        return name;
    }
    string getPassword() const {
        return password;
    }
    int getId()const {
        return id;
    }
};

class Client : public Person
{

    double balance;

public:
    /*Flag to check if the data members are valid*/
    bool isValid = true;
    Client() {}
    Client(string name, string password, int id, double balance) :Person(name, password, id) {
        isValid = Validation::validateName(name) && Validation::validatePassword(password) && Validation::validateBalance(balance);

        if (isValid) {
            this->balance = balance;
        }
        else {
            cout << "ERROR" << endl;
        }
    }

    double getBalance()const
    {
        return balance;
    }

    void deposit(double amount)
    {
        if (isValid)
        {
            if (amount > 0)
            {
                balance += amount;
                cout << " Your deposit of " << amount << " is added to your account. Your new balance is " << balance << endl;
                cout << endl;
                cout << " Thank you for banking with us! " << endl;
            }
            else
            {
                cout << "You entered wrong amount. please try again! " << endl;
            }
        }

        else
        {
            cout << "Invalid Client Data!!!" << endl;
            return;
        }
    }

    void withdraw(double amount)
    {
        if (isValid)
        {
            if (amount <= balance && amount > 0)
            {
                balance -= amount;

                cout << " the amount of " << amount << " is deducted from your account" << endl;
            }
            else
            {
                cout << "You don't have enough credit or invalid amount" << endl;
            }
        }

        else
        {
            cout << "Invalid Client Data!!!" << endl;
            return;
        }
    }

    void transferTo(double amount, Client& recipient)
    {
        if (isValid)
        {

            if (amount <= balance && amount > 0)
            {
                balance -= amount;
                recipient.deposit(amount);
                cout << " Transferred successfully " << amount << " to " << recipient.getName() << endl;
            }

        }
        else
        {
            cout << "Invalid Client Data!!!" << endl;
            return;
        }
    }

    void checkBalance()
    {
        if (isValid)
        {
            cout << "Your current balance: " << balance << endl;
        }

        else
        {
            cout << "Invalid Client Data!!!" << endl;
            return;
        }
    }

    void Displayinfo()
    {
        if (isValid)
        {
            cout << " Welcome " << getName() << endl;
            cout << " id: " << getId() << endl;
            cout << " balance: " << balance << endl;
        }

        else
        {
            cout << "Invalid Client Data!!!" << endl;
            return;
        }
    }
};
class Employee : public Person {
private:
    double salary;
public:
    /*Flag to check if the data members are valid*/
    bool isValid = true;
    Employee() {}
    Employee(string name, int id, string password, double salary) :Person(name, password, id) {
        isValid = Validation::validateName(name) && Validation::validatePassword(password) && Validation::validateSalary(salary);
        if (isValid) {
            setSalary(salary);
        }
    }

    void setSalary(double salary) {
        if (Validation::validateSalary(salary)) {
            this->salary = salary;
        }
    }
    //Getters

    double getSalary() const {
        return salary;
    }
    void print() const {
        if (isValid) {
            cout << "Employee Name:" << getName() << endl;
            cout << "Employee Id:" << getId() << endl;
            cout << "Employee Password:" << getPassword() << endl;
            cout << "Employee Salary:" << getSalary() << endl;
        }
        else {
            return;
        }
    }

};

//********Admin Class***************

class Admin :public Employee {

public:

    Admin() {}
    Admin(string name, int id, string password, double salary) :Employee(name, id, password, salary) {}

    void print() const {
        if (isValid) {
            cout << "Admin Name:" << getName() << endl;
            cout << "Admin Id:" << getId() << endl;
            cout << "Admin Password:" << getPassword() << endl;
            cout << "Admin Salary:" << getSalary() << endl;
        }
        else {
            return;
        }
    }

};
