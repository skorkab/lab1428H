// preprocessor directive
#include <iostream>
#include <iomanip>

using namespace std;

struct song{
    string songTitle = "";
    string fileName = "";
    string genre = "";
    int trackNumber = -1;
    bool fav = false;
};
song ipod[100] = {};
int addSong(string title, string file, string gen, int track, bool favor);
int removeSong(int i);
int displayAll();
int editSong(int i);
int printFavs;
// main function declaration
// opening and closing braces indicate the beginning and end of the 'main' function
int main()
{
    int menu;
    int track;
    string input;
    bool exit = false;
    while(!exit)
    {
        cout << "******************************************" << endl;
        cout << "*" << setw(18) << " " << "Ipod" << setw(18) << " " << "*" << endl;
        cout << "******************************************" << endl;
        cout << "*" << left << setw(40) << " 1)  Add a Song" << "*" << endl;
        cout << "*" << setw(40) << " 2)  Remove a Song" << "*" << endl;
        cout << "*" << setw(40) << " 3)  Display all songs" << "*" << endl;
        cout << "*" << setw(40) << " 4)  Edit a Song" << "*" << endl;
        cout << "*" << setw(40) << " 5)  Print Favorite Songs" << "*" << endl;
        cout << "*" << setw(40) << " 6)  Exit" << "*" << endl;
        cout << "******************************************" << endl;
        cout << "Enter Choice:  ";
        cin >> menu;
        switch (menu)
        {
            case 1: cout << "What is the song's track number: ";
            cin >> track;
            if(!track<0||!track>99)
            {
                ipod[track].trackNumber = track;
                cout << "What is the song's title: ";
                cin >> input;
                ipod[track].songTitle = input;
                cout << "What is the song's file name: ";
                cin >> input;
                ipod[track].fileName = input;
                cout << "What is the song's genre: ";
                cin >> input;
                ipod[track].genre = input;
                cout << "What is the song's title: ";
                cin >> input;
                if(input=="yes"||input=="Yes")
                {
                    ipod[track].fav = true;
                }
                else
                {
                    ipod[track].fav = false;
                }
            }
            else
            {
                cout << "Out of bounds";
            }
            break;
            case 2: cout << "What track number should I delete: ";
            cin >> track;
            if(!track<0||!track>99)
            {
                cout << "Are you sure: ";
                cin >> input;
                if(input=="yes"||input=="Yes")
                {
                    ipod[track].songTitle = "";
                    ipod[track].fileName = "";
                    ipod[track].genre = "";
                    ipod[track].trackNumber = -1;
                    ipod[track].fav = false;
                }
            }
            else
            {
                cout << "Out of bounds";
            }
            break;
            case 3: cout << "************************************************************************************" << endl;
            cout << "*" << setw(39) << " " << "Songs" << setw(38) << " " << "*" << endl;
            cout << "************************************************************************************" << endl;
            cout << "*" << " " << setw(8) << "Track" << setw(20) << "* Song Title" << setw(14) << "* Genre" << setw(9) << "* Fav" << setw(29) << "* File Name" << " " << "*" << endl;
            cout << "************************************************************************************" << endl;
            for(int i = 0; i<100; i++)
            {
                if(ipod[i].fileName!="")
                {
                    if(ipod[i].fav == true)
                    {
                        cout << "*" << " " << setw(8) << ipod[i].trackNumber << "* " << setw(18) << ipod[i].songTitle << "* " << setw(12)
                        << ipod[i].genre << "* " <<  setw(7) << "Y" << "* " << setw(27) << ipod[i].fileName << " " << "*" << endl;
                    }
                    else
                    {
                        cout << "*" << " " << setw(8) << ipod[i].trackNumber << "* " << setw(18) << ipod[i].songTitle << "* " << setw(12)
                        << ipod[i].genre << "* " <<  setw(7) << "N" << "* " << setw(27) << ipod[i].fileName << " " << "*" << endl;
                    }
                }
            }
            cout << "************************************************************************************" << endl << endl;
            case 4: cout << "What track number should I edit: ";
            cin >> track;
            if(!track<0||!track>99)
            {
                ipod[track].trackNumber = track;
                cout << "What is the song's title: ";
                cin >> input;
                ipod[track].songTitle = input;
                cout << "What is the song's file name: ";
                cin >> input;
                ipod[track].fileName = input;
                cout << "What is the song's genre: ";
                cin >> input;
                ipod[track].genre = input;
                cout << "What is the song's title: ";
                cin >> input;
                if(input=="yes"||input=="Yes")
                {
                    ipod[track].fav = true;
                }
                else
                {
                    ipod[track].fav = false;
                }
            }
            else
            {
                cout << "Out of bounds";
            }
            break;
            case 5: cout << "************************************************************************************" << endl;
            cout << "*" << setw(34) << " " << "Favorite Songs" << setw(34) << " " << "*" << endl;
            cout << "************************************************************************************" << endl;
            cout << "*" << " " << setw(8) << "Track" << setw(20) << "* Song Title" << setw(14) << "* Genre" << setw(9) << "* Fav" << setw(29) << "* File Name" << " " << "*" << endl;
            cout << "************************************************************************************" << endl;
            for(int i = 0; i<100; i++)
            {
                if(ipod[i].fileName!="")
                {
                    if(ipod[i].fav == true)
                    {
                        cout << "*" << " " << setw(8) << ipod[i].trackNumber << "* " << setw(18) << ipod[i].songTitle << "* " << setw(12)
                        << ipod[i].genre << "* " <<  setw(7) << "Y" << "* " << setw(27) << ipod[i].fileName << " " << "*" << endl;
                    }
                }
            }
            cout << "************************************************************************************" << endl << endl;
            break;
            case 6: exit = true;
        }
    }
    return 0;
}
