#include <stdio.h>
#include <stdlib.h>

float peso, altura, imc;

void lerPeso(){
	printf("Informe o seu peso:");
	scanf("%f", &peso);
}
void lerAltura(){
	printf("Informe a sua altura:");
	scanf("%f", &altura);
}
void calcularImc(){
	imc = peso/(altura*altura);
}
void resultadoImc(){
	if (imc <19 ){
    	printf("MUITO MAGRO");   
    	}else{       
        	if(imc >= 19 && imc<25){
            	printf("NORMAL");       
        		}else{       
             		if(imc >= 25 && imc<30){
                  		printf("SOBRE PESO");       
             			}else{       
                   			if(imc >= 30 && imc<=40){
                        		printf("NORMAL");       
                  				}else{       
                        			if (imc>40){
                               		printf("OBESIDADE GRAVE");
                        			}
                    			}
                			}
            		} 
        	}
}
void mostrarResultados(){
	printf("Seu peso: %.2f"
			"\tSua altura: %.2f"
			"\tSeu imc: %.2f"
			"\tEstado: ", peso, altura, imc);
}

int main(){
	lerPeso();
	lerAltura();
	calcularImc();
	mostrarResultados();
	resultadoImc();
}
