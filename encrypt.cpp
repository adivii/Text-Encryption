// Encrypt-Decrypt
// - Generate Key : Write randomly generated key to text file (each letter got exactly one letter as encryption key), also generate key to replace whitespace
// - Encrypt : Transform the sentence in normal.txt into encrypted sentence, write it into encrypted.txt, then clear normal.txt
// - Decrypt : Transform the encrypted sentence in encrypted.txt, write it into normal.txt, then clear encrypted.txt
// - Write every operation in log.txt :
//     - Generate Key : write 001_key-result-code
//     - Encrypt : write 002_encrypted-text
//     - Decrypt : write 003_decrypted-text

#include <bits/stdc++.h>
using namespace std;

// Main Function
void _initFile();
void generate_key();
void encrypt();
void decrypt();

// Additional Function
void pauseConsole();

int main(){
    _initFile();
}

void _initFile(){
    // Create directory for text file (if there are none)
    system("mkdir main");
    system("mkdir text");

    // Create variable used to open text file
    ofstream normal_text, encrypted_text, key_file, log_file;

    // Open file in append mode (this will create new file if file not found, but won't overwrite the file if file found)
    normal_text.open("text/normal.txt", ios::app);
    encrypted_text.open("text/encrypted.txt", ios::app);
    key_file.open("main/key.txt", ios::app);
    log_file.open("main/log.txt", ios::app);

    // Check if file can't be initialized
    if(normal_text.fail() || encrypted_text.fail() || key_file.fail() || log_file.fail()){
        cout << "File Initialization Failed" << endl;
        pauseConsole();
        exit(0); // Abort Operation
    }

    // Close opened files
    normal_text.close();
    encrypted_text.close();
    key_file.close();
    log_file.close();
}

void pauseConsole(){
  // Buat dan set nilai ch menjadi NULL (\0)
  char ch = '\0';

  cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan newline yang tersisa di buffer
  cout << "\nPress any key to continue . . . ";

  // Lakukan perulangan selama ch masih NULL
  do{
    cin.get(ch); // Baca input user
  }while (ch == '\0');

  cout << endl;
}
