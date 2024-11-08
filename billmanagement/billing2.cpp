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

void shopping::menu()
{
    int choice;
    string email;
    string password;

    while (true)
    {
        cout << "\t\t\t\t--------------------------------------\n";
        cout << "\t\t\t\t                                      \n";
        cout << "\t\t\t\t       SuperMarket Main Menu          \n";
        cout << "\t\t\t\t                                      \n";
        cout << "\t\t\t\t--------------------------------------\n";
        cout << "\t\t\t\t                                      \n";

        cout << "\t\t\t\t 1) Administrator   \n";
        cout << "\t\t\t\t 2) Buyer           \n";
        cout << "\t\t\t\t 3) Exit            \n";
        cout << "\t\t\t\t                                      \n";

        cout << "\t\t\t\t Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\t\t\t Please Login\n";
            cout << "Email: ";
            cin >> email;
            cout << "Password: ";
            cin >> password;
            if (email == "ukanikishanuk@gmail.com" && password == "uk123123")
            {
                administrator();
            }
            else
            {
                cout << "Invalid email or password\n";
            }
            break;
        case 2:
            buyer();
            break;
        case 3:
            exit(0);
        default:
            cout << "Please select from the given options only\n";
        }
    }
}

void shopping::administrator()
{
    int choice;

    while (true)
    {
        cout << "\n\n\n\t\t\t\tAdmin Menu\n";
        cout << "\t\t\t\t 1) Add Product\n";
        cout << "\t\t\t\t 2) Modify Product\n";
        cout << "\t\t\t\t 3) Delete Product\n";
        cout << "\t\t\t\t 4) Main Menu\n";

        cout << "\n \t\t\t\t Please Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            add();
            break;
        case 2:
            edit();
            break;
        case 3:
            rem();
            break;
        case 4:
            return;
        default:
            cout << "Invalid Choice\n";
        }
    }
}

void shopping::buyer()
{
    int choice;

    while (true)
    {
        cout << "\t\t\t\tBuyer\n";
        cout << "\t\t\t-------------------------\n";
        cout << "\t\t\t 1) Buy product\n";
        cout << "\t\t\t 2) Go back\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            receipt();
            break;
        case 2:
            return;
        default:
            cout << "Invalid Choice\n";
        }
    }
}

void shopping::add()
{
    fstream data;
    int c;
    int token = 0;
    float p, d;
    string n;

    cout << "\n\n\t\t\t Add new product \n";
    cout << "\n\n\t\t\t Product code of product: ";
    cin >> pcode;
    cout << "\n\n\t\t\t Name Of the Product: ";
    cin >> pname;
    cout << "\n\n\t\t\t Price Of the product: ";
    cin >> price;
    cout << "\n\n\t\t\t Discount on product: ";
    cin >> discount;

    data.open("dataset.txt", ios::in);
    if (!data)
    {
        data.open("dataset.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << discount << "\n";
        data.close();
    }
    else
    {
        data >> c >> n >> p >> d;
        while (!data.eof())
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
            cout << "\n\n\t\t Product code already exists. Please try again.\n";
            return;
        }
        else
        {
            data.open("dataset.txt", ios::app | ios::out);
            data << " " << pcode << " " << pname << " " << price << " " << discount << "\n";
            data.close();
        }
    }
    cout << "Record Inserted.\n";
}

void shopping::edit()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p, d;
    string n;

    cout << "\n\n\t\t\t Modify the record\n";
    cout << "\n\n\t\t\t Enter the product code: ";
    cin >> pkey;

    data.open("dataset.txt", ios::in);
    if (!data)
    {
        cout << "\n\n\t\t File does not exist.\n";
        return;
    }
    else
    {
        data1.open("dataset1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> discount;
        while (!data.eof())
        {
            if (pkey == pcode)
            {
                cout << "\n\t\t New product code: ";
                cin >> c;
                cout << "\n\t\t Name of the product: ";
                cin >> pname;
                cout << "\n\t\t Price: ";
                cin >> p;
                cout << "\n\t\t Discount: ";
                cin >> d;
                data1 << " " << c << " " << pname << " " << p << " " << d << "\n";
                cout << "\n\t\t Record edited.\n";
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

        remove("dataset.txt");
        rename("dataset1.txt", "dataset.txt");

        if (token == 0)
        {
            cout << "\n\n\t\t Record not found.\n";
        }
    }
}

void shopping::rem()
{
    fstream data, data1;
    int pkey;
    int token = 0;

    cout << "\n\n\t\t\t Delete product\n";
    cout << "\n\n\t\t\t Enter the product code: ";
    cin >> pkey;

    data.open("dataset.txt", ios::in);
    if (!data)
    {
        cout << "\n\n\t\t File does not exist.\n";
        return;
    }
    else
    {
        data1.open("dataset1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> discount;
        while (!data.eof())
        {
            if (pcode == pkey)
            {
                cout << "\n\n\t\t Product deleted successfully.\n";
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

        remove("dataset.txt");
        rename("dataset1.txt", "dataset.txt");

        if (token == 0)
        {
            cout << "\n\n\t\t Record not found.\n";
        }
    }
}

void shopping::list()
{
    fstream data;
    data.open("dataset.txt", ios::in);
    if (!data)
    {
        cout << "\n\n\t\t File does not exist.\n";
        return;
    }

    cout << "\n\n|-------------------------------------------------------------\n";
    cout << "Product No \t\t Name \t\t Price\n";
    cout << "|-------------------------------------------------------------\n";

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
    fstream data;
    int arrc[100];
    int arrq[100];
    string choice;
    int c = 0;
    float amount = 0;
    float discount = 0;
    float total = 0;

    cout << "\n\n\t\t\tReceipt\n";
    data.open("dataset.txt", ios::in);
    if (!data)
    {
        cout << "\n\n\t\t\t Empty dataset\n";
        return;
    }

    data.close();
    list();

    cout << "\n ------------------------------\n";
    cout << "                                 \n";
    cout << "     Please Place the order      \n";
    cout << "                                 \n";
    cout << "\n ------------------------------\n";

    while (true)
    {
        cout << "Enter Product code: ";
        cin >> arrc[c];
        cout << "Enter the quantity: ";
        cin >> arrq[c];

        for (int i = 0; i < c; i++)
        {
            if (arrc[c] == arrc[i])
            {
                cout << "\n\n Duplicate product code. Please try again.\n";
                return;
            }
        }

        c++;
        cout << "\n\n\t\t Do you want to buy another product? (yes/no): ";
        cin >> choice;
        if (choice != "yes")
        {
            break;
        }
    }

    cout << "\n\n\t\t\t       Receipt       \n";
    cout << "\nProduct No\t Name \t Quantity \t Price \t Amount \t Amount with Discount\n";

    for (int i = 0; i < c; i++)
    {
        data.open("dataset.txt", ios::in);
        data >> pcode >> pname >> price >> discount;
        while (!data.eof())
        {
            if (pcode == arrc[i])
            {
                amount = price * arrq[i];
                discount = amount - (amount * discount / 100);
                total += discount;
                cout << " " << pcode << "\t\t" << pname << "\t " << arrq[i] << "\t " << price << "\t " << amount << "\t " << discount << "\n";
            }
            data >> pcode >> pname >> price >> discount;
        }
        data.close();
    }
    cout << "\n\n---------------------------------------------------";
    cout << "\n Total Amount : " << total << "\n";
}

int main()
{
    shopping s;
    s.menu();
    return 0;
}
