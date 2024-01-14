#ifndef MenuClass
#define MenuClass

#include <iostream>
#include <fstream>
#include <string>
#include<string.h>
#include <algorithm>
#include <cctype>

#define Max 35
using namespace std;

class Menu
{
public:
    // string to store the menu items,prices and quantity
    string _breakfast[Max], _lunch[Max], _dinner[Max], _beverages[Max], _desserts[Max], _raita[Max], _tandoor[Max];
    int breakfast_quantity[Max], lunch_quantity[Max], dinner_quantity[Max], _beverages_quantity[Max], _desserts_quantity[Max], _raita_quantity[Max], _tandoor_quantity[Max];
    int breakfast_price[Max], lunch_price[Max], dinner_price[Max], _beverages_price[Max], _desserts_price[Max], _raita_price[Max], _tandoor_price[Max];
    int count;
    // Variables to store size of arrays
    int length_breakfast, length_lunch, length_dinner, length_beverages, length_desserts, length_raita, length_tandoor;

    ifstream breakfast, lunch, dinner, beverages, desserts, raita, tandoor;                                               // to read item names
    ifstream b_price, l_price, d_price, beverages_price, desserts_price, raita_price, tandoor_price;                      // to read price files
    ifstream b_quantity, l_quantity, d_quantity, beverages_quantity, desserts_quantity, raita_quantity, tandoor_quantity; // to read quantity files
    void read_breakfast();
    void read_lunch();
    void read_dinner();
    void read_Beverages();
    void read_Desserts();
    void read_Tandoor();
    void read_Raita();
    void Display_Breakfast();
    void Display_Lunch();
    void Display_Dinner();
    void Display_Beverages();
    void Display_Desserts();
    void Display_Tandoor();
    void Display_Raita();
    void Display_menu();
    void editmenu()
    {
        string edit, item;
		int price, qty;
        int choice;
    label7:
        cout << "Choose 1 of the following" << endl;
        cout << "1.Breakfast\n2.Lunch\n3.Dinner" << endl;
        cin >> choice;
        switch (choice)
        {
            case 1: {
                read_breakfast();
                Display_Breakfast();
                cout << "\nWhat item do you want to edit : ";
                cin.ignore();
                getline(cin, edit);
                edit.erase(remove_if(edit.begin(), edit.end(), [](unsigned char c) { return isspace(c); }), edit.end());
                ofstream f1("Breakfast.txt");
                ofstream f2("Break_price.txt");
                ofstream f3("break_quant.txt");
                if (f1.is_open() && f2.is_open() && f3.is_open()) {
                    for (int i = 0; i < length_breakfast; i++) {
                        if (edit == _breakfast[i]) {
                            cout << "\nEnter item : ";
                            getline(cin, item);
                            cout << "\nEnter price : ";
                            cin >> price;
                            cout << "\nEnter qty : ";
                            cin >> qty;
                            _breakfast[i] = item;
                            breakfast_quantity[i] = qty;
                            breakfast_price[i] = price;
                        }
                        f1 << _breakfast[i] << endl;
                        f2 << breakfast_price[i] << endl;
                        f3 << breakfast_quantity[i] << endl;
                    }
                    f1.close();
                    f2.close();
                    f3.close();
                } else {
                    cout << "\nError" << endl;
                }
                break;
            }

        case 2:
        {
            read_lunch();
            Display_Lunch();
            cout << "\nWhat item do you want to edit : ";
            getline(cin, edit);
            edit.erase(remove_if(edit.begin(), edit.end(), [](unsigned char c) { return isspace(c); }), edit.end());
            cin.ignore();
            int count = 0, i;
            ofstream f1("lunch.txt", ios::out);
            ofstream f2("lunch_quant.txt", ios::out);
            ofstream f3("lunch_price.txt", ios::out);
            if (f1.is_open() && f2.is_open() && f3.is_open())
            {
                for (int i = 0; i < length_lunch; i++)
                {
                    if (_lunch[i] == edit)
                    {
                    	cout << "\nEnter item : ";
                        cin.ignore();
                        getline(cin, item);
                        cout << "\nEnter price : ";
                        cin >> price;
                        cout << "\nEnter qty : ";
                        cin >> qty;
                        f1 << item << endl;
                        f2 << price << endl;
                        f3 << qty << endl;
                    }
                        f1 << _lunch[i] << endl;
                        f2 << lunch_quantity[i] << endl;
                        f3 << lunch_price[i] << endl;
                }
            }
            else
            {
                cout << "\nError" << endl;
            }
        }
        break;

        case 3:
        {
            read_dinner();
            Display_Dinner();
            cout << "\nWhat item do you want to edit : ";
            cin.ignore();
            getline(cin, edit);
            edit.erase(remove_if(edit.begin(), edit.end(), [](unsigned char c) { return isspace(c); }), edit.end());
            int count = 0, i;
            ofstream f1("dinner.txt", ios::out);
            ofstream f2("dinner_quant.txt", ios::out);
            ofstream f3("dinner_price.txt", ios::out);
            if (f1.is_open() && f2.is_open() && f3.is_open())
            {
                for (int i = 0; i < length_dinner; i++)
                {
                	if (_dinner[i] == edit)
                    {
                    	cout << "\nEnter item : ";
                        cin.ignore();
                        getline(cin, item);
                        cout << "\nEnter price : ";
                        cin >> price;
                        cout << "\nEnter qty : ";
                        cin >> qty;
                        f1 << item << endl;
                        f2 << price << endl;
                        f3 << qty << endl;
                    }
                        f1 << _dinner[i] << endl;
                        f2 << dinner_quantity[i] << endl;
                        f3 << dinner_price[i] << endl;
                    
                }
                f1.close();
                f2.close();
                f3.close();
            }
            else
            {
                cout << "\nError" << endl;
            }
        
        break;
           }
        default:
            {cout << "Invalid input" << endl;
            cout << "Try again" << endl;
            goto label7;
            break;
        }
        }
    }
    void deletemenu()
    {
        string edit, item, price, qty;
        int choice;
    label6:
        cout << "Choose 1 of the following" << endl;
        cout << "1.Breakfast\n2.Lunch\n3.Dinner" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            read_breakfast();
            Display_Breakfast();
            cout << "\nWhat item do you want to delete : ";
            cin.ignore();
            getline(cin, edit);
            edit.erase(remove_if(edit.begin(), edit.end(), [](unsigned char c) { return isspace(c); }), edit.end());
            int count = 0, i;
            ofstream f1("Breakfast.txt", ios::out);
            ofstream f2("Break_price.txt", ios::out);
            ofstream f3("break_quant.txt", ios::out);
            if (f1.is_open() && f2.is_open() && f3.is_open())
            {
                for (int i = 0; i < length_breakfast-1 ; i++)
                {
                	if (_breakfast[i] != edit)
                    {
                        f1 << _breakfast[i] << endl;
                        f2 << breakfast_quantity[i] << endl;
                        f3 << breakfast_price[i] << endl;
                    }
                }
                f1.close();
                f2.close();
                f3.close();
            }
            else
            {
                cout << "\nError" << endl;
            }
        }
        break;

