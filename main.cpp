//Created By KATLEHO KHOSI 2024-09-23

#include <iostream>
#include <fstream>
#include <iomanip>
#include <random>
#include <ctime>
#include <memory>

using namespace std;

struct Student
{
    string Name;
    int Age;
    int Student_ID;
    int Module_Mark;
};


struct Course
{
    string Course_Name;
    string Faculty;
    string Course_ID;
};


class CourseSelection
{
    public:
        string Course_Name;
        string Course_ID;
        string Faculty;
        int choice, CourseOption;



    int assignCourse(Student* student, Course* course, int& count)
    {
        cout << "Faculties available:" << endl;
        cout << "1. Faculty of Computer Sciences" << endl;
        cout << "2. Faculty of Business " << endl;
        cout << "3. Faculty of Engineering " << endl;
        cout << "4. Facutly of Health Sciences " << endl;
        cout << endl;
        cout << "Enter your selection here: ";
        cin >> choice;

        while (cin.fail() || (choice > 4 && choice < 1))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "The choices for faculties are from 1 to 4 for now, Sorry for the inconvenience" << endl;
            cout << "Enter your selection here: ";
            cin >> choice;
        }


        switch (choice)
        {
            case 1:
                (*(course + count)).Faculty = "Faculty of Computer Sciences";
                break;

            case 2:
                (*(course + count)).Faculty = "Faculty of Business";
                break;

            case 3:
                (*(course + count)).Faculty = "Faculty of Engineering";
                break;

            case 4:
                (*(course + count)).Faculty = "Facutly of Health Sciences";
                break;
        }

        return choice;
    }


        void course(Student* student, Course* course, int& count, int option)
        {
            switch (choice)
        {
            case 1:
                cout << "\nAvailable Courses: " << (*(course + count)).Faculty << endl;
                cout << "1. Introduction to programming" << endl;
                cout << "2. Data Structures and Algorithms" << endl;
                cout << "3. Web Development Basics" << endl;

                cout << "Choose desired course: ";
                cin >> CourseOption;

                while (cin.fail() || (CourseOption > 3 && CourseOption < 1))
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cerr << "The choices for courses are from 1 to 3..." << endl;
                    cout << "Choose desired course: ";
                    cin >> CourseOption;
                }


                switch (CourseOption)
                {
                    case 1:
                        (*(course + count)).Course_Name = "IntroductionToProgramming";
                        break;

                    case 2:
                        (*(course + count)).Course_Name = "DataStructuresandAlgorithms";
                        break;

                    case 3:
                        (*(course + count)).Course_Name = "WebDevelopmentBasics";
                        break;
                }
                break;

                case 2:
                cout << "\nAvailable Courses: " << (*(course + count)).Faculty << endl;
                cout << "1. Business Management" << endl;
                cout << "2. Marketing Principles" << endl;

                cout << "Choose desired course: ";
                cin >> CourseOption;

                while (cin.fail() || (CourseOption > 2 && CourseOption < 1))
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cerr << "The choices for courses are from 1 to 2..." << endl;
                    cout << "Choose desired course: ";
                    cin >> CourseOption;
                }

                switch (CourseOption)
                {
                    case 1:
                        (*(course + count)).Course_Name = "BusinessManagement";
                        break;

                    case 2:
                        (*(course + count)).Course_Name = "MarketingPrinciples";
                        break;
                }
                break;

                case 3:
                cout << "\nAvailable Courses: " << (*(course + count)).Faculty << endl;
                cout << "1. Electrical Engineering Principles" << endl;

                cout << "Choose desired course: ";
                cin >> CourseOption;

                while (cin.fail() || (CourseOption > 1 && CourseOption < 1))
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cerr << "There is only 1 choice here too for now!!!" << endl;
                    cout << "Choose desired course: ";
                    cin >> CourseOption;
                }

                switch (CourseOption)
                {
                    case 1:
                        (*(course + count)).Course_Name = "ElectricalEngineeringPrinciples";
                        break;
                }
                break;


                case 4:
                cout << "\nAvailable Courses: " << (*(course + count)).Faculty << endl;
                cout << "1. Human Anatomy" << endl;

                cout << "Choose desired course: ";
                cin >> CourseOption;

                while (cin.fail() || (CourseOption > 1 && CourseOption < 1))
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cerr << "There is only one choice for now!!!" << endl;
                    cout << "Choose desired course: ";
                    cin >> CourseOption;
                }

                switch (CourseOption)
                {
                    case 1:
                        (*(course + count)).Course_Name = "HumanAnatomy";
                        break;
                }
                break;
        }
        int Val;
        string ID = "";
            for (int i = 0; i < (*(course + count)).Course_Name.length(); i++)
            {

                char currentChar = (*(course + count)).Course_Name[i];
                if (isupper(currentChar)) {
                ID += currentChar ;
                }
            }
            Val = 111 + rand() % (999 - 111 + 1);
            (*(course + count)).Course_ID = ID + to_string(Val);
        }
};


