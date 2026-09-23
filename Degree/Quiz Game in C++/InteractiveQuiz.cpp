#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iterator>
#include "StudentQuiz.cpp"

using namespace std;

// Function to allow a student to select a quiz room.
void studentchoice()
{
     Question q;

     int quizroom;
     system("CLS");
  cout <<
    " |------------------------------------------------|\n"
    " |                                                |\n"
    " |                Enter Quiz Room                 |\n"
    " |                                                |\n"
    " |                1. TCN1                         |\n"
    " |                2. TDS1                         |\n"
    " |                3. Exit                         |\n"
    " |                                                |\n"
    " |------------------------------------------------|\n";
    cout<<"Enter Your Choice: ";
  cin >> quizroom;

  switch (quizroom) {
    case 1:
      system("CLS");
      q.tcnquest();
      break;
    case 2:
      system("CLS");
      q.tdsquest();
      break;
    case 3:
      system("PAUSE");
      system("CLS");
      break;
    default:
      cerr << "Invalid option! Please try again." << endl;
        system("PAUSE");
        system("CLS");
      break;
  }
}

// Function to write user data to a file.
void writeUserData(const string& filename, const unordered_map<size_t, string>& userData) {
    ofstream file(filename);

    if (file.is_open()) {
        for (const auto& entry : userData) {
            file << entry.second << endl;
        }
        file.close();
    } else {
        cout << "Error writing to file: " << filename << endl;
    }
}

// Function to perform admin login.
bool AdminLogin() {
    string passAdm, userAdm;
    cout << "Enter Admin Username: ";
    cin >> userAdm;
    cout << "Enter Admin Password: ";
    cin >> passAdm;
    return (userAdm == "admin" && passAdm == "admin123");
}

// Function to perform teacher login.
bool teacherLogin(const unordered_map<size_t, string>& teachersData) {
    string Name, TeachID;
    cout << "Enter Teacher Name: ";
    cin >> Name;
    cout << "Enter Teacher ID: ";
    cin >> TeachID;

    size_t hashValue = hashFunction(Name, TeachID);
    auto it = teachersData.find(hashValue);

    return (it != teachersData.end());
}

// Function to perform student login.
bool studentLogin(const unordered_map<size_t, string>& studentsData) {
    string name, id;
    cout << "Enter Student Name: ";
    cin >> name;
    cout << "Enter Student ID: ";
    cin >> id;

    size_t hashValue = hashFunction(name, id);
    auto it = studentsData.find(hashValue);

    return (it != studentsData.end());
}

// Function to add a new teacher.
void AddTeach(unordered_map<size_t, string>& teachersData) {
    string Name, TeachID;
    cout << "Enter Teacher Name: ";
    cin >> Name;
    cout << "Enter Teacher ID: ";
    cin >> TeachID;

    size_t hashValue = hashFunction(Name, TeachID);
    teachersData[hashValue] = Name + "," + TeachID;

    cout << "Teacher credentials added successfully!\n";
}

// Function to edit teacher credentials.
void EditTeach(unordered_map<size_t, string>& teachersData) {
    string Name, TeachID;
    cout << "Enter Teacher Name to edit: ";
    cin >> Name;
    cout << "Enter Teacher ID to edit: ";
    cin >> TeachID;

    size_t hashValue = hashFunction(Name, TeachID);
    auto it = teachersData.find(hashValue);

    if (it != teachersData.end()) {
        cout << "Enter new Teacher Name: ";
        cin >> Name;
        cout << "Enter new Teacher ID: ";
        cin >> TeachID;

        teachersData.erase(hashValue);
        hashValue = hashFunction(Name, TeachID);
        teachersData[hashValue] = Name + "," + TeachID;

        cout << "Teacher credentials edited successfully!\n";
    } else {
        cout << "Teacher not found. Cannot edit credentials.\n";
    }
}

// Function to delete teacher credentials.
void DelTeach(unordered_map<size_t, string>& teachersData) {
    string Name, TeachID;
    cout << "Enter Teacher Name to delete: ";
    cin >> Name;
    cout << "Enter Teacher ID to delete: ";
    cin >> TeachID;

    size_t hashValue = hashFunction(Name, TeachID);
    auto it = teachersData.find(hashValue);

    if (it != teachersData.end()) {
        teachersData.erase(it);
        cout << "Teacher credentials deleted successfully!\n";
    } else {
        cout << "Teacher not found. Cannot delete credentials.\n";
    }
}

