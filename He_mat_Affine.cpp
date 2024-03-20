#include <iostream>
#include <string>
using namespace std;
 

int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return -1;
}
 

char affineEncrypt(char ch, int a, int b) {
    int x = ch - 'a';
    int y = (a * x + b) % 26;
    char res = y + 'a';
    return res;
}
 
char affineDecrypt(char ch, int a, int b) {
    int y = ch - 'a';
    int x = modInverse(a, 26) * (y - b + 26) % 26;
    char res = x + 'a';
    return res;
}
 
bool coprime(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return (a == 1);
}
 
int main() {
    int a, b;
    cin >> a >> b;
    string s;
    cin.ignore();
    getline(cin, s);
 
    if (!coprime(a, 26)) {
        cout << "Can't Encrypted and Decrypted this Message" << endl;
        return 0;
    }
 
    string encrypted = "";
    for (char ch : s) {
    if(ch == ' ')
encrypted += ch;
        else{
        encrypted += affineEncrypt(ch, a, b);
}
    }
 
    string decrypted = "";
    for (char ch : encrypted) {
    if(ch == ' ')
decrypted += ch;
        else{
        decrypted += affineDecrypt(ch, a, b);
}
    }
 
    cout << "Encrypted Message is : " << encrypted << endl;
    cout << "Decrypted Message is : " << decrypted << endl;
 
    return 0;
}
