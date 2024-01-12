#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
int string_length = characters.length();

string generatePassword(int n)
{
    string password = "";
    password += characters[rand() % 26];  // Uppercase letter
    password += characters[rand() % 10 + 52];  // Digit
    password += characters[rand() % 8 + 62];   // Special character

    for (int c = 3; c < n; ++c)
        password += characters[rand() % string_length];

    return password;
}

void createpassword()
{
    int n;
    cout << "Enter length of password (between 8 and 12): ";
    cin >> n;

    if (n < 8 || n > 12) {
        cout << "Password length must be between 8 and 12 characters." << endl;
        return;
    }

    srand(time(0));
    cout << "Generated password: " << generatePassword(n) << endl;
}

int main()
{
    string ch;
    char ab;

    cout << "Enter your name: ";
    cin >> ch;
    cout << "Welcome " << ch << "\n";

    cout << "Do you have an account? Type yes(Y) or no(N): ";
    cin >> ab;

    if (ab == 'Y') {
        cout << "Generated LOGIN is: ";
        for (int f = 0; f <= 8; f++)
            cout << characters[rand() % string_length];
        cout << "\n";
    } else {
        cout << "To create a login name:\n";
        cout << "Minimum one upper case.\nMinimum one digit.\nMinimum one symbol (only underscore is allowed).\n";

        string logname;
        cout << "Enter your login name: ";
        cin >> logname;
        cout << "You have entered: " << logname << "\n";
        cout << "Your login name has been successfully registered.\n";
    }
    cout << "\n";

    cout << "Let's create your password:\n";
    char genpass;
    cout << "Do you want to create a password by yourself or generate a password? (Y/N): ";
    cin >> genpass;

    if (genpass == 'Y') {
        createpassword();
    } else {
        cout << "Minimum one upper case.\nMinimum one digit.\nMinimum one symbol.\nPassword must be 8 to 12 characters.\n";
        string pass;
        cout << "Enter your password: ";
        cin >> pass;
        cout << "Your PASSWORD IS: " << pass << "\n";
    }

    cout << "\nYour password and login have been created successfully.\n";

    return 0;
}
