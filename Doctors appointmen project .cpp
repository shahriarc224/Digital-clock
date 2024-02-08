/*Ahsanullah university er ak boro vai er project korsolam */


// youtube link :https://youtu.be/Y7O43TXtFyk?si=vwbUkQm_bzikedrr



/*
|-----------------------------------------------------------------------------------------|
| Project Name: Doctors appointment management system                                     |
|-----------------------------------------------------------------------------------------|
| Submitted by:                          | PROJECT SUBMISSION DATE  :    3.2.2024         |        |
| SAHRIKH BIN KHAIR ANIM                 |                                                |
| ID :20210105209                        |                                               |
| Sec:C                                  |Department of Electrical & Electronic Engineering
|                                        | AHSANULLAH UNIVERSITY OF SCIENCE AND TECHNOLOGY|
|                                        | (AUST)                                         |
|                                        |                                                |
|                                        |                                                |
|-----------------------------------------------------------------------------------------|
| project description: This project is a Doctors appointment management system .          |
|

                                            |
|-----------------------------------------------------------------------------------------|

*/


#include <bits/stdc++.h>
using namespace std;

  void getAppointmentDetails(string &firstName, string &lastName, char &gender, string &bloodGroup, int &age)
 {

    cout<<"____________________________________DOCTORS APPOINTMENT___________________________________"<<endl;


    cout << "Enter your first name: ";
    cin >> firstName;

    cout << "Enter your last name: ";
    cin >> lastName;

    cout << "Enter your gender  (M/F): ";
    cin >> gender;

    while (gender != 'M' && gender != 'F')
    {
        cout << "Invalid input. Please enter M or F : ";
        cin >> gender;
    }

    cout << "Enter your blood group (A+, A-, B+, B-, AB+, AB-, O+, O-) : ";
    cin >> bloodGroup;

     while (bloodGroup != "A+" && bloodGroup != "A-" && bloodGroup != "B+" && bloodGroup != "B-" && bloodGroup != "AB+" && bloodGroup != "AB-" && bloodGroup != "O+" && bloodGroup != "O-")
    {
        cout << "Invalid input. Please enter a valid blood group: ";
        cin >> bloodGroup;
    }

    cout << "Enter your age: ";
    cin >> age;

     while (age < 0)
    {
        cout << "Invalid input. Please enter a valid age: ";
        cin >> age;
    }
}



  int bookAppointment ()
{
    system ("cls");
    cout << "\n *************************************** Available slots **************************************\n";
    ifstream read;
    read.open ("appointment.dat");
    int hoursbook = 8;
    int arr[13] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int recordFound = 0;
    if (read)
    {
        string line;
        char key = 'A';
        int i = 9;

        while (getline (read, line))
        {
            char temp = line[0];
            int index = (temp - 65);
            arr[index] = 1;
            recordFound = 1;
        }
        if (recordFound == 1)
        {
            cout << "\n Appointment Summary by hours:";
            char key = 'A';
            int hours = 9;
            for (int i = 0; i <= 12; i++)
            {
                if (i == 0)
                {
                    if (arr[i] == 0)
                        cout << "\n " << key << ": 0" << hours << " - Available";
                    else
                        cout << "\n " << key << ": 0" << hours << " - Booked";
                }
                 else
                {
                    if (arr[i] == 0)
                        cout << "\n " << key << ":" << hours << " - Available";
                    else
                        cout << "\n " << key << ":" << hours << " - Booked";
                }
                 hours++;
                 key++;
            }
         }
         read.close ();
    }
     if (recordFound == 0)
    {
        cout << "\n Appointment is available for following hours :";
         char key = 'A';
        for (int i = 8; i <= 20; i++)
        {
            if (i == 8)
                cout << "\n" << key << ":0" << i << " - Available";
            else
                cout << "\n" << key << ":" << i << " - Available";
            key++;
        }
     }
    char choice;
    cout << "\n\n Input your choice : ";
    cin >> choice;
    if (!(choice >= 'A' && choice <= 'Z'))
    {
         cout << "\n Error:Invalid Selection";
         cout << "\n Please selction correct value from menu A- Z";
         cout << "\n Press any key to continue";
        getchar ();
        getchar ();
        system ("cls");
        bookAppointment ();
    }
     int index = (choice - 65);
     int isBooked = 1;
     if (arr[index] == 0)
        isBooked = 0;

    if (isBooked == 1)
     {
         cout << "\n Error: Some one has already booked an appointment in this Hour.Please kindly choose another hour.";
         cout << "\n Please select different time !!";
        cout << "\n Press any key to continue...";
          getchar ();
         getchar ();
         system ("cls");
         bookAppointment ();
     }

    string name;
     cout << "\n Enter Doctors name:";
     cin >> name;

    ofstream out;
    out.open ("appointment.dat", ios::app);

    if (out)
    {
         out << choice << ":" << name.c_str () << "\n";
        out.close ();

        std::this_thread::sleep_for(std::chrono::microseconds(500000));


        cout << "\n  Your appointment has been successfully granted.It is scheduled in Hours : " << (choice - 65) + 9 << " successfully!!";
    }
     else
     {
        cout << "\n Error while saving booking";
    }

     cout << "\n If you want an appointment of another doctor than press any key to continue..";
     getchar ();
     getchar ();
     return 0;
}

 int existingAppointment ()
{
     system ("cls");
    cout << "\n ----- Appointments Summary ---- \n";
    //check if record already there..
    ifstream read;
    read.open ("appointment.dat");

    int hoursbook = 8;

     int arr[13] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
     int recordFound = 0;

     if (read)
     {
        string line;
        char key = 'A';
        int i = 9;

        while (getline (read, line))
        {
             char temp = line[0];
            int index = (temp - 65);
            arr[index] = 1;
             recordFound = 1;
        }
        if (recordFound == 1)
        {
             cout << "\n Appointment Summary by hours :";
             cout<<endl;
             cout<<endl;
            char key = 'A';
            int hours = 9;
            for (int i = 0; i <= 12; i++)
            {
                if (arr[i] == 0)
                    cout << "\n " << key << ":" << hours << " - Available";
                else
                    cout << "\n " << key << ":" << hours << " - Booked";
                hours++;
                key++;
            }

        }

        read.close ();
    }
    else
    {
        char key = 'A';
        for (int i = 9; i <= 21; i++)
        {
            if (i == 9)
                cout << "\n " << key << " :0" << i << " - Available";
            else
                cout << "\n " << key << " :" << i << " - Available";
            key++;
        }
    }

    cout << "\n Please any key to continue..";
    getchar ();
    getchar ();
    return 0;
}


