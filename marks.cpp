#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace std;

class Subjects {
public:
    class AddSubjects {
    public:
        void main() {
            system("clear");
            cout << "Add subjects" << endl;

            cout << "\nEnter the subject name (or nothing to cancel): ";
            string subjectName, line;
            getline(cin >> ws, subjectName);

            if (subjectName == "") {
                system("clear");
                Subjects Subjects;
                Subjects.main();
            }
            
            ifstream subjectNameFile("subjectNames.txt");
            bool subjectExists = false;
            while (getline(subjectNameFile, line)) {            
                if (line == subjectName) {
                    cout << "Subject name already exists ";
                    cin.ignore();
                    cin.get();
                    subjectExists = true;
                    break;
                }
            }
            subjectNameFile.close();

            if (!subjectExists) {
                ofstream subjectNameFile("subjectNames.txt", ios::app);
                subjectNameFile << subjectName << endl;
                cout << "Added successfully. Subject name: " << subjectName << " ";
                cin.get();
                subjectNameFile.close();
            }

            system("clear");
            Subjects Subjects;
            Subjects.main();
        }
    };

    class EditSubjects {
    public:
        void main() {
            system("clear");
            cout << "Edit subjects" << endl;

            cout << "\nThese are the current subjects: \n" << endl;
            ifstream subjectNameFile("subjectNames.txt");
            string line;
            
            int i = 1;
            while (getline(subjectNameFile, line)) {
                cout << i << ". " << line << endl;
                i++;
            }
            subjectNameFile.close();

            cout << "\nPlease choose a subject to edit (number), or nothing to cancel: ";
            int choice;
            cin >> choice;

            if (choice == 0) {
                system("clear");
                Subjects Subjects;
                Subjects.main();
            }

            ifstream subjectFileEdit("subjectNames.txt");
            string subjectName;
            i = 1;
            while (getline(subjectFileEdit, line)) {
                if (i == choice) {
                    subjectName = line;
                    break;
                }
                i++;
            }
            subjectFileEdit.close();

            cout << "Enter the new subject name for " << subjectName << ": ";
            string newSubjectName;
            getline(cin >> ws, newSubjectName);

            ifstream subjectFileCheck("subjectNames.txt");
            bool subjectExists = false;
            while (getline(subjectFileCheck, line)) {
                if (line == newSubjectName) {
                    cout << "Subject name already exists ";
                    cin.ignore();
                    cin.get();
                    subjectExists = true;
                    break;
                }
            }
            subjectFileCheck.close();

            if (!subjectExists) {
                ifstream subjectNameFileEdit("subjectNames.txt");
                ofstream tempFile("temp.txt");
                while (getline(subjectNameFileEdit, line)) {
                    if (line == subjectName) {
                        tempFile << newSubjectName << endl;
                    } else {
                        tempFile << line << endl;
                    }
                }
                subjectNameFileEdit.close();
                tempFile.close();

                remove("subjectNames.txt");
                rename("temp.txt", "subjectNames.txt");

                cout << "Edited successfully. Subject name: " << newSubjectName << " ";
                cin.get();
            }

            system("clear");
            Subjects Subjects;
            Subjects.main();
        }
    };

    class DeleteSubjects {
    public:
        void main() {
            system("clear");
            cout << "Delete subjects" << endl;

            cout << "\nThese are the current subjects: \n" << endl;
            ifstream subjectNameFile("subjectNames.txt");
            string line;

            int i = 1;
            while (getline(subjectNameFile, line)) {
                cout << i << ". " << line << endl;
                i++;
            }
            subjectNameFile.close();

            cout << "\nPlease choose a subject to delete (number), or nothing to cancel: ";
            int choice;
            cin >> choice;

            if (choice == 0) {
                system("clear");
                Subjects Subjects;
                Subjects.main();
            }
            
            ifstream subjectNameFileDelete("subjectNames.txt");
            string subjectName;
            i = 1;
            while (getline(subjectNameFileDelete, line)) {
                if (i == choice) {
                    subjectName = line;
                    break;
                }
                i++;
            }
            subjectNameFileDelete.close();

            ifstream subjectFileCheck("subjectNames.txt");
            bool subjectExists = false;
            while (getline(subjectFileCheck, line)) {
                if (line == subjectName) {
                    subjectExists = true;
                    break;
                }
            }
            subjectFileCheck.close();

            if (subjectExists) {
                ifstream subjectNameFileDelete("subjectNames.txt");
                ofstream tempFile("temp.txt");
                while (getline(subjectNameFileDelete, line)) {
                    if (line != subjectName) {
                        tempFile << line << endl;
                    }
                }
                tempFile.close();
                subjectNameFileDelete.close();

                remove("subjectNames.txt");
                rename("temp.txt", "subjectNames.txt");

                cout << "Deleted successfully. Subject name: " << subjectName << " ";
                cin.ignore();
                cin.get();
            }
            else {
                cout << "Subject does not exist ";
                cin.ignore();
                cin.get();
            }

            system("clear");
            Subjects Subjects;
            Subjects.main();
        }
    };

