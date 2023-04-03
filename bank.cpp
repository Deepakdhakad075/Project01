#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <windows.h>
using namespace std;

class bank
{
private:
    float balance;
    string id, pin, pass, name, fname, address, phone;

public:
    void menu();
    void bank_management();
    void atm_management();
    void new_user();
    void already_user();
    void deposit();
    void withdraw();
    void transfer();
    void payment();
    void search_user_record();
    void edit_record();
    void delete_record();
    void show_records();
    void show_payment();
    void user_balance();
    void account_details();
};
void introduction()
{
    cout << "\n\n\n\n\n\t\t";
    for (int i = 1; i <= 60; i++)
        cout << "*";
    cout << "\n\n\t\t";
    cout << "      ";
    for (int i = 1; i <= 51; i++)
        cout << "*";
    cout << "\n\n\t\t";
    cout << "           ";
    for (int i = 1; i <= 40; i++)
        cout << "*";
    cout << "\n\n\t\t\t"
         << "   "

         
         << "Welcome to Bank & ATM Management System";
    cout << "\n\n\t\t";
    cout << "           ";
    for (int i = 1; i <= 40; i++)
        cout << "*";
    cout << "\n\n\t\t";
    cout << "      ";
    for (int i = 1; i <= 50; i++)
        cout << "*";
    cout << "\n\n\t\t";
    for (int i = 1; i <= 60; i++)
        cout << "*";
    getch();
    system("cls");
    cout << "\n\n\t";
    for (int i = 0; i < 100; i++)
    {
        cout << "*";
    }
    cout << "\n\n\t\t\t\t"
         << "       "
         << "Project Developer Introduction";
    cout << "\n\n\t\t\t\t  Name:  \t   ==\t Deepak Dhakad";
    cout << "\n\n\t\t\t\t  Project Title:   ==\t Bank & ATM Management System ";
    cout << "\n\n\t\t\t\t  Degree: \t   ==\t Batchlor of Technology";
    cout << "\n\n\t\t\t\t  Branch: \t   ==\t Computer Science and Information Technology";
    cout << "\n\n\t\t\t\t  Year:   \t   ==\t 3rd Year";
    cout << "\n\n\t\t\t\t  college:\t   ==\t Institute of Engineering & Science, IPS Academy";
    cout << "\n\n\t\t\t\t  Language:  \t   ==\t C++";
    cout << "\n\n\t";
    for (int i = 0; i < 100; i++)
    {
        cout << "*";
    }
    getch();
}

