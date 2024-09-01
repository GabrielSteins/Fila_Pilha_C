#include <stdio.h>
#define TamanhoMax 100
int Tamanho = 0;
int dados[TamanhoMax];
int Topo = 0;
int Inicio = 0;
int indice = 0;
int busca = 0;
void Inserir(){
    if(indice == TamanhoMax){
    printf("  cheia \n");    
    }
    else{
        printf(" Digite o dado:\n ");
        scanf("%d",&dados[indice]);
        indice++;
    }
}
void Imprimir(){
    int i;
    if(indice < TamanhoMax){
        printf("{");
        for(i=0;i<indice;i++){
            printf(" %d ", dados[i]);
        }
        printf("}\n");
    }
    else{
            for(i=0;i<indice-1;i++){
            printf(" %d ", dados[i]);
        }
    }
}
void pop(){
    Topo = indice -1;
    if(Topo < 0 ){
        printf(" Nao foi possivel realizar a operacao \n");
    }
    else{
        printf("\nElemento removido[%d]\n",dados[Topo]);
        indice--;
    }
}
int BuscarIndice(){
    int i;
    printf(" \n Digite o indice do dado que deseja buscar: \n ");
    scanf("%d", &i);
    if(dados[i] == 0){
    	printf(" Os dados estao vazio\n");
    	return -1;
	}else{
    printf(" [%d] \n",dados[i]);
    return i;}
}
int BuscarValor(){
    int valor;
    int i;
    printf(" \n Digite o valor do dado que deseja buscar: \n ");
    scanf("%d", &valor);
    for(i=0;i<indice;i++){
    	if( valor == dados[i] ){
    		return valor;
		}
	}
	printf(" Valor nao encontrado\n");
    return 0;
}
void RemoverIndice(int busca){
    int tamanhoAtual = indice;
    int i;
    for(i = busca;i<tamanhoAtual;i++){
        if(dados[i] == 0){
            break;
        }else{
            dados[i] = dados[i+1];
        }
    }
    indice--;
}
void RemoverValor(int valor){
    int tamanhoAtual = indice;
    int i;
    int busca;
    for(i = 0;i<tamanhoAtual;i++){
        if(dados[i] == valor){
            busca = i;
            break;
        }
    }
    for(i = busca;i<tamanhoAtual;i++){
        if(dados[i] == 0){
            break;
        }else{
            dados[i] = dados[i+1];
        }
    }
    indice--;
}

void AlterarIndice(int busca){
    printf( " \nInsira o novo dado: \n");
    scanf("%d",&dados[busca]);
}
void AlterarValor(int valor){
    int i;
    for(i=0;i<indice;i++){
        if(valor == dados[i]){
            break;
        }
    }
    printf( "\n Insira o novo dado: \n");
    scanf("%d",&dados[i]);
}

void RemoverFila(){
    int i = 0;
    if(indice > 0){
    printf("[ %d ]\n", dados[0]);
    for(i=0;i<indice -1;i++){
        dados[i] = dados[i + 1];
    }
    indice--;}
    else{
        printf(" Fila vazia\n");
    }
}

void BubbleSort(){
	int end = indice,i,continuar,aux;
		if (indice == 0){
		printf(" vazia \n");
		return;}
	do{
		continuar = 0;
		for(i=0;i<end-1;i++){
			if(dados[i]>dados[i+1]){
			   aux = dados[i];
			   dados[i] = dados[i+1];
			   dados[i+1] = aux;
			   Imprimir();
			   continuar = i;
			}
			else{
			    Imprimir();
			}
		}

	}while(continuar != 0);
	}
void InsertionSort(){
    int j;
    int i;
    int index;
    int aux;
    if(indice == 0){
    	printf( " VAZIA !!! \n");
    	return;
	}
    Imprimir();
    for(i=0;i<indice - 1;i++){
        index = i;
        j = i + 1;
        if(index>=0 && j>=0 && dados[j]>dados[index]){
        	Imprimir();
		}
        while(index>=0 && j>=0 && dados[j]<dados[index]){
            aux = dados[j];
            dados[j] = dados[index];
            dados[index] = aux;
            Imprimir();
            j = index;
            index--;
    }
    }
}

void SelectSort(){
    int i;
    int j;
    int aux;
    if(indice == 0){
    	printf(" VAZIA !!!!!\n");
    	return;
	}
    for(i=0;i<indice;i++){
        for(j=i+1;j<indice;j++){
            if(dados[i]>dados[j]){
                aux = dados[i];
                dados[i] = dados[j];
                dados[j] = aux;
                Imprimir();
            }
            else{
                Imprimir();
            }
        }
    }
}