// Function to view teacher credentials.
void ViewTeach(const unordered_map<size_t, string>& teachersData) {
    if (teachersData.empty()) {
        cout << "No teachers available.\n";
    } else {
        for (const auto& entry : teachersData) {
            cout << "Name: " << entry.second << endl;
        }
    }
}

// Function to add a new student.
void AddStudent(unordered_map<size_t, string>& studentsData) {
    string name, id;
    cout << "Enter Student Name: ";
    cin >> name;
    cout << "Enter Student ID: ";
    cin >> id;

    size_t hashValue = hashFunction(name, id);
    studentsData[hashValue] = name + "," + id;

    cout << "Student credentials added successfully!\n";
}

// Function to edit student credentials.
void EditStudent(unordered_map<size_t, string>& studentsData) {
    string name, id;
    cout << "Enter Student Name to edit: ";
    cin >> name;
    cout << "Enter Student ID to edit: ";
    cin >> id;

    size_t hashValue = hashFunction(name, id);
    auto it = studentsData.find(hashValue);

    if (it != studentsData.end()) {
        cout << "Enter new Student Name: ";
        cin >> name;
        cout << "Enter new Student ID: ";
        cin >> id;

        studentsData.erase(hashValue);
        hashValue = hashFunction(name, id);
        studentsData[hashValue] = name + "," + id;

        cout << "Student credentials edited successfully!\n";
    } else {
        cout << "Student not found. Cannot edit credentials.\n";
    }
}

// Function to delete student credentials.
void DelStudent(unordered_map<size_t, string>& studentsData) {
    string name, id;
    cout << "Enter Student Name to delete: ";
    cin >> name;
    cout << "Enter Student ID to delete: ";
    cin >> id;

    size_t hashValue = hashFunction(name, id);
    auto it = studentsData.find(hashValue);

    if (it != studentsData.end()) {
        studentsData.erase(it);
        cout << "Student credentials deleted successfully!\n";
    } else {
        cout << "Student not found. Cannot delete credentials.\n";
    }
}

// Function to view student credentials.
void ViewStudent(const unordered_map<size_t, string>& studentsData) {
    if (studentsData.empty()) {
        cout << "No students available.\n";
    } else {
        for (const auto& entry : studentsData) {
            cout << "Name: " << entry.second << endl;
        }
    }
}

// Function to display the content of a file.
void displayFileContent(const string& filename) {
    ifstream file(filename);
    string line;

    if (file.is_open()) {
            ifstream infile (filename);

        cout << "                                          Current records                                                   "<<endl;
        cout<< "====================================================================================================\n";
        cout << left << setw(20) << "Name" << setw(20) << "ID" << setw(20) << "TCN1 MARK" << setw(20) << "TDS1 MARK" << setw(20) << endl;
        cout<<"----------------------------------------------------------------------------------------------------\n";

        while (getline(infile, line))
            {
            vector<string> studentsData = split(line, ',');
            cout << left << setw(20) << studentsData[0] << setw(20) << studentsData[1] << setw(20) << studentsData[2] << setw(20) << studentsData[3]<<setw(20)<<endl;
        }


    } else {
        cout << "Failed to open the file." << endl;
    }
}

