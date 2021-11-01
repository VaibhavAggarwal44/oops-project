#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
using namespace std;

void EnterData();
void DisplayRecords();
void SearchBySerialNo();
void deleteRecord();
void modifyRecord();
void SearchByPhoneNo();
void RemoveAll();
void menu();
void loading();
bool phoneValidator(string ph);

class record
{
public:
    int serialNo;
    int SerialNumberReturn() { return serialNo; }
    string PhonenumberReturn() { return phno; }
    char name[30];
    char email[30];
    string phno;

    void enterdetails()
    {
        cout << "\n\t\t\t\t\t\t\t\t\tENTER SERIAL NUMBER:";
        cin >> serialNo;
        cout << "\n\t\t\t\t\t\t\t\t\tENTER NAME:";
        cin.ignore();
        cin.getline(name, 30);
        cout << "\n\t\t\t\t\t\t\t\t\tENTER PHONE NUMBER: ";
        getline(cin, phno);
        cout << "\n\t\t\t\t\t\t\t\t\tENTER EMAIL: ";
        cin.getline(email, 30);
    }

    void display()
    {
        cout << "\n\t\t\t\t\t\t\t\t\tSERIAL NUMBER:" << serialNo;
        cout << "\n\t\t\t\t\t\t\t\t\tNAME:" << name;
        cout << "\n\t\t\t\t\t\t\t\t\tPHONE NUMBER:" << phno;
        cout << "\n\t\t\t\t\t\t\t\t\tEMAIL:" << email;
        cout << "\n---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
    }

} r;

void EnterData()
{
    ofstream fout;
    fout.open("Record3.txt", ios::out | ios::binary | ios::app);
    r.enterdetails();
    fout.write((char *)&r, sizeof(r));
    fout.close();
    cout << "\n\t\t\t\t\t\t\t\t\tRecord Saved to File......\n";
}

void DisplayRecords()
{
    ifstream fin;
    fin.open("Record3.txt", ios::out | ios::binary | ios::app);
    while (fin.read((char *)&r, sizeof(r)))
    {
        r.display();
    }
    fin.close();
    cout << "\n\t\t\t\t\t\t\t\t\tReading of Data File Completed......\n";
}

void SearchBySerialNo()
{
    ifstream fin;
    int n, flag = 0;
    fin.open("Record3.txt", ios::out | ios::binary | ios::app);
    cout << "\n\t\t\t\t\t\t\t\t\tEnter Serial Number of Record To Display: ";
    cin >> n;

    while (fin.read((char *)&r, sizeof(r)))
    {
        if (n == r.SerialNumberReturn())
        {
            r.display();
            flag++;
            cout << "\n\n\t\t\t\t\t\t\t\t\t-----Record Found and Displayed-----\n";
        }
    }
    fin.close();
    if (flag == 0)
        cout << "\n\t\t\t\t\t\t\t\t\tThe Record of Serial Number " << n << " is not in file....\n";
    cout << "\n\t\t\t\t\t\t\t\t\tReading of Data File Completed-----\n";
}

void deleteRecord()
{
    ifstream fin;
    ofstream fout;
    int n, flag = 0;
    fin.open("Record3.txt", ios::out | ios::binary | ios::app);
    fout.open("temp.txt", ios::out | ios::binary);
    cout << "\n\t\t\t\t\t\t\t\t\tEnter Serial Number of Record To Delete : ";
    cin >> n;

    while (fin.read((char *)&r, sizeof(r)))
    {
        if (n == r.SerialNumberReturn())
        {
            cout << "\n\t\t\t\t\t\t\t\t\tThe Following record is deleted....\n";
            r.display();
            flag++;
        }
        else
        {
            fout.write((char *)&r, sizeof(r));
        }
    }
    fin.close();
    fout.close();
    if (flag == 0)
        cout << "\n\t\t\t\t\t\t\t\t\tThe Record of Serial Number " << n << " is not in file....\n";
    cout << "\n\t\t\t\t\t\t\t\t\tReading of Data File Completed......\n";
    remove("Record3.txt");
    rename("temp.txt", "Record3.txt");
}

