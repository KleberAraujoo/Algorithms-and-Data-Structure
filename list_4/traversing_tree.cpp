#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Função para inserir um valor na árvore binária de busca
Node* insert(Node* root, int value) {

    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    }

    else {
        root->right = insert(root->right, value);
    }

    return root; // Retorna a raiz da árvore
}

// Função para percorrer a árvore em pré-ordem
void preOrder(Node* root, vector<int>& res) {
    if (root == nullptr) return;
    res.push_back(root->data);
    preOrder(root->left, res);
    preOrder(root->right, res);
}

// Função para percorrer a árvore em ordem
void inOrder(Node* root, vector<int>& res) {
    if (root == nullptr) return;
    inOrder(root->left, res);
    res.push_back(root->data);
    inOrder(root->right, res);
}

// Função para percorrer a árvore em pós-ordem
void postOrder(Node* root, vector<int>& res) {
    if (root == nullptr) return;
    postOrder(root->left, res);
    postOrder(root->right, res);
    res.push_back(root->data);
}

void printVector(const string& label, const vector<int>& vec) {
    cout << label;
    for (size_t i = 0; i < vec.size(); ++i) {
        if (i >= 0) {
            cout << " ";
        }
        cout << vec[i];
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    vector<int> data(n);
    for (int i = 0; i < n; ++i) {
        cin >> data[i];
    }

    Node* root = nullptr; // Inicializa a raiz da árvore como nula
    for (int val : data) {
        root = insert(root, val); // Insere cada valor na árvore
    }

    // Vetores para armazenar o percurso da árvore
    vector<int> pre, in, post;
    preOrder(root, pre);
    inOrder(root, in);
    postOrder(root, post);

    printVector("Pre order : ", pre);
    printVector("In order  : ", in);
    printVector("Post order:", post);

    return 0;
}
