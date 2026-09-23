#include <iostream>
#include <fstream>
#include <cstddef>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

size_t hashFunction(const string& name, const string& id) {
    return hash<string>{}(name + id);
}

unordered_map<size_t, string> readUserData(const string& filename) {
    ifstream file(filename);
    unordered_map<size_t, string> userData;

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string name, id;
            getline(ss, name, ',');
            getline(ss, id, ',');
            size_t hashValue = hashFunction(name, id);
            userData[hashValue] = name + "," + id;
        }
        file.close();
    }
    return userData;
}

vector<string> split(const string &s, char delimiter) {
  vector<string> tokens;
  string token;
  istringstream tokenStream(s);
  while (getline(tokenStream, token, delimiter)) {
    tokens.push_back(token);
  }
  return tokens;
}

int total;
char guess1;
int guess2;
string guess3;

class Question
{
public:
    void setvaluesmarkQ1(string, string, string, string, string,char,int);
    void setvaluesmarkQ2(string, int, int);
    void setvaluesmarkQ3(string, string,int);
    char answer1;
    int answer2;
    string answer3;
    void DisplayQuestion1();
    void DisplayQuestion2();
    void DisplayQuestion3();
    void tcnquest();
    void tdsquest();
    void studentchoice();
    bool findstudent (const unordered_map<size_t, string>& ,string,string);
    void saveandexittcn (string, string, int);
    void saveandexittds (string, string, int);

    private:
    string QuestionText;
    string option1;
    string option2;
    string option3;
    string option4;
    string correctanswer3;
    string name;
    string idnumber;

    char correctanswer1;
    int Question_Score;
    int correctanswer2;
};

bool Question::findstudent(const unordered_map<size_t, string>& studentsData, string n, string id)
 {

    idnumber = id;
    name = n;
    size_t hashValue = hashFunction(n, id);
    auto it = studentsData.find(hashValue);

    return (it != studentsData.end());
}

void Question::tcnquest()
{
    total=0;

     Question q1;
     Question q2;
     Question q3;
     cout<<"Enter your name(withoutspace): ";
     cin >>name;
     cout<<"Enter your idnumber: ";
     cin >>idnumber;
     system("pause");
     system("cls");
     q1.setvaluesmarkQ1("What protocol can be enabled to listen in on IPv4 multicast streams and  maintain a map of what each client requests on a wireless LAN controller?",
                         "IGMP",
                         "MLD",
                         "PAP",
                         "ICMP",
                         'A',
                         10);
     q1.DisplayQuestion1();
     q2.setvaluesmarkQ2("How many 10GBASE-T port licenses are preinstalled on a Cisco Nexus 3064-32T?",
                        32,
                        10);
    q2.DisplayQuestion2();
     q3.setvaluesmarkQ3("What OSI layer does a switch reside on?",
                         "datalink",
                         10);
     q3.DisplayQuestion3();

cout << "Your Total Score is " << total << " out of 30!\n";
      cout << "\n";
       system("pause");
     system("cls");
      cout<< "Press enter to save and exit"<<endl;
      cin.get();
      saveandexittcn(name,idnumber,total);
}

void Question::tdsquest()
{
    total=0;
     Question q1;
     Question q2;
     Question q3;
     cout<<"Enter your name(withoutspace): ";
     cin >>name;
     cout<<"Enter your idnumber: ";
     cin >>idnumber;
     system("pause");
     system("cls");
     q1.setvaluesmarkQ1(" A graph in which all vertices have equal degree is known as ____",
                         "Complete graph",
                         "Regular graph",
                         "Multi graph",
                         "Simple graph",
                         'A',
                         10);
     q1.DisplayQuestion1();
     q2.setvaluesmarkQ2("Minimum number of fields in each node of a doubly linked list is",
                        3,
                        10);
    q2.DisplayQuestion2();
     q3.setvaluesmarkQ3("A parentheses checker program would be best implemented using",
                         "STACK",
                         10);
     q3.DisplayQuestion3();

cout << "Your Total Score is " << total << " out of 30!\n";
      cout << "\n";
    system("PAUSE");
    system("CLS");
      cout<< "Press enter to save and exit";
      cin.get();
        system("PAUSE");
        system("CLS");
      saveandexittds(name,idnumber,total);
}

 void Question::setvaluesmarkQ1(string q, string op1, string op2, string op3, string op4, char correct_answer1,int score)
 {
     QuestionText =q;
     option1=op1;
     option2=op2;
     option3=op3;
     option4=op4;

     correctanswer1=correct_answer1;
     Question_Score=score;
 }

 void Question::setvaluesmarkQ2(string q, int correct_answer2, int score)
 {
     QuestionText =q;
     correctanswer2=correct_answer2;
     Question_Score=score;
 }

  void Question::setvaluesmarkQ3(string q, string correct_answer3, int score)
 {
     QuestionText =q;
     correctanswer3=correct_answer3;
     Question_Score=score;
 }

