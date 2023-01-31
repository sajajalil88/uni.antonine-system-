static int i = 0;
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<fstream>
#include<fstream>
#include <conio.h>
using namespace std;

class Parking
{
    string fName, lName;
    string carType;
    int carNumber;


public:
    void menu();
    void addVehicle();
    void deleteVehicle();
    void printvehicle(Parking p);
    void show();
    bool writeRecordToFile2(string file_name, string firstName, string lastName, string VecType, int vecNumber);


};


vector<Parking> vehicles(10);
int static totalvehicles = 0, totalcar = 0, totalbike = 0, z=0;


void Parking::menu() {
    int choice1;
    char choice;


    do
    {

        cout << "\n\n\t\t\t=======================================";
        cout << "\n\n\t\t\t======= PARKING RESERVATION SYSTEM =======";
        cout << "\n\n\t\t\t=======================================" << endl;
        cout << "1-Arrival of a vehicle" << endl;
        cout << "2-Departure of vehicle" << endl;
        cout << "3-Display  " << endl;
        cout << "4-Exit " << endl;
        cout << "\n\n\t\t\t=======================================" << endl;
        cout << "Enter your Choice : ";
        cin >> choice1;

        switch (choice1)
        {
        case 1:
            cout << "Add : " << endl;
            vehicles.at(z).addVehicle();
            break;

        case 2:
            cout << "Departure : " << endl;
            vehicles.at(z).deleteVehicle();
            break;

        case 3:
            vehicles.at(z).show();
            break;
        case 4: cout << "Exit Parking ";
        default:
            cout << "error" << endl;
        }

        cout << "\nDo you want to continue, press y/n : " << endl;
        cin >> choice;
        if (choice == 'n')
        {
            break;
        }
        else
        {
            continue;
        }

    } while (1);
}
bool Parking::writeRecordToFile2(string file_name, string firstName, string lastName, string VecType, int vecNumber) {
    ofstream file;
    file.open(file_name, ios_base::app);
    file
        << firstName << ", "
        << lastName << ", "
        << VecType << ", "
        << vecNumber << ", "
        << endl;
    file.close();
    return true;
}
void Parking::addVehicle()
{
    cout << "\n\n\t\t\t=======================================";
    cout << "\n\n\t\t\t======= PARKING RESERVATION SYSTEM =======";
    cout << "\n\n\t\t\t=======================================" << endl;
    Parking* p = new Parking;
    cout << "enter your first name:" << endl;
    cin >> p->fName;
    cout << "enter your last name:" << endl;
    cin >> p->lName;
    cout << "Enter vehicle type (car / bike) : ";
    cin >> p->carType;
    cout << "Enter vehicle number : ";
    cin >> p->carNumber;

    vehicles.at(z).fName = p->fName;
    vehicles.at(z).lName = p->lName;
    vehicles.at(z).carType = p->carType;
    vehicles.at(z).carNumber = p->carNumber;

    bool writeFile = writeRecordToFile2("VehicleInfo.txt", p->fName, lName, p->carType, p->carNumber);
   
    totalvehicles++;

    if (p->carType == "car")
    {
        totalcar++;
    }
    else
    {
        totalbike++;
    }

    cout << "\nVehicle added successfully" << endl;
}


void Parking::deleteVehicle()
{
    cout << "\n\n\t\t\t=======================================";
    cout << "\n\n\t\t\t======= PARKING RESERVATION SYSTEM =======";
    cout << "\n\n\t\t\t=======================================" << endl;
    string type;
    int number;

    cout << "Enter your vehicle type(car / bike): ";
    cin >> type;
    cout << "Enter your vehicle number : ";
    cin >> number;



    for (int j = 0; j <= z; j++)
    {
        if ((vehicles.at(j).carNumber == number) && (vehicles.at(j).carType == type))
        {
            if (vehicles.at(j).carType == "car" || vehicles.at(j).carType == "Car")
            {
                totalcar--;

            }
            else
            {
                totalbike--;


            }
            z--;
            totalvehicles--;
            break;

        }

        if (j == z)
        {
            cout << "\nWrong Entry , Try Again " << endl;
            cout << "Departure : " << endl;
            deleteVehicle();
        }

    }



}


void Parking::printvehicle(Parking p)
{

    cout << p.fName << " " << p.lName << "\t\t\t" << p.carType << "\t\t\t" << p.carNumber << endl;
}

