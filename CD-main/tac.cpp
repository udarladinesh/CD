

#include <iostream>
#include <string>
#include <stack>
#include <cctype>
using namespace std;

int precedence(char op) {
    if (op == '*' || op == '/')
        return 2;

    if (op == '+' || op == '-')
        return 1;

    return 0;
}

int main() {
    string s;
    cout << "Enter expression: ";
    cin >> s;

    stack<string> operands;
    stack<char> operators;

    int temp = 1;

    for (int i = 0; i < s.length(); i++) {

        if (isalnum(s[i])) {
            string x = "";

            while (i < s.length() && isalnum(s[i])) {
                x += s[i];
                i++;
            }

            i--;
            operands.push(x);
        }

        else if (s[i] == '(') {
            operators.push(s[i]);
        }

        else if (s[i] == ')') {
            while (!operators.empty() &&
                   operators.top() != '(') {

                char op = operators.top();
                operators.pop();

                string b = operands.top();
                operands.pop();

                string a = operands.top();
                operands.pop();

                string t = "t" + to_string(temp++);

                cout << t << " = " << a
                     << " " << op << " " << b << endl;

                operands.push(t);
            }

            if (!operators.empty())
                operators.pop();
        }

        else {
            while (!operators.empty() &&
                   precedence(operators.top()) >= precedence(s[i])) {

                char op = operators.top();
                operators.pop();

                string b = operands.top();
                operands.pop();

                string a = operands.top();
                operands.pop();

                string t = "t" + to_string(temp++);

                cout << t << " = " << a
                     << " " << op << " " << b << endl;

                operands.push(t);
            }

            operators.push(s[i]);
        }
    }

    while (!operators.empty()) {

        char op = operators.top();
        operators.pop();

        string b = operands.top();
        operands.pop();

        string a = operands.top();
        operands.pop();

        string t = "t" + to_string(temp++);

        cout << t << " = " << a
             << " " << op << " " << b << endl;

        operands.push(t);
    }

    return 0;
} 