//Main function

int main (int argc, char **argv)
{

    string firstName, lastName;
    char gender;
    string bloodGroup;
    int age;

    getAppointmentDetails(firstName, lastName, gender, bloodGroup, age);        //function for heading...

    cout << "\nAppointment Details: \n";
    cout << "Name: " << firstName << " " << lastName << "\n";
    cout << "Gender: " << gender << "\n";
    cout << "Blood Group: " << bloodGroup << "\n";
    cout << "Age: " << age << "\n";

    while (1)                                            //infinity loop
    {
        system ("cls");
        cout << "\t\t\tDoctor Appointment System\n";
        cout << "-----------------------------------------------------------------\n\n";

        cout << "1. Book Appointment\n";
        cout << "2. Check available Appointment\n";
        cout << "0. Exit\n";
        int choice;

        cout << "\n Enter you choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            bookAppointment ();
            break;
        case 2:
            existingAppointment ();
            break;
        case 0:
            while (1)
            {
                system ("cls");
                cout << "\n Are you sure, you want to exit? y | n \n";
                char ex;
                cin >> ex;
                if (ex == 'y' || ex == 'Y')
                    exit (0);
                else if (ex == 'n' || ex == 'N')
                {
                    break;
                }
                else
                {
                    cout << "\n Invalid choice ...";
                    getchar ();
                }
            }
            break;

        default:
            cout << "\n Invalid choice. Enter again... ";
            getchar ();

        }

    }
    return 0;
}

                         //END









