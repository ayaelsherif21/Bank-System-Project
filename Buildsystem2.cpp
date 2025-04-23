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
        return((password.size() >= 8 && password.size() <= 20) ? true : false);
    }
    /*Function to check if the balance is validated*/
    static bool validateBalance(double balance) {
        return((balance >= 0) ? true : false);
    }
    /*Function to check if the salary is validated*/
    static bool validateSalary(double salary) {
        return ((salary >= 5000) ? true : false);
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
    bool setName(string name) {
        if (Validation::validateName(name))
        {
            this->name = name;
            return true;
        }
        else {
            // cout << "Invalid Name!!!"<<endl;
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
    string getName () {
        return name;
    }
    string getPassword() {
        return password;
    }
    int getId() {
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

    Client(string name, string password, int id, double balance):Person(name,password,id) {
		isValid = Validation::validateName(name) && Validation::validatePassword(password) && Validation::validateBalance(balance);
        setId(id);
        if (isValid) {
           this->balance = balance;
        }
        else {
            cout << "ERROR" << endl;
        }
	}

    double getBalance()
    {
        return balance;
    }

    void deposit(double amount)
    {
        if (!isValid) {
            return;
        }
        if (amount > 0)
        {
            if (Validation::validateBalance(balance))
            {
                balance += amount;
                cout << " Your deposit of " << amount << " is add to your account. Your new balance is " << balance << endl;
                cout << endl;
                cout << " Thank you for banking with us! " << endl;
            }
        }
    }

    void withdraw(double amount)
    {
        if (isValid) {
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
        else {
            return;
        }
       
    }

    void transferTo(double amount, Client& recipient)
    {
        if (!isValid) {
            return;
        }
        if (amount <= balance && amount > 0)
        {
            if (Validation::validateBalance(balance))
            {
                balance -= amount;
                recipient.deposit(amount);
                cout << " Transferred successfully " << amount << " to " << recipient.getName() << endl;
            }

        }
        else
        {
            cout << "Insufficient funds or invalid amount." << endl;
        }
    }

    void checkBalance()
    {
        if (!isValid) {
            return;
        }
        if (Validation::validateBalance(balance))
        {
            cout << "Your current balance: " << balance << endl;
        }
        else
        {
            cout << "Your balance is negative! Please deposit funds to avoid issues." << endl;
        }
    }

    void Displayinfo()
    {
        if (!isValid) {
            return;
        }
        if (Validation::validateBalance(balance))
        {
            cout << " Welcome " << getName() << endl;
            cout << " id: " << getId() << endl;
            cout << " balance: " << balance << endl;
        }
        else
        {
            cout << "Your balance is negative! Please deposit funds to avoid issues." << endl;
        }
    }
};
class Employee : public Person {
private:
    string name;
    string password;
    int id;
	double salary;


public:
	Employee() {}
	Employee(string name, int id, string password, double salary) {
		setName(name);
		setId(id);
		setPassword(password);
		setSalary(salary);
	}
	//Setters
	void setId(int id) {
		this->id = id;
	}
	void setName(const string& name) {
		if (name.length() >= 5 && name.length() <= 20 && isAlphachars(name)) {
			this->name = name;
		}
		else {
			cout << "Error: Name must be 5-20 Alphabetic chars" << endl;
		}
	}
	void setPassword(const string& password) {
		if (password.length() >= 8 && password.length() <= 20) {
			this->password = password;
		}
		else {
			cout << "Error: Password must be 8-20 chars long" << endl;
		}
	}
	void setSalary(double salary) {
		if (salary > 5000) {
			this->salary = salary;
		}
		else {
			cout << "Error: Salary must be at least 5000$" << endl;
		}
	}
	//Getters
	int getId() const {
		return id;
	}
	string getName() const {
		return name;
	}
	string getPassword() const {
		return password;
	}
	double getSalary() const {
		return salary;
	}
	void print() const {
		cout << "Employee Name:" << getName() << endl;
		cout << "Employee Id:" << getId() << endl;
		cout << "Employee Password:" << getPassword() << endl;
		cout << "Employee Salary:" << getSalary() << endl;
	}

};

//********Admin Class***************

class Admin :public Employee {
private:
	int id;
	string name;
	string password;
	double salary;

	bool isAlphachars(const string& str) {
		for (char c : str) {
			if (!isalpha(c) && c != ' ') {
				return false;
			}
		}
		return true;
	}
public:
	Admin() {}
	Admin(string name, int id, string password, double salary) {
		setName(name);
		setId(id);
		setPassword(password);
		setSalary(salary);
	}
	//Setters
	void setId(int id) {
		this->id = id;
	}
	void setName(const string& name) {
		if (name.length() >= 5 && name.length() <= 20 && isAlphachars(name)) {
			this->name = name;
		}
		else {
			cout << "Error: Name must be 5-20 Alphabetic chars" << endl;
		}
	}
	void setPassword(const string& password) {
		if (password.length() >= 8 && password.length() <= 20) {
			this->password = password;
		}
		else {
			cout << "Error: Password must be 8-20 chars long" << endl;
		}
	}
	void setSalary(double salary) {
		if (salary > 5000) {
			this->salary = salary;
		}
		else {
			cout << "Error: Salary must be at least 5000$" << endl;
		}
	}
	//Getters
	int getId() const {
		return id;
	}
	string getName() const {
		return name;
	}
	string getPassword() const {
		return password;
	}
	double getSalary() const {
		return salary;
	}
	void print() const {
		cout << "Admin Name:" << getName() << endl;
		cout << "Admin Id:" << getId() << endl;
		cout << "Admin Password:" << getPassword() << endl;
		cout << "Admin Salary:" << getSalary() << endl;
	}

};

