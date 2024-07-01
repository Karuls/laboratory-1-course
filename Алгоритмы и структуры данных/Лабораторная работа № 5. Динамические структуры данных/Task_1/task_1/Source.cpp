#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool areBracketsBalanced(const string& s) {
    stack<char> stack;

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            stack.push(c);
        }
        else if (c == ')' && !stack.empty() && stack.top() == '(') {
            stack.pop();
        }
        else if (c == ']' && !stack.empty() && stack.top() == '[') {
            stack.pop();
        }
        else if (c == '}' && !stack.empty() && stack.top() == '{') {
            stack.pop();
        }
        else if (c == ')' || c == ']' || c == '}') {
            return false; // Если встречаем закрывающую, а в стеке нет соответствующей открывающей
        }
    }

    return stack.empty(); // Если стек пуст, значит скобки сбалансированы
}

int main() {
    setlocale(0, "");
    string inputString;
    cout << "Введите символьную строку: ";
    getline(cin, inputString);

    if (areBracketsBalanced(inputString)) {
        cout << "Скобки расставлены верно\n";
    }
    else {
        cout << "Скобки расставлены неверно\n";
    }

    return 0;
}