        case 2:
        {
            read_lunch();
            Display_Lunch();
            cout << "\nWhat item do you want to delete : ";
            cin.ignore();
            getline(cin, edit);
            edit.erase(remove_if(edit.begin(), edit.end(), [](unsigned char c) { return isspace(c); }), edit.end());
            int count = 0, i;
            ofstream f1("lunch.txt", ios::out);
            ofstream f2("lunch_quant.txt", ios::out);
            ofstream f3("lunch_price.txt", ios::out);
            if (f1.is_open() && f2.is_open() && f3.is_open())
            {
            
                for (int i = 0; i < length_lunch-1 ; i++)
                {
                	_lunch[i].erase(remove_if(_lunch[i].begin(), _lunch[i].end(), [](unsigned char c) { return isspace(c); }), _lunch[i].end());
                    if (_lunch[i] != edit)
                    {
                        f1 << _lunch[i] << endl;
                        f2 << lunch_quantity[i] << endl;
                        f3 << lunch_price[i] << endl;
                    }
                }
                f1.close();
                f2.close();
                f3.close();
            }
            else
            {
                cout << "\nError" << endl;
            }
        }
        break;

        case 3:
        {
            read_dinner();
            Display_Dinner();
            cout << "\nWhat item do you want to delete : ";
            cin.ignore();
            getline(cin, edit);
            int count = 0, i;
            ofstream f1("dinner.txt", ios::out);
            ofstream f2("dinner_quant.txt", ios::out);
            ofstream f3("dinner_price.txt", ios::out);
            if (f1.is_open() && f2.is_open() && f3.is_open())
            {
            	for (int i = 0; i < length_dinner-1 ; i++)
                {
                	_dinner[i].erase(remove_if(_dinner[i].begin(), _dinner[i].end(), [](unsigned char c) { return isspace(c); }), _dinner[i].end());
                    if (_dinner[i] != edit)
                    {
                        f1 << _dinner[i] << endl;
                        f2 << dinner_quantity[i] << endl;
                        f3 << dinner_price[i] << endl;
                    }
                }
                f1.close();
                f2.close();
                f3.close();
            }
            else
            {
                cout << "\nError" << endl;
            }
        }
        break;

