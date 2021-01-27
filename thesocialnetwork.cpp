#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

struct User_input{
    string firstname, surname, email, password;
    int choice1, choice2;                   // CHOICE1 = OUTER , CHOICE2 = INNER
    bool toLoop = true;
};

class User{
    private:
        string user_password;
        string email_address;
    public:
	    string first_name;
	    string sur_name;
        string filename;
        string gender;
        string birthday;
        string post;

	    string setPassword(string password){
            this->user_password = password;
        }string getPassword(){
            return user_password;
        }
	    string setEmail(string email){        //for email
            this->email_address = email;
        }string getEmail(){
            return email_address;
        }
        void HomePage(ifstream &User_file, string firstname, string surname, string gender, string birthday, string for_email, string for_password, ofstream &User_fileO);
        //void Profile(ifstream &User_file, string firstname, string for_email, string for_password);

};

void OFile(ofstream &User_fileO, string first_name, string surname, string gender, string birthday, string email, string password, string post){
    User_fileO << first_name <<  "  " << surname << "  " << gender << "  " << birthday << "  " <<email << "  " << password << "  " << post << "  ";
}

void Convert(string name){             //Convert to Lowercase
    int length = name.length();
    for (int i=0; i<length; i++){
        if(name[i] >= 'A' && name[i]<= 'Z'){
            name = name[i] +32;
        }
        else{
            name = name[i];
        }
    }
}

void Convert_Upper(string& input){             //Convert to uppercase
    for (int i=0; i < input.length(); i++){
        input[i] = toupper(input[i]);
    }
}

void MindTwist(){
    bool toEnd = false;
    string input, choice;

    while (toEnd == false){
        cout << "\t\t Welcome to Mind Twist! " << endl << endl << "\t\t";
        cout << "Enter a word, phrase or a sentence: " << endl << endl << "\t\t";
        getline(cin,input);
        cout << endl << endl; Sleep(500);
        Convert_Upper(input);

        for(int i=0;input[i]!='\0';i++){
            switch (input[i]){
                case 'A':input[i]='4';
                         break;
                case 'E':input[i]='3';
                         break;
                case 'I':input[i]='1';
                         break;
                case 'O':input[i]='0';
                         break;
                case 'S':input[i]='5';
                         break;
                case 'T':input[i]='7';
            }
        }
        cout<<": " << input << endl << endl;
        cout << "Do you want to convert again? [ Y | N ]: ";
        cin >> choice;
        cin.ignore();
        if (choice == "y" || choice == "Y"){
            cout << "Loading ."; Sleep(500); cout <<"."; Sleep(500); cout <<"."; Sleep(2000);
            system("cls");
        }else if (choice == "n" || choice == "N"){
            cout << "Redirecting to Games ."; Sleep(500); cout <<"."; Sleep(500); cout <<"."; Sleep(2000);
            system("cls");
            toEnd = true;
        }else{
            cout <<"Invalid Choice, Redirecting to Games ."; Sleep(500); cout <<"."; Sleep(500); cout <<"."; Sleep(2000);
            system("cls");
            toEnd = true;
        }
    }
}

