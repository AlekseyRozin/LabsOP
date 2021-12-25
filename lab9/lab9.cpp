#include <iostream>
#include <string>
using namespace std;

int wordsCount(string s); // функция, которая возвращает кол-во слов, которые стоят на парных позициях в строке
void getWords(string* words, int len, string s); // функция, которая заполняет массив словами, которые стоят на парных позициях в строке
bool isVowel(char letter); // функция, которая возвращает истиное значение, если буква является гласной
string transfer(string word); // функция, которая возвращает слово с дефисами в тех метсах, где слово можно перенести
void outputTransferedWords(string words[], int len); // функция, которая выводит уже измененные слова, с дефисами в тех метсах, где слово можно перенести

int main()
{
    string input;
    cout << "Enter your text: ";
    getline(cin, input);
    
    int len = wordsCount(input);
    string* words = new string[len];

    getWords(words, len, input);
    outputTransferedWords(words, len);

}

int wordsCount(string s) {
    int words = 1;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            words++;
        }
    }
    return words / 2;
}
void getWords(string* words, int len, string s) {
    int startIndex;
    int endIndex = 0;
    for (int i = 0; i < len; i++) {
        startIndex = s.find(" ", endIndex+1);
        endIndex = s.find(" ", startIndex+1);
        words[i] = s.substr(startIndex+1, endIndex - startIndex - 1);
    }
}
bool isVowel(char letter) {
    string vowels = "aeiou";
    if (vowels.find(letter) == -1) {
        return false;
    }
    else {
        return true;
    }
}
string transfer(string word){
    if (word.length() < 5 || word.find('-') != -1) {
        return "Word cannot be transfered";
    }
    string res = "";
    for (int i = 0; i < word.length(); i++) {
        res += word[i];
        bool dash = true;
        if (i < 1 || i > word.length() - 4) dash = false;
        else if(!isVowel(word[i]) && isVowel(word[i+1])) dash = false;
        else if(isVowel(word[i]) && isVowel(word[i+1])) dash = false;
        else if (isVowel(word[i]) && !isVowel(word[i + 1]) && !isVowel(word[i + 2])) dash = false;

        if (dash) res += '-';
    }
    if (res.find('-') == -1) {
        return "Word cannot be transfered";
    }
    else {
        return res;
    }
}
void outputTransferedWords(string words[], int len) {
    for (int i = 0; i < len; i++) {
        cout << "\n" << (i + 1) * 2 << ". " << words[i] << "  --->  " << transfer(words[i]);
    }
    cout << "\n\n";
}