    class ViewSubjects {
    public:
        void main() {
            system("clear");
            cout << "View subjects" << endl;

            cout << "\nThese are the current subjects: \n" << endl;
            ifstream subjectNameFile("subjectNames.txt");
            string line;

            int i = 1;
            while (getline(subjectNameFile, line)) {
                cout << i << ". " << line << endl;
                i++;
            }
            subjectNameFile.close();

            cout << "\nPress enter to continue... ";
            cin.ignore();
            cin.get();

            system("clear");
            Subjects Subjects;
            Subjects.main();
        }
    };

    class BackSubjects {
    public:
        void main() {
            system("clear");
            void choose();
            choose();
        }
    };

    void main() {
        system("clear");
        cout << "Subject management" << endl;

        while (true) {
            cout << "\nPlease choose an option: \n" << endl;
            string subjectOptions[] = {
                "1. Add subjects",
                "2. Edit subjects",
                "3. Delete subjects",
                "4. View subjects",
                "5. Back"
            };

            for (string option : subjectOptions) {
                cout << option << endl;
            }

            cout << "\nOption: ";
            int choice;
            cin >> choice;

            AddSubjects AddSubjects;
            EditSubjects EditSubjects;
            DeleteSubjects DeleteSubjects;
            ViewSubjects ViewSubjects;
            BackSubjects BackSubjects;

            switch (choice) {
                case 1:
                    cout << "Add subjects" << endl;
                    AddSubjects.main();
                    break;
                case 2:
                    cout << "Edit subjects" << endl;
                    EditSubjects.main();
                    break;
                case 3:
                    cout << "Delete subjects" << endl;
                    DeleteSubjects.main();
                    break;
                case 4:
                    cout << "View subjects" << endl;
                    ViewSubjects.main();
                    break;
                case 5:
                    cout << "Back" << endl;
                    BackSubjects.main();
                    break;
                default:
                    cout << "Invalid option" << endl;
                    continue;
            }
        }
    }
};

class Marks {
public:
    class AddMarks {
    public:
        void main() {
            system("clear");
            cout << "Add marks" << endl;

            cout << "\nThese are the current subjects: \n" << endl;
            ifstream subjectNameFile("subjectNames.txt");
            string line;

            int i = 1;
            while (getline(subjectNameFile, line)) {
                cout << i << ". " << line << endl;
                i++;
            }
            subjectNameFile.close();

            cout << "\nPlease choose a subject to add marks to (number), or nothing to cancel: ";
            int choice;
            cin >> choice;

            if (choice == 0) {
                system("clear");
                Marks Marks;
                Marks.main();
            }

            ifstream subjectFileCheck("subjectNames.txt");
            string subjectName;
            i = 1;
            while (getline(subjectFileCheck, line)) {
                if (i == choice) {
                    subjectName = line;
                    break;
                }
                i++;
            }
            subjectFileCheck.close();

            cout << "Enter the exam name: ";
            string examName;
            getline(cin >> ws, examName);

            ifstream examFileCheck("marks.txt");
            bool examExists = false;
            while (getline(examFileCheck, line)) {
                size_t pos1 = line.find(" --> ");
                size_t pos2 = line.find(" --> ", pos1 + 5);
                string existingSubjectName = line.substr(0, pos1);
                string existingExamName = line.substr(pos1 + 5, pos2 - pos1 - 5);
                if (existingSubjectName == subjectName && existingExamName == examName) {
                    cout << "Exam name already exists for this subject ";
                    cin.get();
                    examExists = true;
                    break;
                }
            }
            examFileCheck.close();

            if (examExists) {
                system("clear");
                Marks Marks;
                Marks.main();
            }

            cout << "Enter the mark: ";
            double mark;
            cin >> mark;

            ofstream marksFile("marks.txt", ios::app);
            marksFile << subjectName << " --> " << examName << " --> " << mark << endl;
            marksFile.close();

            cout << "Added successfully. Subject name: " << subjectName << ", Exam name: " << examName << ", Mark: " << mark << " ";
            cin.ignore();
            cin.get();

            system("clear");
            Marks Marks;
            Marks.main();
        }
    };

