
#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node *left, *right;
    
    Node(char c) {
        data = c;
        left = right = NULL;
    }
};

// Generate machine code
int reg = 0;

string generate(Node *root) {
    if (root == NULL)
        return "";

    // Leaf node
    if (root->left == NULL && root->right == NULL) {
        string r = "R" + to_string(reg++);
        cout << "MOV " << r << ", " << root->data << endl;
        return r;
    }

    // Generate code for left subtree
    string left = generate(root->left);

    // Generate code for right subtree
    string right = generate(root->right);

    string result = "R" + to_string(reg++);

    switch (root->data) {
        case '+':
            cout << "ADD ";
            break;
        case '-':
            cout << "SUB ";
            break;
        case '*':
            cout << "MUL ";
            break;
        case '/':
            cout << "DIV ";
            break;
    }

    cout << result << ", " << left
         << ", " << right << endl;

    return result;
}

int main() {
    Node *root;

    // AST for a + b * c
    root = new Node('+');
    root->left = new Node('a');
    root->right = new Node('*');

    root->right->left = new Node('b');
    root->right->right = new Node('c');

    cout << "Generated Machine Code:\n";

    generate(root);

    return 0;
} 