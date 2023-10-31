#include <string>
using namespace std;

struct PHONE_RECORD {
        string name;
        string birthdate;
        string phone;
     };;

//extern the struct for mini5phone.c and mini5main.c
extern struct PHONE_RECORD phonebook[10];