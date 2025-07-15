#include<iostream>
#include<string>
#include "func.h"
using namespace std;


int main()
{
    
    string ciText, key;
    cout << "Шифрованная комбианция" << endl;
    getline(cin, ciText);
    cout << "\nКлюч" << endl;
    getline(cin, key);
    string res  = decryptionXOR(hexStringToBytes(ciText), key);
    cout << res << endl;
}