    class EditMarks {
    public:
        void main() {
            system("clear");
            cout << "Edit marks" << endl;

            cout << "\nThese are the current marks: \n" << endl;
            ifstream marksFile("marks.txt");
            string line;

            int i = 1;
            while (getline(marksFile, line)) {
            cout << i << ". " << line << endl;
            i++;
            }
            marksFile.close();

            cout << "\nPlease choose a mark to edit (number), or nothing to cancel: ";
            int choice;
            cin >> choice;

            if (choice == 0) {
            system("clear");
            Marks Marks;
            Marks.main();
            }

            ifstream marksFileEdit("marks.txt");
            string mark;
            i = 1;
            while (getline(marksFileEdit, line)) {
            if (i == choice) {
                mark = line;
                break;
            }
            i++;
            }
            marksFileEdit.close();

            cout << "Enter the new mark for " << mark << ": ";
            int newMark;
            cin >> newMark;

            ifstream marksFileCheck("marks.txt");
            bool markExists = false;
            while (getline(marksFileCheck, line)) {
            if (line == mark) {
                markExists = true;
                break;
            }
            }
            marksFileCheck.close();

            if (markExists) {
            ifstream marksFileEdit("marks.txt");
            ofstream tempFile("temp.txt");
            while (getline(marksFileEdit, line)) {
                if (line == mark) {
                size_t pos1 = mark.find(" --> ");
                size_t pos2 = mark.find(" --> ", pos1 + 5);
                string subjectName = mark.substr(0, pos1);
                string examName = mark.substr(pos1 + 5, pos2 - pos1 - 5);
                tempFile << subjectName << " --> " << examName << " --> " << newMark << endl;
                } else {
                tempFile << line << endl;
                }
            }
            marksFileEdit.close();
            tempFile.close();

            remove("marks.txt");
            rename("temp.txt", "marks.txt");

            cout << "Edited successfully. New mark: " << newMark << " ";
            cin.ignore();
            cin.get();
            }

            system("clear");
            Marks Marks;
            Marks.main();
        }
    };

    class DeleteMarks {
    public:
        void main() {
            system("clear");
            cout << "Delete marks" << endl;

            cout << "\nThese are the current marks: \n" << endl;
            ifstream marksFile("marks.txt");
            string line;

            int i = 1;
            while (getline(marksFile, line)) {
                cout << i << ". " << line << endl;
                i++;
            }
            marksFile.close();

            cout << "\nPlease choose a mark to delete (number), or nothing to cancel: ";
            int choice;
            cin >> choice;

            if (choice == 0) {
                system("clear");
                Marks Marks;
                Marks.main();
            }

            ifstream marksFileDelete("marks.txt");
            string mark;
            i = 1;
            while (getline(marksFileDelete, line)) {
                if (i == choice) {
                    mark = line;
                    break;
                }
                i++;
            }
            marksFileDelete.close();

            ifstream marksFileCheck("marks.txt");
            bool markExists = false;
            while (getline(marksFileCheck, line)) {
                if (line == mark) {
                    markExists = true;
                    break;
                }
            }
            marksFileCheck.close();

            if (markExists) {
                ifstream marksFileDelete("marks.txt");
                ofstream tempFile("temp.txt");
                while (getline(marksFileDelete, line)) {
                    if (line != mark) {
                        tempFile << line << endl;
                    }
                }
                marksFileDelete.close();
                tempFile.close();

                remove("marks.txt");
                rename("temp.txt", "marks.txt");

                cout << "Deleted successfully. Mark: " << mark << " ";
                cin.ignore();
                cin.get();
            }
            else {
                cout << "Mark does not exist ";
                cin.ignore();
                cin.get();
            }

            system("clear");
            Marks Marks;
            Marks.main();
        }
    };

    class ViewMarks {
    public:
        void main() {
            system("clear");
            cout << "View marks" << endl;

            cout << "\nThese are the current marks: \n" << endl;
            ifstream marksFile("marks.txt");
            string line;

            int i = 1;
            while (getline(marksFile, line)) {
                cout << i << ". " << line << endl;
                i++;
            }
            marksFile.close();

            cout << "\nPress enter to continue... ";
            cin.ignore();
            cin.get();

            system("clear");
            Marks Marks;
            Marks.main();
        }
    };

