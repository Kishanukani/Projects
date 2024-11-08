#include <iostream>
#include <fstream>
using namespace std;

class shopping
{
private:
    int pcode;
    float price;
    float discount;
    string pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};

void shopping ::menu()
{
m:
    int choice;
    string email;
    string password;

    cout << "\t\t\t\t--------------------------------------\n";
    cout << "\t\t\t\t                                      \n";
    cout << "\t\t\t\t       SuperMarket Main Menu   \n";
    cout << "\t\t\t\t                                      \n";
    cout << "\t\t\t\t--------------------------------------\n";
    cout << "\t\t\t\t                                      \n";

    cout << "\t\t\t\t 1)Administrator   \n";
    cout << "\t\t\t\t 2)Buyer   \n";
    cout << "\t\t\t\t 3)Exit   \n";
    cout << "\t\t\t\t                                      \n";

    cout << "\t\t\t\t   Enter Choice \n";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        cout << "\t\t\t Please Login\n";
        cout << "Email       \n";
        cin >> email;
        cout << "Password \n";
        cin >> password;
        if (email == "ukanikishanuk@gmail.com" && password == "uk123123")
        {
            administrator();
        }
        else
        {
            cout << "invalid mail pass";
        }
        break;
    }
    case 2:
    {
        buyer();
    }
    case 3:
    {
        exit(0);
    }
    default:
    {
        cout << "Please select form the given options only";
    }
    }
    goto m;
    // cout<<"\t\t\t\t 1)Administrator   \n";
}

void shopping::administrator()
{
m:
    int choice;
    cout << "\n\n\n\t\t\t\tAdmin Menue\n";
    cout << "\t\t\t\t\t 1)Add Product\n";
    cout << "\t\t\t\t\t 2)Modify Product\n";
    cout << "\t\t\t\t\t 3)Delete Product\n";
    cout << "\t\t\t\t\t 4)Main Menu\n";

    cout << "\n \t\t\t\t Please Enter Your Choice\n";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        add();
        break;
    }
    case 2:
    {
        edit();
        break;
    }
    case 3:
    {
        rem();
        break;
    }
    case 4:
    {
        menu();
        break;
    }
    default:
    {
        cout << "invalid Choice";
    }
    }
    goto m;
    // cout
}

void shopping::buyer()
{
m:
    int choice;
    cout << "\t\t\t\tBuyer\n";
    cout << "\t\t\t-------------------------\n";
    cout << "\t\t\t\t 1)Buy product\n";
    cout << "\t\t\t\t 2)GO back\n";

    cout << "Enter Choice\n";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        receipt();
        break;
    }
    case 2:
    {
        menu();
        break;
    }
    default:
        cout << "Invalid;\n";
        // break;
    }
    goto m;
}

