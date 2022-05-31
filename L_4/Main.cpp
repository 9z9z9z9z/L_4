#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
#include <Windows.h>
#include "Storage.h"
#include "Date.h"
#include "Stock.h"
#include <cstdlib>

using namespace std;

string stockPath = "StockData.txt";
string storagePath = "StorageData.txt";

#pragma region Operators

bool operator > (Storage a, Date b)
{
    int day = a.getDate().getDay();
    int month = a.getDate().getMonth();
    int year = a.getDate().getYear();
    if (year >= b.getYear())
    {
        if (month >= b.getMonth())
        {
            if (day > b.getDay())
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool operator > (Stock a, Date b)
{
    int day = a.getDate().getDay();
    int month = a.getDate().getMonth();
    int year = a.getDate().getYear();
    if (year >= b.getYear())
    {
        if (month >= b.getMonth())
        {
            if (day > b.getDay())
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

Date Date::operator=(Date data)
{
    Date::setDay(data.getDay());
    Date::setMonth(data.getMonth());
    Date::setYear(data.getYear());
    return *this;
}

Storage Storage::operator=(Storage base)
{

    Storage::setName(base.getName());
    Storage::setPrice(base.getPrice());
    Storage::getDate() = base.getDate();
    Storage::setQuant(base.getQuant());
    Storage::setNum(base.getNum());
    return *this;
}

#pragma endregion Operators


#pragma region Other_Functions

void input_int(int& num)
{
    string num_value;
    cin >> num_value;

    try
    {
        num = stoi(num_value);
    }
    catch (invalid_argument)
    {
        //Говорим, что можно вводить только числа
        cout << "Only numbers are allowed! \n";
    }
    catch (out_of_range)
    {
        //Говорим, что число слишком большое
        cout << "You can't be that old! \n";
    }
    catch (...)
    {
        //Если будет выброшено какое-то исключение, которое не обработано выше, то говорим, что возникла неизвестная ошибка
        cout << "Unknown error! \n";
    }
}

int string_to_int(string str)
{
    int result;
    istringstream iss(str, istringstream::in);
    iss >> result;
    return result;
}

double string_to_double(string str)
{
    double result;
    istringstream iss(str, istringstream::in);
    iss >> result;
    return result;
}

bool comp(int a, int b)
{
    if (a > b)
        return a < b;
    else
        return a > b;
}

#pragma endregion Other_Functions

#pragma region File_Functions

void save(Stock*& stockData, Storage*& storageData)
{
    fstream datainput;
    datainput.open(stockPath, ios::out);
    for (int i = 0; i < stockData->count; i++)
    {
        datainput << stockData[i].getName() << endl << stockData[i].getPrice() << endl << stockData[i].getQuant()
            << endl << stockData[i].getNum() << endl << stockData[i].count << endl << stockData[i].getDate().getDay() << endl
            << stockData[i].getDate().getMonth() << endl << stockData[i].getDate().getYear() << endl;
    }
    datainput.close();

    datainput.open(storagePath, ios::out);
    for (int i = 0; i < Storage::count; i++)
    {
        datainput << storageData[i].getName() << endl << storageData[i].getPrice() << endl << storageData[i].getQuant()
            << endl << storageData[i].getNum() << endl << storageData[i].count << endl << storageData[i].getDate().getDay() << endl
            << storageData[i].getDate().getMonth() << endl << storageData[i].getDate().getYear() << endl;
    }
    datainput.close();
}

void load(Stock*& stockData, Storage*& storageData)
{
    fstream datainput;
    int i = 0;

    datainput.open(stockPath, ios::in);
    for (int j = 0; j < Stock::count * 6;)
    {
        for (i = 0; i < 6; i++)
        {
            switch (i)
            {
            case 0:
            {
                string line;
                getline(datainput, line);
                stockData[j / 6].setName(line);
                break;
            }
            case 1:
            {
                string line;
                getline(datainput, line);
                stockData[j / 6].setPrice(string_to_double(line));
                break;
            }
            case 2:
            {
                string line;
                getline(datainput, line);
                stockData[j / 6].setQuant(string_to_int(line));
                break;
            }
            case 3:
            {
                string line;
                getline(datainput, line);
                stockData[j / 6].setNum(string_to_int(line));
                break;
            }
            case 4:
            {
                string line;
                getline(datainput, line);
                stockData[j / 6].count = string_to_int(line);
                break;
            }
            case 5:
                string line;
                getline(datainput, line);
                stockData[j / 6].getDate().setDay(string_to_int(line));
                getline(datainput, line);
                stockData[j / 6].getDate().setMonth(string_to_int(line));
                getline(datainput, line);
                stockData[j / 6].getDate().setYear(string_to_int(line));
            }
        }
        j = j + 6;
    }
    datainput.close();

    i = 0;
    datainput.open(storagePath, ios::in);
    for (int j = 0; j < Storage::count * 6;)
    {
        for (i = 0; i < 6; i++)
        {
            switch (i)
            {
            case 0:
            {
                string line;
                getline(datainput, line);
                storageData[j / 6].setName(line);
                break;
            }
            case 1:
            {
                string line;
                getline(datainput, line);
                storageData[j / 6].setPrice(string_to_double(line));
                break;
            }
            case 2:
            {
                string line;
                getline(datainput, line);
                storageData[j / 6].setQuant(string_to_int(line));
                break;
            }
            case 3:
            {
                string line;
                getline(datainput, line);
                storageData[j / 6].setNum(string_to_int(line));
                break;
            }
            case 4:
            {
                string line;
                getline(datainput, line);
                storageData[j / 6].count = string_to_int(line);
                break;
            }
            case 5:
                string line;
                getline(datainput, line);
                storageData[j / 6].getDate().setDay(string_to_int(line));
                getline(datainput, line);
                storageData[j / 6].getDate().setMonth(string_to_int(line));
                getline(datainput, line);
                storageData[j / 6].getDate().setYear(string_to_int(line));
            }
        }
        j = j + 6;
    }
    datainput.close();
}

void value() {
    fstream read;
    int count = 0;
    string tmp;

    read.open(stockPath, ios::in);
    while (read.peek() != EOF) {
        getline(read, tmp);
        ++count;
        if (count % 6 == 0)
        {
            Stock::count++;
        }
    }
    read.close();

    read.open(storagePath, ios::in);
    while (read.peek() != EOF) {
        getline(read, tmp);
        ++count;
        if (count % 6 == 0)
        {
            Storage::count++;
        }
    }
    read.close();
}

#pragma endregion File_Functions


#pragma region mainFunctions

void add(Stock*& stockData, Storage*& storageData, int classSelect)
{
    system("cls");

    string string_buffer;
    double double_buffer;
    int int_buffer;
    if (classSelect == 0)
    {
        cout << "Please input product name: "; cin >> string_buffer;
        storageData[Storage::count].setName(string_buffer);

        cout << "Please input product price: "; cin >> double_buffer;
        storageData[Storage::count].setPrice(double_buffer);

        cout << "Please input quant of products: "; cin >> int_buffer;
        storageData[Storage::count].setQuant(int_buffer);

        cout << "Please input section number: "; cin >> int_buffer;
        storageData[Storage::count].setNum(int_buffer);

        Storage::count++;
        cout << "Product was added." << endl << endl;
    }
    else if (classSelect == 1)
    {
        cout << Stock::count << endl;
        cout << "Please input product name: "; cin >> string_buffer;
        stockData[Stock::count].setName(string_buffer);

        cout << "Please input product price: "; cin >> double_buffer;
        stockData[Stock::count].setPrice(double_buffer);

        cout << "Please input quant of products: "; cin >> int_buffer;
        stockData[Stock::count].setQuant(int_buffer);

        cout << "Please input section number: "; cin >> int_buffer;
        stockData[Stock::count].setNum(int_buffer);

        Stock::count++;
        cout << "Product was added." << endl << endl;
    }
    else
    {
        cout << "Undefined functions!" << endl;
    }
    system("pause");
}

void printMass(Stock*& stockData, Storage*& storageData)
{
    system("cls");
    cout << "---------------------------------------" << endl;
    cout << "Storage class:\n" << endl;
    for (int i = 0; i < Storage::count; i++)
    {
        cout << "Name: " << storageData[i].getName() << endl;
        cout << "Price: " << storageData[i].getPrice() << endl;
        cout << "Quant: " << storageData[i].getQuant() << endl;
        cout << "Num: " << storageData[i].getNum() << endl;
        cout << "Date: " << storageData[i].getDate().getDay() << "." << storageData[i].getDate().getMonth() << "." << storageData[i].getDate().getYear() << endl;
        cout << "=======================================" << endl;
    }
    cout << "\n---------------------------------------" << endl;
    cout << "Stock class:\n" << endl;
    for (int i = 0; i < Stock::count; i++)
    {
        cout << "Name: " << stockData[i].getName() << endl;
        cout << "Price: " << stockData[i].getPrice() << endl;
        cout << "Quant: " << stockData[i].getQuant() << endl;
        cout << "Num: " << stockData[i].getNum() << endl;
        cout << "Date: " << stockData[i].getDate().getDay() << "." << stockData[i].getDate().getMonth() << "." << stockData[i].getDate().getYear() << endl;
        cout << "=======================================" << endl;
    }
    cout << "\n---------------------------------------" << endl;
    system("pause");
}

void searchByName(Stock*& stockData, Storage*& storageData)
{
    string name;
    bool error_msg = true;
    int tmp;

    cout << "Enter section number: "; cin >> name; cout << endl;

    cout << "\n---------------------------------------" << endl;
    cout << "Storage class:\n" << endl;
    for (int i = 0; i < Storage::count; i++)
    {
        if (storageData[i].getName() == name)
        {
            cout << "Name: " << storageData[i].getName() << endl;
            cout << "Price: " << storageData[i].getPrice() << endl;
            cout << "Quant: " << storageData[i].getQuant() << endl;
            cout << "Num: " << storageData[i].getNum() << endl;
            cout << "Date: " << storageData[i].getDate().getDay() << "." << storageData[i].getDate().getMonth() << "." << storageData[i].getDate().getYear() << endl;
            cout << "######################################" << endl;
        }
    }

    cout << endl;

    cout << "---------------------------------------" << endl;
    cout << "Stock class:\n" << endl;
    for (int i = 0; i < Stock::count; i++)
    {
        if (stockData[i].getName() == name)
        {
            cout << "Name: " << stockData[i].getName() << endl;
            cout << "Price: " << stockData[i].getPrice() << endl;
            cout << "Quant: " << stockData[i].getQuant() << endl;
            cout << "Num: " << stockData[i].getNum() << endl;
            cout << "Date: " << stockData[i].getDate().getDay() << "." << stockData[i].getDate().getMonth() << "." << stockData[i].getDate().getYear() << endl;
            cout << "######################################" << endl;
        }
    }

    system("pause");
}

void filterByNum(Stock*& stockData, Storage*& storageData)
{
    int num;
    bool error_msg = true;
    int tmp;

    cout << "Enter section number: "; cin >> num; cout << endl;

    cout << "\n---------------------------------------" << endl;
    cout << "Storage class:\n" << endl;
    for (int i = 0; i < Storage::count; i++)
    {
        if (storageData[i].getNum() == num)
        {
            cout << "Name: " << storageData[i].getName() << endl;
            cout << "Price: " << storageData[i].getPrice() << endl;
            cout << "Quant: " << storageData[i].getQuant() << endl;
            cout << "Num: " << storageData[i].getNum() << endl;
            cout << "Date: " << storageData[i].getDate().getDay() << "." << storageData[i].getDate().getMonth() << "." << storageData[i].getDate().getYear() << endl;
            cout << "######################################" << endl;
        }
    }

    cout << endl;

    cout << "---------------------------------------" << endl;
    cout << "Stock class:\n" << endl;
    for (int i = 0; i < Stock::count; i++)
    {
        if (stockData[i].getNum() == num)
        {
            cout << "Name: " << stockData[i].getName() << endl;
            cout << "Price: " << stockData[i].getPrice() << endl;
            cout << "Quant: " << stockData[i].getQuant() << endl;
            cout << "Num: " << stockData[i].getNum() << endl;
            cout << "Date: " << stockData[i].getDate().getDay() << "." << stockData[i].getDate().getMonth() << "." << stockData[i].getDate().getYear() << endl;
            cout << "######################################" << endl;
        }
    }

    system("pause");
}

void sortByQuant(Stock*& stockData, Storage*& storageData)
{
    map<int, Storage> arrStorage;
    map<int, Stock> arrStock;
    vector<int> quantStorage;
    vector<int> quantStock;

    for (int i = 0; i < Storage::count; i++)
    {
        quantStorage.push_back(storageData[i].getQuant());
        arrStorage[quantStorage[i]] = storageData[i];
    }
    for (int i = 0; i < Stock::count; i++)
    {
        quantStock.push_back(stockData[i].getQuant());
        arrStock[quantStock[i]] = stockData[i];
    }

    Storage* resultStorage = new Storage[Storage::count];
    int j = Storage::count;

    for (auto& i : arrStorage)
    {
        resultStorage[j - 1] = i.second;
        j--;
    }

    Stock* resultStock = new Stock[Stock::count];
    j = Stock::count;

    for (auto& i : arrStock)
    {
        resultStock[j - 1] = i.second;
        j--;
    }

    printMass(resultStock, resultStorage);
    delete[] resultStorage;
    delete[] resultStock;
}

void findByDate(Stock*& stockData, Storage*& storageData)
{
    Date date;
    bool error_msg = true;
    int tmp;

    cout << "Enter day: "; input_int(tmp); date.setDay(tmp);
    cout << "Enter month: "; input_int(tmp); date.setMonth(tmp);
    cout << "Enter year: "; input_int(tmp); date.setYear(tmp);

    cout << "\n---------------------------------------" << endl;
    cout << "Storage class:\n" << endl;
    for (int i = 0; i < Storage::count; i++)
    {
        if (storageData[i] > date)
        {
            cout << "Name: " << storageData[i].getName() << endl;
            cout << "Price: " << storageData[i].getPrice() << endl;
            cout << "Quant: " << storageData[i].getQuant() << endl;
            cout << "Num: " << storageData[i].getNum() << endl;
            cout << "Date: " << storageData[i].getDate().getDay() << "." << storageData[i].getDate().getMonth() << "." << storageData[i].getDate().getYear() << endl;
            cout << "######################################" << endl;
        }
    }

    cout << endl;

    cout << "---------------------------------------" << endl;
    cout << "Stock class:\n" << endl;
    for (int i = 0; i < Stock::count; i++)
    {
        if (stockData[i] > date)
        {
            cout << "Name: " << stockData[i].getName() << endl;
            cout << "Price: " << stockData[i].getPrice() << endl;
            cout << "Quant: " << stockData[i].getQuant() << endl;
            cout << "Num: " << stockData[i].getNum() << endl;
            cout << "Date: " << stockData[i].getDate().getDay() << "." << stockData[i].getDate().getMonth() << "." << stockData[i].getDate().getYear() << endl;
            cout << "######################################" << endl;
        }
    }

    system("pause");
}

#pragma endregion mainFunctions

#pragma region interfaceFunctions

void functions_list() {
    system("cls");
    cout << "=============================================" << endl;
    cout << "Current functions:" << endl;
    cout << "1) Add product to DB." << endl;
    cout << "2) Print all products from DB." << endl;
    cout << "3) Search product by name." << endl;
    cout << "4) Filter products by section number." << endl;
    cout << "5) Sort products by count decrease." << endl;
    cout << "6) Find products by date." << endl;
    cout << "7) Exit program." << endl;
    cout << "=============================================" << endl << endl;
}

void menu(Stock*& stockData, Storage*& storageData) {
    bool start_msg = true;
    int choice = 0;
    Storage* storageTmp;
    Stock* stockTmp;
    int classSelect;

    while (choice != 7)
    {
        functions_list();
        start_msg = false;
        cout << "Type function number: "; input_int(choice); cout << endl;
        switch (choice) {
        case 1:
            cout << "Select class: " << endl << "0 - Storage, 1 - Stock\n" << endl;
            cin >> classSelect; cout << endl;

            if (classSelect == 0)
            {
                storageTmp = new Storage[Storage::count + 1];

                for (int i = 0; i < Storage::count; i++)
                {
                    storageTmp[i] = storageData[i];
                }

                add(stockData, storageTmp, classSelect);
                delete[] storageData;
                storageData = new Storage[Storage::count];

                for (int i = 0; i < Storage::count; i++)
                {
                    storageData[i] = storageTmp[i];
                }
                break;
            }
            else if (classSelect == 1)
            {
                stockTmp = new Stock[Stock::count + 1];

                for (int i = 0; i < Stock::count; i++)
                {
                    stockTmp[i] = stockData[i];
                }

                add(stockTmp, storageData, classSelect);
                delete[] stockData;
                stockData = new Stock[Stock::count];

                for (int i = 0; i < Stock::count; i++)
                {
                    stockData[i] = stockTmp[i];
                }
                break;
            }
            else
            {
                cout << "Undefined class!" << endl;
                break;
            }
        case 2:
            printMass(stockData, storageData);
            break;
        case 3:
            searchByName(stockData, storageData);
            break;
        case 4:
            filterByNum(stockData, storageData);
            break;
        case 5:
            sortByQuant(stockData, storageData);
            break;
        case 6:
            findByDate(stockData, storageData);
            break;
        case 7:
            save(stockData, storageData);
            cout << "Program was exit..." << endl;
            exit(0);
            break;
        default:
            cout << "Error... Function was not find!" << endl;
            break;
        }
    }
}

#pragma endregion interfaceFunctions


int main() {
    value();
    Stock* stockData = new Stock[Stock::count];
    Storage* storageData = new Storage[Storage::count];

    load(stockData, storageData);
    menu(stockData, storageData);

    delete[] stockData;
    delete[] storageData;
    return 0;
}