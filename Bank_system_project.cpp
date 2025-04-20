#include <iostream>
#include<string>
using namespace std;
class Person {
	string name;
	string password;
	int id;
public:
	Person() {}
	Person(string name,string password,int id):name(name),password(password),id(id){}
	void setName(string name) {
		if (Validation::validateName(name)) {
			this->name = name;
		}
	}
	void setPassword(string password) {
		if (Validation::validatePassword(password)) {
			this->password = password;
		}
	}
	void setId(int id) {
		this->id = id;
	}
	string getName() {
		return name;
	}
	string getPassword() {
		return password;
	}
	int getId() {
		return id;
	}
};
class Validation {
public:
	static bool validateName(string name) {
		for (int i = 0; i < name.size(); i++) {
			if (!(name[i] >= 'a' && name[i] <= 'z') && !(name[i] >= 'A' && name[i] <= 'Z')) {
				cout << "Invalid Name!!!" << endl;
				return false;
			}
		}
			if (name.size() >= 5 && name.size() <= 20) {
				return true;
			}
			else {
				cout << "Invalid Name!!!" << endl;
				return false;
			}
	}
	static bool validatePassword(string password) {
		return((password.size() >= 8 && password.size() <= 20) ? true : false);
	}
	static bool validateBalance(double balance) {
		return((balance >= 0) ? true : false);
	}
	static bool validateSalary(double salary) {
		return ((salary >= 5000) ? true : false);
	}
};
int main()
{
	return 0;
}