void Parking::show()
{

    cout << "Full Name\t\tVehicle Type\t\tVehicle Number" << endl;
    for (int j = 0; j < z; j++)
    {
        printvehicle(vehicles[j]);
    }
}

void totalveh()
{
    cout << "Total number of vehicle parked : " << totalvehicles << endl;
    cout << "Total number of car parked : " << totalcar << endl;
    cout << "Total number of bike parked : " << totalbike << endl;

}
class Dorm
{
private:

    struct Node
    {
        int id, semester;
        string firstName, lastName, roomType;
        Node* next;
    };

public:
    Node* head = NULL;
    void menu();
    void insert();
    void search();
    void update();
    void cancel();
    void sort();
    void show();
    bool writeRecordToFile3(string file_name, int id, string firstName, string lastName, int semester, string roomType);
};

void Dorm::menu() {
    // system("cls");
    int choice = 0;
    while (choice != 6) {
        cout << "\n";
        cout << "\n\n\t\t\t=======================================";
        cout << "\n\n\t\t\t======= DORM MANAGMENT SYSTEM =======";
        cout << "\n\n\t\t\t=======================================";
        cout << "\n1-Allocate Room\t\t\t\t\t\t\tInsert new Room";
        cout << "\n2-Search Room\t\t\t\t\t\t\tSearch Room using ID";
        cout << "\n3-Update Room\t\t\t\t\t\t\tUpdate Room Record";
        cout << "\n4-Delete Room\t\t\t\t\t\t\tDelete Room using ID";
        cout << "\n5-Show Room Records\t\t\t\t\t\tShow Room Records that we Added";
        cout << "\n6- Exit" << endl;
        cout << "Enter Your Choice" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            insert();
            break;
        case 2:
            search();
            break;
        case 3:
            update();
            break;
        case 4:
            cancel();
            break;
        case 5:
            sort();
            show();
            break;
        case 6:
            cout << "EXIT LIBRARY " << endl;
        default:
            cout << "\n\n Invalid choice ... Please try again .....";
        }

    }

}
bool Dorm::writeRecordToFile3(string file_name, int id, string firstName, string lastName, int semester, string roomType) {
    ofstream file;
    file.open(file_name, ios_base::app);
    file
        << id << ", "
        << firstName << ", "
        << lastName << ", "
        << semester << ", "
        << roomType << ", "
        << endl;
    file.close();
    return true;
}
void Dorm::insert()
{
    cout << "\n\n\t\t\t=======================================";
    cout << "\n\n\t\t\t======= DORM MANAGMENT SYSTEM =======";
    cout << "\n\n\t\t\t=======================================";
    Node* new_node = new Node;

    cout << "\n enter room ID:" << endl;
    cin >> new_node->id;

    cout << "\n enter your firstName:" << endl;
    cin >> new_node->firstName;

    cout << "\n enter your lastName:" << endl;
    cin >> new_node->lastName;

    cout << "\n enter your current semester:" << endl;
    cin >> new_node->semester;

    cout << "\n enter room type(single/double):" << endl;
    cin >> new_node->roomType;
    bool writeFile = writeRecordToFile3("DormInfo.txt", new_node->id, new_node->firstName, new_node->lastName, new_node->semester, new_node->roomType);
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        Node* ptr;
        ptr = head;

        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
    cout << "\n\n\t\t New Room Inserted";
}





void Dorm::search()
{
    cout << "\n\n\t\t\t=======================================";
    cout << "\n\n\t\t\t======= DORM MANAGMENT SYSTEM =======";
    cout << "\n\n\t\t\t=======================================";
    int t_id;

    if (head == NULL)
    {
        cout << "\n\n Linked List is Empty";
    }
    else
    {
        cout << "\n Room ID:";
        cin >> t_id;

        Node* ptr;
        ptr = head;

        while (ptr != NULL)
        {
            if (t_id == ptr->id)
            {
                cout << "\n\n Room ID :" << ptr->id;
                cout << "\n\n Student Name:" << ptr->firstName << " " << ptr->lastName;
                cout << "\n\n  Current Semester :" << ptr->semester;
                cout << "\n\n Room Type :" << ptr->roomType;
            }
            ptr = ptr->next;
        }
    }

}