void shopping::add()
{
m:
    fstream data; // creating object of fstream class
    int c;
    int token = 0;
    float p, d;
    string n;

    cout << "\n\n\t\t\t Add new product \n";
    cout << "\n\n\t\t\t Product code of produce ";
    cin >> pcode;
    cout << "\n\n\t\t\t Name Of the Product ";
    cin >> pname;
    cout << "\n\n\t\t\t Price Of the product";
    cin >> price;

    cout << "\n\n\t\t\t Discount on product";
    cin >> discount;

    data.open("database.txt", ios::in); // data helps to open file, ios to open file in reading mode for in and ios out for writing mide
    if (!data)
    {
        data.open("database.txt", ios::app | ios::out); // if file doesont exist ios app for append mode
        data << " " << pcode << " " << pname << " " << price << " " << discount << "\n";
        data.close();
    }
    else
    {
        data >> c >> n >> p >> d; // reading from file,,,,,,,initializing index;
        while (!data.eof())       // eof end of file function
        {
            if (c == pcode)
            {
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();
        if (token == 1)
        {
            goto m;
        }
        else
        { // writing inside a file;
            // data.open
            data.open("database.txt", ios::app | ios::out); // if file doesont exist ios app for append mode
            data << " " << pcode << " " << pname << " " << price << " " << discount << "\n";
            data.close();
        }
    }
    cout << "Record INsreted;";
}

void shopping::edit()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p, d;
    string n;
    cout << "Modify the record\n";
    cout << "Enter the product code\n";
    cin >> pkey;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "File dnot exist\n";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> discount;
        while (!data.eof())
        {
            if (pkey == pcode)
            {
                cout << "\n\t\t new product code\n";
                cin >> c;
                cout << "\n\t\t Name of the product\n";
                cin >> pname;
                cout << "\n\t\t Price\n";
                cin >> p;
                cout << "\n\t\t Discount\n";
                cin >> d;
                data1 << " " << c << " " << n << " " << p << " " << d << "\n";
                cout << "Rcord edited";
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << discount << "\n";
            }
            data >> pcode >> pname >> price >> discount;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");
        if (token == 0)
        {
            cout << "Record not found\n";
        }
    }
}

void shopping::rem()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    cout << "\n\t\t delete product\n";
    cout << "Product code \n";
    cin >> pkey;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "File dnot exist\n";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> discount;
        while (!data.eof())
        {
            if (pcode == pkey)
            {
                cout << "\n\n\t Product deleted Successfully";
                token++;
            }
            else
            {
                data << " " << pcode << " " << pname << " " << price << " " << discount << "\n";
            }
            // data
            data >> pcode >> pname >> price >> discount;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");
        if (token == 0)
        {
            cout << "Record not found\n";
        }
    }
}

void shopping::list()
{
    fstream data;
    data.open("database.txt", ios::in);
    cout << "\n\n|-------------------------------------------------------------\n";
    cout << "product No \t\t Name \t\t Price\n";
    cout << "\n\n|-------------------------------------------------------------\n";
    data >> pcode >> pname >> price >> discount;
    while (!data.eof())
    {
        cout << pcode << "\t\t" << pname << "\t\t" << price << "\n";
        data >> pcode >> pname >> price >> discount;
    }
    data.close();
}

void shopping::receipt()
{
m:
    fstream data;
    int arrc[100];
    int arrq[100];
    string choice;
    int c = 0;
    float amount = 0;
    float discount = 0;
    float total = 0;
    cout << "\n\n\t\t\treceipt";
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "Empty database\n";
    }
    else
    {
        data.close();
        list();
        cout << "\n ------------------------------\n";
        cout << "                                       \n";
        cout << "         Please Place the order            \n";
        cout << "                                       \n";
        cout << "\n ------------------------------\n";

        do
        {
            cout << "Enter Product code\n";
            cin >> arrc[c];
            cout << "Enter the quant\n";
            cin >> arrq[c];
            // cout<<"\n\n"
            for (int i = 0; i < c; i++)
            {
                if (arrc[c] == arrc[i])
                {
                    cout << "\n\n Duplicat product code Please Try again \n";
                    goto m;
                }
            }
            c++;
            cout << "\n\n\t\t want to buy another product";
            cin >> choice;
        } while (choice == "yes");

        cout << "\n\n\t\t\t       Receipt       \n";
        cout << "\n Prduct No\t Name \t quant \t price \t Amount \t with discount\n";
        for (int i = 0; i < c; i++)
        {
            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price >> discount;
            while (!data.eof())
            {
                if (pcode == arrc[i])
                {
                    amount = price * arrq[i];
                    discount = amount - (amount * discount / 100);
                    total = total + discount;
                    cout << " " << pcode << "\t\t" << pname << "\t  " << arrq[i] << "\t  " << price << "\t  " << discount;
                }
                data >> pcode >> pname >> price >> discount;
            }
        }
        data.close();
    }
    cout << "\n\n---------------------------------------------------";
    cout << "\n Total Amount : " << total;
}

int main()
{
    shopping s;
    s.menu();
    return 0;
}