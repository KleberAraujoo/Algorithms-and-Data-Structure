#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
using namespace std;

int main() {

    // para gerar números aleatórios entre 1 e 15
    time_t sec;
    time(&sec);
    srand((unsigned) sec);
    int num_aleatorio = rand() % 15 + 1;

    int tentativas = 3; // número de tentativas do jogador
    bool acertou = false;   // verificador se acertou ou não
    string continuar = "Sim";   // verificador para contiuar a jogar ou não
    
    vector<int> num_tentados; // lista para armazenar os números tentados
    
    // loop para rodar o jogo
    while (!acertou && (tentativas > 0 || continuar == "Sim")) {

        int num_jogador;
        cout << "Digite um número entre 1 e 15: ";   // pede ao usuário para digitar um número
        cin >> num_jogador;
        
        if (num_jogador > 15 || num_jogador < 0) {
            cout << "Número digitado não válido, digite novamente entre 1 e 15.\n";
            continue;
        }
        
        // verifica se o número já foi tentado
        bool ja_tentado = false;
        for (int i = 0; i < num_tentados.size(); i++) {
            if (num_tentados[i] == num_jogador) {
                ja_tentado = true;
                break; // sai do loop assim que encontrar o número
            }
        }
        
        // condições para verificar se o usuário já tentou ou não o número digitado
        if (ja_tentado) { 
            cout << "Você já digitou este número. Digite novamente.\n";
            continue;
        } else {
            num_tentados.push_back(num_jogador); // adiciona o número à lista de tentativas
            cout << "Número " << num_jogador << " adicionado à lista de tentativas.\n";
        }
            
        if (num_jogador != num_aleatorio) {     // verifica se o número digitado pelo jogador é diferente do número gerado pelo computador
            tentativas -= 1;    // caso seja, diminui as tentativas

            // verificação de condições para dizer ao jogador se o número dele é maior ou menor que o número procurado
            if (num_jogador > num_aleatorio) {
                cout << "O número procurado é menor que " << num_jogador << "\n";
            } else {
                cout << "O número procurado é maior que " << num_jogador << "\n";
            }


            if (tentativas > 0) {   // faz a verificação da quantidade de tentativas restantes
                cout << "Você tem mais " << tentativas << " tentativas restantes.\n";

            } else {    // se o jogador não tiver mais tentativas, é perguntado se deseja continuar ou não
                cout << "Que pena! Você perdeu todas as suas tentativas.\n";
                cout << "Você deseja continuar? [Sim ou Não]: ";
                cin >> continuar;   // recebe a entrada digitada pelo usuário

                // o for ira percorrer a variavel continuar e guardar a resposta digitada pelo usuario
                for (auto &c : continuar) {
                    c = tolower(c); }  // tolower para deixar em minúscula a resposta do usuario

                if (continuar == "sim") {   // caso o usuário tenha digitado sim, ganha mais 3 tentativas
                    tentativas = 3;
                    
                    cout << "Reiniciando as tentativas...\n";

                } else {    // caso contrario, o loop irá parar
                    continuar = "Não";
                }
            }

        // caso o número do jogador seja igual ao do computador
        } else {
            cout << "VOCÊ ACERTOU! O número procurado é: " << num_aleatorio << "\n";
            acertou = true;
        }
    }

    // se ele desistiu do jogo, ou seja, não acertou, é informado o número gerado pelo computador
    if (!acertou) {
        cout << "Obrigado por jogar! O número correto era " << num_aleatorio << ".\n";
    }

    return 0;
}