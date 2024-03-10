// magement System
// Add Student
// View all the list of students
// Search particular student
// fs module // os module

#include <iostream>
#include <fstream>
using namespace std;

class temp
{
    string roll_no, name, fName, address, search;
    fstream file;

public:
    void addStu();
    void viewStu();
    void searchStu();
    void updateStu();
    void deletestu();
    void stuRecord();
} obj;

int main()
{
    char choice;

    cout << "-----------------------------------------" << endl
         << "1-Addd Student record" << endl
         << "2-View all student record" << endl
         << "3-search student from record" << endl
         << "4-Update Student data" << endl
         << "5-Delete student data" << endl
         << "6-Total Record" << endl
         << "7-exit" << endl;

    cout << "-----------------------------------------" << endl;

    cin >> choice;

    switch (choice)
    {
    case '1':
        cin.ignore();
        obj.addStu();
        break;

    case '2':
        cin.ignore();
        obj.viewStu();
        break;

    case '3':
        cin.ignore();
        obj.searchStu();
        break;

    case '4':
        cin.ignore();
        obj.updateStu();
        break;

    case '5':
        cin.ignore();
        obj.deletestu();
        break;

    case '6':
        cin.ignore();
        obj.stuRecord();
        break;

    case '7':
        return 0;
        break;

    default:
        cout << "Invalid Choice";
        break;
    }
}

void temp ::addStu()
{
    cout << "Enter Student Roll No. : ";
    getline(cin, roll_no);

    cout << "Enter Student Name : ";
    getline(cin, name);

    cout << "Enter Student Fathers Name : ";
    getline(cin, fName);

    cout << "Enter Student Address : ";
    getline(cin, address);

    file.open("Student_Data.txt", ios ::out | ios ::app);
    file << roll_no << "*";
    file << name << "*";
    file << fName << "*";
    file << address << "\n";
    file.close();
}

void temp ::searchStu()
{
    cout << "Enter Student Roll No. to search: ";
    getline(cin, search);

    file.open("Student_Data.txt", ios ::in);
    getline(file, roll_no, '*');
    getline(file, name, '*');
    getline(file, fName, '*');
    getline(file, address, '\n');

    while (!file.eof())
    {
        if (roll_no == search)
        {
            cout << "Student Roll No. : " << roll_no << endl;
            cout << "Student Name : " << name << endl;
            cout << "Student fathers name : " << fName << endl;
            cout << "Student Address : " << address << endl;
        }
        getline(file, roll_no, '*');
        getline(file, name, '*');
        getline(file, fName, '*');
        getline(file, address, '\n');
    }
    file.close();
}

void temp ::viewStu()
{
    file.open("Student_Data.txt", ios ::in);
    getline(file, roll_no, '*');
    getline(file, name, '*');
    getline(file, fName, '*');
    getline(file, address, '\n');

    // u have to implement a loop to print all the fields

    while (!file.eof())
    {
        cout << "\n";
        cout << "Student Roll No. : " << roll_no << endl;
        cout << "Student Name : " << name << endl;
        cout << "Student fathers name : " << fName << endl;
        cout << "Student Address : " << address << endl;

        getline(file, roll_no, '*');
        getline(file, name, '*');
        getline(file, fName, '*');
        getline(file, address, '\n');
    } // last entry is missing

    file.close();
}

void temp ::updateStu()
{
    cout << "Enter Student Roll No. to update : ";
    string updateRollNumber;
    getline(cin, updateRollNumber);

    file.open("Student_Data.txt", ios::in);
    ofstream tempFile("Temp_Student_Data.txt");
    getline(file, roll_no, '*');
    getline(file, name, '*');
    getline(file, fName, '*');
    getline(file, address, '\n');

    while (!file.eof())
    {
        if (roll_no == updateRollNumber)
        {
            cout << "Enter Student Name : ";
            getline(cin, name);

            cout << "Enter Student Fathers Name : ";
            getline(cin, fName);

            cout << "Enter Student Address : ";
            getline(cin, address);
        }

        tempFile << roll_no << "*";
        tempFile << name << "*";
        tempFile << fName << "*";
        tempFile << address << endl;

        getline(file, roll_no, '*');
        getline(file, name, '*');
        getline(file, fName, '*');
        getline(file, address, '\n');
    }
    file.close();
    tempFile.close();

    remove("Student_Data.txt");
    rename("Temp_Student_Data.txt", "Student_Data.txt");

    cout << "Student Record Updated!!!" << endl;
}

void temp ::deletestu()
{
    cout << "Enter Student Roll No. to delete : ";
    string deleteRollNumber;
    getline(cin, deleteRollNumber);

    file.open("Student_Data.txt", ios::in);
    ofstream tempFile("Temp_Student_Data.txt");
    getline(file, roll_no, '*');
    getline(file, name, '*');
    getline(file, fName, '*');
    getline(file, address, '\n');

    while (!file.eof())
    {
        if (roll_no != deleteRollNumber)
        {
            tempFile << roll_no << "*";
            tempFile << name << "*";
            tempFile << fName << "*";
            tempFile << address << endl;
        }

        getline(file, roll_no, '*');
        getline(file, name, '*');
        getline(file, fName, '*');
        getline(file, address, '\n');
    }

    file.close();
    tempFile.close();

    remove("Student_Data.txt");
    rename("Temp_Student_Data.txt", "Student_Data.txt");

    cout << "Student Record Deleted!!!" << endl;
}

void temp ::stuRecord()
{
    int count = 0;

    file.open("Student_Data.txt",ios::in);

    while (!file.eof())
    {
        count++;
        getline(file, roll_no, '*');
        getline(file, name, '*');
        getline(file, fName, '*');
        getline(file, address, '\n');
    }
    
    file.close();
    cout<<"Number of record are : "<<count-1<<endl;
}