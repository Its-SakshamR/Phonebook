#include<bits/stdc++.h>
using namespace std;

string first_name, last_name, number;

void myexit(){
    system("clear");
    cout << "Thank you for using our Phonebook\n";
    exit(0);
}

void help(){
    cout << "\n \t HELP\n\n";
    cout << "Press 1 to Add Contact\n"
            "Press 2 to search Contact\n"
            "Press 3 for Help\n"
            "Press 4 to Exit\n";
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
    system("clear");
}

bool isNumber(string number){
    for(int i = 0 ; i < number.length() ; i++){
        if(int(number[i]) < 48 || int(number[i]) > 57) return false;
    }

    return true;
}

void add(){
    ofstream phonebook("contact.txt",ios::app);
    system("clear");
    cout << "\nFirst (and Middle, if any) Name: ";
    cin >> first_name;
    cout << "\nLast Name: ";
    cin >> last_name;
    cout << "\nPhone Number: ";
    cin >> number;

    if(number.length() == 10){
        if(isNumber(number) == true){
            if(phonebook.is_open()){
                phonebook << first_name << " " << last_name << "\t" << number << endl;
                cout << "\n \t Contact Saved!";
            }
            else{
                cout << "\n \t Error!";
            }
        }
        else{
            cout << "\n \t Only numbers allowed!";
        }
    }
    else{
        cout << "\n \t Number should be of 10 digits!";
    }

    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
    system("clear");
    phonebook.close();
}

void search(){
    bool found = false;
    ifstream contactbook("contact.txt");
    string name;
    cout << "\n \t Enter Name of the contact:";
    cin >> name;
    system("clear");
    while(contactbook >> first_name >> last_name >> number){
        if(name == first_name || name == last_name){
            cout << "\n \n \n \t First Name : " << first_name;
            cout << "\n \n \t Last Name : " << last_name;
            cout << "\n \n \t Phone Number : " << number;
            cout << "\n \n";
            found = true;
        }
    }
    if (found == false) cout << "\n \t No such contact is found!";

    cout << endl << endl;
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
    system("clear");
}

int main(){
    system("clear");
    int choice;
    while(true){
        cout << "\n\n\n \t \t PHONEBOOK";
        cout << "\n\n \t 1) Add Contact \n \t 2) Search Contact"
                "\n \t 3) Help \n \t 4) Exit\n >>>>>>>";

        cin >> choice;

        switch(choice){
            case 1:
                add();
                break;
            case 2:
                search();
                break;
            case 3:
                help();
                break;
            case 4:
                myexit();
                break;
        }
    }

        return 0;
}