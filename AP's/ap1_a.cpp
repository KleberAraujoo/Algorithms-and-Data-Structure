#include <iostream>
#include <string>
using namespace std;

int main() {
    
    // variaveis para os dois times
    string time_1;
    string time_2;
    
    // receber a entrada do nome dos dois times
    getline(cin,time_1);
    getline(cin,time_2);
    
    // pontução dos times 
    int pontuacao_time_1;
    int pontuacao_time_2;

    int rodadas = 0; // numero de rodadas
    
    // contador de vitoria dos times
    int vitorias_time_1 = 0;
    int vitorias_time_2 = 0;
    
    // variavel para guardar o vencedor da rodada 
    string vencedor_rodada;
    
    // loop para verificar se chegou a 5 rodadas ou um dos times chegou a 3 vitorias durante as rodadas
    while (rodadas < 5 && vitorias_time_1 < 3 && vitorias_time_2 < 3) {
        
        // recebe a entrada da pontuacao do time na rodada
        cin >> pontuacao_time_1;
        cin >> pontuacao_time_2;
        
        // verificação qual time ganhou mais pontuação
        if (pontuacao_time_1 > pontuacao_time_2) {
            vitorias_time_1 += 1;
            vencedor_rodada = time_1;
        }
        else {
            vitorias_time_2 += 1;
            vencedor_rodada = time_2;
        }

        rodadas += 1;

        cout << "O vencedor da " << rodadas << "ª rodada foi: " << vencedor_rodada << '\n';
    }
    
    // verificação se o time ganhou 3 rodadas
    if (vitorias_time_1 == 3) {
        cout << "O time " << time_1 << " ganhou a partida final!" << endl;
    }
    else if (vitorias_time_2 == 3) {
        cout << "O time " << time_2 << " ganhou a partida final!" << endl;
    }

    return 0;
}