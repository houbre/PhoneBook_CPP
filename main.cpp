#include <iostream>
#include <string>
#include <fstream>
#include "phone_record.hpp"
using namespace std;


struct PHONE_RECORD phonebook[10];

//Here are the promises for every functions
void initialize_phonebook();
int loadCSV();
int saveCSV();
int addRecord(string pName, string pBirthdate, string pPhone);
int findRecord(string pName);
int listRecords();

int menu(int user_input){

    switch (user_input)
    {
        //add a record to the phonebook
        case 1: {
            
            //if phonebook is full, cannot add anymore contacts

            if (phonebook[9].name.length() > 0 ){
                cout << "Sorry the phonebook is full\n";
                break;
            }

            string name, birth, phone;

            //Input name
            cout << "Name: ";
            getline(cin >> ws, name);

            //We will only take names of length 50 or less
            if(name.length() > 25){
                name = name.substr(0, 50);
            }

            //input birthday
            cout << "Birthdate: ";
            getline(cin, birth);

            //We will only take birthdate of length 10 or less
            //Assume it is of the form DD-MM-YYYY (10 chars)
            if(birth.length() > 10){
                birth = birth.substr(0, 10);
            }

            //input Phone
            cout << "Phone: ";
            getline(cin, phone);

            //We will only take phone numbers of length 12 or less
            //assume phone number of format 123-456-7891
            if(phone.length() > 12){
                phone = phone.substr(0, 12);
            }

            //add a record to the phonebook
            addRecord(name, birth, phone);

            break;
        }
        
        //find a record by its name
        case 2: {

            if (phonebook[0].name.length() == 0){
                cout << "The phonebook is empty. No records to find\n";
                break;
            }

            string name;

            cout << "Find name: ";
            getline(cin >> ws, name);

            findRecord(name);

            break;
        }

        //list all records
        case 3: {

            if (phonebook[0].name.length() == 0){
                cout << "The phonebook is empty. No records to list\n";
                break;
            }

            listRecords();

            break;
        }

        //exit the program and save the phonebook records to a csv file
        case 4: {

            saveCSV();

            break;
        }
    }

    return 0;
} //return to menu prompt


//check if user input is 1, 2, 3 or 4

int check_valid_input(string pBuffer){

    if (pBuffer.size() > 1){
        cout << "Please input a valid option\n";
        cout << "Phonebook Menu: (1)Add, (2)Find, (3)List, (4)Quit> ";
        return 1;
    }

    if (pBuffer[0] != '1' && pBuffer[0] != '2' && pBuffer[0] != '3' && pBuffer[0] != '4'){
        cout << "Please input a valid option\n";
        cout << "Phonebook Menu: (1)Add, (2)Find, (3)List, (4)Quit> ";
        return 1;
    }

    return 0;
}

int main() {

    //Initialize the phonebook (allows 10 contact max)
    initialize_phonebook();

    //error output
    int err;

    //file pointer
    string csvPath = "data.csv";

    //int for menu user input
    int userInput;

    //Create buffer to handle errors form user input
    string buffer;

    //load CSV file if it exists
    loadCSV();

    //output menu 
    cout << "Phonebook Menu: (1)Add, (2)Find, (3)List, (4)Quit> ";

    //user input
    cin >> buffer;

    //check if user input is valid
    err = check_valid_input(buffer);

    while(err == 1 ){
        cin >> buffer;
        err = check_valid_input(buffer);
    }

    userInput = stoi(buffer);

    menu(userInput);

    while (userInput != 4) {

        cout << "Phonebook Menu: (1)Add, (2)Find, (3)List, (4)Quit> ";

        //user input
        cin >> buffer;

        //check if user input is valid
        err = check_valid_input(buffer);

        while(err == 1 ){
            cin >> buffer;
            err = check_valid_input(buffer);
        }

        userInput = stoi(buffer);

        menu(userInput);
    }

    //exit program
    cout << "End of phonebook program\n";

}