    class BackMarks {
    public:
        void main() {
            system("clear");
            void choose();
            choose();
        }
    };

    void main() {
        system("clear");
        cout << "Marks management" << endl;
        
        while (true) {
            cout << "\nPlease choose an option: \n" << endl;
            string marksOptions[] = {
                "1. Add marks",
                "2. Edit marks",
                "3. Delete marks",
                "4. View marks",
                "5. Back"
            };

            for (string option : marksOptions) {
                cout << option << endl;
            }

            cout << "\nOption: ";
            int choice;
            cin >> choice;

            AddMarks AddMarks;
            EditMarks EditMarks;
            DeleteMarks DeleteMarks;
            ViewMarks ViewMarks;
            BackMarks BackMarks;

            switch (choice) {
                case 1:
                    cout << "Add marks" << endl;
                    AddMarks.main();
                    break;
                case 2:
                    cout << "Edit marks" << endl;
                    EditMarks.main();
                    break;
                case 3:
                    cout << "Delete marks" << endl;
                    DeleteMarks.main();
                    break;
                case 4:
                    cout << "View marks" << endl;
                    ViewMarks.main();
                    break;
                case 5:
                    cout << "Back" << endl;
                    BackMarks.main();
                    break;
                default:
                    cout << "Invalid option" << endl;
                    continue;
            }
        }
    }
};

class Operations {
public:
    class Average {
    public:
        void main() {
            system("clear");
            cout << "Calculate average mark" << endl;

            cout << "\nThese are the current subjects: \n" << endl;
            ifstream subjectNameFile("subjectNames.txt");
            string line;

            int i = 1;
            while (getline(subjectNameFile, line)) {
                cout << i << ". " << line << endl;
                i++;
            }
            subjectNameFile.close();

            cout << "\nPlease choose a subject to calculate the average mark for (number), or nothing to cancel: ";
            int choice;
            cin >> choice;

            if (choice == 0) {
                system("clear");
                Operations Operations;
                Operations.main();
            }

            ifstream subjectFileCheck("subjectNames.txt");
            string subjectName;
            i = 1;
            while (getline(subjectFileCheck, line)) {
                if (i == choice) {
                    subjectName = line;
                    break;
                }
                i++;
            }
            subjectFileCheck.close();

            ifstream marksFile("marks.txt");
            double totalMarks = 0;
            int totalExams = 0;
            while (getline(marksFile, line)) {
                size_t pos1 = line.find(" --> ");
                size_t pos2 = line.find(" --> ", pos1 + 5);
                string existingSubjectName = line.substr(0, pos1);
                string existingExamName = line.substr(pos1 + 5, pos2 - pos1 - 5);
                double existingMark = stod(line.substr(pos2 + 5));
                if (existingSubjectName == subjectName) {
                    totalMarks += existingMark;
                    totalExams++;
                }
            }
            marksFile.close();

            if (totalExams == 0) {
                cout << "No exams found for this subject ";
                cin.ignore();
                cin.get();
            }
            else {
                double averageMark = totalMarks / totalExams;
                cout << "Average mark for " << subjectName << ": " << averageMark << " ";
                cin.ignore();
                cin.get();
            }

            system("clear");
            Operations Operations;
            Operations.main();
        }

    };

    class Total {
    public:
        void main() {
            system("clear");
            cout << "Calculate total marks" << endl;

            cout << "\nThese are the current subjects: \n" << endl;
            ifstream subjectNameFile("subjectNames.txt");
            string line;

            int i = 1;
            while (getline(subjectNameFile, line)) {
                cout << i << ". " << line << endl;
                i++;
            }
            subjectNameFile.close();

            cout << "\nPlease choose a subject to calculate the total marks for (number), or nothing to cancel: ";
            int choice;
            cin >> choice;

            if (choice == 0) {
                system("clear");
                Operations Operations;
                Operations.main();
            }

            ifstream subjectFileCheck("subjectNames.txt");
            string subjectName;
            i = 1;
            while (getline(subjectFileCheck, line)) {
                if (i == choice) {
                    subjectName = line;
                    break;
                }
                i++;
            }
            subjectFileCheck.close();

            ifstream marksFile("marks.txt");
            double totalMarks = 0;

            while (getline(marksFile, line)) {
                size_t pos1 = line.find(" --> ");
                size_t pos2 = line.find(" --> ", pos1 + 5);
                string existingSubjectName = line.substr(0, pos1);
                double existingMark = stod(line.substr(pos2 + 5));
                if (existingSubjectName == subjectName) {
                    totalMarks += existingMark;
                }
            }
            marksFile.close();

            cout << "Total marks for " << subjectName << ": " << totalMarks << " ";
            cin.ignore();
            cin.get();

            system("clear");
            Operations Operations;
            Operations.main();
        }
    };