void Dorm::update()
{
    cout << "\n\n\t\t\t=======================================";
    cout << "\n\n\t\t\t======= DORM MANAGMENT SYSTEM =======";
    cout << "\n\n\t\t\t=======================================";

    int t_id;

    if (head == NULL)
    {
        cout << "\n\n Linked List is Empty";
    }
    else
    {
        cout << "\n Room ID:";
        cin >> t_id;

        Node* ptr;
        ptr = head;

        while (ptr != NULL)
        {
            if (t_id == ptr->id)
            {
                cout << "\n enter room ID:" << endl;
                cin >> ptr->id;

                cout << "\n enter your firstName:" << endl;
                cin >> ptr->firstName;

                cout << "\n enter your lastName:" << endl;
                cin >> ptr->lastName;

                cout << "\n enter your current semester:" << endl;
                cin >> ptr->semester;

                cout << "\n enter room type(single/double):" << endl;
                cin >> ptr->roomType;

                cout << "\n\n\t\t Update Record Successfully";
            }
            ptr = ptr->next;
        }
    }

}

void Dorm::cancel()
{
    cout << "\n\n\t\t\t=======================================";
    cout << "\n\n\t\t\t======= DORM MANAGMENT SYSTEM =======";
    cout << "\n\n\t\t\t=======================================";

    int t_id;

    if (head == NULL)
    {
        cout << "\n\n Linked List is Empty";
    }
    else {
        cout << "\n\n Room ID:" << endl;
        cin >> t_id;

        if (t_id == head->id)
        {
            Node* ptr = head;
            head = head->next;
            delete ptr;

            cout << "Room deleted Successfully\n";
        }
        else
        {
            Node* pre = head;
            Node* ptr = head;

            while (ptr != NULL)
            {
                if (t_id == ptr->id)
                {
                    pre->next = ptr->next;
                    delete ptr;
                    cout << "Deletion Succeded";
                    break;
                }
                pre = ptr;
                ptr = ptr->next;
            }
        }
    }

}

void Dorm::show()
{
    Node* ptr = head;
    while (ptr != NULL)
    {
        cout << "\n\nRoom ID:" << ptr->id;
        cout << "\n\n Student Name:" << ptr->firstName << " " << ptr->lastName;
        cout << "\n\n  Current Semester :" << ptr->semester;
        cout << "\n\n Room Type :" << ptr->roomType;
        ptr = ptr->next;
    }

}

void Dorm::sort()
{
    if (head == NULL)
    {
        cout << "\n\n Linked List is Empty";
        menu();
    }
    int count = 0, t_sem, t_id;
    string t_fname, t_lname, t_roomType;
    Node* ptr = head;

    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    for (int i = 1; i <= count; i++)
    {
        Node* ptr = head;
        for (int j = 1; j < count; j++)
        {
            if (ptr->id > ptr->next->id)
            {
                t_id = ptr->id;
                t_fname = ptr->firstName;
                t_lname = ptr->lastName;
                t_sem = ptr->semester;
                t_roomType = ptr->roomType;

                //save date on cur Node
                ptr->id = ptr->next->id;
                ptr->firstName = ptr->next->firstName;
                ptr->lastName = ptr->next->lastName;
                ptr->semester = ptr->next->semester;
                ptr->roomType = ptr->next->roomType;

                //save Date into next Node
                ptr->next->id = t_id;
                ptr->next->firstName = t_fname;
                ptr->next->lastName = t_lname;
                ptr->next->semester = t_sem;
                ptr->next->roomType = t_roomType;

            }
        }
    }
}
class library
{
private:
    struct node {
        int id;
        string name, author, publisher;
        node* next;
    };
public:
    node* head = NULL;
    void menu();
    void insert();
    void search();
    void update();
    void cancel();
    void sort();
    void show();
    bool writeRecordToFile(string file_name, int id, string name, string author, string publisher);
};

