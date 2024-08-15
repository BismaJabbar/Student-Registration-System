#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct student {
    int id;
    string name;
    string fname;
    string email;
    char gender;
    string DOB;
    string mobile;
    string phone;
    string state;
    string city;
    string address;
    string religion;
    int passport;
    string nationality;
    string country;
} applicant[5];

int i = 0;
fstream applicant_file, update_file, temp_file;
char choice;

void input() {
    system("cls");
    applicant_file.open("applicant.txt", ios::app);
    cout << "Press I for international student " << endl;
    cout << "Press N for national student " << endl;
    cin >> choice;

    bool genderValid = false;
    cout << "---- ENTER PERSONAL INFORMATION----" << endl;

    cout << "ID: ";
    cin >> applicant[i].id;
    applicant_file << "ID: " << applicant[i].id << endl;

    cout << "NAME: ";
    cin.ignore();
    getline(cin, applicant[i].name);
    applicant_file << "Name: " << applicant[i].name << endl;

    cout << "FATHER NAME: ";
    getline(cin, applicant[i].fname);
    applicant_file << "Father Name: " << applicant[i].fname << endl;

    cout << "EMAIL: ";
    cin >> applicant[i].email;
    applicant_file << "Email: " << applicant[i].email << endl;

    if (choice == 'I' || choice == 'i') {
        cout << "PASSPORT NO.: ";
        cin >> applicant[i].passport;
        applicant_file << "Passport No: " << applicant[i].passport << endl;
    }
    cout << "GENDER (M/F/X): ";
    cin >> applicant[i].gender;

    if (applicant[i].gender == 'M' || applicant[i].gender == 'F' || applicant[i].gender == 'X' || applicant[i].gender == 'm' || applicant[i].gender == 'f' || applicant[i].gender == 'x') {
        genderValid = true;
    }

    if (!genderValid) {
        cout << "Invalid Gender" << endl;
        applicant_file << "Invalid Gender" << endl;
    }
    else {
        applicant_file << "Gender: " << applicant[i].gender << endl;
    }

    cout << "DATE OF BIRTH : ";
    cin >> applicant[i].DOB;
    applicant_file << "DOB: " << applicant[i].DOB << endl;

    cout << "MOBILE NO: ";
    cin >> applicant[i].mobile;
    applicant_file << "Mobile No: " << applicant[i].mobile << endl;

    cout << "PHONE NO. (HOME) : ";
    cin >> applicant[i].phone;
    applicant_file << "Phone No: " << applicant[i].phone << endl;

    if (choice == 'i' || choice == 'I') {
        cout << "Nationality: ";
        cin >> applicant[i].nationality;
        applicant_file << "Nationality: " << applicant[i].nationality << endl;
    }
    if (choice == 'i' || choice == 'I') {
        cout << "COUNTRY: ";
        cin >> applicant[i].country;
        applicant_file << "Country: " << applicant[i].country << endl;
    }
    cout << "STATE/ PROVINCE: ";
    cin >> applicant[i].state;
    applicant_file << "State: " << applicant[i].state << endl;

    cout << "DISTRICT/ CITY: ";
    cin >> applicant[i].city;
    cin.ignore();
    applicant_file << "City: " << applicant[i].city << endl;

    cout << "ADDRESS: ";
    getline(cin, applicant[i].address);
    applicant_file << "Address: " << applicant[i].address << endl;

    cout << "RELIGION: ";
    cin >> applicant[i].religion;
    applicant_file << "Religion: " << applicant[i].religion << endl;

    i++;
    applicant_file.close();
    cout << "\n\n **Student Record Added Successfully**" << endl;
}

void display() {
    system("cls");
    cout << "\n\n\t\t----PERSONAL INFORMATION----" << endl;
    applicant_file.open("applicant.txt", ios::in);
    string data;
    while (getline(applicant_file, data)) {
        cout << data << endl;
    }
    applicant_file.close();
}

int search(int value) {
    for (int i = 0; i < 5; i++) {
        if (applicant[i].id == value) {
            return i;
        }
    }
    return -1;
}

void fetch(int id) {
    system("cls");
    cout << "\n\n\t\t\t **Search Record** " << endl;
    cout << "Enter ID to search: ";
    cin >> id;
    int index = search(id);
    if (index == -1) {
        cout << "Record not found" << endl;
    }
    else {
        cout << "ID: " << applicant[index].id << endl;
        cout << "Name: " << applicant[index].name << endl;
        cout << "Father Name: " << applicant[index].fname << endl;
        cout << "Email: " << applicant[index].email << endl;
        cout << "Gender: " << applicant[index].gender << endl;
        cout << "DOB: " << applicant[index].DOB << endl;
        cout << "Mobile: " << applicant[index].mobile << endl;
        cout << "Phone: " << applicant[index].phone << endl;
        cout << "State: " << applicant[index].state << endl;
        cout << "City: " << applicant[index].city << endl;
        cout << "Address: " << applicant[index].address << endl;
        cout << "Religion: " << applicant[index].religion << endl;
        if (choice == 'i' || choice == 'I') {
            cout << "Country: " << applicant[index].country << endl;
        }
    }
}

