#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Bank
{
    string f_name, l_name, ph_no, address, cnic;

    Bank() : f_name(""), l_name(""), ph_no(""), address(""), cnic("") {}

    void welcome()
    {
        cout << "\t\t\t\t\t\tWelcome to the bank\t\t\t\t\t\t" << endl;
    }

    void info()
    {
        cout << "Please enter your First name: ";
        cin >> f_name;
        cout << "Please enter your Last name: ";
        cin >> l_name;
        cout << "Please enter your Phone no.: ";
        cin >> ph_no;
        cout << "Please enter your Address: ";
        cin >> address;
        cout << "Please enter your CNIC: ";
        cin >> cnic;
    }

    void display()
    {
        cout << "Your First name: " << f_name << endl;
        cout << "Your Last name: " << l_name << endl;
        cout << "Your Phone no.: " << ph_no << endl;
        cout << "Your Address: " << address << endl;
        cout << "Your CNIC: " << cnic << endl;
    }

    // Serialize function to write object to file
    void serialize(ofstream &ofs) const
    {
        ofs << f_name << endl;
        ofs << l_name << endl;
        ofs << ph_no << endl;
        ofs << address << endl;
        ofs << cnic << endl;
    }
};

int main()
{
    int key;

    Bank b;
    b.welcome();

    cout << "Please select one option from below menu:\n"
         << endl;

    cout << "1. Open Account \n2. Deposit Amount \n3. Withdraw Amount \n4. Check Balance \n5. Update Record \n6. Delete Record \n7. Search Record \n8. Exit \n";

    do
    {
        cin >> key;

        if (key == 1)
        {
            b.info();
            ofstream f("C:/Users/asus/Desktop/Coding/Bank_Management/Reg_users.dat", ios::app);

            if (f.is_open())
            {
                b.serialize(f);
                f.close();
                b.display();
            }
            else
            {
                cout << "Error opening file!: " << endl;
            }
        }

    } while (key != 8);

    return 0;
}
