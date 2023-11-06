#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include<ctype.h>

void AutomataFD(int NumEstados,int NumEstFinales,int NumSimbolos);
void especial();
	
main(){
	setlocale(LC_CTYPE,"Spanish");
	int respuesta,ciclo=1,bandera=1,NumEstados,NumEstFinales,NumSimbolos,NumMinimEstados;
	do{
		do{
			printf("Aut�matas Finitos Deterministas");
			printf("\nEste programa lee los estados de la forma q0,q1...qn");
			printf("\n\nIntrodusca los datos siguientes");
	
			printf("\nCantidad de estados: ");
			scanf(" %d",&NumEstados);
			if(NumEstados==1){
				NumEstFinales=1;
			}
			else{
				printf("Cantidad de estados finales: ");
				scanf(" %d",&NumEstFinales);
			}
		
			if(NumEstados!=0 && NumEstFinales!=0){
				if(NumEstFinales<=NumEstados){
					bandera=0;
				}	
			}
			
			if(bandera==1){
				printf("\n\nNo es posible hacer un AFD con los datos ingresados\nIntente de nuevo\n\n");
			}
			
		}while(bandera==1);
		
		do{
			if(NumEstados!=1){
				printf("\nCantidad de s�mbolos que conforma su alfabeto: ");
				scanf(" %d",&NumSimbolos);
				NumMinimEstados=NumSimbolos+1;
				if(NumEstados<NumMinimEstados) printf("\nNo puede ingresar una cantidad de simbolos >= a la cantidad de estados");
			}
		}while(NumEstados<NumMinimEstados);
		
		if(NumEstados==1){
			especial();
		}
		else{
			AutomataFD(NumEstados,NumEstFinales,NumSimbolos);
		}
	
		printf("\n\n�Desea intentar de nuevo?\nPulse el n�mero que acompa�a cada opci�n");
		printf("\n0) No");
		printf("\n1) Si\n");
		scanf(" %d",&respuesta);
		
		ciclo=respuesta;
	}while(ciclo!=0);
	printf("\nGracias por su tiempo.");
	return 0;
}


void AutomataFD(int NumEstados,int NumEstFinales,int NumSimbolos){
	int q[NumEstados],Finales[NumEstFinales],Letrallegada[NumEstados][NumSimbolos],Estadollegada[NumEstados][NumSimbolos];
	int aceptada,palabra[100],repetir=0,i,j,k;
	char simbolos[NumSimbolos][1];
	
	if(NumEstFinales!=1){ 
		printf("\nIntroduzca el n�mero de los estados finales");
		for(i=0;i<NumEstFinales;i++){
			do{ 
				printf("\nq");
				scanf(" %d",&Finales[i]);
			}while(Finales[i]<0);
		}
	}
	else{
		printf("\nIntroduzca el n�mero del estado final: ");
		scanf(" %d",&Finales[0]);
	}
	
	for(i=1;i<=NumSimbolos;i++){
		printf("\nIntroduzca el %d s�mbolo de su alfabeto: ",i);
		scanf(" %c",&simbolos[i][0]);
	}
	
	printf("\nTransiciones\n");
	
	for(i=1;i<=NumEstados;i++){
		for(j=1;j<=NumSimbolos;j++){
			printf("De q%d->q",i-1);
			scanf(" %c",&Estadollegada[i][j]);
			printf("Transita la letra: ");
			scanf(" %c",&Letrallegada[i][j]);
		}
	}
	
	do{
		//leer palabra
		int permanece,ciclo;
		aceptada=0;
		printf("\nEscriba una palabra formado por su alfabeto para verificar si lo acepta el AFD");
		printf("\nPalabra");
		scanf(" %c",&palabra);
		
		for(k=1;k<=100;k++){
			for(i=1;i<=NumEstados;i++){
				for(j=1;j<=NumSimbolos;j++){
					if(palabra[k]==Letrallegada[i][j]){
						permanece=Estadollegada[i][j];
						i=NumEstados+1;
						j=NumSimbolos+1;
					}
				}
			}
		}
		
		for(i=1;i<=NumEstFinales;i++){
			if(permanece==Finales[i]){
				aceptada=1;
			}
		}
		if(aceptada==1){
			printf("Aceptada");
		}
		else{
			printf("Rechazada");
		}
		
		printf("\n¿Desea intentar con otra palabra?");
		printf("\n0) NO");
		printf("\n1) SI");
		scanf(" %d",&ciclo);
		repetir=ciclo;
	} while (repetir!=0);
}

void especial(){
	printf("\nEl AFD tendr� un solo estado");
	printf("\n)->El estado inicial ser� el mismo que el estado final");
	printf("\n)->Tendr� n transisiones que ir�n de q0->q0 con cada s�mbolo del alfabeto\n");
	printf("\nTodas las palabras dentro del alfabeto ser�n aceptadas por el AFD: ");
}