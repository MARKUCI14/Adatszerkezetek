#include <iostream>
#include <vector>
#include "hash_table.h"

using namespace std;

int convert(char a) {
    switch (a) {
        case 'A':
            return 10;
            break;
        case 'B':
            return 11;
            break;
        case 'C':
            return 12;
            break;
        case 'D':
            return 13;
            break;
        case 'E':
            return 14;
            break;
        case 'F':
            return 15;
            break;
        default:
            return a - '0';
            break;
    }
}

ULL decode(string number, ULL p) {
    if (number.empty())
        return 0;
    else
    {
        char a = number.back();
        number.pop_back();
        int c = convert(a);
        return c * p + decode(number, p * 16);
    }
}

pair<ULL, int> beforeDecode(string message) {
    ULL decoded = decode(message, 1);
    int x = decoded % 10;
    return pair<ULL, int> (decoded/10, x);
}


int main() {
    HashTable a;
    createHash(&a, 10);
    
    int n;
    string temp;
    cin >> n;
    getline(cin, temp);
    for (int i = 0; i < n; i++) {
        string cnp, number, email;
        cin >> cnp >> number >> email;
        insert(&a, cnp, number, email);
    }
    
    int m;
    cin >> m;
    getline(cin, temp);
    vector<string> messages;
    for (int i = 0 ; i < m; i++) {
        string msg1, msg2, msg3;
        cin >> msg1 >> msg2 >> msg3;
        messages.push_back(msg1 + msg2 + msg3);
    }
    
    for (int i = 0; i < m; i++) {
        pair<ULL,int> code = beforeDecode(messages[i]);
        string cnp = to_string(code.first);
        Node* data = search(&a, cnp);
        if (code.second == 1) {
            cout << data -> email << '\n';
        } else {
            cout << data -> number << '\n';
        }
    }
}

