#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Employee{
	private:
		int id;
		string name;
		string password;
		double salary;
		
		bool isAlphachars(const string& str){
			for(char c : str){
				if(!isalpha(c) && c !=' '){
					return false;
				}
			}
			return true;
		}
	public:
		Employee() {}
		Employee(string name, int id, string password, double salary){
		setName(name); 
        setId(id);
        setPassword(password);
        setSalary(salary);
		}
		//Setters
		void setId(int id){
			this->id = id;
		}
		void setName(const string& name){
			if(name.length() >= 5 && name.length() <=20 && isAlphachars(name) ){
				this->name = name;
			}
			else{
				cout << "Error: Name must be 5-20 Alphabetic chars" << endl;
			}
		}
		void setPassword(const string& password){
			if(password.length() >= 8 && password.length() <=20){
				this->password = password;
			}
			else{
				cout << "Error: Password must be 8-20 chars long" << endl;
			}
		}
		void setSalary(double salary){
			if(salary > 5000){
				this->salary=salary;
			}
			else{
				cout << "Error: Salary must be at least 5000$" << endl;
			}
		}
		//Getters
		int getId() const{
			return id;
		}
		string getName() const{
			return name;
		}
		string getPassword() const{
			return password;
		}
		double getSalary() const{
			return salary;
		}
		void print() const {
			cout<<"Employee Name:" <<getName()<<endl;
			cout<<"Employee Id:" <<getId()<<endl;
			cout<<"Employee Password:" <<getPassword()<<endl;
			cout<<"Employee Salary:" <<getSalary()<<endl;
		}
		
};

//********Admin Class***************

class Admin{
	private:
		int id;
		string name;
		string password;
		double salary;
		
		bool isAlphachars(const string& str){
			for(char c : str){
				if(!isalpha(c) && c !=' '){
					return false;
				}
			}
			return true;
		}
	public:
		Admin() {}
		Admin(string name, int id, string password, double salary){
		setName(name); 
        setId(id);
        setPassword(password);
        setSalary(salary);
		}
		//Setters
		void setId(int id){
			this->id = id;
		}
		void setName(const string& name){
			if(name.length() >= 5 && name.length() <=20 && isAlphachars(name) ){
				this->name = name;
			}
			else{
				cout << "Error: Name must be 5-20 Alphabetic chars" << endl;
			}
		}
		void setPassword(const string& password){
			if(password.length() >= 8 && password.length() <=20){
				this->password = password;
			}
			else{
				cout << "Error: Password must be 8-20 chars long" << endl;
			}
		}
		void setSalary(double salary){
			if(salary > 5000){
				this->salary=salary;
			}
			else{
				cout << "Error: Salary must be at least 5000$" << endl;
			}
		}
		//Getters
		int getId() const{
			return id;
		}
		string getName() const{
			return name;
		}
		string getPassword() const{
			return password;
		}
		double getSalary() const{
			return salary;
		}
		void print() const {
			cout<<"Admin Name:" <<getName()<<endl;
			cout<<"Admin Id:" <<getId()<<endl;
			cout<<"Admin Password:" <<getPassword()<<endl;
			cout<<"Admin Salary:" <<getSalary()<<endl;
		}
		
};

int main(){
	Employee emp("es",101, "an123", 4000.0);;
	emp.print();
	cout << "===================="<<endl;
	Employee emp1("Moham21" , 212 , "ayamo5900" , 8000.0);
	emp1.print();
	
	Admin ad("es",101, "es123", 4000.0);;
	ad.print();
	cout << "===================="<<endl;
	Admin ad1("Moham21" , 212 , "ayamo5900" , 8000.0);
	ad1.print();
	return 0;
}