void FileData(Student* student, Course* course, int& count) {
    ifstream file("student_data.txt");
    string line;

    if (file.fail()) {
        cerr << "Error opening the file" << endl;
        return;
    }

    while (getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        line = (line);

        size_t pos1 = line.find(' ');
        if (pos1 == string::npos) {
            continue;
        }

        try {
            int pos2 = line.find(' ', pos1 + 1);
            int pos3 = line.find(' ', pos2 + 1);
            int pos4 = line.rfind(' ');

            if (pos1 == string::npos || pos2 == string::npos || pos3 == string::npos || pos4 == string::npos) {
                continue;
            }

            (*(student + count)).Name = line.substr(0, pos1);
            (*(student + count)).Age = stoi(line.substr(pos1 + 1, pos2 - pos1 - 1));
            (*(course + count)).Course_Name = line.substr(pos4 + 1);
            (*(student + count)).Student_ID = stoi(line.substr(pos2 + 1, pos3 - pos2 - 1));

            string ID = "";
            for (char currentChar : (*(course + count)).Course_Name) {
                if (isupper(currentChar)) {
                    ID += currentChar;
                }
            }
            int Val = 111 + rand() % (999 - 111 + 1);
            (*(course + count)).Course_ID = ID + to_string(Val);

            count++;
        } catch (const invalid_argument&) {
            cerr << "Invalid data format, skipping line" << endl;
            continue;
        }
    }
    file.close();
}


void viewStudentAndCourse(Student* student, Course* course, int count)
{
    if (count < 1)
    {
        cout << "There are no students in the system" << endl;
    }
    else{
        cout << "****Student and Course Details****" << endl;
        cout << "-------------------------------------------------" << endl;

        for (int i = 0; i < count; i++)
        {
            cout << (*(student + i)).Name << "\n- Age: " << (*(student + i)).Age
            << "\n- Course: " << (*(course + i)).Course_Name << "(" << (*(course + i)).Course_ID
            << ")" << endl;
            cout << endl;
        }

        cout << "-------------------------------------------------" << endl;
    }
}


void RegisterStudent(Student* student, Course* course, int& count)
{
    CourseSelection courseSelection;
    cout << "******Register a student and assign a Course******" << endl;
    cout << endl;

    string name;
    int age;

    cin.ignore();
    cout << "Enter the name and surname of student in the form (Name_Surname): ";
    getline(cin, name);

    cout << "Enter age of student: ";
    cin >> age;

    while (cin.fail() || age < 18 || age > 100)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (age < 18)
        {
            cerr << "The student is too young to register" << endl;
        }else{
            cerr << "The student cannot register" << endl;
        }
        cout << "Enter age of student: ";
        cin >> age;
    }


    srand(time(0));
    int ST_ID = 10000000 + rand() % (99999999 - 10000000 + 1);

    student[count].Name = name;
    student[count].Age = age;
    student[count].Student_ID = ST_ID;
    cout << "\n*****Assign course for the student*****" << endl;

    int option = courseSelection.assignCourse(student, course, count);
    courseSelection.course(student, course, count, option);
    cout << (*(student + count)).Name << " Has been added into the " << (*(course + count)).Faculty << endl;
    count++;
}


