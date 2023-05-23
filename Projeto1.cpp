#include <cstdlib>
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main(int arcg, char ** argv){
    float valor,    //Valor do carro.
        km,         //Quilometragem do automóvel.
        pmotor,     //Potência do motor. 
        pctvca,     //Variável para o calculo do segundo exercício. Carro automático e com direção hidráulica.
        pct2,       //Variável para o calculo do segundo exercício. Câmbio automático e direção hidráulica.
        md,         //Média de quilometragem dos carros com mais de 5 anos.
        qt,         //Quantidade total de carros.
        qs,         //Quantidade de sedans.
        qp,         //Quantidade de pick-ups.
        qsu,        //Quantidade de SUVs.
        qh,         //Quantidade de Hatchs.
        qpa,        //Quantidade de carros do tipo passeio.
        qv,         //Quantidade de carros do tipo VAN.
        menor,      //Variável para guardar o menor valor de um carro.
        jurosm,     //Variável para calculo do juros do carro de menor valor.
        segma,      //Variável para o calculo do seguro do carro de maior valor.
        maior,      //Variável para guardar o maior valor de um carro.
        km5;        //Variável para guardar a soma dos carros com mais ou 5 anos.
    int portas,     //Quntas portas possui.
        ano,        //Qual o ano do modelo.
        ano5,       //Variável para o calculo de carros com mais ou 5 anos.
        qkm5;       //Variável para saber a quantidade de carros com mais ou 5 anos.
    char modelo,    //Qual é o "nome" do carro.
        marca,      //De qual marca.
        tipo,       //Tipo do carro. SEDAN/SUV/ETC...
        comb,       //Qual o combustível é movido o automóvel.
        camb,       //É câmbio automático ou manual?
        dire,       //Direção. Hidráulica ou elétrica?
        cor,        //Cor do carro. 
        placa,      //Qual é a placa.
        placam,     //Qual a placa do carro mais barato.
        placama;    //Qual a placa do carro mais caro.
        
    ifstream teclado ("Carros");    //Leitura do arquivo com os dados fornecidos.
    if (!teclado.is_open()){    //Condição de negação caso o arquivo não foi encontrado.
        cout << "\n Erro: Arquivo não encontrado." << endl;     //Mensagem de aviso para a falha de reconhecimento do arquivo.
        return 1;
    }

        //Esse espaço será reservado para a setagem devalores para a iniciação do problema.{
    q5 = 0;
    qh = 0;
    qp = 0;
    qpa = 0;
    qv = 0;
    qsu = 0;
    qs = 0;
    qr = 0;
    km5 = 0;
    menor = 999999999999;
        //}Esse espaço será reservado para a setagem de valores para a iniciação do problema.

    while (modelo != 'FIM'){
        //Todas as linhas que possuem "teclado >>" no início, são linhas em que estamos setando nas variáveis os valores contidos no arquivo de exemplo, de forma sincronizada com o arquivo-modelo.
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

        qt++;   //Soma gradativa de +1 no valor total.
                
                //Início para a resolução do primeiro problema sobre a porcentagem de cada categoria.
        if(modelo == 'Sedã'){           //Soma gradativa da quantidade de carros Sedã.
            qs++;
        }
        if(modelo == 'Hatch'){          //Soma gradativa da quantidade de carros Hatch. 
            qh++;
        }
        if(modelo == 'Pick-up'){        //Soma gradativa da quantidade de carros Pick-up.
            qp++;
        }
        if(modelo == 'Passeio'){        //Soma gradativa da quantidade de carros do tipo Passeio.
            qpa++;
        }
        if(modelo == 'SUV'){            //Soma gradativa da quantidade de carros SUV.
            qsu++;
        }
        if(modelo == 'Van'){            //Soma gradativa da quantidade de carros do tipo Van.
            qv++;
        }
                //Fim do primeiro exercício e início do segundo.
        if(camb == 'automático' && dire == 'hidráulica'){ //Começo do segundo exercício proposto sobre a porcentagem de carros com câmbio automático e direção hidráulica.
            pctvca++;
        }
                //Fim do segundo exercício e início do terceiro.
        if(pmotor = 1.0){
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
            
            //Espaço dedicado para os cálculos das informações pedidas que precisam ser feita fora da repetição.
    jurosm = ;                          //Calculo para saber o jutos da prestação do carro mais barato em 48 parcelas.
    segma = ;                           //Calculo para saber quanto custa o seguro do carro mais caro.
    ano5 << 2023 - ano;                 //Calculo para saber se o carro tem ou mais de 5 anos.
    md << km5/qkm5;                     //Calculo das médias dos km rodados pelos carros com mais de 5 anos.
            //Fim do espaço para os cálculos fora da repetição.       
            
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
    
    return 0;
    
}
