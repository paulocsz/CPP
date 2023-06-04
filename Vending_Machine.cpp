// Paulo César da Silva Zanotelo - RA 2840482313040
// Victor Breno Anastacio de Matos - RA 2840482313038

#include <iostream>
#include <locale.h>
using namespace std;
float faturamento(int array_quant[], float array_preco[]); // função de calculo de valor x quantia

int main()
{
    int modo; // identeificação e inicialização de variaveis
    int verificacao_modo = 1;
    int senha;
    int produto;
    float valor;
    float caixa = 0;
    int quantidade[5] ={10, 10, 10, 10, 10}; // array para guardar quantidade de produtos que se inicia sempre em 10 unidades de cada produto
    float preco[5] = {2.00, 3.00, 4.00, 5.00, 6.00}; // array para precificar produtos, cada endereço cada produto
    char abastecimento;
    int produto_abastecimento;
    int quantia_abastecimento;
    
   

    while (true)
    { // rodar o codigo sempre em loop
        while (verificacao_modo == 1)
        { // Loop para identificação de modo e trativa de opção errada selecionada
            cout << "Digite o codigo do produto selecionado" << '\n'
                 << "01 - Produto 1 - 2,00" << '\n'
                 << "02 - Produto 2 - 3,00" << '\n'
                 << "03 - Produto 3 - 4,00" << '\n'
                 << "04 - Produto 4 - 5,00" << '\n'
                 << "05 - Produto 5 - 6,00" << '\n'
                 << "99 - Entrar em modo administrador"
                 << '\n';

            cin >> produto;
            produto = produto - 1; // para que o codigo 'bata' com o endereçamento da array

            if (produto == 98)
            { // se modo adm selecionado
                verificacao_modo = 2;
            }
            else
            { // se qualquer codigo selecionado

                cout << "Digite o valor em reais inserido na maquina:" << '\n';
                cin >> valor;

                if (quantidade[produto] > 0)
                { // se a quantidade de produto for positiva
                    quantidade[produto]--;
                    cout << "Produto retirado" << '\n'
                         << "Seu troco de R$" << valor - preco[produto] << " será devolvido a seguir" << '\n';
                    caixa = caixa + preco[produto];
                }
                else
                {
                    cout << "Produto indisponivel, o valor total será devolvido" << '\n'; // se a quantidade for 0 ou menor
                }
            }
        }

        while (verificacao_modo == 2)
        { // se modo de administrador
            cout << "Você entrou em modo administrador" << '\n'<<'\n';
            cout << "Produtos e suas respesctivas quantidades:" << '\n'
                 << "01 - Produto 1 - 2,00: " << quantidade[0] << '\n'
                 << "02 - Produto 2 - 3,00: " << quantidade[1] << '\n'
                 << "03 - Produto 3 - 4,00: " << quantidade[2] << '\n'
                 << "04 - Produto 4 - 5,00: " << quantidade[3] << '\n'
                 << "05 - Produto 5 - 6,00: " << quantidade[4] << '\n'
                 << '\n'
                 << "Valor faturado: R$" << caixa << '\n'
                 << "Valor a faturar: R$" << faturamento(quantidade, preco)<<'\n' // chama função de calculo de valor x quantidade
                 << "Deseja abastecer algum produto? S/N" << '\n';

            cin >> abastecimento;
            abastecimento = toupper(abastecimento);

            if (abastecimento == 'S')
            {
                cout << "Digite o codigo do produto a ser adicionado:" << '\n';
                cin >> produto_abastecimento;
                produto_abastecimento--;
                cout << "Digite a quantidade a ser adicionada:" << '\n';
                cin >> quantia_abastecimento;
                quantidade[produto_abastecimento] = quantidade[produto_abastecimento] + quantia_abastecimento; // adiciona a quantia abastecida na quantia ja existente
            }
            else
            {
                cout << "Entrando no modo usuario"
                     << "'\n";
                verificacao_modo = 1;
            }
        }
    }


system("pause");
return 0;
}

float faturamento(int array_quant[], float array_preco[])
{ // função de calculo de valor x quantia
    float resultado = 0;
    for (int i = 0; i <= 5; i++)
    {
        resultado = resultado + (array_quant[i] * array_preco[i]);
    }

    return resultado;
}