void update(int& value) {
    int choice;
    char choice1;
    applicant_file.open("u_applicant.txt", ios::out);
    cout << "Enter ID to update: ";
    cin >> value;

    int index = search(value);
    if (index == -1) {
        cout << "Record not found!" << endl;
    }
    else {
        do {
            cout << "What do you want to update?" << endl;
            cout << "1. Name" << endl;
            cout << "2. Email" << endl;
            cout << "3. Mobile number" << endl;
            cout << "4. Landline" << endl;
            cout << "5. State/Province" << endl;
            cout << "6. City" << endl;
            cout << "7. Address" << endl;
            cout << "8. Country" << endl;
            cin >> choice;
            switch (choice) {
            case 1:
                cout << "New name: ";
                cin.ignore();
                getline(cin, applicant[index].name);
                applicant_file << "Name: " << applicant[index].name << endl;
                break;
            case 2:
                cout << "New email: ";
                cin >> applicant[index].email;
                applicant_file << "Email: " << applicant[index].email << endl;
                break;
            case 3:
                cout << "New mobile number: ";
                cin >> applicant[index].mobile;
                applicant_file << "Mobile: " << applicant[index].mobile << endl;
                break;
            case 4:
                cout << "New landline: ";
                cin >> applicant[index].phone;
                applicant_file << "Phone: " << applicant[index].phone << endl;
                break;
            case 5:
                cout << "New state/province: ";
                cin >> applicant[index].state;
                applicant_file << "State: " << applicant[index].state << endl;
                break;
            case 6:
                cout << "New city: ";
                cin >> applicant[index].city;
                applicant_file << "City: " << applicant[index].city << endl;
                break;
            case 7:
                cout << "New address: ";
                cin.ignore();
                getline(cin, applicant[index].address);
                applicant_file << "Address: " << applicant[index].address << endl;
                break;
            case 8:
                cout << "New country: ";
                cin >> applicant[index].country;
                applicant_file << "Country: " << applicant[index].country << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
            }
            cout << "Do you want to keep updating? (y/n): ";
            cin >> choice1;

        } while (choice1 == 'y' || choice1 == 'Y');
    }
    applicant_file.close();
}
void _delete(int& value) {
    system("cls");
    cout << "\n\n\t\t\t **Delete Record** " << endl;
    cout << "Enter ID to delete: ";
    cin >> value;

    int index = search(value);
    if (index == -1) {
        cout << "Record not found!" << endl;
    }
    else {
        fstream temp_file;
        applicant_file.open("applicant.txt", ios::in);
        temp_file.open("temp.txt", ios::out);

        string line;
        bool skip = false;
        while (getline(applicant_file, line)) {
            if (line.find("ID: " + to_string(value)) != string::npos) {
                skip = true;  // Start skipping lines until we reach the next ID
            }
            if (skip) {
                if (line.find("ID: ") != string::npos && line.find("ID: " + to_string(value)) == string::npos) {
                    skip = false;  // Stop skipping when we reach the next record
                }
            }
            if (!skip) {
                temp_file << line << endl;
            }
        }

        applicant_file.close();
        temp_file.close();
        remove("applicant.txt");
        rename("temp.txt", "applicant.txt");
        cout << "Record deleted successfully" << endl;
    }
}


int main() {
    int value;
    char choice1;
    do {
        cout << "-------------------------------STUDENT REGISTRATION SYSTEM----------------------------" << endl;
        cout << "PRESS " << endl;
        cout << "1. Enter record" << endl;
        cout << "2. Update record" << endl;
        cout << "3. Search record" << endl;
        cout << "4. Delete record" << endl;
        cout << "5. Display record" << endl;
        cin >> choice1;

        switch (choice1) {
        case '1':
            input();
            break;
        case '2':
            update(value);
            break;
        case '3':
            fetch(value);
            break;
        case '4':
            _delete(value);
            break;
        case '5':
            display();
            break;
        default:
            cout << "Invalid choice" << endl;
        }
        cout << "Do you want to continue (y/n)? ";
        cin >> choice1;
    } while (choice1 == 'y' || choice1 == 'Y');

    return 0;
}
