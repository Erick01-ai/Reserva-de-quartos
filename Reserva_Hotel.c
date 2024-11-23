#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

#define MAX_QUARTOS 50
#define MAX_RESERVAS 50

struct dados {
     char nome[40];
     char telefone[14];
     int quarto;
};
typedef struct dados dados;

struct dia{
    int dia;
    int mes;
    int ano;
};
typedef struct dia dia;

struct diaSaida{
    int dia;
    int mes;
    int ano;
};
typedef struct diaSaida diaSaida;

int isDisponivel(dia dataEntrada, diaSaida dataSaida, int quarto, dia data[], diaSaida dataSaidas[], int quartos[], int reservas) {
    for (int n = 0; n < reservas; n++) {

        if (quartos[n] == quarto) { // Mesma reserva de quarto

            // Verificação de datas
            if (!(dataSaida.ano < data[n].ano ||
                 (dataSaida.ano == data[n].ano && dataSaida.mes < data[n].mes) ||
                 (dataSaida.ano == data[n].ano && dataSaida.mes == data[n].mes && dataSaida.dia < data[n].dia) ||
                 dataEntrada.ano > dataSaidas[n].ano ||
                 (dataEntrada.ano == dataSaidas[n].ano && dataEntrada.mes > dataSaidas[n].mes) ||
                 (dataEntrada.ano == dataSaidas[n].ano && dataEntrada.mes == dataSaidas[n].mes && dataEntrada.dia > dataSaidas[n].dia))) {
                return 0; // tem conflito de datas
            }
        }
    }
    return 1; // não tem conflito
}



