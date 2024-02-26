#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream InPutFile("plaintext.txt", ios::in);
    ofstream outPutFile("ciphertext.txt", ios::out);
    char data{' '};
    while (InPutFile >> data)
    {
        outPutFile << data;
    }
    // while (outPutFile >> data)
    // {
    //     cout << data;
    // }
    return 0;
}