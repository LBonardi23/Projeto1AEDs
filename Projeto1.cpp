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
            qt,         //Quantidade total de carros.
            qs,         //Quantidade de Sedans.
            qp,         //Quantidade de Pick-ups.
            qsu,        //Quantidade de SUVs.
            qh,         //Quantidade de Hatchs.
            qpa,        //Quantidade de carros do tipo passeio.
            qv,         //Quantidade de carros do tipo VAN.
            menor,      //Variável para guardar o menor valor de um carro.
            jurosm,     //Variável para calculo do juros do carro de menor valor.
            segma,      //Variável para o calculo do seguro do carro de maior valor.
            maior,      //Variável para guardar o maior valor de um carro.
            km5;        //Variável para guardar a soma dos carros com mais ou 5 anos.

    //Variáveis com valores inteiros:
    int     portas,     //Quantidade de portas do carro.
            ano,        //Ano do modelo.
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
    char    modelo,     //Modelo do carro.
            marca,      //Marca do carro.
            tipo,       //Tipo do carro.
            comb,       //Combustível utilizado pelo carro.
            camb,       //Classificação entre Câmbio automático ou Manual.
            dire,       //Classificação da direção entre Hidráulica ou Elétrica.
            cor,        //Cor do carro.
            placa,      //Placa do carro.
            placam,     //Placa do carro mais barato.
            placama;    //Placa do carro mais caro.
        
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
    menor = 999999999999;
    modelo = 'START';

    //Descrição repetição!!!!!!
    while (modelo != 'FIM'){
        teclado >> modelo;
        teclado >> marca;
        teclado >> tipo;
        teclado >> ano;
        teclado >> km;
        teclado >> pmotor;
        teclado >> comb; 
        telcado >> camb; 
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

        //Separação para o exercicio de porcentagem de veículos com câmbio automático e com direção hidráulica entre todos os veículos.
        if(camb == 'automático' && dire == 'hidráulica'){ 
            pctvca++;
        }

        //Separação para o exercicio de placa e valor do veículo mais barato entre os veículos com potência do motor 1.0.
        if(pmotor == 1.0 && menor < valor){
            menor << valor;
            placam << placa;
            }
        
        //Separação para o exercicio de placa e valor do veículo mais caro com direção hidráulica e combustível flex.
        if(dire == 'Hidráulica' && comb == 'Flex' && valor > maior){
            maior << valor;
            placama << placa;
        }

        //Separação para a quantidade e média de kilometragem dos veículos com 5 anos ou mais (2018).
        if(ano5 >= 5){
            km5 = km5+km;
            qkm5++;
        }
    }    //Fim da repetição da linha 71.

    //Espaço dedicado para os cálculos das informações pedidas.
    jurosm = ;            //Calculo para saber o valor da prestação do carro mais barato em 48 parcelas.
    segma = ;             //Calculo para saber quanto custa o seguro do carro mais caro.
    ano5 << 2023 - ano;   //Calculo para saber se o carro tem ou mais de 5 anos.
    md << km5/qkm5;       //Calculo das médias dos km rodados pelos carros com mais de 5 anos.       
        
    //Porcentagens de veículos nas categorias de tipo.
    cout << "\n A porcentagem de carros do tipo sedã é de: %" << (qs/qt)*100 << endl;
    cout << "\n A porcentagem de carros do tipo hatch é de: %" << (qh/qt)*100 << endl;
    cout << "\n A porcentagem de carros do tipo pick-up é de: %" << (qp/qt)*100 << endl;
    cout << "\n A porcentagem de carros do tipo passeio é de: %" << (qpa/qt)*100 << endl;
    cout << "\n A porcentagem de carros do tipo SUV é de: %" << (qsu/qt)*100 << endl;
    cout << "\n A porcentagem de carros do tipo van é de: %" << (qv/qt)*100 << endl;
            
    //Porcentagem de veículos com câmbio automático e com direção hidráulica entre todos os veículos.
    cout << "\n A porcentagem de carros que possuem câmbio automático e direção hidráulica entre todos os veículos é de: %" << (pctvca/qt)*100 << endl;

    //Placa e valor do veículo mais barato entre os veículos com potência do motor 1.0, e ainda, valor da prestação do financiamento em 48 meses com taxa de juros atuais.
    cout << "\n A placa do veículo 1.0 mais barato é: " << placam << "\n O valor desse carro é de: " << menor << "E o valor da prestação desse carro em 48 vezes com juros anuais é de: " << jurosm << endl;

    //Placa e valor do veículo mais caro com direção hidráulica e combustível flex, e ainda, valor do seguro estimado (porcentagem estimada sobre o valor do veículo)
    cout << "\n A placa do veículo mais caro é: " << placama << "\n O valor desse carro é de: " << maior << "\n E o valor do seguro para este carro é de: " << segma << endl;

    //Quantidade e média de kilometragem dos veículos com 5 anos ou mais (2018).
    cout << "\n A quantidade de quilometros rodados para carros com ou mais de 5 anos foi de: " << km5 << "\n A média de quilometros rodados entre esses carros foi de: " << md << endl;
   
    teclado.close();    //Fim da abertura do arquivo.
    
    return 0;

}