void library::menu() {


    int choice = 0;
    while (choice != 6) {
        cout << "\n\n\t\t\t=======================================";
        cout << "\n\n\t\t\t======= LIBRARY MANAGMENT SYSTEM =======";
        cout << "\n\n\t\t\t=======================================";
        cout << "\n 1-Insert New Record \t\t\t\t\t\t Add a new book";
        cout << "\n 2-Search Record \t\t\t\t\t\t Search for a book";
        cout << "\n 3-Update Record \t\t\t\t\t\t update a book details";
        cout << "\n 4-Delete Record \t\t\t\t\t\t Add delete a book";
        cout << "\n 5-Show All Record \t\t\t\t\t\t show all books";
        cout << "\n 6-Exit ";
        cout << "\n Enter a value of your choice : ";
        cin >> choice;
        switch (choice) {
        case 1:
            insert();
            break;
        case 2:
            search();
            break;
        case 3:
            update();
            break;
        case 4:
            cancel();
            break;
        case 5:
            sort();
            show();
            break;
        case 6:
            cout << "EXIT LIBRARY " << endl;
        default:
            cout << "\n\n Invalid choice ... Please try again .....";
        }
    }

}
bool library::writeRecordToFile(string file_name, int id, string name, string author, string publisher) {
    ofstream file;
    file.open(file_name, ios_base::app);
    file
        << id << ", "
        << name << ", "
        << author << ", "
        << publisher << ", "
        << endl;
    file.close();
    return true;
}
void library::insert() {
    cout << "\n\n\t\t\t=======================================";
    cout << "\n\n\t\t\t======= LIBRARY MANAGMENT SYSTEM =======";
    cout << "\n\n\t\t\t=======================================";
    node* temp = new node;
    cout << "\n\n Book ID: ";
    cin >> temp->id;
    cout << "\n\n Name :";
    cin >> temp->name;
    cout << "\n\n Author Name: ";
    cin >> temp->author;
    cout << "\n\n Publisher Name: ";
    cin >> temp->publisher;
    bool writeFile = writeRecordToFile("libraryInfo.txt", temp->id, temp->name, temp->author, temp->publisher);
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
    }
    else {
        node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = temp;
        // current=temp ;
    }
    cout << "\n\n\t\t New Book Inserted Successfully.... ";

}

void library::search() {
    int t_id, found = 0;
    bool isFound = false;
    cout << "\n\n\t\t\t=======================================";
    cout << "\n\n\t\t\t======= LIBRARY MANAGMENT SYSTEM =======";
    cout << "\n\n\t\t\t=======================================";
    if (head == NULL) {
        cout << "\n\n Linked List Is Empty...";
    }
    else {
        cout << "\n\n Book ID: ";
        cin >> t_id;
        node* current = head;
        while (current != NULL) {
            if (t_id == current->id)
            {
                cout << "\n\n\t\t\t=======================================";
                cout << "\n\n\t\t\t======= LIBRARY MANAGMENT SYSTEM =======";
                cout << "\n\n\t\t\t=======================================";
                isFound = true;
                cout << "\n\n Book ID: " << current->id;
                cout << "\n\n Name :" << current->name;
                cout << "\n\n Author Name: " << current->author;
                cout << "\n\n Publisher Name: " << current->publisher;
                found++;
            }
            current = current->next;
        }
        if (!(isFound)) {
            cout << "\n\n Book ID is Invalid ......";
        }

    }
}
void library::update() {
    int t_id, found = 0;
    bool isFound = false;
    cout << "\n\n\t\t\t=======================================";
    cout << "\n\n\t\t\t======= LIBRARY MANAGMENT SYSTEM =======";
    cout << "\n\n\t\t\t=======================================";
    if (head == NULL) {
        cout << "\n\n Linked List Is Empty...";
    }
    else {
        cout << "\n\n Book ID: ";
        cin >> t_id;
        node* current = head;
        while (current != NULL) {
            if (t_id == current->id)
            {
                cout << "\n\n\t\t\t=======================================";
                cout << "\n\n\t\t\t======= LIBRARY MANAGMENT SYSTEM =======";
                cout << "\n\n\t\t\t=======================================";
                isFound = true;
                cout << "\n\n Book ID: ";
                cin >> current->id;
                cout << "\n\n Name :";
                cin >> current->name;
                cout << "\n\n Author Name: ";
                cin >> current->author;
                cout << "\n\n Publisher Name: ";
                cin >> current->publisher;
                found++;
                cout << "\n\n\t\t Update Book Successfully ... ";
            }
            current = current->next;
        }
        if (!(isFound)) {
            cout << "\n\n Book ID is Invalid ......";
        }

    }
}
void library::cancel() {
    int tId = 0, found = 0;
    cout << "\n\n\t\t\t=======================================";
    cout << "\n\n\t\t\t======= LIBRARY MANAGMENT SYSTEM =======";
    cout << "\n\n\t\t\t=======================================";
    if (head == NULL) {
        cout << "\n\n Linked List Is Empty...";
    }
    else {
        if (tId == head->id) {
            node* current = head;
            head = head->next;
            delete current;
            cout << "\n\n Delete Book Successfully.....";
            found++;
        }
        else {
            node* pre = head;
            node* current = head;
            while (current != NULL) {
                if (tId == current->id)
                {
                    pre->next = current->next;
                    delete current;
                    cout << "Delete Book Successfully .....";
                    found++;
                    break;
                }
                pre = current;
                current = current->next;

            }
        }
        if (found == 0)
            cout << "\n\n Book ID is Invalid ......";
    }
}
void library::sort() {

    if (head == NULL)
    {
        system("cls");
        cout << "\n\n\t\t\t=======================================";
        cout << "\n\n\t\t\t======= LIBRARY MANAGMENT SYSTEM =======";
        cout << "\n\n\t\t\t=======================================";
        cout << "\n\n Linked List is empty ....";
        //getch();
        menu();
    }
    else {
        int count = 0, t_id;
        string t_name, t_author, t_publisher;
        node* current = head;
        while (current != NULL) {
            count++;
            current = current->next;
        }
        for (int i = 1; i <= count; i++) {
            node* current = head;
            for (int j = 1; j < count; j++) {
                if (current->id > current->next->id) {
                    // save data in temp 
                    t_id = current->id;
                    t_name = current->name;
                    t_author = current->author;
                    t_publisher = current->publisher;
                    // save data in current node 
                    current->id = current->next->id;
                    current->name = current->next->name;
                    current->author = current->next->author;
                    current->publisher = current->next->publisher;
                    // save data in next node 
                    current->next->id = t_id;
                    current->next->name = t_name;
                    current->next->author = t_author;
                    current->next->publisher = t_publisher;
                }
                current = current->next;
            }
        }
    }
}
void library::show() {
    int t_id, found = 0;
    bool isFound = false;
    cout << "\n\n\t\t\t=======================================";
    cout << "\n\n\t\t\t======= LIBRARY MANAGMENT SYSTEM =======";
    cout << "\n\n\t\t\t=======================================";
    if (head == NULL) {
        cout << "\n\n Linked List Is Empty...";
    }
    else {
        cout << "\n\n Book ID: ";
        cin >> t_id;
        node* current = head;
        while (current != NULL) {
            cout << "\n\n Book ID: " << current->id;
            cout << "\n\n Name :" << current->name;
            cout << "\n\n Author Name: " << current->author;
            cout << "\n\n Publisher Name: " << current->publisher;
            cout << "\n\n\t\t\t=======================================";
            current = current->next;
        }

    }
}

