
class Client : public Person
{

    double balance;

public:

    Client(){}

    Client( string name, string password,int id, double balance) : Person(name,password,id), balance(balance){}

    double getBalance()
    {
        return balance;
    }

    void deposit(double amount)
    {
        if(amount > 0 )
        {
            if (Validation::validateBalance(balance))
            {
               balance += amount;
            cout<< " Your deposit of "<< amount<< " is add to your account. Your new balance is " <<balance<<endl;
            cout<<endl;
            cout<< " Thank you for banking with us! "<<endl;
            }
        }
    }

    void withdraw(double amount)
    {
        if(amount < balance && amount > 0)
        {
            if(Validation::validateBalance(balance))
            {
              balance-= amount;

              cout<< " the amount of "<< amount << " is deducted from your account"<<endl;
            }
        }
        else
        {
          cout<< "You don't have enough credit or invalid amount"<<endl;
        }
    }

    void transferTo (double amount, Client&recipient)
    {
        if(amount < balance && amount > 0)
        {
            if(Validation::validateBalance(balance))
         {
              balance -=  amount;
              recipient.deposit(amount);
              cout<< " Transferred successfully " << amount <<" to "<< recipient.getName()<< endl;
         }

        }
        else
        {
            cout<< "Insufficient funds or invalid amount."<<endl;
        }
    }

    void checkBalance()
    {
         if(Validation::validateBalance(balance))
         {
           cout<< "Your current balance: "<<balance<<endl;
         }
         else
        {
          cout << "Your balance is negative! Please deposit funds to avoid issues." << endl;
        }
    }

    void Displayinfo()
    {
        if(Validation::validateBalance(balance))
         {
           cout<< " Welcome "<< getName() << endl;
           cout<< " id: " << getId() <<endl;
           cout<< " balance: "<<balance<<endl;
         }
       else
         {
          cout << "Your balance is negative! Please deposit funds to avoid issues." << endl;
         }
    }


};
