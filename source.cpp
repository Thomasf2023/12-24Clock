#include <time.h>
#include <stdio.h>
#include <string>
#include <chrono>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstring>
#include <stdlib.h>
#include<dos.h> 
#include <Windows.h>



// This program will display 2 clock, and then a menu. The menu will have 4 options, add one hour, add one minute, 
// add one second, and exit program. It will run until the user exit's the program. It will display the clocks in two formats,
// 24 hour format and 12 hour format. The 12 hour clock will also display AM and PM. 

//Author: Thomas Fiske
//Date: 01/17/2022
using namespace std;

//Variables
int hours12 = 12;
int minutes12 = 34;
int seconds12 = 28;
int hours24 = 13;
int minutes24 = 54;
int seconds24 = 24;
string amOrPm = "";
//There is hours,minutes, and seconds for each clock to make them display a seperate time

void addHour() { // Function that will add an hour onto the clock when requested by the user.
    hours12 = hours12 + 1;
    hours24 = hours24 + 1;
    if (hours12 > 12) {
        hours12 = hours12 = 1;
        amOrPm = "PM";
    }
    if (hours24 > 24) {
        hours24 = hours24 = 0;
    }
}

void addMinute() { // Function that will add a minute onto the clock when requested by the user.
    minutes12 = minutes12 + 1;
    minutes24 = minutes24 + 1;
    if (minutes12 > 60) {
        minutes12 = minutes12 = 0;
    }
    if (minutes24 > 60) {
        minutes24 = minutes24 = 0;
    }
}

void addSecond() { // Function that will add an second onto the clock when requested by the user.
    seconds12 = seconds12 + 1;
    seconds24 = seconds24 + 1;
    if (seconds12 > 60) {
        seconds12 = seconds12 = 0;
    }
    if (seconds24 > 60) {
        seconds24 = seconds24 = 0;
    }
}

void print12Clock(int hours, int minutes, int seconds) { // Function that prints 12 hour clock.

    
    if (minutes >= 60) {
        minutes -= 60;
    }
    if (seconds >= 60) {
        seconds -= 60;
    }
    cout << "*******************" << endl;
    cout << "* 12-hour Clock   *" << endl;
    cout << "* ";

    if ((hours12 >= 0) && (hours12 < 10)) {
        cout << "0";
    }
   cout << hours << ":" << minutes << ":" << seconds << "" << amOrPm;
    
    cout << "      *" << endl;
    cout << "*******************" << endl;

}

void print24Clock(int hours, int minutes, int seconds) { // Function that prints 24 hour clock.

    if (hours >= 24) {
        hours -= 24;
    }
    if (minutes >= 60) {
        minutes -= 60;
        hours += 1;
    }
    if (seconds >= 60) {
        seconds -= 60;
        minutes += 1;
    }
    cout << "*******************" << endl;
    cout << "* 24-hour Clock   *" << endl;
    cout << "* ";
    if ((hours >= 0) && (hours < 10)) {
        cout << "0";
    } 
    cout << hours << ":" << minutes << ":" << seconds << "        *" << endl;
    cout << "*******************" << endl;


    
}

//void getTime() { //Get Time function that gets local time from computer

    //time_t ttime = time(0);
    //tm* local_time = localtime(&ttime);

   // hour = local_time->tm_hour;
   // minutes = local_time->tm_min;
   // seconds = local_time->tm_sec;


        

int menu() { // function that prints main menu

    int choice; 

    cout << "*********************" << endl;
    cout << "*     Main Menu     *" << endl;
    cout << "*                   *" << endl;
    cout << "* 1: Add One Hour   *" << endl;
    cout << "* 2: Add One Minute *" << endl;
    cout << "* 3: Add One Second *" << endl;
    cout << "* 4: Exit Program   *" << endl;
    cout << "*                   *" << endl;
    cout << "*********************" << endl;

    cin >> choice; //user input 

    while (choice != 4) { //While menu that will run until user selects exit program option
        if (choice == 1) { // Add one hour
            addHour();
            if (hours12 > 12) { // Prints AM or PM 
                hours12 = hours12 = 1;
                amOrPm = "PM";
            }
            print12Clock(hours12, minutes12, seconds12);
            print24Clock(hours24, minutes24, seconds24);
            Sleep(1000);
            system("CLS");
            hours12 = 12; //Resets time on clock
            hours24 = 13;
            menu();
            cin >> choice;
        }
        else if (choice == 2) { //Add one minute
            addMinute();
            print12Clock(hours12, minutes12, seconds12);
            print24Clock(hours24, minutes24, seconds24);
            Sleep(1000);
            system("CLS");
            minutes12 = 34;
            minutes24 = 54;
            menu();
            cin >> choice;
        }
        else if (choice == 3) { //Add one second
            addSecond();
            print12Clock(hours12, minutes12, seconds12);
            print24Clock(hours24, minutes24, seconds24);
            Sleep(1000);
            system("CLS");
            seconds12 = 28;
            seconds24 = 24;
            menu();
            cin >> choice;
        }
        else {
            cout << "Error:Incorrect Input";
            Sleep(1000);
            system("CLS");
            menu();
            cin >> choice;
        }
    }
    if (choice == 4) { // Exit program
        cout << "Thank you for using our Clock!" << endl;
    }
    return 0;
}



int main() { // main function
    

    print12Clock(hours12, minutes12, seconds12);
    print24Clock(hours24, minutes24, seconds24);
    
    Sleep(1000); //will rogram delay 1 second

    system("CLS"); //clears screen

    menu();

    
   
    
    



}