        default:
            cout << "Invalid input" << endl;
            cout << "Try again" << endl;
            goto label6;
        }
    }
    void addmenu()
    {
        string item, price, qty;
        int choice;
    label:
        cout << "Choose 1 of the following" << endl;
        cout << "1.Breakfast\n2.Lunch\n3.Dinner" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            read_breakfast();
            Display_Breakfast();
            string x;
            ofstream f1("breakfast.txt", ios::app);
            ofstream f2("Break_price.txt", ios::app);
            ofstream f3("break_quant.txt", ios::app);
            if (f1.is_open() && f2.is_open() && f3.is_open())
            {
                cout << "\nEnter item : ";
                cin >> item;
                cout << "\nEnter price : ";
                cin >> price;
                cout << "\nEnter qty : ";
                cin >> qty;
                f1 << item << endl;
                f2 << price << endl;
                f3 << qty << endl;
                f1.close();
                f2.close();
                f3.close();
                cout << "\nItem added successfully!";
            }
            else
            {
                cout << "\nItem not added.\nTry again!";
                goto label;
            }
            break;
        }
        case 2:
        {
            read_lunch();
            Display_Lunch();
            string x;
            ofstream f1("lunch.txt", ios::app);
            ofstream f2("lunch_price.txt", ios::app);
            ofstream f3("lunch_quant.txt", ios::app);
        label1:
            if (f1.is_open() && f2.is_open() && f3.is_open())
            {
                cout << "\nEnter item : ";
                cin >> item;
                cout << "\nEnter price : ";
                cin >> price;
                cout << "\nEnter qty : ";
                cin >> qty;
                f1 << item << endl;
                f2 << price << endl;
                f3 << qty << endl;
                f1.close();
                f2.close();
                f3.close();
                cout << "\nItem added successfully!";
            }
            else
            {
                cout << "\nItem not added.\nTry again!";
                goto label1;
            }
            break;
        }

        case 3:
        {
            read_dinner();
            Display_Dinner();
            string x;
            ofstream f1("dinner.txt", ios::app);
            ofstream f2("dinner_price.txt", ios::app);
            ofstream f3("dinner_quant.txt", ios::app);
            if (f1.is_open() && f2.is_open() && f3.is_open())
            {
                cout << "\nEnter item : ";
                cin.ignore();
                getline(cin, item);
                cout << "\nEnter price : ";
                cin >> price;
                cout << "\nEnter qty : ";
                cin >> qty;
                f1 << item << endl;
                f2 << price << endl;
                f3 << qty << endl;
                f1.close();
                f2.close();
                f3.close();
                cout << "\nItem added successfully!";
            }
            else
            {
                cout << "\nItem not added.\nTry again!";
                goto label;
            }
            break;
        }

        default:
            cout << "Invalid input" << endl;
            cout << "Try again" << endl;
            goto label;
        }
    }
};

