#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;
struct Bank
{
    string f_name, l_name, ph_no, address, cnic;
    int amount;
    Bank() : f_name(""), l_name(""), ph_no(""), address(""), cnic(""), amount(0) {}
    void welcome()
    {
        cout << "\t\t\t\t\t\t Jaali Bank \t\t\t\t\t\t" << endl;
    }
    void info()
    {
        cout << "Please enter your first name: ";
        cin >> f_name;
        cout << "Please enter your last name: ";
        cin >> l_name;
        cout << "Please enter your phone no.: ";
        cin >> ph_no;
        cout << "Please enter your address: ";
        cin.ignore();
        getline(cin, address);
        cout << "Please enter your CNIC: ";
        cin >> cnic;
    }
    void display()
    {
        cout << "\nYour first name: " << f_name << endl;
        cout << "Your last name: " << l_name << endl;
        cout << "Your phone no.: " << ph_no << endl;
        cout << "Your address: " << address << endl;
        cout << "Your CNIC: " << cnic << endl;
        cout << "Your current amount is: " << amount << endl
             << endl;
    }
};

int main()
{
    int key;
    Bank b;
    do
    {
        b.welcome();
        cout << "Please select one option from below menu. \n";
    c:
        cout << "1. Account Open. \n2. Deposit Amount. \n3. Withdraw Amount. \n4. Check Balance. \n";
        cout << "5. Update Record. \n6. Delete Record. \n7. Search Record. \n8. Exit. \n";
        cin >> key;
        if (key == 1)
        {
            b.info();
            ofstream f("Reg_users.dat", ios::app);
            f.write((char *)&b, sizeof(b));
            f.close();
            b.display();
            Sleep(3000);
            system("cls");
        }
        else if (key == 2)
        {
            string nam;
            int am = 0, count = 0;
            cout << "\nPlease enter your first name: ";
            cin >> nam;
            ifstream u("Reg_users.dat");
            while (u.read((char *)&b, sizeof(b)))
            {
                if (nam == b.f_name)
                {
                    ofstream f("Reg_users1.dat", ios::app);
                    cout << "\nName of account holder is: " << b.f_name << " " << b.l_name << endl;
                    cout << "Current amount is: " << b.amount << endl;
                    cout << "Please enter new amount: " << endl;
                    cin >> am;
                    b.amount += am;
                    cout << "Name of account holder is: " << b.f_name << " " << b.l_name << endl;
                    cout << "Current amount is: " << b.amount << endl;
                    f.write((char *)&b, sizeof(b));
                    ifstream u("Reg_users.dat");
                    while (u.read((char *)&b, sizeof(b)))
                    {
                        if (nam != b.f_name)
                        {
                            f.write((char *)&b, sizeof(b));
                        }
                    }
                    f.close();
                    count += 1;
                }
                else
                {
                    cout << "Computer is either searching or wasn`t able to find your record. \n"
                         << endl;
                }
            }
            Sleep(3000);
            system("cls");
            u.close();
            if (count >= 1)
            {
                remove("Reg_users.dat");
                rename("Reg_users1.dat", "Reg_users.dat");
            }
        }
        else if (key == 3)
        {
            string nam;
            int am = 0, count = 0;
            cout << "\nPlease enter your first name: ";
            cin >> nam;
            ifstream u("Reg_users.dat");
            while (u.read((char *)&b, sizeof(b)))
            {
                if (nam == b.f_name)
                {
                    ofstream f("Reg_users1.dat", ios::app);
                    cout << "\nName of account holder is: " << b.f_name << " " << b.l_name << endl;
                    cout << "Current amount is: " << b.amount << endl;
                a:
                    cout << "Please enter new amount: ";
                    cin >> am;
                    if (am < b.amount)
                    {
                        b.amount -= am;
                    }
                    else
                    {
                        cout << "Amount being withdrawn is more than amount available in the account.\n"
                             << endl;
                        goto a;
                    }
                    cout << "\nName of account holder is: " << b.f_name << " " << b.l_name << endl;
                    cout << "Current amount is: " << b.amount << endl;
                    f.write((char *)&b, sizeof(b));
                    ifstream u("Reg_users.dat");
                    while (u.read((char *)&b, sizeof(b)))
                    {
                        if (nam != b.f_name)
                        {
                            f.write((char *)&b, sizeof(b));
                        }
                    }
                    f.close();
                    count += 1;
                }
                else
                {
                    cout << "Computer is either searching or wasn`t able to find your record. \n"
                         << endl;
                }
            }
            Sleep(3000);
            system("cls");
            u.close();
            if (count >= 1)
            {
                remove("Reg_users.dat");
                rename("Reg_users1.dat", "Reg_users.dat");
            }
        }
        else if (key == 4)
        {
            string nam;
            cout << "\nPlease enter your first name: ";
            cin >> nam;
            ifstream u("Reg_users.dat");
            while (u.read((char *)&b, sizeof(b)))
            {
                if (nam == b.f_name)
                {
                    cout << "Name of account holder is: " << b.f_name << " " << b.l_name << endl;
                    cout << "Current amount is: " << b.amount << endl
                         << endl;
                }
                else
                {
                    cout << "Computer is either searching or wasn`t able to find your record. \n"
                         << endl;
                }
            }
            Sleep(3000);
            system("cls");
            u.close();
        }
        else if (key == 5)
        {
            string nam;
            int count = 0;
            char ke, opt;
            cout << "\nPlease enter your first name: ";
            cin >> nam;
            ifstream u("Reg_users.dat");
            while (u.read((char *)&b, sizeof(b)))
            {
                if (nam == b.f_name)
                {
                    b.display();
                    cout << "\n=================================================================\n";
                    ofstream f("Reg_users1.dat", ios::app);
                b:
                    cout << "To update first name (Press f). \nTo update last name (Press l). \n";
                    cout << "To update phone no. (Press p). \nTo update address (Press a). \nTo update cnic (Press c). \n";
                    cin >> ke;
                    if (ke == 'f')
                    {
                        cout << "\nPlease enter your new first name: ";
                        cin >> b.f_name;
                        f.write((char *)&b, sizeof(b));
                        ifstream u("Reg_users.dat");
                        while (u.read((char *)&b, sizeof(b)))
                        {
                            if (nam != b.f_name)
                            {
                                f.write((char *)&b, sizeof(b));
                            }
                        }
                    }
                    else if (ke == 'l')
                    {
                        cout << "\nPlease enter your new last name: ";
                        cin >> b.l_name;
                        f.write((char *)&b, sizeof(b));
                        ifstream u("Reg_users.dat");
                        while (u.read((char *)&b, sizeof(b)))
                        {
                            if (nam != b.f_name)
                            {
                                f.write((char *)&b, sizeof(b));
                            }
                        }
                    }
                    else if (ke == 'p')
                    {
                        cout << "\nPlease enter your new number: ";
                        cin >> b.ph_no;
                        f.write((char *)&b, sizeof(b));
                        ifstream u("Reg_users.dat");
                        while (u.read((char *)&b, sizeof(b)))
                        {
                            if (nam != b.f_name)
                            {
                                f.write((char *)&b, sizeof(b));
                            }
                        }
                    }
                    else if (ke == 'a')
                    {
                        cout << "\nPlease enter your new address: ";
                        cin >> b.address;
                        f.write((char *)&b, sizeof(b));
                        ifstream u("Reg_users.dat");
                        while (u.read((char *)&b, sizeof(b)))
                        {
                            if (nam != b.f_name)
                            {
                                f.write((char *)&b, sizeof(b));
                            }
                        }
                    }
                    else if (ke == 'c')
                    {
                        cout << "\nPlease enter your new CNIC: ";
                        cin >> b.cnic;
                        f.write((char *)&b, sizeof(b));
                        ifstream u("Reg_users.dat");
                        while (u.read((char *)&b, sizeof(b)))
                        {
                            if (nam != b.f_name)
                            {
                                f.write((char *)&b, sizeof(b));
                            }
                        }
                    }
                    cout << "\nDo you want to update record again? (y/n) ";
                    cin >> opt;
                    if (opt == 'y')
                    {
                        goto b;
                    }
                    else
                    {
                        f.close();
                        count += 1;
                    }
                }
                else
                {
                    cout << "Computer is either searching or wasn`t able to find your record. \n"
                         << endl;
                }
            }
            Sleep(3000);
            system("cls");
            u.close();
            if (count >= 1)
            {
                remove("Reg_users.dat");
                rename("Reg_users1.dat", "Reg_users.dat");
            }
        }
        else if (key == 6)
        {
            string nam;
            int count = 0;
            char ke;
            cout << "\nPlease enter your first name: ";
            cin >> nam;
            ifstream u("Reg_users.dat");
            while (u.read((char *)&b, sizeof(b)))
            {
                if (nam == b.f_name)
                {
                    ofstream f("Reg_users1.dat", ios::app);
                    cout << "\nName of account holder is: " << b.f_name << " " << b.l_name << endl;
                    cout << "Current amount is: " << b.amount << endl;
                    cout << "Do you really want to delete the record? (y/n) ";
                    cin >> ke;
                    if (ke == 'y')
                    {
                        ifstream u("Reg_users.dat");
                        while (u.read((char *)&b, sizeof(b)))
                        {
                            if (nam != b.f_name)
                            {
                                f.write((char *)&b, sizeof(b));
                            }
                        }
                    }
                    else
                    {
                        goto c;
                    }
                    f.close();
                    count += 1;
                }
                else
                {
                    cout << "Computer is either searching or wasn`t able to find your record. \n"
                         << endl;
                }
            }
            Sleep(3000);
            system("cls");
            u.close();
            if (count >= 1)
            {
                remove("Reg_users.dat");
                rename("Reg_users1.dat", "Reg_users.dat");
            }
        }
        else if (key == 7)
        {
            string nam;
            cout << "\nPlease enter your first name: ";
            cin >> nam;
            ifstream u("Reg_users.dat");
            while (u.read((char *)&b, sizeof(b)))
            {
                if (nam == b.f_name)
                {
                    b.display();
                }
                else
                {
                    cout << "Computer is either searching or wasn`t able to find your record. \n"
                         << endl;
                }
            }
            Sleep(5000);
            system("cls");
            u.close();
        }
    } while (key > 0 && key < 8);
    system("cls");
    b.welcome();
    cout << "\t\t\t\t\t Thank You for visiting our bank. \n\t\t\t\t\t\t";
}