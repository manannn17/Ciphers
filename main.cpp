#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// Function prototypes at the top of the file for function decomposition

/**
 * Print instructions for using the program.
 */
void printMenu();
/**
 * Returns the 0-based index in the English alphabet where `c` appears,
 * or -1 if `c` is not an uppercase letter in the alphabet.
 *
 * For example:
 *  - `findIndexInAlphabet('A')` returns 0
 *  - `findIndexInAlphabet('D')` returns 3
 *  - `findIndexInAlphabet('+')` returns -1
 *  - `findIndexInAlphabet('a')` returns -1
 */
int findIndexInAlphabet(char c);
/**
 * Returns `c` rotated by `amount` many characters forward. If we run out
 * of letters in the alphabet, wrap around back to 'A'. This method
 * assumes that `c` is an uppercase letter.
 * For example:
 *  - `rot('A', 0)` returns 'A'
 *  - `rot('A', 1)` returns 'B'
 *  - `rot('Z', 1)` returns 'A'
 *  - `rot('A', 10)` returns 'K'
 *  - `rot('J', 25)` returns 'I'
 */
char rot(char c, int amount);
/**
 * Returns a new string in which every character has been rotated by `amount`
 * letters. Lowercase letters are converted to uppercase and rotated.
 * Non-alphabetic characters are left alone.
 * For example:
 *  `rot("A", 0)` returns "A"
 *  `rot("AA", 3)` returns "DD"
 *  `rot("HELLO", 0)` returns "HELLO"
 *  `rot("HELLO", 1)` returns "IFMMP"
 *  `rot("oh HEL-LO!", 1)` returns "PI IFM-MP!"
 */
string rot(string line, int amount);
char vigenereEncrypt(char plainText, const string& key,int keyIndex); // Function to encrypt a single character using Vigenere Cipher
string vigenereCipher(const string& plaintext, const string& key); // Function to apply Vigenere Cipher on the entire plaintext using a given key
string cleanKey(const string& key); // Function to clean the key by removing non-alphabetic characters and converting to uppercase
string decrypt(string plainText,int key); // Function to decrypt the Vigenere Cipher using the original key


int main() {
    string command;

    cout << "Welcome to Ciphers!" << endl;
    cout << "-------------------" << endl;
    cout << endl;

    do {
        printMenu();
        cout << endl
             << "Enter a command (case does not matter): ";

        // Use getline for all user input to avoid needing to handle
        // input buffer issues relating to using both >> and getline
        getline(cin, command);
        cout << endl;

        // TODO_STUDENT: Execute non-exit commands
        
        string plainText;
        int charRot;
        string cipherT,decrypted,key;
        switch(command[0]) //using switch case to make it menu-driven 
        {
            case 'C': //putting upper case and lower case to ensure if they both will work
            case 'c':
                cout<<"Enter the text to encrypt:"<<endl;  
                getline(cin,plainText); //inputting the string

                cout<<"Enter the number of characters to rotate by:"<<endl;
                cin>>charRot; //inputting the key
                cout<<endl;
                cin.ignore();

                cipherT=rot(plainText,charRot); //calling the function
                cout<<cipherT<<endl; //printing the string.
            break;

            case 'D': 
            case 'd':
                cout<<"Enter the text to Caesar-cipher decrypt:";
                getline(cin,plainText);  //inputting the string

                cout<<endl;
                //cin.ignore();

                decrypted=decrypt(plainText,charRot); //calling the function
                cout<<decrypted;  //printing the string.
            break;

            case 'V': 
            case 'v':
                cout<<"Enter text to encrypt:"<<endl;
                getline(cin,plainText);  //inputting the string

                cout<<"Enter the Vigenère key:";
                getline(cin,key);  //inputting the key
                cout<<endl;
                //cin.ignore();

                cipherT=vigenereCipher(plainText, key); //calling the function
                cout<<cipherT<<endl;  //printing the string.
            break;
        }

        cout << endl;

    } while (!(command == "x" || command == "X"));

    return 0;
}

void printMenu() {
    cout << "Ciphers Menu" << endl;
    cout << "------------" << endl;
    // Caesar Ciphers
    cout << "C - Encrypt with Caesar Cipher" << endl;
    cout << "D - Decrypt Caesar Cipher" << endl;
    // Vigenere
    cout << "V - Encrypt with Vigenère" << endl;
    // Utility
    cout << "X - Exit Program" << endl;
}

int findIndexInAlphabet(char c) {
    // TODO_STUDENT
    string alphabet="ABCDEFGHIJKLMNOPQRSTUVWXYZ";   // Define the alphabet
    size_t index=alphabet.find(c);

    if(index!=string::npos)  //checking if the sting is empty or not.
    {
        return static_cast<int>(index);  //returning index
    }
    else
    {
        return -1;
    }
}

