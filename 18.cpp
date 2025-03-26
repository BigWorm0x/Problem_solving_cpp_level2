#include <iostream>
#include <string>
using namespace std;

int readOption()
{
    int number;
    cout << "Choose your option:\n1: Encrypt\n2: Decrypt\n";
    cin >> number;
    cin.ignore(); 
    return number;
}

string readText()
{
    string text;
    cout << "Please enter text:\n";
    getline(cin, text);
    return text;
}

string encryptText(string text, short key)
{
    string encryptedText;
    for (char c : text)
    {
        encryptedText += c + key;
    }
    return encryptedText;
}

string decryptText(string text, short key)
{
    string decryptedText;
    for (char c : text)
    {
        decryptedText += c - key;
    }
    return decryptedText;
}

void processOption(int option)
{
    const short key = 5;
    if (option == 1)
    {
        string text = readText();
        cout << "Encrypted text: " << encryptText(text, key) << endl;
    }
    else if (option == 2)
    {
        string text = readText();
        cout << "Decrypted text: " << decryptText(text, key) << endl;
    }
    else
    {
        cout << "Invalid option!" << endl;
    }
}

int main()
{
    processOption(readOption());
    return 0;
}