void Question::saveandexittcn(string n, string id, int totalscore) {
    name = n;
    idnumber = id;
    total = totalscore;

    // Add this line at the beginning of the function to get studentsData
    unordered_map<size_t, string> studentsData = readUserData("Studentsmarks.txt");

    string line;
    ifstream infile("Studentsmarks.txt");
    ofstream temp("temp.txt");
    bool foundstudent = findstudent(studentsData, n, id);

    while (getline(infile, line)) {
        vector<string> studentInfo = split(line, ',');
        if  (foundstudent && studentInfo[0] == n && studentInfo[1] == id) {
            // cin >> totalscore;
            temp << name << "," << idnumber << "," << totalscore << "," << studentInfo[3] << endl;
            cout<<"Successfully save!"<<endl<<"Bye!"<<endl;
            foundstudent = true;
            system("CLS");
        } else {
           temp << line << endl;
        }
    }
    if (!foundstudent) {
        // If student was not found in the file, add their data
        temp << name << "," << idnumber << "," << totalscore << ",0" << endl;
        cout << "New student data created and saved!" << endl << "Bye!";
      }
    temp.close();
    infile.close();
    remove("Studentsmarks.txt");
    rename("temp.txt", "Studentsmarks.txt");
}

void Question::saveandexittds(string n, string id, int totalscore) {
     name = n;
    idnumber = id;
    total = totalscore;

    // Add this line at the beginning of the function to get studentsData
    unordered_map<size_t, string> studentsData = readUserData("Studentsmarks.txt");

    string line;
    ifstream infile("Studentsmarks.txt");
    ofstream temp("temp.txt");
    bool foundstudent = findstudent(studentsData, n, id);

    while (getline(infile, line)) {
        vector<string> studentInfo = split(line, ',');
        if  (foundstudent && studentInfo[0] == n && studentInfo[1] == id) {
            // cin >> totalscore;
            temp << name << "," << idnumber << "," << studentInfo[2] << "," << totalscore << endl;
            cout<<"Successfully save!"<<endl<<"Bye!";
            foundstudent = true; // Student is found in the file
        } else {
           temp << line << endl;
        }

    }
    if (!foundstudent) {
        // If student was not found in the file, add their data
        temp << name << "," << idnumber << "," << totalscore << ",0" << endl;
        cout << "New student data created and saved!" << endl << "Bye!";
      }
    temp.close();
    infile.close();
    remove("Studentsmarks.txt");
    rename("temp.txt", "Studentsmarks.txt");
}

void Question::DisplayQuestion1()
{
    cout << "\n";
    cout << QuestionText << "\n";
    cout << "a. " << option1 << "\n";
    cout << "b. " << option2 << "\n";
    cout << "c. " << option3 << "\n";
    cout << "d. " << option4 << "\n";
    cout << "\n";

    //User enters their answer.
    cout << "What is your answer?" << "\n";
    cin >> guess1;
    char correctAnswerLower = tolower(correctanswer1);
    char userAnswerLower = tolower(guess1);
    //If their answer is correct, message is displayed and 10 points are added to their score.
    if (userAnswerLower == correctAnswerLower) {
        cout << "\n";
        cout << "Correct!" << "\n";
        total = total + Question_Score;
        cout << "\n";
        cout << "Press enter to continue." << "\n";
        cin.get();
        cin.ignore();
    }
    else //If their answer is incorrect, message is displayed, no points added.
         //Correct answer displayed.
    {
        cout << "\n";
        cout << "Wrong!!" << "\n";
        cout << "The correct answer is " << correctanswer1 << "." << "\n";
        cout << "\n";
        cout << "Press enter to continue." << "\n";
        cin.get();
        cin.ignore();
    }
}

void Question::DisplayQuestion2()
{
    cout<<"\n";
    cout<<QuestionText<<endl;
    cout<<"What is your answer?"<<endl;

    cin>>guess2;

    int correctAnswerLower = correctanswer2;
    int userAnswerLower = guess2;
    if (userAnswerLower == correctAnswerLower) {
        cout << "\n";
        cout << "Correct!" << "\n";
        total = total + Question_Score;
        cout << "\n";
        cout << "Press enter to continue." << "\n";
        cin.get();
        cin.ignore();
    }
    else //If their answer is incorrect, message is displayed, no points added.
         //Correct answer displayed.
    {
        cout << "\n";
        cout << "Wrong!!" << "\n";
        cout << "The correct answer is " << correctanswer2 << "." << "\n";
        cout << "\n";
        cout << "Press enter to continue." << "\n";
        cin.get();
        cin.ignore();
    }
}

void Question::DisplayQuestion3()
{
    cout<<"\n";
    cout<<QuestionText<<endl;
    cout<<"What is your answer?"<<endl;
    cin>>guess3;
    string correctAnswerLower = correctanswer3;
    transform(correctAnswerLower.begin(), correctAnswerLower.end(), correctAnswerLower.begin(), ::tolower);

    string userAnswerLower = guess3;
    transform(userAnswerLower.begin(), userAnswerLower.end(), userAnswerLower.begin(), ::tolower);
    if (userAnswerLower == correctAnswerLower) {
        cout << "\n";
        cout << "Correct!" << "\n";
        total = total + Question_Score;
        cout << "\n";
        cout << "Press enter to continue." << "\n";
        cin.get();
        cin.ignore();
    }
    else //If their answer is incorrect, message is displayed, no points added.
         //Correct answer displayed.
    {
        cout << "\n";
        cout << "Wrong!!" << "\n";
        cout << "The correct answer is " << correctanswer3 << "." << "\n";
        cout << "\n";
        cout << "Press enter to continue." << "\n";
        cin.get();
        cin.ignore();
    }
}

void Question::studentchoice()
 {
     Question q;
     system("CLS");
     int quizroom;
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