struct teacher {
    int id;
    char tFName[30];
    char tLName[30];
    char email[30];
    char speciality[30];
};
struct course {

    char CourseName[15];
    int CourseYear;
    int NbOfCredits;
    double grade;
    teacher* t;
};
struct student {
    int id;
    int n;
    char firstName[20];
    char lastName[20];
    int phoneNumber;
    char address[20];
    double GPA;
    int nbCourses;
    course* c;
};
int getNumberOfStudents() {
    static int i = 0;
    i++;
    return i;
}
bool writeRecordToFile4(string file_name, int id, string name, string lastName, string address, int phoneNumber, double GPA) {
    ofstream file;
    file.open(file_name, ios_base::app);
    file
        << id << ", "
        << name << ", "
        << lastName << ", "
        << address << ", "
        << phoneNumber << ", "
        << GPA << ", "

        << endl;
    file.close();
    return true;
}
void RegiterStudents(student* s) {
    s[i].id = 20220001 + i;
    cout << "enter student firstName:" << endl;
    cin >> s[i].firstName;
    cout << "enter student lastName:" << endl;
    cin >> s[i].lastName;
    cout << "enter student address" << endl;
    cin >> s[i].address;
    cout << "enter student phoneNumber:" << endl;
    cin >> s[i].phoneNumber;
    cout << "enter student GPA:" << endl;
    cin >> s[i].GPA;
    cout << "please enter the number of courses:" << endl;
    cin >> s[i].nbCourses;
    s[i].c = new course[s[i].nbCourses];
    for (int j = 0; j < s[i].nbCourses; j++)
    {
        cout << "enter course name:" << endl;
        cin >> s[i].c[j].CourseName;
        cout << "enter course year:" << endl;
        cin >> s[i].c[j].CourseYear;
        cout << "enter NbOfCredits:" << endl;
        cin >> s[i].c[j].NbOfCredits;
        cout << "enter course grade:" << endl;
        cin >> s[i].c[j].grade;
        s[i].c[j].t = new teacher[1];
        for (int k = 0; k < 1; k++) {
            cout << "Enter Teacher's Full Name ";
            cin >> s[i].c[j].t[k].tFName;
            cin >> s[i].c[j].t[k].tLName;
            cout << "Enter Teacher's Email Address ";
            cin >> s[i].c[j].t[k].email;
            cout << "Enter Teacher's Speciality ";
            cin >> s[i].c[j].t[k].speciality;
        }
    }
    bool writeFile = writeRecordToFile4("StudentInfo.txt", s[i].id, s[i].firstName, s[i].lastName, s[i].address, s[i].phoneNumber, s[i].GPA);
    i++;
  
    s->n = i;
   
    cout << "Student added successfully " << endl;
}
void DisplayStudents(student* s) {
    int x = i ;
    for (int i = 0; i <x; i++)
    {

        cout << "ID:" << s[i].id << endl;
        cout << "Full Name :" << s[i].firstName << " " << s[i].lastName << endl;
        cout << "Address:" << s[i].address << endl;
        cout << "phoneNumber :" << s[i].phoneNumber << endl;
        cout << "GPA:" << s[i].GPA << endl;

        for (int j = 0; j < s[i].nbCourses; j++)
        {
            cout << "Course Name:" << s[i].c[j].CourseName << endl;
            cout << "Course Year :" << s[i].c[j].CourseYear << endl;
            cout << "Number of Credits :" << s[i].c[j].NbOfCredits << endl;
            cout << "Course Grade:" << s[i].c[j].grade << endl;

            for (int k = 0; k < 1; k++) {
                cout << "Teacher's Full Name " << s[i].c[j].t[k].tFName << s[i].c[j].t[k].tLName << endl;
                cout << "Teacher's Email Address " << s[i].c[j].t[k].email << endl;
                cout << "Teacher's Speciality " << s[i].c[j].t[k].speciality << endl;
            }
        }
    }
}
void displayInfo(student* st) {
    cout << "ID: " << st->id << endl;
    cout << "name:";
    cout << st->firstName << " " << st->lastName << endl;
    cout << "phoneNumber: "; cout << st->phoneNumber << endl;
    cout << "Address: "; cout << st->address << endl;
    cout << "GPA: "; cout << st->GPA << endl;
}
void displayCourseDetails(course* c) {
    cout << "Course Name:" << c->CourseName << endl;
    cout << "Course Year :" << c->CourseYear << endl;
    cout << "Number of Credits :" << c->NbOfCredits << endl;
    cout << "Course Grade:" << c->grade << endl;
}
int SearchById(student* st) {

    bool isfound = false;
    int ids;
    student* std = NULL;
    int position = -1;
    cout << "enter id for student you're searching for :" << endl;
    cin >> ids;
    for (int i = 0; i < st->n; i++)
    {
        if (ids == st[i].id)
        {
            std = &st[i];
            position = i;
            isfound = true;

        }
    }

    if (isfound) {
        cout << "The student is found: " << endl;
        // cout << std;
        displayInfo(std);
    }
    else
    {
        cout << "The student is not found " << endl;

    }
    return position;

}
void modifyStudentById(student* s) {
    int found = SearchById(s);
    cout << endl;
    if (found != -1) {
        cout << "enter student firstName:" << endl;
        cin >> s->firstName;
        cout << "enter student lastName:" << endl;
        cin >> s->lastName;
        cout << "enter  student address" << endl;
        cin >> s->address;
        cout << "enter student phoneNumber:" << endl;
        cin >> s->phoneNumber;
        cout << "enter student GPA:" << endl;
        cin >> s->GPA;
        cout << "please enter the number of courses:" << endl;
        cin >> s->nbCourses;
        s->c = new course[s->nbCourses];
        for (int j = 0; j < s->nbCourses; j++)
        {
            cout << "enter course name:" << endl;
            cin >> s->c[j].CourseName;
            cout << "enter course year:" << endl;
            cin >> s->c[j].CourseYear;
            cout << "enter NbOfCredits:" << endl;
            cin >> s->c[j].NbOfCredits;
            cout << "enter course grade:" << endl;
            cin >> s->c[j].grade;
            s->c[j].t = new teacher[1];
            for (int k = 0; k < 1; k++) {
                cout << "Enter Teacher's Full Name ";
                cin >> s->c[j].t[k].tFName;
                cin >> s->c[j].t[k].tLName;
                cout << "Enter Teacher's Email Address ";
                cin >> s->c[j].t[k].email;
                cout << "Enter Teacher's Speciality ";
                cin >> s->c[j].t[k].speciality;
            }
        }
    }
    else
        cout << "Student not found " << endl;
}
void isProbation(student* s) {
    char fname[20];
    char lname[20];
    cout << "enter student full name" << endl;
    cin >> fname;
    cin >> lname;

    bool isfound = false;
    for (int i = 0; i < s->n; i++)
    {
        if (strcmp(fname, s[i].firstName) == 0 && strcmp(lname, s[i].lastName) == 0)
        {
            isfound = true;
            if (s[i].GPA < 1)
            {
                cout << "you are in an academic probation" << endl;
            }
            else {
                cout << "you are not in an academic probation" << endl;
            }
        }

    }
    if (isfound)
        cout << "";
    else
        cout << "student not found " << endl;
}
void studentWithHonor(student* s) {
    int max = 0;
    student* std = NULL;
    for (int i = 0; i < s->n; i++)
    {
        if (s[i].GPA > max)
        {
            max = s[i].GPA;
            std = &s[i];
            displayInfo(std);
        }
    }
}
void ViewGrades(student* s) {
    char fname[20], lname[20];
    cout << "enter student full name" << endl;
    cin >> fname;
    cin >> lname;
    int sum;
    bool isfound = false;

    for (int i = 0; i < s->n; i++)
    {
        if (strcmp(fname, s[i].firstName) == 0 && strcmp(lname, s[i].lastName) == 0)
        {
            isfound = true;
            for (int j = 0; j < s[i].nbCourses; j++)
            {
                cout << s[i].c[j].CourseName << " : " << s[i].c[j].grade << endl;
            }
        }

    }
    if (isfound)
        cout << "";
    else
        cout << "student not found " << endl;

}
int TotalCredits(student* s) {
    char fname[20], lname[20];
    cout << "enter student full name to find total credits" << endl;
    cin >> fname;
    cin >> lname;
    int nb = 0;
    bool isfound = false;
    for (int i = 0; i < s->n; i++)
    {
        if (strcmp(s[i].firstName, fname) == 0 && strcmp(s[i].lastName, lname) == 0)
        {
            isfound = true;
            for (int j = 0; j < s[i].nbCourses; j++)
            {
                nb += s[i].c[j].NbOfCredits;
            }
        }
    }
    if (isfound)
        return nb;
    else
        return -1;
}
void viewpayments(student* s) {
    char fname[20], lname[20];

    cout << "\nenter student full name to find total payments" << endl;
    cin >> fname;
    cin >> lname;
    int nb = 0;
    double cost;
    bool isfound = false;
    for (int i = 0; i < s->n; i++)
    {
        if (strcmp(s[i].firstName, fname) == 0 && strcmp(s[i].lastName, lname) == 0)
        {
            isfound = true;
            for (int j = 0; j < s[i].nbCourses; j++)
            {
                if (s[i].c[j].NbOfCredits > 0 && s[i].c[j].NbOfCredits < 20)
                {
                    cost += 2000;
                }
                else if (s[i].c[j].NbOfCredits >= 20 && s[i].c[j].NbOfCredits <= 30)
                {
                    cost += 3000;
                }

            }
        }
        if (s[i].GPA > 3.5)
        {
            cost -= 500;
            cout << "you got a discount for gpa above 3.5" << endl;
        }

    }
    if (isfound) {
        cout << " the total payment is :" << cost << "$";
    }
    else
    {
        cout << " student is not found";
    }
}
bool isEnrolled(student* s) {
    course* courses;
    char course[30];
    int search = SearchById(s);
    if (search != -1) {
        cout << "Enter the name of the course that you are searching for " << endl;
        cin.getline(course, 30);
        for (int i = 0; i < s->n; i++) {
            for (int j = 0; j < s[i].nbCourses; j++) {
                if (strcmp(course, s[i].c[j].CourseName) == 0) {
                    courses = &s[i].c[j];
                    displayCourseDetails(courses);
                    return true;
                }
            }
        }
        return false;
    }
    else
        return false;
}
void dropSemester(student* s) {

    int drop = SearchById(s);
    if (drop == -1)
    {
        return;
    }
    else {

        for (int i = drop; i < (s->n) - 1; i++)
        {
            s[i] = s[i + 1];
        }
        (s->n)--;
        cout << "Semester dropped " << endl;
    }
}
int searchCourse(student* st) {
    bool isfound = false;
    bool isFoundID = false;
    char nameCourse[30];
    int ids;
    student* std = NULL;
    int position = -1;
    cout << "enter id for student you're searching for :" << endl;
    cin >> ids;
    cin.ignore();
    for (int i = 0; i < st->n; i++)
    {
        if (ids == st[i].id)
        {
            std = &st[i];
            isFoundID = true;
            cout << "enter course name you are searching for " << endl;
            cin.getline(nameCourse, 30);
            for (int j = 0; j < st->nbCourses; j++) {
                if (strcmp(nameCourse, st[i].c[j].CourseName) == 0)
                {
                    position = i;
                    isfound = true;
                }
            }

        }
    }

    if (isFoundID && isfound) {
        cout << "The course is found for:  " << endl;
        displayInfo(std);
    }
    else if (isFoundID == true && isfound == false)
    {
        cout << "The student is not enrolled in  " << nameCourse << endl; ;
    }
    else {
        cout << "The student with the id is not found " << endl;
    }
    return position;
}
void dropCourse(student* s) {

    int drop = searchCourse(s);
    if (drop == -1)
    {
        return;
    }
    else {
        for (int i = drop; i < (s->n) - 1; i++) {
            for (int j = drop; j < (s->nbCourses) - 1; j++) {
                s[i].c[j] = s[i].c[j + 1];
            }
            (s->nbCourses)--;
        }

        cout << "course dropped " << endl;
    }
}

