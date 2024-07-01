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
            return false; // ���� ��������� �����������, � � ����� ��� ��������������� �����������
        }
    }

    return stack.empty(); // ���� ���� ����, ������ ������ ��������������
}

int main() {
    setlocale(0, "");
    string inputString;
    cout << "������� ���������� ������: ";
    getline(cin, inputString);

    if (areBracketsBalanced(inputString)) {
        cout << "������ ����������� �����\n";
    }
    else {
        cout << "������ ����������� �������\n";
    }

    return 0;
}
