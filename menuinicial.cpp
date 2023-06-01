#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <time.h>

using namespace std;

void limpaTela()
{
    system("CLS");
}

string retornaPalavraAleatoria()
{
    string palavras[3] = {"Banana", "Uva", "Melancia"};

    int indiceAleatorio = rand() % 3;

    return palavras[indiceAleatorio];
}

string retornaPalavraComMascara(string palavra, int tamanhoDaPalavra)
{
    int cont = 0;
    string palavraComMascara;

    while (cont < tamanhoDaPalavra)
    {
        palavraComMascara += "_";
        cont++;
    }

    return palavraComMascara;
}

void exibeStatus(string palavraComMascara, int tamanhoDaPalavra, int tenativasRestantes, string letrasArriscadas, string mensagem)
{
    cout << mensagem;
    cout << "\n Palavra: " << palavraComMascara << "(Tamando:" << tamanhoDaPalavra << ")";
    cout << "\n Tenativas Restantes:" << tenativasRestantes;

    int cont;
    cout << "\n Letras Arriscadas: ";
    for (cont = 0; cont < letrasArriscadas.size(); cont++)
    {
        cout << letrasArriscadas[cont] << ", ";
    }
}

int jogar(int numDeJogadores)
{
    string palavra;

    if(numDeJogadores == 1){
        palavra = retornaPalavraAleatoria();

    }
    else{

        cout << "\n Digite uma palavra(somente letras minusculas): ";
        cin >> (palavra);
        
    }

    
    int tamanhoDaPalavra = palavra.size();

    string palavraComMascara = retornaPalavraComMascara(palavra, tamanhoDaPalavra);

    int tenativas = 0, maximoDeTenativas = 10;
    int cont = 0;
    int opcao;
    char letra;
    string letrasArriscadas;
    string mensagem;
    bool letraJaDigitada, acertouLetra = false;

    while (palavra != palavraComMascara && maximoDeTenativas - tenativas > 0)
    {
        limpaTela();

        exibeStatus(palavraComMascara, tamanhoDaPalavra, maximoDeTenativas - tenativas, letrasArriscadas, mensagem);

        cout << "\n Digite uma letra: ";
        cin >> letra;

        // confere letras digitadas
        for (cont = 0; cont < tenativas; cont++)
        {
            if (letrasArriscadas[cont] == letra)
            {
                mensagem = "Digite uma letra diferente!";
                letraJaDigitada = true;
            }
        }

        if (letraJaDigitada == false)
        {

            letrasArriscadas += tolower(letra);

            for (cont = 0; cont < tamanhoDaPalavra; cont++)
            {
                if (palavra[cont] == tolower(letra))
                {
                    palavraComMascara[cont] = palavra[cont];

                    acertouLetra = true;
                }
            }
            if (acertouLetra == false)
            {
                mensagem = "Voce errou uma letra !";
            }
            else
            {
                mensagem = "Voce acertou uma letra! ";
            }

            tenativas++;
        }

        // reincia auxiliar
        letraJaDigitada = false;
        acertouLetra = false;
    }

    if (palavra == palavraComMascara)
    {
        limpaTela();
        cout << "Parabens voce VENCEU!";
        cout << "\n Deseja reiniciar?";
        cout << "\n 1 - Sim";
        cout << "\n 2 - Nao";
        cin >> opcao;
        return opcao;
    }
    else
    {
        limpaTela();
        cout << "Voce PERDEU!";
        cout << "\n Deseja reiniciar?";
        cout << "\n 1 - Sim";
        cout << "\n 2 - Nao";
        cin >> opcao;
        return opcao;
    }
}

void menuInicial()
{

    int opcao = 0;

    while (opcao < 1 || opcao > 3)
    {
        limpaTela();

        cout << "Bem Vindo ao Jogo";
        cout << "\n 1 - Jogar Sozinho";
        cout << "\n 2 - Jogar em Dupla";
        cout << "\n 3 - Sobre";
        cout << "\n 4 - Sair";
        cout << "\n Escolha uma opcao e tecle ENTER \n";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            if (jogar(1) == 1){
                menuInicial();
            }
            break;
         case 2:
            if (jogar(2) == 1){
                menuInicial();
            }
            break;
        case 3:
            cout << "Informacoes do jogo";
            limpaTela();
            cout << "Jogo desenvolvido por Filipe Brandao com base no curso 'C e C++ do Zero'";
            cout << "\n 1 - Voltar";
            cout << "\n 2 - Sair";
            cout << "\n";
            cin >> opcao;
            if(opcao == 1){
                menuInicial();
            }

            break;
        case 4:
            cout << "Ate mais";
            break;
        }
    }
}

int main()
{

    srand((unsigned int)time(NULL));

    menuInicial();
}