void bank::menu() // define the functions
{
p:
    system("cls");
    int choice;
    cout << "\n\n\t\t\tControl panel";
    cout << "\n\n\t\t\t 1. Bank Management";
    cout << "\n\t\t\t 2. ATM Management";
    cout << "\n\t\t\t 3. Exit";
    cout << "\n\n\t\t\t  Enter Your Choice :";
    cin >> choice;
    char ch;
    string pin, pass, email;
    switch (choice)
    {
    case 1:
        system("cls");
        cout << "\n\n\t\tLogin Account      Temprary email is email: deepak@123 , pin or pass: 11111";
        cout << "\n\n\tE-mail :";
        cin >> email;
        cout << "\n\n\tPin Code";
        for (int i = 1; i <= 5; i++)
        {
            ch = getch();
            pin += ch;
            cout << "*";
        }

        cout << "\n\n\t Password";
        for (int i = 1; i <= 5; i++)
        {
            ch = getch();
            pass += ch;
            cout << "*";
        }
        if (email == "deepak@123" && pin == "11111" && pass == "11111")
        {
            bank_management();
        }
        else
        {
            cout << "\n\n Your E-mail ,pin & password is wrong....";
        }
        break;
    case 2:
        atm_management();
        break;
    case 3:
        cout<<"Thank You Visit again";
        exit(0);
    default:
        cout << "\n\n Invalide Choice...... Please Try Again ";
    }
    getch();
    goto p;
}
void bank::bank_management() // defain bank_management function
{
p:
    system("cls");
    int choice;
    cout << "\n\n\t\t\tBank Mamagement System";
    cout << "\n\n1. New user";
    cout << "\n 2. Already user";
    cout << "\n 3. Deposit Option";
    cout << "\n 4. Withdraw Option";
    cout << "\n 5. Transfer Option";
    cout << "\n 6. Payment Option";
    cout << "\n 7. Search User Record";
    cout << "\n 8. Edit User Record";
    cout << "\n 9. Delete User Record";
    cout << "\n 10. Show All Record";
    cout << "\n 11. All payment   Records";
    cout << "\n 12. Go-Back";
    cout << "\n\n Enter Your Choice";
    cin >> choice;
    switch (choice)
    {
    case 1:
        new_user();
        break;
    case 2:
        already_user();
        break;
    case 3:
        deposit();
        break;
    case 4:
        withdraw();
        break;
    case 5:
        transfer();
        break;
    case 6:
        payment();
        break;
    case 7:
        search_user_record();
        break;
    case 8:
        edit_record();
        break;
    case 9:
        delete_record();
        break;
    case 10:
        show_records();
        break;
    case 11:
        show_payment();
        break;
    case 12:
        menu();
    default:
        cout << "\n\n Invalide Choice...... Please Try Again ";
    }
    getch();
    goto p;
}
void bank::new_user()
{
p:
    system("cls");
    fstream file;
    int p;
    string n, f, pa, a, ph, i;
    float b;
    cout << "\n\n\t\tAdd new user";
    cout << "\n\n User ID :";
    cin >> id;
    cout << "\n\n\t\tName : ";
    cin >> name;
    cout << "\n\n Father Name : ";
    cin >> fname;
    cout << "\n\n\t\t Adress : ";
    cin >> address;
    cout << "\n\n Pin Code(5 Disit) : ";
    cin >> pin;
    cout << "\n\n\t\tPassword(5 Disit) : ";
    cin >> pass;
    cout << "\n\n Phone No. : ";
    cin >> phone;
    cout << "\n\n\t\tCurrent Balance : ";
    cin >> balance;
    file.open("bank.txt", ios::in);
    if (!file)
    {
        file.open("bank.txt", ios::app | ios::out);
        file << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
        file.close();
    }
    else
    {
        file >> i >> n >> f >> a >> p >> pa >> ph >> b;
        while (!file.eof())
        {
            if (i == id)
            {
                cout << "user id already exist";
                getch();
                goto p;
            }
            file >> i >> n >> f >> a >> p >> pa >> ph >> b;
        }
        file.close();
        file.open("bank.txt", ios::app | ios::out);
        file << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
        file.close();
    }
    cout << "\n\n Add New user  successfully join....";
}