void modifyRecord()
{
    fstream fio;
    int n, flag = 0, pos;
    fio.open("Record3.txt", ios::out | ios::binary | ios::in);

    cout << "Enter Serial Number of Record To Modify : ";
    cin >> n;

    while (fio.read((char *)&r, sizeof(r)))
    {
        pos = fio.tellg();
        if (n == r.SerialNumberReturn())
        {
            cout << "\n\t\t\t\t\t\t\t\t\tThe Following record will be modified....\n";
            r.display();
            flag++;
            cout << "\n\t\t\t\t\t\t\t\t\tRe-Enter the New Details----\n";
            r.enterdetails();
            fio.seekg(pos - sizeof(r));
            fio.write((char *)&r, sizeof(r));
            cout << "\n\t\t\t\t\t\t\t\t\t----Data Modified Successfully----\n";
        }
    }
    fio.close();
    if (flag == 0)
        cout << "\n\t\t\t\t\t\t\t\t\tThe Record of Serial Number " << n << " is not in file....\n";
    cout << "\n\t\t\t\t\t\t\t\t\tReading of Data File Completed......\n";
}

void SearchByPhoneNo()
{
    ifstream fin;
    string n;
    int flag = 0;
    fin.open("Record3.txt", ios::out | ios::binary | ios::app);
    cout << "\n\t\t\t\t\t\t\t\t\tEnter Phone Number of Record To Display: ";
    cin >> n;

    while (fin.read((char *)&r, sizeof(r)))
    {
        if (n == r.PhonenumberReturn())
        {
            r.display();
            flag++;
            cout << "\n\n\t\t\t\t\t\t\t\t\t-----Record Found and Displayed-----\n";
        }
    }
    fin.close();
    if (flag == 0)
        cout << "\n\t\t\t\t\t\t\t\t\tThe Record of Serial Number " << n << " is not in file....\n";
    cout << "\n\t\t\t\t\t\t\t\t\tReading of Data File Completed-----\n";
}

void RemoveAll()
{
    string ans;
    cout << "\n\t\t\t\t\t\t\t\t\tDO YOU REALLY WANT TO DELETE ALL THE RECORDS?(Y/N)";
    cin >> ans;
    if (ans == "y" || ans == "Y")
        remove("Record3.txt");

    cout << "\n\t\t\t\t\t\t\t\t\tDELETED ALL RECORDS!!!!";
}

void menu()
{
    int ch;
    do
    {
        system("cls");
        cout << "\n\n\n\n\n\n";
        cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t|           PHONEBOOK APPLICATION SYSTEM              |\n";
        cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t|                [1]ADD CONTACTS                      |\n";
        cout << "\t\t\t\t\t\t\t\t|                [2]DISPLAY CONTACTS                  |\n";
        cout << "\t\t\t\t\t\t\t\t|                [3]UPDATE CONTACTS                   |\n";
        cout << "\t\t\t\t\t\t\t\t|                [4]DELETE CONTACTS                   |\n";
        cout << "\t\t\t\t\t\t\t\t|                [5]SEARCH BY SERIAL NUMBER           |\n";
        cout << "\t\t\t\t\t\t\t\t|                [6]SEARCH BY PHONE NUMBER            |\n";
        cout << "\t\t\t\t\t\t\t\t|                [7]DELETE ALL CONTACTS               |\n";
        cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t|                   [8]EXIT                           |\n";
        cout << "\t\t\t\t\t\t\t\t-------------------------------------------------------\n";
        cin >> ch;
        system("cls");
        switch (ch)
        {
        case 1:
            EnterData();
            break;
        case 2:
            DisplayRecords();
            break;
        case 3:
            modifyRecord();
            break;
        case 4:
            deleteRecord();
            break;
        case 5:
            SearchBySerialNo();
            break;
        case 6:
            SearchByPhoneNo();
            break;
        case 7:
            RemoveAll();
            break;
        }
        getch();
    } while (ch != 8);
}

void loading()
{
    // char x=219;
    char x = 254;
    cout << "\n\n\n\n\n\n";
    cout << "\t\t\t\t\t\t\t\t\tPHONEBOOK MANAGEMENT SYSTEM\n ";
    cout << "\t\t\t\t\t\t\t\tLoading: ";
    for (int i = 0; i < 35; i++)
    {
        cout << x;
        Sleep(100);
        if (i > 10 && i <= 20)
            Sleep(50);
        if (i > 20)
            Sleep(25);
    }
    system("cls");
}

int main()
{
    // loading();

    menu();

    return 0;
}