int main()
{   int i;
    int menuA;
    int menuB;
    int menuC;
    int busca;
    int valor;
    int menuD;
    Inicializar:
    printf(" \nDigite o Tamanho \n");
    scanf("%d", &Tamanho);
    indice = 0;
    i = 0;
    if( Tamanho<TamanhoMax){
    do{
    printf(" 1 - Pilha\n 2 - Fila\n 3 - Voltar\n 4 -Finalizar \n ");
    scanf("%d",&menuA);
    switch(menuA){
        case 1:
        do{
        menu2:
        printf(" 1- Push\n 2- Pop\n 3 - Buscar\n 4 - Ordenar\n 5- Voltar\n 6-imprimir\n");
        scanf("%d", &menuB);
        switch(menuB){
            case 1:
              if(i < Tamanho){
              Inserir();
			  i++;}
              else{
              	printf(" Tamanho Maximo \n");
			  }
            break;
            case 2:
            if(i>0){
			
            pop();
            i--;}
            else{
            	pop();
			}
            break;
            case 3:
            	if(indice == 0){
            		printf(" Vazia\n");
            		goto menu2;
				}
            printf( " 1 - Indice 2 - valor \n ");
            scanf("%d",&menuC);
            switch(menuC){
                case 1:
                busca = BuscarIndice();
                if(busca == -1){
                	goto menu2;
				}
                do{ printf( " Indice encontrado\n");
                    printf(" 1- Remover 2 - Alterar 3 - Voltar ");
                    scanf("%d", &menuD);
                    switch(menuD){
                        case 1:
                        if(i>0){
						
                        RemoverIndice(busca);
                        i--;
						goto menu2;}
                        else{
                        RemoverIndice(busca);
                        goto menu2;
						}
                        break;
                        case 2:
                        AlterarIndice(busca);
                        goto menu2;
                        break;
                    }
                }while(menuD != 3);
                break;
                case 2:
                valor = BuscarValor();
                if(valor == 0){
                	
                	goto menu2;
				}   
			
                    do{ printf(" Valor encontrado\n");
                    printf(" 1- Remover 2 - Alterar 3 - Voltar ");
                    scanf("%d", &menuD);
                    switch(menuD){
                        case 1:
                        if(i>0){
						
                        RemoverValor(valor);
                        i--;
						goto menu2;}
                        else{
                        RemoverValor(valor);
						goto menu2;	
						}
                        break;
                        case 2:
                        AlterarValor(valor);
                        goto menu2;
                        break;
                    }
                }while(menuD != 3);
                break;
            }
            break;
            case 4:
            	if(indice == 0){
            		printf(" Vazio \n");
            		goto menu2;
				}
                      do{
            printf( " 1 - Bubble Sort\n 2 - Insert Sort\n 3- Select Sort \n 4- Voltar\n " );
                scanf("%d",&menuD);
                switch(menuD){
                case 1:
                BubbleSort();
                break;
                case 2:
                InsertionSort();
                break;
                case 3:
                SelectSort();
                break;
                }
            }while(menuD !=4);
            break;
            case 6:
            	Imprimir();
            	break;
        }
        }while(menuB != 5);
        break;
        case 2:
        	
        do{ 
		menu3: 
		 printf(" 1- Inserir\n 2- Remover\n 3- Buscar\n 4- Ordenar\n 5- voltar\n 6-imprimir \n");
        scanf("%d", &menuB);
        switch(menuB){
            case 1:
             if(i < Tamanho){
              Inserir();
			  i++;}
              else{
              	printf(" Tamanho Maximo \n");
			  }
			  break;
            case 2:
            if(i>0){
			
            RemoverFila();
            i--;}
            else{
            RemoverFila();	
			}
            break;
            case 3:
             if(indice == 0){
             	printf(" Vazia\n");
             	goto menu3;
			 }
            printf(" 1 - indice 2 - valor  ");
            scanf("%d",&menuC);
            switch(menuC){
                case 1:
                busca = BuscarIndice();
                if( busca == -1){
                	goto menu3;
				}
                do{ printf(" Indice encontrado\n");
                    printf(" 1- Remover 2 - Alterar 3 - Voltar ");
                    scanf("%d", &menuD);
                    switch(menuD){
                        case 1:
                        if(i>0){
                        RemoverIndice(busca);
                        i--;
						goto menu3;}
                        else{
                        RemoverIndice(busca);
                        goto menu3;
						}
                        break;
                        case 2:
                        AlterarIndice(busca);
                        goto menu3;
                        break;
                    }
                }while(menuD != 3);
                break;
                case 2:
                valor = BuscarValor();
                    if(valor == 0){
                	goto menu3;
				}
                                do{ printf(" Valor encontrado\n");
                    printf(" 1- Remover 2 - Alterar 3 - Voltar ");
                    scanf("%d", &menuD);
                    switch(menuD){
                        case 1:
                        if(i>0){
                        RemoverValor(valor);                       
						i--;
						goto menu3;}
						else{
						RemoverValor(valor);
						goto menu3;
						}
                        break;
                        case 2:
                        AlterarValor(valor);
                        goto menu3;
                        break;
                    }
                }while(menuD != 3);
                break;
            }break;
            case 4:
            	if(indice == 0){
            	    printf( " Vazio\n");
            		goto menu3;
				}
            do{
            printf( " 1 - Bubble Sort\n 2 - Insert Sort\n 3- Select Sort \n 4- Voltar\n " );
                scanf("%d",&menuD);
                switch(menuD){
                case 1:
                BubbleSort();
                break;
                case 2:
                InsertionSort();
                break;
                case 3:
                SelectSort();
                break;
                }
            }while(menuD !=4);
            break;
            case 6:
            	Imprimir();
        }
        }while(menuB != 5);
              break;
        case 3:
        goto Inicializar;
        break;
        case 4:
             break;
        default:
        printf(" Opcao invalida \n");
        break;
    
    }}while(menuA != 4);}
    else{
    	printf( " Valor ultrapassa o limite maximo  ");
    	goto Inicializar;
	}
    
 return 0;   
}