// Function to bubble sort student marks and display them.
void BubbleSortStudentsMarks(const unordered_map<size_t, string>& studentsData) {
    ifstream inputFile("Studentsmarks.txt");
    cout << "===== All Students' Marks (Unsorted) =====\n";
    displayFileContent("Studentsmarks.txt");
    ofstream outputFile("sortedStudentsmarks.txt");

    if (inputFile.is_open() && outputFile.is_open()) {
        vector<string> lines;
        string line;

        while (getline(inputFile, line)) {
            lines.push_back(line);
        }

        bool swapped;
        int n = lines.size();
        for (int i = 0; i < n - 1; i++) {
            swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (lines[j] > lines[j + 1]) {
                    swap(lines[j], lines[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) // If no two elements were swapped in inner loop, the array is already sorted.
                break;
        }

        copy(lines.begin(), lines.end(), ostream_iterator<string>(outputFile, "\n"));

        inputFile.close();
        outputFile.close();

        cout << "\n==== List of Student Sorted Alphabetically ====\n" << endl;
        displayFileContent("sortedStudentsmarks.txt");
    } else {
        cout << "\nFailed to open the files." << endl;
    }
    cout << "====================================================================================================\n";
}

int main() {
    unordered_map<size_t, string> teachersData = readUserData("Teachers.txt");
    unordered_map<size_t, string> studentsData = readUserData("studentscredential.txt");

    while (true) {
        int choice;
        cout << "===============================\n";
        cout << "   Quiz Interaction Game\n";
        cout << "===============================\n\n";
        cout << "Select User Type:\n";
        cout << "1. Admin\n2. Teacher\n3. Student\n";
        cout << "4. Quit\n\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 4) {
            cout << "Exiting the program. Goodbye!\n";
            break; // Exit the program
        }

        bool loginSuccess = false;

        switch (choice) {
            case 1:
                loginSuccess = AdminLogin();
                if (loginSuccess) {
                    int adminChoice;
                    do {
                        system("cls");
                        cout << "================\n";
                        cout << "Admin Menu\n";
                        cout << "================\n";
                        cout << "1. Add Teacher\n";
                        cout << "2. Edit Teacher Credentials\n";
                        cout << "3. Delete Teacher Credentials\n";
                        cout << "4. View Teacher Credentials\n";
                        cout << "5. Exit\n\n";
                        cout << "Enter your choice: ";
                        cin >> adminChoice;

                        switch (adminChoice) {
                            case 1:
                                system("cls");
                                AddTeach(teachersData);
                                break;
                            case 2:
                                system("cls");
                                EditTeach(teachersData);
                                break;
                            case 3:
                                system("cls");
                                DelTeach(teachersData);
                                break;
                            case 4:
                                system("cls");
                                ViewTeach(teachersData);
                                break;
                            case 5:
                                writeUserData("Teachers.txt", teachersData);
                                cout << "Returning to Main Menu...\n";
                                break;
                            default:
                                cout << "Invalid Choice\n";
                        }

                        if (adminChoice != 5) {
                            cout << "\nPress any key to continue...\n";
                            cin.ignore();
                            cin.get();
                        }

                    } while (adminChoice != 5);
                    system("cls");

                } else {
                    system("cls");
                    cout << "Login Failed. Incorrect admin password.\n";
                }
                break;
            case 2:
                loginSuccess = teacherLogin(teachersData);
                if (loginSuccess) {
                    int teacherChoice;
                    do {
                        system("cls");
                        cout << "================\n";
                        cout << "Teacher Menu\n";
                        cout << "================\n";
                        cout << "1. Add Student\n";
                        cout << "2. Edit Student Credentials\n";
                        cout << "3. Delete Student Credentials\n";
                        cout << "4. View Student Credentials\n";
                        cout << "5. View All Student Marks\n";
                        cout << "6. Exit\n\n";
                        cout << "Enter your choice: ";
                        cin >> teacherChoice;

                        switch (teacherChoice) {
                            case 1:
                                system("cls");
                                AddStudent(studentsData);
                                break;
                            case 2:
                                system("cls");
                                EditStudent(studentsData);
                                break;
                            case 3:
                                system("cls");
                                DelStudent(studentsData);
                                break;
                            case 4:
                                system("cls");
                                ViewStudent(studentsData);
                                break;
                            case 5:
                                system("cls");
                                BubbleSortStudentsMarks(studentsData);
                                break;
                            case 6:
                                writeUserData("studentscredential.txt", studentsData);
                                cout << "Returning to Main Menu...\n";
                                break;
                            default:
                                cout << "Invalid Choice\n";
                        }

                        if (teacherChoice != 6) {
                            cout << "\nPress any key to continue...\n";
                            cin.ignore();
                            cin.get();
                        }

                    } while (teacherChoice != 6);
                    system("cls");

                } else {
                    system("cls");
                    cout << "Login Failed. Incorrect teacher credentials.\n";
                }
                break;
            case 3:
                loginSuccess = studentLogin(studentsData);
                if (loginSuccess) {
                    cout << "Student login successful!\n";
                    studentchoice();
                } else {
                    cout << "Login Failed. Incorrect student credentials.\n";
                }
                break;
            default:
                cout << "Invalid Choice\n";
        }
    }

    return 0;
}
