#include <iostream>
using namespace std;

string textToBin(char text);
string asciiToBin(int num);
void reverseString(string &input);
string swapBinString(string &str);
string initialPermutation(string &str);
char encryption(char strText, char key);
char binaryToChar(const string &binaryStr);
char decryption(char cText, char key);
string inversePermutation(string &str);
string xorFunction(string text, string key);

int main()
{
    string purpose{};
    cout << "Enter E For Encryption and D For Decryption" << endl;
    cin >> purpose;

    if (purpose == "E")
    {
        char plainText{};
        cout << "Enter One Character to Encrypt" << endl;
        cin >> plainText;

        char key{};
        cout << "Enter One Character for Key to Encrypt" << endl;
        cin >> key;

        char cipherText = encryption(plainText, key);
        cout << "Cipher Text IS  " << cipherText << endl;
    }

    if (purpose == "D")
    {
        char cipherText{};
        cout << "Enter Cipher Character" << endl;
        cin >> cipherText;

        char key{};
        cout << "Enter One Character for Key to Decrypt" << endl;
        cin >> key;

        char plainText = decryption(cipherText, key);
        cout << "Plain Text IS  " << plainText << endl;
    }

    return 0;
}

//// Converts Text To Binary ////

string textToBin(char text)
{
    int ascii = text;
    string binString{""};
    binString = asciiToBin(ascii);
    return binString;
}

string asciiToBin(int num)
{
    string binString{""};
    while (num > 0)
    {
        binString += to_string(num % 2);
        num /= 2;
    }
    while (binString.length() < 8)
    {
        binString += '0';
    }
    reverseString(binString);
    return binString;
}

//// Reverse Strings ////

void reverseString(string &input)
{
    int left = 0;
    int right = input.length() - 1;

    while (left < right)
    {
        // Swap characters at the left and right positions
        swap(input[left], input[right]);

        left += 1;
        right -= 1;
    }
}

//// Swap String Such That Right Part of String Become Left ////
//// AND Left Part of String Become Right ////

string swapBinString(string &str)
{
    string swapString{""};
    string leftString{""};
    string rightString{""};

    for (int i{0}; i < 4; i += 1)
    {
        leftString += str[i];
    }
    for (int i{4}; i < 8; i += 1)
    {
        rightString += str[i];
    }
    swapString += rightString;
    swapString += leftString;

    return swapString;
}

// Permutate the String According to Given Algorithm

string initialPermutation(string &str)
{
    string ipString{""};
    string leftString{""};
    string rightString{""};

    for (int i{0}; i < 8; i += 1)
    {
        if (i % 2 == 0)
        {
            rightString += str[i];
        }
        else
        {
            leftString += str[i];
        }
    }
    reverseString(leftString);
    reverseString(rightString);
    ipString += leftString;
    ipString += rightString;

    return ipString;
}

// Encryption Method to Encrypt the Cipher

char encryption(char strText, char key)
{
    string binText = textToBin(strText);
    string swapedString = swapBinString(binText);
    string permutatedString = initialPermutation(swapedString);

    string cipherText{""};
    // Binary Key
    string strKey = textToBin(key);
    cipherText = xorFunction(permutatedString, strKey);
    cout << "Cipher Text Binary Is " << cipherText << endl;
    char cipher = binaryToChar(cipherText);
    return cipher;
}

string xorFunction(string text, string key)
{
    string xorString{""};
    for (int i{}; i < 8; i += 1)
    {
        int textNum = text[i] - '0';
        int keyNum = key[i] - '0';
        xorString += ((textNum ^ keyNum) + '0');
    }
    return xorString;
}

// Convert binary string to decimal integer

char binaryToChar(const string &binaryStr)
{

    // Convert binary string to decimal integer
    int decimalValue = 0;
    for (int i = 0; i < 8; ++i)
    {
        decimalValue = (decimalValue << 1) + (binaryStr[i] - '0');
    }
    char charValue = char(decimalValue);

    return charValue;
}

char decryption(char cText, char key)
{
    string cBin = textToBin(cText);

    string strKey = textToBin(key);

    string XorText{""};
    XorText = xorFunction(cBin, strKey);
    string inversePermutated = inversePermutation(XorText);
    string swapedString = swapBinString(inversePermutated);
    reverseString(swapedString);
    string plainTextBin = swapedString;
    cout << "Plain Text Bin Is " << plainTextBin << endl;
    char plainText = binaryToChar(plainTextBin);
    return plainText;
}

string inversePermutation(string &str)
{
    string ipString{""};

    ipString.push_back(str[7]);
    ipString.push_back(str[3]);
    ipString.push_back(str[6]);
    ipString.push_back(str[2]);
    ipString.push_back(str[5]);
    ipString.push_back(str[1]);
    ipString.push_back(str[4]);
    ipString.push_back(str[0]);
    reverseString(ipString);

    return ipString;
}