void Menu::read_breakfast()
{
    count = 0;
    // Reading and stroing item names from file
    breakfast.open("Breakfast.txt");
    if (!breakfast.is_open())
    {
        cout << "Failed to open file " << endl;
        return;
    }

    while (breakfast.eof() == 0) // to read the file till end
    {
        getline(breakfast, _breakfast[count]);
        count++;
    }
    length_breakfast = count; // size of array of breakfast
    count = 0;
    breakfast.close();

    b_quantity.open("break_quant.txt");
    if (!b_quantity.is_open())
    {
        cout << "Failed to open file " << endl;
        return;
    }

    while (b_quantity.eof() == 0) // to read the file till end
    {
        b_quantity >> breakfast_quantity[count];
        count++;
    }
    // length_breakfast = count; // size of array of breakfast
    count = 0;
    b_quantity.close();

    b_price.open("Break_price.txt");
    if (!b_price.is_open())
    {
        cout << "Failed to open file " << endl;
        return;
    }

    while (b_price.eof() == 0) // to read the file till end
    {
        b_price >> breakfast_price[count];
        count++;
    }
    // length_breakfast = count; // size of array of breakfast
    count = 0;
    b_price.close();
}

void Menu::read_lunch()
{
    lunch.open("lunch.txt");
    if (!lunch.is_open())
    {
        cout << "Failed to open file " << endl;
        return;
    }

    while (lunch.eof() == 0)
    {
        getline(lunch, _lunch[count]);
        count++;
    }
    length_lunch = count; // size of array of lunch
    count = 0;
    lunch.close();

    l_price.open("lunch_price.txt");
    if (!l_price.is_open())
    {
        cout << "Failed to open file " << endl;
        return;
    }

    while (l_price.eof() == 0)
    {
        l_price >> lunch_price[count];
        // getline(l_price, lunch_price[count]);
        count++;
    }
    count = 0;
    l_price.close();

    l_quantity.open("lunch_quant.txt");
    if (!l_quantity.is_open())
    {
        cout << "Failed to open file " << endl;
        return;
    }

    while (l_quantity.eof() == 0)
    {
        l_quantity >> lunch_quantity[count];
        count++;
    }
    count = 0;
    l_quantity.close();
}

void Menu::read_dinner()
{
    dinner.open("dinner.txt");
    if (!dinner.is_open())
    {
        cout << "Failed to open file " << endl;
        return;
    }

    while (dinner.eof() == 0)
    {
        getline(dinner, _dinner[count]);
        count++;
    }
    length_dinner = count; // size of array of dinner
    count = 0;
    dinner.close();

    d_price.open("dinner_price.txt");
    if (!d_price.is_open())
    {
        cout << "Failed to open file " << endl;
        return;
    }

    while (d_price >> dinner_price[count])
    {

        count++;
    }

    count = 0;
    d_price.close();

    d_quantity.open("dinner_quant.txt");
    if (!d_quantity.is_open())
    {
        cout << "Failed to open file " << endl;
        return;
    }

    while (d_quantity.eof() == 0)
    {
        d_quantity >> dinner_quantity[count];
        count++;
    }
    count = 0;
    d_quantity.close();
}

