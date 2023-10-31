#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "phone_record.hpp"

using namespace std;

//Void function that sets every field to an empty string
//for every slot in the phonebook
void initialize_phonebook(){
	
	int i = 0;
	
	for(int i = 0; i < 10; i++){
		phonebook[i].name = "";
    }

}

//Take as input : a csv file pointer
//load the phonebook with the info in the csv
int loadCSV(){

    string csvPath = "data.csv";

    ifstream CSVfile(csvPath);

    if (!CSVfile.is_open()){
        cout << "No the phonebook is empty";
        return 1;
    }

    string line;
    int count = 0;

    while(getline(CSVfile, line)){

        vector<string> row; 
        stringstream s(line);
        string element;

        while(getline(s, element, ',')){
            row.push_back(element);
        }

        if (count != 0){
            phonebook[count-1].name = row[0];
            phonebook[count-1].birthdate = row[1];
            phonebook[count-1].phone = row[2];
        }

        count++;

    }

    return 0;

}

//take as input a csv file pointer
//when the user exit the program, save the phonebook into the csv file
int saveCSV(){

    string csvPath = "data.csv";

    //open csv file
    ofstream CSVfile(csvPath);

    string header = "name, birthdate,phone";

    CSVfile << header << endl;

    for (int i = 0; i < 10; i++) {

        if (phonebook[i].name.length() == 0){
            break;
        }

        CSVfile << phonebook[i].name << ','
                << phonebook[i].birthdate << ','
                << phonebook[i].phone << endl;

    }

    CSVfile.close();

    return 0;
}

//Takes as input: the name, birthdate and phone number entered by the user
//add those into the phonebook
int addRecord(string pName, string pBirthdate, string pPhone){

    //find the next empty slot for the phonebook

    int empty_slot;

    for (int i = 0; i < 10; i++){
        if (phonebook[i].name.length() == 0){
            empty_slot = i;
            break;
        }
    }

    phonebook[empty_slot].name = pName;
    phonebook[empty_slot].birthdate = pBirthdate;
    phonebook[empty_slot].phone = pPhone;

    return 0; //everything ok
}

//Takes as input: the name the user is searching for
//retun the contact info if it matches the search
int findRecord(string pName){

    for (int i = 0; i < 10; i++){

        if (phonebook[i].name.length() == 0){

            //looked through every record
            cout << "Record does not exist\n";
            break;
        }

        if (phonebook[i].name == pName){

            string header = "-----------NAME----------- ------BIRTH------ -----PHONE-----\n";
            int name_len = 27;
            int birth_len = 18;
            int phone_len = 15;

            int name_ws = name_len - phonebook[i].name.length();
            int birth_ws = birth_len - phonebook[i].birthdate.length();
            int phone_ws = phone_len - phonebook[i].phone.length();

            cout << header 
                 << phonebook[i].name << string(name_ws, ' ')
                 << phonebook[i].birthdate << string(birth_ws, ' ')
                 << phonebook[i].phone << string(birth_ws, ' ')
                 << "\n";

            break;
        }
    }

    return 0; //everything ok
}

//no input parameters
//prints every records in the phonebook
int listRecords(){

    string header = "-----------NAME----------- ------BIRTH------ -----PHONE-----\n";
    cout << header;

    for (int i = 0; i < 10; i++){
        if (phonebook[i].name.length() == 0){

            break;
        }

        int name_len = 27;
        int birth_len = 18;
        int phone_len = 15;

        int name_ws = name_len - phonebook[i].name.length();
        int birth_ws = birth_len - phonebook[i].birthdate.length();
        int phone_ws = phone_len - phonebook[i].phone.length();

        cout << phonebook[i].name << string(name_ws, ' ')
             << phonebook[i].birthdate << string(birth_ws, ' ')
             << phonebook[i].phone << string(birth_ws, ' ')
             << "\n";

    }

    return 0; //everything okay
}