void menuStudent() {
    int isenrolled = 0;
    int choice = 0;
    int n = 100;
    student* students = new student[n];

    while (choice != 11) {
        cout << "\n\n\t\t\t=======================================";
        cout << "\n\n\t\t\t======= STUDENT MANAGMENT SYSTEM =======";
        cout << "\n\n\t\t\t=======================================";
        cout << endl;
        cout << "1-Enroll student \t\t\t\t\t\t Apply here  " << endl;
        cout << "2-Search for a student file \t\t\t\t\t Search for a student by id  " << endl;
        cout << "3-Modify the information of the student \t\t\t modify student information by id " << endl;
        cout << "4-Check if student is enrolled in specific course  \t\t check if student is enrolled  by full name " << endl;
        cout << "5-Checks if a student is in probation or not \t\t\t check if student is in probation by full name " << endl;
        cout << "6-Student with Honor section \t\t\t\t\t check the student with the highest GPA " << endl;
        cout << "7-Check for payemnts and discounts \t\t\t\t check payments by entering the full name " << endl;
        cout << "8-Drop a Semester \t\t\t\t\t\t enter id " << endl;
        cout << "9-Drop a course  \t\t\t\t\t\t enter id and course name " << endl;
        cout << "10-Print the list of all students \t\t\t\t Display Student Files " << endl;
        cout << "11-Exit :) \t\t\t\t\t\t\t Thank you for your visit " << endl;
        cout << "\n\n\t\t\t=======================================";
        cout << endl;
        cout << endl;
        cout << "Enter a choice from the list above " << endl;
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
            getNumberOfStudents();
            RegiterStudents(students);
            cout << "Students is enrolled, you can check the information entered in the section below " << endl;
            break;
        case 2:
            SearchById(students);
            break;
        case 3:
            modifyStudentById(students);
            break;
        case 4:
            isenrolled = isEnrolled(students);
            if (isenrolled == 1)
                cout << "the student is enrolled " << endl;
            else
                cout << "the student is not enrolled " << endl;
            break;
        case 5:
            isProbation(students);
            break;
        case 6:
            studentWithHonor(students);
            break;
        case 7:
            viewpayments(students);
            break;
        case 8:
            dropSemester(students);
            break;
        case 9:
            dropCourse(students);
            break;
        case 10:
            DisplayStudents(students);
            break;
        case 11:
            cout << "exit " << endl;
            break;
        default:
            cout << "Enter a choice from the mentioned above only " << endl;
        }
    }
}
int main()
{
    Dorm d;
    Parking p;
    library l;
    int choice1 = 0;
    while (choice1 != 5) {
        cout << "\n\n\t\t\t=======================================";
        cout << "\n\n\t\t\t======= UNIVERSITY MANAGMENT SYSTEM =======";
        cout << "\n\n\t\t\t=======================================";
        cout << endl;
        cout << "1-SIS" << endl;
        cout << "2-LIBRARY" << endl;
        cout << "3-PARKING" << endl;
        cout << "4-DORMS" << endl;
        cout << "5-EXIT" << endl;
        cout << "enter a choice " << endl;
        cin >> choice1;
        switch (choice1) {
        case 1:
            menuStudent();
            break;
        case 2:
            l.menu();
            break;
        case 3:
            p.menu();
            break;
        case 4:
            d.menu();
            break;
        case 5:
            cout << "EXIT SIS " << endl;
            break;
        default:
            cout << "Enter one of the choices " << endl;
        }

    }


}