void Menu::read_Beverages()
{
    beverages.open("Beverages.txt");
    if (!beverages.is_open())
    {
        cout << "Failed to open file " << endl;
        return;
    }

    while (beverages.eof() == 0)
    {
        getline(beverages, _beverages[count]);
        count++;
    }
    length_beverages = count; // size of array of Beverages
    count = 0;
    beverages.close();

    beverages_price.open("Beverages_price.txt");
    if (!beverages_price.is_open())
    {
        cout << "Failed to open file " << endl;
        return;
    }

    while (beverages_price.eof() == 0)
    {
        beverages_price >> _beverages_price[count];
        count++;
    }

    count = 0;
    beverages_price.close();

    beverages_quantity.open("Beverages_quantity.txt");
    if (!beverages_quantity.is_open())
    {
        cout << "Failed to open file " << endl;
        return;
    }

    while (beverages_quantity.eof() == 0)
    {
        beverages_quantity >> _beverages_quantity[count];
        count++;
    }
    count = 0;
    beverages_quantity.close();
}

void Menu::read_Desserts()
{
    desserts.open("Desserts.txt");
    if (!desserts.is_open())
    {
        cout << "Failed to open file " << endl;
        return;
    }

    while (desserts.eof() == 0)
    {
        getline(desserts, _desserts[count]);
        count++;
    }
    length_desserts = count; // size of array of desserts
    count = 0;
    desserts.close();

    desserts_price.open("Desserts_price.txt");
    if (!desserts_price.is_open())
    {
        cout << "Failed to open file " << endl;
        return;
    }

    while (desserts_price.eof() == 0)
    {
        desserts_price >> _desserts_price[count];
        count++;
    }

    count = 0;
    desserts_price.close();

    desserts_quantity.open("Desserts_quantity.txt");
    if (!desserts_quantity.is_open())
    {
        cout << "Failed to open file " << endl;
        return;
    }

    while (desserts_quantity.eof() == 0)
    {
        desserts_quantity >> _desserts_quantity[count];
        count++;
    }
    count = 0;
    desserts_quantity.close();
}

void Menu::read_Tandoor()
{
    tandoor.open("Tandoor.txt");
    if (!tandoor.is_open())
    {
        cout << "Failed to open file " << endl;
        return;
    }

    while (tandoor.eof() == 0)
    {
        getline(tandoor, _tandoor[count]);
        count++;
    }
    length_tandoor = count; // size of array of Tandoor
    count = 0;
    tandoor.close();

    tandoor_price.open("Tandoor_price.txt");
    if (!tandoor_price.is_open())
    {
        cout << "Failed to open file " << endl;
        return;
    }

    while (tandoor_price.eof() == 0)
    {
        tandoor_price >> _tandoor_price[count];
        count++;
    }

    count = 0;
    tandoor_price.close();

    tandoor_quantity.open("Tandoor_quantity.txt");
    if (!tandoor_quantity.is_open())
    {
        cout << "Failed to open file " << endl;
        return;
    }

    while (tandoor_quantity.eof() == 0)
    {
        tandoor_quantity >> _tandoor_quantity[count];
        count++;
    }
    count = 0;
    tandoor_quantity.close();
}

void Menu::read_Raita()
{
    raita.open("Raita_Salad.txt");
    if (!raita.is_open())
    {
        cout << "Failed to open file " << endl;
        return;
    }

    while (raita.eof() == 0)
    {
        getline(raita, _raita[count]);
        count++;
    }
    length_raita = count; // size of array of Tandoor
    count = 0;
    raita.close();

    raita_price.open("Raita_price.txt");
    if (!raita_price.is_open())
    {
        cout << "Failed to open file " << endl;
        return;
    }

    while (raita_price.eof() == 0)
    {
        raita_price >> _raita_price[count];
        count++;
    }

    count = 0;
    raita_price.close();

    raita_quantity.open("Raita_quantity.txt");
    if (!raita_quantity.is_open())
    {
        cout << "Failed to open file " << endl;
        return;
    }

    while (raita_quantity.eof() == 0)
    {
        raita_quantity >> _raita_quantity[count];
        count++;
    }
    count = 0;
    raita_quantity.close();
}