char rot(char c, int amount) {
    // TODO_STUDENT
    if(isalpha(c))  // Check if the character is an alphabet character
    {
        char rotate=toupper(c);  // Convert character to uppercase for rotation
        rotate=(rotate-'A'+amount);  // Perform rotation by adjusting values and handling overflow
        rotate=rotate%26+'A';  // Convert back to lowercase if the original character was lowercase
        
        if(islower(c))  // Convert back to lowercase if the original character was lowercase
        {
            rotate=tolower(rotate);
        }
        return rotate;  // Return the rotated character
    }
    else
    {
        return c;
    }
}

string rot(string line, int amount) {
    // TODO_STUDENT

    string convert;
    for(unsigned c=0;c<line.length();c++)
    {
        char upper=rot(line[c],amount);  // Rotate each character individually using the previously defined 'rot' function

        if(islower(line[c]))  // Convert the character back to uppercase if the original character was lowercase
        {
            upper=toupper(upper);
        }
        convert+=upper;  // Append the rotated character to the result string
    }
    return convert;
}

char vigenereEncrypt(char plainText, const string& key,int keyIndex) {
    char shift = toupper(key[keyIndex]) - 'A';
    if(isalpha(plainText)) //checks if the plaintext has alphabet or not
    {
        char encryptedChar;
        
        if (isupper(plainText))  // Perform Vigenere encryption for uppercase characters
        {
            encryptedChar=(plainText-'A'+shift)%26+'A';
        } 
        else // Perform Vigenere encryption for lowercase characters
        {
            encryptedChar=(plainText-'a'+shift)%26+'a';
        }
        return encryptedChar;
    } 
    else 
    {
        return plainText;
    }
}

string vigenereCipher(const string& plainText, const string& key) {
    string encryptedText;
    string cleanedKey = cleanKey(key);
    int keyIndex=0;

    for(char c:plainText) //loop through to check characters
    {
        if(isalpha(c)) //checks if the plaintext has alphabet or not
        {
            char encryptedChar=vigenereEncrypt(c, cleanedKey, keyIndex);  // Encrypt the character using the 'vigenereEncrypt' function
            encryptedText += toupper(encryptedChar);  //converting text into upper case 
            keyIndex=(keyIndex+1)%cleanedKey.length();  //updating the keyIndex
        } 
        else 
        {
            encryptedText+=c;
        }
    }
    return encryptedText;
}
string cleanKey(const string& key) {
    string cleaned="";  //declared empty string
    for(int i=0;i<key.size();i++) // Iterate through each character in the original key
    {
        if(isalpha(key.at(i)))  // Check if the character is an alphabet character 
        {
            cleaned += toupper(key.at(i));   // Append the uppercase version of the alphabet character to the cleaned key
        }
    }
    return cleaned;
}

string decrypt(string plainText,int key)
{
    ifstream infs;
    int bestRotation=-1;
    string line;
    int amount;
    vector<string> dict;
    infs.open("dictionary.txt");  //// Open the dictionary file
    if(!infs.is_open()) 
    {
        cout<<"Could not open file dictionary.txt."<<endl;
        return "error"; // 1 indicates error
    }

    // Break text into words, remove non-letters
    vector<string> words;
    string word;
    while(infs>>word) 
    {
        dict.push_back(word); 
    }
    infs.close();
    
    word = "";
    for(int i=0;i<plainText.length();i++) 
    {
        char c=plainText[i];
        if(!isspace(c)) 
        {
            word+=toupper(c); 
        }
        else if(word != "") 
        {
            words.push_back(word);
            word = "";
        }
    }
    
    if(word != "") 
    {
        words.push_back(word);
    }

    // Try all rotations
    string bestDecryption; 
    //int bestRotation=-1;
    for(int j=0;j<26;j++)  // Check how many words match with the dictionary for each rotation
    {
        int matches=0;
        for(int k=0;k<words.size();k++) 
        {
            string w=words[k];
            string rotated=rot(w,26+j);
            //cout << rotated << '\n';
            bool found=false;
            for(size_t r=0;r<dict.size();r++) // If more than half of the words match, consider it a potential decryption
            {
                if(dict[r] == rotated) 
                {
                    found=true;
                    break;
                }
            }
            if(found) 
            {
                matches++;
            }
        }
        if(matches>words.size()/2) 
        {
            bestRotation = 1;
            cout<<rot(plainText,26+j)<< '\n';
        }
    }

    if(bestRotation==-1)  // Return the best decryption if found
    {
        return "No good decryptions found";
    } 
    return "";
}
