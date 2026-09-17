#include <iostream>

using namespace std;

int main() {
    char text[1000];

    cout << "Masukkan pesan asli: ";
    cin.getline(text, 1000);

    int shift = 0; 

    for (int i = 0; text[i] != '\0'; ++i) {
        char ch = text[i];

        
        if (ch >= 'A' && ch <= 'Z') {
            int originalPos = ch - 'A'; 
            int newPos = (originalPos + shift) % 26; 
            shift = originalPos + 1; 
            text[i] = 'A' + newPos; 
        }
        
        else if (ch >= 'a' && ch <= 'z') {
            int originalPos = ch - 'a';
            int newPos = (originalPos + shift) % 26;
            
            shift = originalPos + 1;
            text[i] = 'a' + newPos;
        }
        
    }

    cout << "Pesan terenkripsi: " << text << endl;

    return 0;
}
