#include <iostream>
#include <string>
using namespace std;

int main() {
    string text = "This is a lines";
    string output = "";
    int text_size = text.size();
    for (int i = 0; i< text_size; i++) {
        if (text[i] != 's') {
            output += text[i];
        }
    }
    cout << output << endl;
    return 0;
}