int main(){
    setlocale(LC_ALL,"Portuguese");

    dados reserva[MAX_RESERVAS];
    dia data[MAX_RESERVAS];
    diaSaida dataSaida[MAX_RESERVAS];

    int op,opcao;
    int n=0,i=0;
    int reservas=0;
    int numero_quarto[MAX_QUARTOS];
    int quartoReservado,quartoJaReservado;

    dia novaDataEntrada ,novaDataSaida;


     do{
        do{
            printf("   _-_-_-HOTEL SENA 5 STARS-_-_-_   \n");
            printf("Deseja fazer uma reserva?\n");
            printf("1 - Sim\n");
            printf("2 - Não\n");
            scanf("%d",&op);
            if(op < 1 || op > 2){
                printf("Opção invalida!\n");

            }
        }while(op < 1 || op > 2);

            system("cls");

              if(op == 1){
                    printf("   _-_-_-HOTEL SENA 5 STARS-_-_-_   \n");

                printf("\nInsira seu nome:");
                scanf(" %39[^\n]s",&reserva[n].nome);

                printf("\nInsira seu telefone (xx)xxxxx-xxxx:");
                scanf(" %13[^\n]s",&reserva[n].telefone);

            //INSERIR DATA DE ENTRADA
            do{
                    do{
                            do{
                                    printf("\n-_-_-Data De Entrada-_-_-\n");
                                printf("Insira a data dd/mm/aaaa: ");
                                scanf("%d/%d/%d",&data[n].dia,&data[n].mes,&data[n].ano);

                                if(data[n].dia < 1 || data[n].dia > 31){
                                    printf("Dia inexistente!\n\n");
                                }
                                if(data[n].mes < 1 || data[n].mes > 12){
                                    printf("Mês inexistente!\n\n");
                                }
                                if(data[n].ano < 1){
                                    printf("Ano inexistente!\n\n");
                                }


                            }while(data[n].ano < 1);
                    }while(data[n].mes < 1 || data[n].mes > 12);
              }while(data[n].dia < 1 || data[n].dia > 31);

              //INSERIR DATA DE SAIDA
               do{
                    do{
                            do{
                                    printf("\n-_-_-Data De Saida-_-_-\n");
                                printf("Insira a data dd/mm/aaaa: ");
                                scanf("%d/%d/%d",&dataSaida[n].dia,&dataSaida[n].mes,&dataSaida[n].ano);

                                if(dataSaida[n].dia < 1 || dataSaida[n].dia > 31){
                                    printf("Dia inexistente!\n\n");
                                }
                                if(dataSaida[n].mes < 1 || dataSaida[n].mes > 12){
                                    printf("Mês inexistente!\n\n");
                                }
                                if(dataSaida[n].ano < 1){
                                    printf("Ano inexistente!\n\n");
                                }


                            }while(dataSaida[n].ano < 1);
                    }while(dataSaida[n].mes < 1 || dataSaida[n].mes > 12);
              }while(dataSaida[n].dia < 1 || dataSaida[n].dia > 31);


                  do{
                    printf("\nInsira qual quarto deseja reservar? 1 a 50\n");
                    printf("QUARTOS DISPONIVEIS\n");

                       for(int j=1;j<=MAX_QUARTOS;j++){

                           int reservado = 0;

                            for(i=0;i<reservas;i++){

                                if(numero_quarto[i] == j && !isDisponivel(data[n],dataSaida[n],j,data,dataSaida,numero_quarto,reservas)){

                                    reservado = 1;
                                    break;
                                }
                            }
                            if(reservado){
                                 printf("X ");
                             }else {
                                 printf("%d ",j);
                               }
                               if(j % 10 == 0){
                                 printf("\n");
                               }
                        }
                        scanf("%d",&quartoReservado);

                if (quartoReservado < 1 || quartoReservado > MAX_QUARTOS){
                    printf("Quarto inexistente!\n");

                }
                  else if(!isDisponivel(data[n], dataSaida[n],quartoReservado,data,dataSaida,numero_quarto,reservas)){
                    printf("Este quarto já esta reservado para estas datas.\n");
                    printf("Por favor escolha outro quarto ou altere as datas.\n");

                       quartoReservado = 0;
                  }

              }while(quartoReservado < 1 || quartoReservado > MAX_QUARTOS);

                  reserva[n].quarto = quartoReservado;
                  numero_quarto[reservas] = quartoReservado;



                   system("cls");

                    printf("Reserva feita com sucesso!\n");
                    printf("   _-_-_-HOTEL SENA 5 STARS-_-_-_   \n");
                    printf("             AGRADEÇE               \n");

                    printf("Reserva %d°\n",n+1);
                    printf("\nNome: %s\n",reserva[n].nome);
                    printf("\nTelefone: %s\n",reserva[n].telefone);
                    printf("\nQuarto: n°%d\n",reserva[n].quarto);
                    printf("\nEntrada: %02d/%02d/%d\n",data[n].dia,data[n].mes,data[n].ano);
                    printf("\nSaída: %02d/%02d/%d\n",dataSaida[n].dia,dataSaida[n].mes,dataSaida[n].ano);
                    printf("\n");

              n++;
             reservas++;

            }
            if(op == 2){
                 printf("   _-_-_-HOTEL SENA 5 STARS-_-_-_   \n");
                 printf("             AGRADEÇE               \n");

                 printf("Ver reservas salvas?\n");
                 printf("1- SIM\n");
                 printf("2- NÃO\n");
                 scanf("%d",&opcao);

                 if(opcao < 1 || opcao > 2){
                    printf("Opção invalida!\n");
                    printf("Digite novamente:");
                    scanf("%d",&opcao);

                 } else if (opcao == 1){
                       if(reservas == 0){
                            system("cls");
                          printf("Não há reservas feitas!\n\n");
                          printf("   _-_-_-HOTEL SENA 5 STARS-_-_-_   \n");
                          printf("             AGRADEÇE               \n");
                       }else{
                           for(n=0;n<reservas;n++){
                                printf("Reserva %d°\n",n+1);
                                printf("Nome: %s\n",reserva[n].nome);
                                printf("Telefone: %s\n",reserva[n].telefone);
                                printf("Quarto: n°%d\n",reserva[n].quarto);
                                printf("Entrada: %02d/%02d/%d\n",data[n].dia,data[n].mes,data[n].ano);
                                printf("Saída: %02d/%02d/%d\n",dataSaida[n].dia,dataSaida[n].mes,dataSaida[n].ano);

                                printf("-----------------------------------\n");
                           }
                       }
                   } else if(opcao == 2){
                       system("cls");
                         printf("   _-_-_-HOTEL SENA 5 STARS-_-_-_   \n");
                         printf("             AGRADEÇE               \n");
                     }
                 break;
            }

      }while(reservas != MAX_RESERVAS);



return 0;
}