void RPS(){
    int computer;
	char user, playAgain;

	enum GameStates{
	ROCK, PAPER, SCISSORS
	};

	bool Quit = false;

	//cout << "\tRock, Paper and Scissors! " << endl <<endl <<endl; Sleep(900);


    // while loop until Quit falls to true
	while(1){
		if (Quit)
			break;
        {
            cout << "\tRock, Paper and Scissors! " << endl <<endl <<endl;
			cout << "   Choose your weapon:" << endl; Sleep(400);
			cout << "   R for Rock" << endl; Sleep(400);
			cout << "   P for Paper" << endl; Sleep(400);
			cout << "   S for Scissors" << endl; Sleep(400);
			cout << "   Q for Quit" << endl << endl; Sleep(400);
			cout << endl << "   : ";
			cin >> user;

			user = tolower(user);

			if (user == 'q'){
				Quit = true;
				cout << "   Thanks for Playing." << endl;
				break;
			}

            while (1){
                if (!(user == 'r' || user == 'p' || user == 's'))
				{   cout << "   Invalid Option! Please try again." << endl << endl;
                    cout << ": ";
                    cin >> user;
                    if (user == 'q'){
                        exit(1);
                        break;
                    }
                }else{
                	break;
                }
            }
            cout <<endl <<endl;
			// Computer's moves
			computer = rand() % 3; /*generate pseudo-random numbers in a determined range of 0-3 */
			switch(computer){
            case ROCK:
				if (user == 'r')
					cout << "Computer chose 'ROCK'... Tied!" << endl;
				if (user == 'p')
					cout << "Computer chose 'ROCK'... You Win!" << endl;
				if (user == 's')
					cout << "Computer chose 'ROCK'... You Lose!" << endl;
				break;

			case PAPER:
				if (user == 'r')
					cout << "Computer chose 'PAPER'... You Lose!" << endl;
				if (user == 'p')
					cout << "Computer chose 'PAPER'... Tied!" << endl;
				if (user == 's')
					cout << "Computer chose 'PAPER'... You Win!" << endl;
				break;

			case SCISSORS:
				if (user == 'r')
					cout << "Computer chose 'SCISSORS'... You Win!" << endl;
				if (user == 'p')
					cout << "Computer chose 'SCISSORS'... You Lose!" << endl;
				if (user == 's')
					cout << "Computer chose 'SCISSORS'... Tied!" << endl;
				break;

            default:
				cout << "Please try again." << endl;
				system("cls");
				break;
			}

            // Play again?
			cout << endl << "Play again [Y/N]?: " ;
			cin >> playAgain;
			playAgain = tolower(playAgain);

			switch(playAgain){
				case 'y':
					system("CLS");
					break;
				case 'n':
					Quit = true;
					cout << endl << endl << "Thanks for Playing!" << endl;
					break;
				default:
                    cout << endl << endl << "Invalid choice! Redirecting back to game."; cout << "."; cout << "."; Sleep(700);
                    system("CLS");
					break;
			}
		}
	}

}

void News(){

	int newsChoice;
	char ch;
	bool toEnd = false;
    FILE * fPtr;

    while(toEnd == false){
        cout<<"\t NEWS"<<endl<<endl;
        cout<<"What do you want to read?"<<endl;
        cout<<"[1] COVID-19"<<endl;
        cout<<"[2] Technology"<<endl;
        cout<<"[3] Science"<<endl;
        cout<<"[4] Entertainment"<<endl;
        cout<<"[5] Back "<< endl <<endl<<endl;
        cout<<": ";
        cin>>newsChoice;

        if (newsChoice == 1) {                              	// COVID-19
            fPtr = fopen("news/COVID19.txt", "r");
            if(fPtr == NULL){
                cout<<"Unable to open file.\n";
                cout<<"Please check whether file exists and you have read privilege.\n";
                exit(EXIT_FAILURE);
            }
            cout<<"\nNews opened successfully. Fetching top COVID-19 news from Google News... \n\n";

            do {
                ch = fgetc(fPtr);
                putchar(ch);

            } while(ch != EOF);

            fclose(fPtr);
            system("pause");
            system("cls");
        }

        else if (newsChoice == 2) {                                  // Technology
            fPtr = fopen("news/Tech.txt", "r");
            if(fPtr == NULL){
                cout<<"Unable to open file.\n";
                cout<<"Please check whether file exists.\n";
                exit(EXIT_FAILURE);
            }
            cout<<"\nNews opened successfully. Fetching top Tech news from Google News... \n\n";

            do {
                ch = fgetc(fPtr);
                putchar(ch);

            } while(ch != EOF);
            fclose(fPtr);
            system("pause");
            system("cls");
        }

        else if (newsChoice == 3) {                               // Science
            fPtr = fopen("news/Science.txt", "r");
            if(fPtr == NULL){
                cout<<"Unable to open file.\n";
                cout<<"Please check whether file exists.\n";
                exit(EXIT_FAILURE);
            }
            cout<<"\nNews opened successfully. Fetching top Science news from Google News... \n\n";

            do {
                ch = fgetc(fPtr);
                putchar(ch);

            } while(ch != EOF);
            fclose(fPtr);
            system("pause");
            system("cls");
        }

        else if (newsChoice == 4) {                                   // Entertainment
            fPtr = fopen("news/Entertainment.txt", "r");
            if(fPtr == NULL){
                cout<<"Unable to open file.\n";
                cout<<"Please check whether file exists.\n";
                exit(EXIT_FAILURE);
            }
            cout<<"\nNews opened successfully. Fetching top Entertainment news from Google News... \n\n";
            do {
                ch = fgetc(fPtr);
                putchar(ch);

            } while(ch != EOF);
            fclose(fPtr);
            system("pause");
            system("cls");
        }
        else if (newsChoice == 5) {
            cout << "Redirecting to Homepage ."; Sleep(500); cout <<"."; Sleep(500); cout <<"."; Sleep(700);
            system("cls");
            toEnd = true;
        }else{
            system("cls");
        }
    }
}


