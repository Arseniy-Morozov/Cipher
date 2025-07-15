#include<iostream>
#include<string>
#include "func.h"
using namespace std;

int main()
{
    string inputText;   // Входной текст
    string key;         // Ключ для шифрования

    cout << "Пароль" << endl;
    getline(cin, inputText);
    cout << "\nКлюч" << endl;
    getline(cin, key);
    string encp = toHexString(encryptionXOR(inputText, key));
    cout << encp << endl;


}

