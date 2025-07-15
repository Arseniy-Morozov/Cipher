#include<iostream>
#include<string>
#include <iomanip>
#include <sstream>
#include <charconv> 
using namespace std;



//Шифрование

string encryptionXOR(const string& text, const string& key)
{
    string result = "";


    //Переборка каждого символа входного текста
    for(size_t i = 0; i < text.length(); ++i)
    {
        unsigned char textChar = text[i]; // текущий символ текста
        unsigned char keyChar = key[i % key.length()]; // соответствующий символ ключика
        int offset = (int)i % 7; //  модуль по позиции - дополнительное смещение (i необязательно приводить к инту, но лишним не будет)

        /*
            Ксорим символ текста и символ ключа, после прибавляем смещение
        */
        unsigned char encryptedChar = (textChar ^ keyChar) + offset;
        result += encryptedChar;
    }
    return result;
}


//Расшифровка (зеркальный процесс)

string decryptionXOR(const string& encryptedText, const string& key)
{
    string result = "";


    //Переборка каждого символа входного текста
    for(size_t i = 0; i < encryptedText.length(); ++i)
    {
        unsigned char encryptedChar = encryptedText[i]; // текущий символ текста
        unsigned char keyChar = key[i % key.length()]; // соответствующий символ ключика
        int offset = (int)i % 7; //  модуль по позиции - дополнительное смещение (i необязательно приводить к инту, но лишним не будет)

        /*
            Обратный процесс предыдущей функции
        */
        unsigned char decryptedChar = (encryptedChar - offset) ^ keyChar;
        result += decryptedChar;
    }
    return result;
}

// перевод в 16-ричный формат так как шифрованный результат может быть не читаемым
string toHexString(const string& data) {
    stringstream ss;
    ss << hex << setfill('0'); 
    for (unsigned char c : data) {
        ss << setw(2) << (int)c; // задаем что бы число выводилос двумя символами - вместо a - 0a
    }
    return ss.str();
}


// перевод из 16-ричного формата в "изначальные шифрованные байты"
string hexStringToBytes(const string& hex) {
    if (hex.size() % 2 != 0)
        throw invalid_argument("HEX string length must be even");

    string bytes;
    bytes.reserve(hex.size() / 2);

    for (size_t i = 0; i < hex.size(); i += 2) {
        unsigned int byte = 0;
        auto [ptr, ec] = from_chars(hex.data() + i, hex.data() + i + 2, byte, 16);
        if (ec != std::errc() || ptr != hex.data() + i + 2)
            throw invalid_argument("Invalid HEX format");
        bytes.push_back(static_cast<unsigned char>(byte));
    }
    return bytes;
}