    class Percentage {
    public:
        void main() {
            system("clear");
            cout << "Calculate percentage" << endl;

            cout << "\nThese are the current subjects: \n" << endl;
            ifstream subjectNameFile("subjectNames.txt");
            string line;

            int i = 1;
            while (getline(subjectNameFile, line)) {
                cout << i << ". " << line << endl;
                i++;
            }
            subjectNameFile.close();

            cout << "\nPlease choose a subject to calculate the percentage for (number), or nothing to cancel: ";
            int choice;
            cin >> choice;

            if (choice == 0) {
                system("clear");
                Operations Operations;
                Operations.main();
            }

            ifstream subjectFileCheck("subjectNames.txt");
            string subjectName;
            i = 1;
            while (getline(subjectFileCheck, line)) {
                if (i == choice) {
                    subjectName = line;
                    break;
                }
                i++;
            }
            subjectFileCheck.close();

            ifstream marksFile("marks.txt");
            double totalMarks = 0;
            double totalExams = 0;
            while (getline(marksFile, line)) {
                size_t pos1 = line.find(" --> ");
                size_t pos2 = line.find(" --> ", pos1 + 5);
                string existingSubjectName = line.substr(0, pos1);
                double existingMark = stod(line.substr(pos2 + 5));
                if (existingSubjectName == subjectName) {
                    totalMarks += existingMark;
                    totalExams++;
                }
            }
            marksFile.close();

            if (totalExams == 0) {
                cout << "No exams found for this subject ";
                cin.ignore();
                cin.get();
            }
            else {
                double percentage = (totalMarks / (totalExams * 100)) * 100;
                cout << "Percentage for " << subjectName << ": " << percentage << "% ";
                cin.ignore();
                cin.get();
            }

            system("clear");
            Operations Operations;
            Operations.main();
        }
    };

    class Back {
    public:
        void main() {
            system("clear");
            void choose();
            choose();
        }
    };

    void main() {
        system("clear");
        cout << "Marks operations" << endl;

        while (true) {
            cout << "\nPlease choose an option: \n" << endl;
            string operationsOptions[] = {
                "1. Calculate average mark",
                "2. Calculate total marks",
                "3. Calculate percentage",
                "4. Back"
            };

            for (string option : operationsOptions) {
                cout << option << endl;
            }

            cout << "\nOption: ";
            int choice;
            cin >> choice;

            Average Average;
            Total Total;
            Percentage Percentage;
            Back Back;

            switch (choice) {
                case 1:
                    cout << "Calculate average mark" << endl;
                    Average.main();
                    break;
                case 2:
                    cout << "Calculate total marks" << endl;
                    Total.main();
                    break;
                case 3:
                    cout << "Calculate percentage" << endl;
                    Percentage.main();
                    break;
                case 4:
                    cout << "Back" << endl;
                    Back.main();
                    break;
                default:
                    cout << "Invalid option" << endl;
                    continue;
            }
        }
    }
};

class Exit {
public:
    void main() {
        system("clear");
        exit(0);
    }
};

void choose() {
    cout << "\nPlease choose an option: \n" << endl;
    string options[] = {
        "1. Subject management",
        "2. Marks management",
        "3. Operations",
        "4. Exit"
    };

    for (string option : options) {
        cout << option << endl;
    }

    cout << "\nOption: ";
    int choice;
    cin >> choice;

    Subjects Subjects;
    Marks Marks;
    Operations Operations;
    Exit Exit;

    switch (choice) {
        case 1:
            cout << "Subject management" << endl;
            Subjects.main();
            break;
        case 2:
            cout << "Marks management" << endl;
            Marks.main();
            break;
        case 3:
            cout << "Exiting program..." << endl;
            Exit.main();
            break;
        default:
            cout << "Invalid option" << endl;
            break;
    }
}

int main() {
    system("clear");
    cout << "Welcome to the marks register program" << endl;
    choose();
}