void viewMarkAverageCourse(Student* student, Course* course, int count)
{
    CourseSelection faculty;
    int choice;
    string Faculty;

    choice = faculty.assignCourse(student, course, count);

    switch (choice)
    {
        case 1:
            Faculty = "Faculty of Computer Sciences";
            break;
        case 2:
            Faculty = "Faculty of Business";
            break;
        case 3:
            Faculty = "Faculty of Engineering";
            break;
        case 4:
            Faculty = "Faculty of Health Sciences";
            break;
        default:
            cerr << "Invalid faculty choice." << endl;
            return;
    }

     if (count < 1)
        {
            cout << "There are  no students in the system." << endl;
        }
        else{
            cout << "Chosen: " << Faculty << endl;
            cout << "*****Course average and Student grade*****" << endl;

            cout << "-----------------------------------------------------------------" << endl;
            cout << left << setw(2) << "|" << setw(15) << "Student ID" << setw(2) << "|" << setw(15)
                 << "Name" << setw(2) << "|" << setw(15) << "Course ID" << setw(2) << "|" << setw(10)
                 << "Mark" << setw(2) << "|" << endl;
            cout << "-----------------------------------------------------------------" << endl;

            for (int i = 0; i < count; i++)
            {
                if ((*(course + i)).Faculty == Faculty)
                {
                    int val = 0 + rand() % (100 - 0 + 1);
                    (*(student + i)).Module_Mark = val;

                    cout << left << setw(2) << "|" << setw(15) << (*(student + i)).Student_ID << setw(2) << "|" << setw(15)
                         << (*(student + i)).Name << setw(2) << "|" << setw(15) << (*(course + i)).Course_ID << setw(2) << "|" << setw(10)
                         << (*(student + i)).Module_Mark << setw(2) << "|" << endl;
                }
            }

            cout << "-----------------------------------------------------------------" << endl;
    }

}



void saveData(Student* student, Course* course, int count)
{
    ofstream outFile("student_data.txt", ios::trunc);

    if (outFile.fail()) {
        cerr << "Error opening the file for writing!" << endl;
        return;
    }
    else{

            for (int i = 0; i < count; i++)
            {
                outFile << (*(student + i)).Name << " " << (*(student + i)).Age << " " << (*(student + i)).Student_ID << " " << (*(course + i)).Course_Name << endl;
            }
            cout << "Data successfully saved to the file." << endl;
            outFile.close();
        }

}




int main()
{

    const int SIZE = 100;
    int Count = 0;
    std::unique_ptr<Student[]> arrStudent = std::make_unique<Student[]>(SIZE);
    std::unique_ptr<Course[]> arrCourse = std::make_unique<Course[]>(SIZE);

    Student* pStudents = arrStudent.get();
    Course* pCourse = arrCourse.get();

    FileData(pStudents, pCourse, Count);


    int choice;
    cout << "**ADMINISTRATIVE DASHBOARD FOR STUDENT RECORDS**" << endl;
    cout << endl;

    do
    {
        cout << "Menu:" << endl;
        cout << "1. Register a student and assign courses." << endl;
        cout << "2. View students and view courses" << endl;
        cout << "3. View course , Marks and Module Mark." << endl;
        cout << "4. Save and Exit." << endl;

        cout << "\nChoice (1 - 4): ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
            case 1:
                RegisterStudent(pStudents, pCourse, Count);
                break;

            case 2:
                viewStudentAndCourse(pStudents, pCourse, Count);
                break;

            case 3:
                viewMarkAverageCourse(pStudents, pCourse, Count);
                break;

            case 4:
                saveData(pStudents, pCourse, Count);
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "You selected a non-existent option..." << endl;
                break;
        }

        cout << endl;

    } while (choice != 4);

    return 0;
}