void User::HomePage(ifstream &User_file, string firstname, string surname, string gender, string birthday, string for_email, string for_password, ofstream &User_fileO){                      //  HOMEPAGE
    User user;
    User_input input;
    string full_name;
    HOMEPAGE:
        while (input.toLoop == true){
            User_file.open(user.filename.c_str());
            if(!User_file.is_open()){
                cout << "File doesn't exist!"<<endl;
            }
            else{
                cout << "File is ready" << endl;
                cout << "Welcome ";

                User_file >> firstname >> surname >> gender >> birthday >> for_email >> for_password;
                cout << firstname << "!" << endl << endl;

                cout << "[1]Profile \t\t [2]Post \t\t [3]Games \t\t [4]News \t\t [5]Logout  \t\t" << endl << endl;
                cout << "What do you want to do?: ";
                cin >> input.choice1;


                switch (input.choice1){
                    case 1:                                                                             //  PROFILE
                        system("cls");
                        PROFILE:
                            cout << firstname << "'s PROFILE " << endl << endl;
                            cout << "[1]View \t\t [2]Exit Profile" << endl << endl;
                            cout << "What do you want to do?: ";
                            cin >> input.choice2;
                            //user.Profile(User_file, user.first_name, user.getEmail(), user.getPassword());
                            if(input.choice2 == 1){                                                             // VIEW PROFILE
                                system("cls");
                                cout << "View Profile" << endl << endl;
                                User_file >> firstname >> surname >> gender >> birthday >> for_email >> for_password;
                                full_name = firstname + " " + surname;
                                cout << "\t Name: ";
                                cout << full_name <<endl;
                                cout << "\t Gender: ";
                                cout << gender << endl;
                                cout << "\t Birthday: ";
                                cout << birthday << endl;
                                cout << "[1]Back" << endl<<endl;
                                cout << "What do you want to do?: ";                                    // GO BACK TO PROFILE PAGE
                                cin >> input.choice2;
                                if(input.choice2 == 1){
                                    system("cls");
                                    goto PROFILE;
                                }else{
                                    cout << "Invalid choice!";
                                }
                            }else if (input.choice2 == 2){                                      // EDIT PROFILE
                                cout << "Exit";
                                system("cls");
                            }
                            break;

                    case 2:
                        system("cls");
                        POST:
                            cout << "POST" << endl;
                            cout <<"[1]Write Post \t\t [2]View Post \t\t [3]Back" << endl << endl;
                            cout << ": ";
                            cin >> input.choice1;

                            if(input.choice1 == 1){                                 //  WRITE POST
                                cin.ignore();
                                cout << "\t\tTell The World How Your Feeling: "<<endl << endl << "\t\t" ;
                                getline(cin, user.post);

                                ofstream User_fileO;
                                User_fileO.open(user.filename.c_str());
                                OFile(User_fileO, user.first_name, user.sur_name, user.gender, user.birthday, input.email, input.password, user.post);
                                User_fileO.close();
                                cout << endl <<endl<<endl;
                                system("pause");
                                system("cls");
                                goto POST;
                            }else if (input.choice1 == 2){                      // EDIT POST
                                system("cls");
                                cout << "\t\tView your Posts: "<< endl << endl << "\t\t";
                                User_file.open(user.filename.c_str());
                                User_file >> user.post;
                                cout << user.post << endl <<endl <<endl;
                                system("pause");
                                system("cls");
                                goto POST;
                            }else if(input.choice1 == 3){
                                system("cls");
                            }
                        break;

                    case 3:
                        system("cls");
                        GAMES:
                            cout << "GAMES" << endl;
                            cout << "[1]Mind Twist \t\t [2]Rock Paper Scissors \t\t [3]Back" << endl <<endl;
                            cout << "\t: ";
                            cin >> input.choice1;
                            cin.ignore();

                            if(input.choice1 == 1){
                                system("cls");
                                MindTwist();
                                system("cls");
                                goto GAMES;
                            }else if (input.choice1 == 2){
                                system("cls");
                                RPS();
                                system("cls");
                                goto GAMES;
                            }else if (input.choice1 == 3){
                                system("cls");
                            }else{
                                cout << "Invalid choice, Redirecting to Games ."; Sleep(500); cout <<"."; Sleep(500); cout <<"."; Sleep(700);
                                goto GAMES;
                            }
                        break;

                    case 4:
                        system("cls");
                        News();
                        system("cls");
                        break;

                    case 5:
                        system("cls");
                        User_file.close();
                        cout << "Thank You For Using The Program! " << endl;
                        exit(0);
                        break;

                    default:
                        cout << "Invalid choice!" << endl;
                        break;

                }
            }
        }
}
int main()
{
    User user;
    User_input input;
    string name, for_email, for_password;
    ofstream User_fileO;
    ifstream User_file;

    while (input.toLoop == true){                       //  PORTAL
        cout<<"[1] Login" << endl;
        cout<<"[2] Sign up" <<endl;
        cout<<"[3] Exit" << endl <<endl;
        cout<<"Select an Option: ";
        cin >> input.choice1;
        cout << endl << endl;

        if(input.choice1 == 1){                                         // LOGIN

            while (input.toLoop == true){
                //system("cls");
                cout << "Enter below your first name to access the file where your info are saved. Please don't include spaces."<<endl;
                cout << "First Name: ";
                cin >> name;

                user.filename = name + ".txt";

                User_file.open(user.filename.c_str());

                if (!User_file.is_open()){                                                // IF FILE DOES NOT EXIST
                    cout <<"FILE NOT FOUND" << endl << endl; system("pause");
                    cout << endl << "Invalid File name! "; Sleep(400);
                    cout << "File doesn't exist."; Sleep(1000);
                    system("cls");
                }
                else
                {
                    cin.ignore();
                    system("cls");
                    cout <<"FILE IS READY" << endl << endl;                     // IF FILE EXIST
                    LOGIN:
                        cout <<endl << endl<< "Email: ";
                        getline(cin, input.email);
                        cout <<endl<< "Password: ";
                        getline(cin, input.password);

                        Convert(name);
                        for_email = user.getEmail();
                        for_password = user.getPassword();

                        //   FILE ACCESS (ACCESS DATA FROM FILE)
                        User_file >> user.first_name >> user.sur_name >> user.gender >> user.birthday >> for_email >> for_password;

                        while(input.toLoop == true){
                            if(input.email == for_email && input.password == for_password){
                                system("cls");

                                cout<<" Logging in . "; Sleep(400);
                                cout << ". "; Sleep(400);
                                cout << ". " <<endl;
                                system("cls");


                                input.toLoop = false;
                                user.HomePage(User_file, user.first_name, user.sur_name, user.gender, user.birthday, user.getEmail(), user.getPassword(), User_fileO);                      //ACCESS HOMEPAGE FUNCTION
                            }
                            else{
                                cout<<"Email or Password is invalid!"<<endl; Sleep(400);
                                cout<<"Try again, Redirecting to Login . "; Sleep(400);
                                cout<<". "; Sleep(400);
                                cout<<". " << endl;
                                system("cls");
                                goto LOGIN;
                            }
                        }
                }

            }
        }else if (input.choice1 == 2){                                          //SIGN UP
            cout << "First Name: ";
            cin >> input.firstname;
            cout << endl;
            cout << "Last Name: ";
            cin >> input.surname;
            GENDER:
                cout << "Gender (Male[M] | Female[F]): ";                   // TO CONVERT M -> MALE / F -> FEMALE
                cin >> user.gender;
                if(user.gender == "M" || user.gender == "m"){
                    user.gender = "Male";
                }else if(user.gender == "F" || user.gender == "f"){
                    user.gender = "Female";
                }else{
                    goto GENDER;
                }
            cin.ignore();
            cout << "Birthday (use the format mm/dd/yy): ";
            getline(cin, user.birthday);
            cout << endl<< "Email: ";
            getline(cin, input.email);
            cout << "Password: ";
            getline(cin, input.password);

            //CONVERT to access class variables
            user.first_name = input.firstname;
            user.sur_name = input.surname;
            user.setEmail(input.email);
            user.setPassword(input.password);

            Convert(input.firstname);

            user.filename = user.first_name + ".txt";           // TO MATCH FILE FORMAT

            //  FILE ACCESS (STORE DATA TO FILE)
            User_fileO.open(user.filename.c_str());
            OFile(User_fileO, user.first_name, user.sur_name, user.gender, user.birthday, input.email, input.password, user.post);

            User_fileO.close();

            system("cls");
            cout<<"Creating Account. ";   Sleep(400);
            cout<<". "; Sleep(400);
            cout<<". " << endl <<"Account Created! " <<endl;
            system("cls");
        }
        else if (input.choice1 == 3){
            cout << "Thankyou, for using the program!!" << endl;
            exit(0);
        }
        else {
            cout << "Invalid Choice, ";  Sleep(500);
            cout << "Please choose again." << endl;
            system("cls");
        }
    }
}


