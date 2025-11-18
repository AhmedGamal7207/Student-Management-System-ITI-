#include <iostream>
#include <string.h>
#include <limits>
#include "database_models/MyDatabase.h"
#include "services/StudentService.h"

using namespace std;
Student fill_student();
string get_input_string(string prompt);

int main()
{
    MyDatabase db;
    StudentService ss(db);    
    int choice;
    cout << "****Welcome to ITI Student Management System****" << endl << endl;

    do{
        cout << "1) Add New Student" << endl;
        cout << "2) Show All Students" << endl;
        cout << "3) Search for a Student with ID" << endl;
        cout << "4) Search for Students with Name" << endl;
        cout << "5) Update Student" << endl;
        cout << "6) Delete Student" << endl;
        cout << "7) Exit" << endl;
        cout << endl << "Your Choice: ";
        cin >> choice;

        switch(choice){
            case 1:
            {
                Student s = fill_student();
                ss.add_student(s);
                break;
            }
            case 2:
            {
                vector<Student> students = ss.get_all_students();
                break;
            } 
            case 3:
            {
                int id;
                cout << "Please enter Student ID: ";
                cin >> id;
                Student s = ss.search_student_id(id);
                break;
            }
            case 4:
            {
                string name;
                name = get_input_string("Student Name");
                vector<Student> students = ss.search_student_name(name);
                break;
            } 
            case 5:
            {
                int id;
                cout << "Please enter Student ID: ";
                cin >> id;
                Student s = ss.search_student_id(id, 0);
                if(!s.get_id()){
                    break;
                }
                string col_name;
                string new_value;

                cout << "These are the available columns in the table students, please choose a one"<<endl;
                vector<string> columns = db.get_columns_names("students", 1);
                col_name = get_input_string("Column Name");
                
                new_value = get_input_string("New Value for "+col_name);

                ss.update_student(id, col_name, new_value);
                break;
            }
            case 6:
            {
                int id;
                cout << "Please enter Student ID: ";
                cin >> id;
                ss.delete_student(id);
                break;
            }
            case 7:
            {
                break;
            }
            default:
                cout << "Please enter one of the options provided" << endl << endl;
                break;
        }
    }while(choice != 7);

    cout  << endl << endl << "****Thank You for using ITI Student Management System****" << endl;
    
    return 0;
}

Student fill_student(){

    string name;
    int age;
    string department;
    float gpa;
        
    name = get_input_string("Student Name");

    cout << "Please enter Student Age: ";
    cin >> age;

    department = get_input_string("Student Department");

    cout << "Please enter Student GPA: ";
    cin >> gpa;

    Student s(name, age, department, gpa);
    return s;
    
}

string get_input_string(string prompt){
    string s;
    cout << "Please enter "<< prompt << ": ";
    getline(cin, s);
    if(s == "")
    {
        getline(cin, s);
    }
    return s;
}


