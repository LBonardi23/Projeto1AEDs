#include <cstdlib>
#include <iostream>
#include <fstream>
#include <math.h>

        //Cabeçalho: Nomes e RA - Leonardo Bonardi Marques Silva 2023.1.08.011 e Vinícius Piotto 2023.1.08.024. Trabalho sobre BD_veículos de AEDs I, data máxima para entrega 31/5. Professor - Paulo Bressan. 
        //Dica: Podemos fazer o calculo do juros e do seguro  e não guadar o valor em uma variável. Isso otimiza o código.

using namespace std;

int main(int arcg, char ** argv){

    //Variáveis com valores em ponto flutuante:
    float   valor,      //Valor do carro.
            km,         //Quilometragem do automóvel.
            pmotor,     //Potência do motor. 
            pctvca,     //Variável para o calculo do segundo exercício. Carro automático e com direção hidráulica.
            pct2,       //Variável para o calculo do segundo exercício. Câmbio automático e direção hidráulica.
            md,         //Média de quilometragem dos carros com mais de 5 anos.
            menor,      //Variável para guardar o menor valor de um carro.
            jurosm,     //Variável para calculo do juros do carro de menor valor.
            segma,      //Variável para o calculo do seguro do carro de maior valor.
            maior,      //Variável para guardar o maior valor de um carro.
            km5;        //Variável para guardar a soma dos carros com mais ou 5 anos.

    //Variáveis com valores inteiros:
    int     portas,     //Quntas portas possui.
            ano,        //Qual o ano do modelo.
            ano5,       //Variável para o calculo de carros com mais ou 5 anos.
            qkm5,       //Variável para saber a quantidade de carros com mais ou 5 anos.
            qt,         //Quantidade total de carros.
            qs,         //Quantidade de sedans.
            qp,         //Quantidade de pick-ups.
            qsu,        //Quantidade de SUVs.
            qh,         //Quantidade de Hatchs.
            qpa,        //Quantidade de carros do tipo passeio.
            qv;         //Quantidade de carros do tipo VAN.
  
    //Variáveis literais
    char    modelo,     //Qual é o "nome" do carro.
            marca,      //De qual marca.
            tipo,       //Tipo do carro. SEDAN/SUV/ETC...
            comb,       //Qual o combustível é movido o automóvel.
            camb,       //É câmbio automático ou manual?
            dire,       //Direção. Hidráulica ou elétrica?
            cor,        //Cor do carro. 
            placa,      //Qual é a placa.
            placam,     //Qual a placa do carro mais barato.
            placama;    //Qual a placa do carro mais caro.
        
    //Leitura do arquivo com os dados fornecidos.
    ifstream teclado ("BD_veiculos.txt");

    //Condição de negação caso o arquivo não foi encontrado.
    if (!teclado.is_open()){    
        cout << "\n Erro: Arquivo não encontrado." << endl;    //Mensagem de aviso para a falha de reconhecimento do arquivo.
        return 1;
    }

    //Atribuição de valores para as variáveis na inicialização
    qk5 = 0; 
    qh  = 0;
    qp  = 0;
    qpa = 0;
    qv  = 0;
    qsu = 0;
    qs  = 0;
    km5 = 0;
    menor = 999999999999;   //Valor máximo para que o valor a ser lido passe a ser a variável de comparação.
    modelo = 'START';       //Atribuição de inicialização para que a variável "modelo" não receba lixo do computador.      

    //Descrição repetição
    while (modelo != 'FIM'){
        teclado >> modelo;
        teclado >> marca;
        teclado >> tipo;
        teclado >> ano;
        teclado >> km;
        teclado >> pmotor;
        teclado >> comb; //perguntar se afeta ter 2 variaveis parecidas!!!!!!!!!!
        telcado >> camb; //camb e comb
        teclado >> dire;
        teclado >> cor;
        teclado >> portas;
        teclado >> placa;
        teclado >> valor;

        //Quantidade de carro recebe +1 a cada nova leitura
        qt++;  
                
        //Separação do modelo de carro
        if(modelo == 'Sedã'){
            qs++;    //modelo Sedã recebe + 1 em sua quantidade total
        }   else {
                if (modelo == 'Hatch'){
                    qh++;    //modelo Hatch recebe + 1 em sua quantidade total
                }   else {
                        if (modelo == 'Pick-up'){
                            qp++;    //modelo Pick-up recebe + 1 em sua quantidade total
                        }   else {
                                if (modelo == 'Passeio'){
                                    qpa++;    //modelo Passeio recebe + 1 em sua quantidade total
                                }   else {
                                        if (modelo == 'SUV'){
                                            qsu++;    //modelo SUV recebe + 1 em sua quantidade total
                                        }   else {
                                                qv++;    //modelo Van recebe + 1 em sua quantidade total
                                            }
                                    }
                            }
                    }
            }
        
        if(camb == 'automático' && dire == 'hidráulica'){ //Começo do segundo exercício proposto sobre a porcentagem de carros com câmbio automático e direção hidráulica.
            pctvca++;
        }
                //Fim do segundo exercício e início do terceiro.
        if(pmotor == 1.0){
            if(menor < valor){
                menor << valor;
                placam << placa;
            }
        }
                //Fim do terceiro exercício e início do quarto. 
        if(dire == 'Hidráulica' && comb == 'Flex'){
            if(valor > maior){
                maior << valor;
                placama << placa;
            }
        }
                //Fim do quarto exercício e início o quinto.
        if(ano5 >= 5){
            km5 = km5+km;
            qkm5++;
        }
                //Fim do quinto exercício.
    }           //Fim da repetição.
            
            //Espaço dedicado para os cálculos das informações pedidas que precisam ser feita fora da repetição. Temporário.
    jurosm = ;                          //Calculo para saber o jutos da prestação do carro mais barato em 48 parcelas. Porém no final não precisamos adicionar esse cálculo em uma variável, mas apenas no cout.
    segma = ;                           //Calculo para saber quanto custa o seguro do carro mais caro. Porém no final não precisamos adicionar esse cálculo em uma variável, mas apenas no cout.
    ano5 << 2023 - ano;                 //Calculo para saber se o carro tem ou mais de 5 anos. Essa variável está fora da repetição. Isso está correto? Acho que não.
    md << km5/qkm5;                     //Calculo das médias dos km rodados pelos carros com mais de 5 anos. Essa variável está fora da repetição. Isso está correto? Acho que não.
            //Fim do espaço para os cálculos fora da repetição. Temporário.
            
            //Início das printagens/informações sobre os exercícios.
    cout << "\n A porcentagem de carros do tipo sedã é de: %" << (qs/qt)*100 << endl;
    cout << "\n A porcentagem de carros do tipo hatch é de: %" << (qh/qt)*100 << endl;
    cout << "\n A porcentagem de carros do tipo pick-up é de: %" << (qp/qt)*100 << endl;
    cout << "\n A porcentagem de carros do tipo passeio é de: %" << (qpa/qt)*100 << endl;
    cout << "\n A porcentagem de carros do tipo SUV é de: %" << (qsu/qt)*100 << endl;
    cout << "\n A porcentagem de carros do tipo van é de: %" << (qv/qt)*100 << endl;
            //Fim dos couts do primeiro exercício e começo do segundo.
    cout << "\n A porcentagem de carros que possuem câmbio automático e direção hidráulica entre todos os veículos é de: %" << (pctvca/qt)*100 << endl;
            //Fim do cout do segundo exercício e início do terceiro.
    cout << "\n A placa do veículo 1.0 mais barato é: " << placam << "\n O valor desse carro é de: " << menor << "E o valor da prestação desse carro em 48 vezes com juros anuais é de: " << jurosm << endl; 
            //Fim do cout do terceiro exercício e início do quarto.
    cout << "\n A placa do veículo mais caro é: " << placama << "\n O valor desse carro é de: " << maior << "\n E o valor do seguro para este carro é de: " << segma << endl;
            //Fim do cout do quarto exercício e início do quinto.
    cout << "\n A quantidade de quilometros rodados para carros com ou mais de 5 anos foi de: " << km5 << "\n A média de quilometros rodados entre esses carros foi de: " << md << endl;
            //Fim dos cout.
    
    teclado.close();        //Fim da abertura do arquivo.
    
    return 0;
    
}
