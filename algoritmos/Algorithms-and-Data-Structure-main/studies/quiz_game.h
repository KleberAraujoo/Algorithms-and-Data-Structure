#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void exibirPergunta(const string& pergunta, const string opcoes[4]) {
    cout << "**************************" << endl;
    cout << pergunta << endl;
    cout << "**************************" << endl;
    for (int j = 0; j < 4; j++) {
        cout << opcoes[j] << endl;
    }
}

bool verificarResposta(char opcao, char resposta) {
    return toupper(opcao) == resposta;
}

int main() {
    const string perguntas[] = {
        "1. Qual ano de criação do C++?",
        "2. Quem inventou o C++?",
        "3. Qual o antecessor do C++?",
        "4. C++ é uma linguagem rápida?"
    };

    const string opcoes[][4] = {
        {"A. 1969", "B. 1975", "C. 1985", "D. 1963"},
        {"A. Guido van Rossum", "B. Bjarne", "C. John Lennon", "D. Karl Marx"},
        {"A. Python", "B. C", "C. Java", "D. Assembly"},
        {"A. Ás vezes", "B. Não", "C. Sim", "D. Talvez"}
    };

    const char resposta[] = {'C', 'B', 'B', 'C'};
    int tamanho = sizeof(perguntas) / sizeof(perguntas[0]);
    char opcao;
    int pontos = 0;

    for (int i = 0; i < tamanho; i++) {
        exibirPergunta(perguntas[i], opcoes[i]);
        cout << "Digite sua resposta: ";
        cin >> opcao;

        if (opcao < 'A' || opcao > 'D') {
            cout << "Opção inválida. Digite A, B, C ou D." << endl;
            i--;
            continue;
        }

        if (verificarResposta(opcao, resposta[i])) {
            cout << "Correto!" << endl;
            pontos++;
        } else {
            cout << "Incorreto. A resposta correta era: " << resposta[i] << endl;
        }
    }

    cout << "**************************" << endl;
    cout << "Fim do QUIZ" << endl;
    cout << "Você acertou " << pontos << " de " << tamanho << " perguntas." << endl;
    cout << "**************************" << endl;

    return 0;
}