void bank::atm_management() // defain atm_management function
{
p:
    system("cls");
    int choice;
    cout << "\n\n\t\t\tATM Mamagement System";
    cout << "\n\n 1. User Login & Check Balance";
    cout << "\n 2.Withdraw Amount";
    cout << "\n 3.Account Details";
    cout << "\n 4.Go Back";
    cout << "\n\n Enter Your Choice";
    cin >> choice;
    switch (choice)
    {
    case 1:
        user_balance();
        break;
    case 2:
         withdraw();
        break;
    case 3:
        account_details();
        break;
    case 4:
        menu();
    default:
        cout << "\n\n Invalide Choice...... Please Try Again ";
    }
    getch();
    goto p;
}
void bank::already_user()
{
    system("cls");
    fstream file;
    string t_id;
    int found = 0;
    cout << "\n\n Already user Account";
    file.open("bank.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File Opening Error...";
    }
    else
    {
        cout << "\n\n User ID :";
        cin >> t_id;
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while (!file.eof())
        {
            if (t_id == id)
            {
                system("cls");
                cout << "\n\n\t\t\t Already user Account";
                cout << "\n\n User Id: " << id << "  Pin Code: " << pin << "  Password: " << pass;

                found++;
            }
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }
        file.close();
        if (found == 0)
            cout << "\n\n User ID can't Found...";
    }
}
void bank::deposit()
{
    fstream file, file1;
    float dep;
    string t_id;
    int found = 0;
    system("cls");
    cout << "\n\n\t\t\tDeposit Amount Option: ";
    file.open("bank.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File Opening Error...";
    }
    else
    {
        cout << "\n\n User ID :";
        cin >> t_id;
        file1.open("bank1.txt", ios::app | ios::out);
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while (!file.eof())
        {
            if (t_id == id)
            {

                cout << "\n\n\t\t\t Enter Amount for Deposit : ";
                cin >> dep;
                balance += dep;
                file1 << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
                found++;
                cout << "\n\n\t\t\tYour Amount  " << dep << "  Successfully deposit....\n\n\t\t\t Your total balance is : " << balance;
            }
            else
            {
                file1 << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
            }
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");
        if (found == 0)
            cout << "\n\n User ID can't Found...";
    }
}
void bank::withdraw()
{
    fstream file, file1;
    float with;
    string t_id;
    int found = 0;
    system("cls");
    cout << "\n\n\t\t\tWithdraw Amount Option: ";
    file.open("bank.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File Opening Error...";
    }
    else
    {
        cout << "\n\n\t\t\t User ID :";
        cin >> t_id;
        file1.open("bank1.txt", ios::app | ios::out);
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while (!file.eof())
        {
            if (t_id == id)
            {

                cout << "\n\n\t\t\t Enter Amount for Withdraw : ";
                cin >> with;

                if (balance >= with)
                {
                    balance -= with;
                    file1 << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
                    found++;
                    cout << "\n\n\t\t\tYour Amount  " << with << "  Successfully Withdraw....";
                    cout << "\n\n\t\t\tyour current balance is only:" << balance;
                }
                else
                {
                    found++;
                    file1 << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
                    found++;

                    cout << "\n\n\t\t\tinsufficient balance...";
                    cout<< "\n\n\t\t\tyour current balance is only:" << balance;
                }
            }
            else
            {
                file1 << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
            }
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");
        if (found == 0)
            cout << "\n\n User ID can't Found...";
    }
}
void bank::transfer()
{
    fstream file, file1;
    string s_id, r_id;
    float amount;
    int found = 0;
    system("cls");
    cout << "\n\n\t\t\t Payment Transfer Option ";
    file.open("bank.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File Opening Error...";
    }
    else
    {
        cout << "\n\n Enter Sender User Id for transaction :";
        cin >> s_id;
        cout << "\n\n Enter Reciver User id for transaction :";
        cin >> r_id;
        cout << "\n\n Enter amount :";
        cin >> amount;
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while (!file.eof())
        {
            if (s_id == id && amount <= balance)
            {
                found++;
            }
            else if (r_id == id)
            {
                found++;
            }
            else
            {
            }
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }
        file.close();
        if (found == 2)
        {
            file.open("bank.txt", ios::in);
            file1.open("bank1.txt", ios::app | ios::out);
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
            while (!file.eof())
            {
                if (s_id == id)
                {
                    balance -= amount;
                    file1 << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
                }
                else if (r_id == id)
                {
                    balance += amount;
                    file1 << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
                    cout << "\n\t\t Transfer Successfully";
                }
                else
                {
                    file1 << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
                }
                file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
            }
            file.close();
            file1.close();
            remove("bank.txt");
            rename("bank1.txt", "bank.txt");
        }
        else
        {
            cout << "\n\n\t\t\t Both transaction Id's & Balance  Invalid.....";
        }
    }
}
void bank::payment()
{
    system("cls");
    fstream file, file1;
    string t_id, b_name;
    float amount;
    int found = 0;
    SYSTEMTIME x;
    cout << "\n\n\t\t\t Bills Payment Option: ";
    file.open("bank.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File Opening Error...";
    }
    else
    {
        cout << "\n\n Enter User ID : ";
        cin >> t_id;
        cout << "\n\nBill Name : ";
        cin >> b_name;
        cout << "\n\n Bill Amount : ";
        cin >> amount;
        file1.open("bank1.txt", ios::app | ios::out);
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while (!file.eof())
        {
            if (t_id == id && amount <= balance)
            {
                balance -= amount;

                file1 << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
                found++;
            }
            else
            {
                file1 << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
            }
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");
        if (found == 1)
        {
            GetSystemTime(&x);
            file.open("bill.txt", ios::app | ios::out);
            file << t_id << " " << b_name << " " << amount << " " << x.wDay << "/" << x.wMonth << "/" << x.wYear;
            file.close();
            cout << "\n\n\t\t\t " << b_name << "   Bill Pay Successfully";
        }
        else
        {
            if (t_id != id)
            {
                cout << "\n\n\t\t User ID ";
            }
            else
            {
                cout << "\n\n\t\t Insuficient Balance";
            }
        }
    }
}
void bank::search_user_record()
{
    system("cls");
    fstream file;
    string t_id;
    int found = 0;
    cout << "\n\n\t\t\tvoid Search User Record";
    file.open("bank.txt", ios::in);
    if (!file)
    {
        cout << "\n\n\t\t\tFile Opening Error...";
    }
    else
    {
        cout << "\n\n\t\t\tUser Id  :  ";
        cin >> t_id;
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while (!file.eof())
        {
            if (t_id == id)
            {
                system("cls");
                cout << "\n\n\t\t\tSearch User Record  :";
                cout << "\n\n\tUser_ID : " << id << "  Name : " << name;
                cout << "\n\tFather_Name : " << fname << " Address : " << address;
                cout << "\n\tPin : " << pin << " Password : " << pass;
                cout << "\n \tPhone No. :" << phone << "  Current Balance :" << balance;
                found++;
            }
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }
        file.close();
        if (found == 0)
        {
            cout << "User Id Can't Found";
        }
    }
}
void bank::edit_record()
{
    system("cls");
    fstream file, file1;
    string t_id;
    int pi;
    string n, f, p, a, ph;
    float b;

    int found = 0;
    cout << "\n\n\t\t\tEdit User Record";
    file.open("bank.txt", ios::in);
    if (!file)
    {
        cout << "\n\n\t\t\t File Opening Error....";
    }
    else
    {
        cout << "\n\n\t\t\t User Id  :";
        cin >> t_id;
        file1.open("bank1.txt", ios::app | ios::out);
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while (!file.eof())
        {
            if (t_id == id)
            {

                cout << "\n\n\t\tName : ";
                cin >> n;
                cout << "\n\n Father Name : ";
                cin >> f;
                cout << "\n\n\t\t Adress : ";
                cin >> a;
                cout << "\n\n Pin Code(5 Disit) : ";
                cin >> pi;
                cout << "\n\n\t\tPassword(5 Disit) : ";
                cin >> p;
                cout << "\n\n Phone No. : ";
                cin >> ph;
                cout << "\n\n Balance :";
                cin >> b;

                file1 << " " << id << " " << n << " " << f << " " << a << " " << pi << " " << p << " " << ph << " " << b << " "
                      << "\n";
                cout << "\n\n\t\t\t Your Record Update Successfully ";
                found++;
            }
            else
            {
                file1 << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
            }
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");
        if (found == 0)
        {
            cout << "User Id Can't Found";
        }
    }
}

void bank::delete_record()
{
    system("cls");
    fstream file, file1;
    string t_id;
    int found = 0;
    cout << "\n\n\t\t\tEdit User Record";
    file.open("bank.txt", ios::in);
    if (!file)
    {
        cout << "\n\n\t\t\t File Opening Error....";
    }
    else
    {
        cout << "\n\n\t\t\t User Id  :";
        cin >> t_id;
        file1.open("bank1.txt", ios::app | ios::out);
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while (!file.eof())
        {
            if (t_id == id)
            {
                cout << "\n\n\t\t\t Your Record Delete Successfully... ";

                found++;
            }
            else
            {
                file1 << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
            }
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");

        if (found == 0)
        {
            cout << "User Id Can't Found";
        }
    }
}
void bank::show_records()
{
    system("cls");
    fstream file;
    int found = 0;
    cout << "\n\n\t\t\t Show All User Records";
    file.open("bank.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File Opening Error....";
    }
    else
    {
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while (!file.eof())
        {

            cout << "\n UserID  :" << id;
            cout << "\n Name  :" << name;
            cout << "\n FatherName  :" << fname;
            cout << "\n Address  :" << address;
            cout << "\n Pin  :" << pin;
            cout << "\n PassWord :" << pass;
            cout << "\n Phone No  :" << phone;
            cout << "\n Balance  :" << balance;
            cout << "\n\n=================================================";
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
            found++;
        }
        file.close();
        if (found == 0)
        {
            cout << "\n\n Data Base is Empty...";
        }
    }
}
void bank::show_payment()
{
    system("cls");
    fstream file;
    float amount;
    int found = 0;
    string c_date;
    cout << "\n\n\t\t\t Show All Bill's Records";
    file.open("bill.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File Opening Error....";
    }
    else
    {
        file >> id >> name >> amount >> c_date;
        while (!file.eof())
        {

            cout << "\n UserID  :" << id;
            cout << "\n Bill Name  :" << name;
            cout << "\n Amount  :" << amount;
            cout << "\n Date  :" << c_date;

            cout << "\n\n=================================================";
            file >> id >> name >> amount >> c_date;
            found++;
        }
        file.close();
        if (found == 0)
        {
            cout << "\n\n Data Base is Empty...";
        }
    }
}
void bank::user_balance()
{
    system("cls");
    fstream file;
    string t_id, t_pin, t_pass;
    char ch;
    int found = 0;
    cout << "\n\n\t\t User Login & Chack Balance ";
    file.open("bank.txt", ios::in);
    if (!file)
    {
        cout << "\n\n\t File Opening Error...";
    }
    else
    {
        cout << "\n\n UserId :";
        cin >> t_id;
        cout << "\n\n Pin Code :";
        for (int i = 0; i < 5; i++)
        {
            ch = getch();
            t_pin += ch;
            cout << "*";
        }
        cout << "\n\n Password :";
        for (int i = 0; i < 5; i++)
        {
            ch = getch();
            t_pass += ch;
            cout << "*";
        }
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while (!file.eof())
        {
            if (t_id == id && t_pin == pin && t_pass == pass)
            {
                cout << "\n\n\t\t\t Your Current Balance is:" << balance;
                found++;
            }
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }
        file.close();
        if (found == 0)
        {
            cout << "\n\n\t\t\t Invalide id password or name";
        }
    }
}
void bank::account_details()
{
    system("cls");
    fstream file;
    string t_id;
    int found = 0;
    cout << "\n\n Already user Account";
    file.open("bank.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File Opening Error...";
    }
    else
    {
        cout << "\n\n User ID :";
        cin >> t_id;
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while (!file.eof())
        {
            if (t_id == id)
            {
                system("cls");
                cout << "\n\n\t\t\t Already user Account";
                cout << "\n\n User Id: " << id << "  Pin Code: " << pin << "  Password: " << pass;
                cout<<"\n User Name: " << name << "Father name: " << fname << " phone: "<<phone ;
                cout<<"\n Available balance:"<< balance; 
                found++;
            }
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }
        file.close();
        if (found == 0)
            cout << "\n\n User ID can't Found...";
    }
}
main()
{
    bank obj;
    introduction();
    obj.menu();
}