void Menu::Display_Breakfast()
{
    count = 0;
    cout << "Name                Price            Quantity" << endl;
    for (int i = 0; i < length_breakfast; i++)
    {
        cout << i + 1 << ". " << _breakfast[i] << "    " << breakfast_price[i] << "          " << breakfast_quantity[i] << endl;
    }
}

void Menu::Display_Lunch()
{
    count = 0;
    cout << "Name                             Price            Quantity" << endl;
    for (int i = 0; i < length_lunch; i++)
    {
        cout << i + 1 << ". " << _lunch[i] << "    " << lunch_price[i] << "          " << lunch_quantity[i] << endl;
    }
}

void Menu::Display_Dinner()
{
    count = 0;
    cout << "Name                        Price            Quantity" << endl;
    for (int i = 0; i < length_dinner; i++)
    {
        cout << i + 1 << ". " << _dinner[i] << "    " << dinner_price[i] << "            " << dinner_quantity[i] << endl;
    }
}

void Menu::Display_Beverages()
{
    count = 0;
    cout << "Name                        Price            Quantity" << endl;
    for (int i = 0; i < length_beverages; i++)
    {
        cout << i + 1 << ". " << _beverages[i] << "    " << _beverages_price[i] << "                   " << _beverages_quantity[i] << endl;
    }
}

void Menu::Display_Desserts()
{
    count = 0;
    cout << "Name                Price      Quantity" << endl;
    for (int i = 0; i < length_desserts; i++)
    {
        cout << i + 1 << ". " << _desserts[i] << "    " << _desserts_price[i] << "      " << _desserts_quantity[i] << endl;
    }
}

void Menu::Display_Tandoor()
{
    count = 0;
    cout << "Name                Price            Quantity" << endl;
    for (int i = 0; i < length_tandoor; i++)
    {
        cout << i + 1 << ". " << _tandoor[i] << "    " << _tandoor_price[i] << "          " << _tandoor_quantity[i] << endl;
    }
}

void Menu::Display_Raita()
{
    count = 0;
    cout << "Name         Price            Quantity" << endl;
    for (int i = 0; i < length_raita; i++)
    {
        cout << i + 1 << ". " << _raita[i] << "    " << _raita_price[i] << "                   " << _raita_quantity[i] << endl;
    }
}

void Menu::Display_menu()
{
    int choice;
label:
    cout << "Choose 1 of the following" << endl;
    cout << "1.Breakfast\n2.Lunch\n3.Dinner\n4.Beverages\n5.Desserts\n6.Tandoor\n7.Raita & Salad\n8.Full Menu" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        Display_Breakfast();
        break;

    case 2:
        Display_Lunch();
        break;

    case 3:
        Display_Dinner();
        break;

    case 4:
        Display_Beverages();
        break;

    case 5:
        Display_Desserts();
        break;

    case 6:
        Display_Tandoor();
        break;

    case 7:
        Display_Raita();
        break;

    case 8:
        cout << "                Breakfast" << endl
             << "________________" << endl;
        Display_Breakfast();
        cout << endl
             << endl;
        cout << "                Lunch" << endl
             << "________________" << endl;
        Display_Lunch();
        cout << endl
             << endl;
        cout << "                Dinner" << endl
             << "________________" << endl;
        Display_Dinner();
        cout << endl
             << endl;
        cout << "                Beverages" << endl
             << "________________" << endl;
        Display_Beverages();
        cout << "                Desserts" << endl
             << "________________" << endl;
        Display_Desserts();
        cout << endl
             << endl;
        cout << "                Raita & Salad" << endl
             << "________________" << endl;
        Display_Raita();
        cout << endl
             << endl;
        cout << "                Tandoor" << endl
             << "________________" << endl;
        Display_Tandoor();
        cout << endl
             << endl;
        break;

    default:
        cout << "Please enter valid input" << endl;
        goto label;
    }
}
#endif