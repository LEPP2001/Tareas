//Luis Poot Poot

#include <stdio.h>
#include <locale.h>
#include <conio.h>

main(){
	setlocale(LC_CTYPE,"Spanish");
	
	int Dim, Dir[2]={0,0}, esize, Base, opcion, Mult,i, k;
	int  LimInfN[Dim], LimSupN[Dim], DN[Dim], iN[Dim], ipN[Dim];
	
	do{
		do{
			printf("\nCalculando la dirección de elementos en un arreglo de k dimensiones");
			printf("\nNúmero de dimensiones: ");
			scanf(" %d",&Dim);
			if(Dim<=0) printf("\nDimensión no válida\nIntente de nuevo.\n");
		}while(Dim<=0);
		
		for(k=0;k<Dim;k++){
			printf("\nLímite inferior de la dimensión %d: ",(k+1));
			scanf(" %d",&LimInfN[k]);
			
			do{
				printf("Límite superior de la dimensión %d: ",(k+1));
				scanf(" %d",&LimSupN[k]);
				
				if(LimInfN[k]>LimSupN[k]) printf("El límite superior debe ser mayor que el límite inferior\n\n");
				else DN[k]=LimSupN[k] - LimInfN[k] + 1;
			}while(LimInfN[k]>LimSupN[k]);
		}
		
		for(k=0;k<Dim;k++){
			do{
				printf("\nÍndice i%d del elemento a localizar: ",(k+1));
				scanf(" %d",&ipN[k]);
				iN[k] = ipN[k] - LimInfN[k] + 1;
				if(iN[k]>DN[k] || iN[k]<1) printf("Índice No válido\nIntente de nuevo\n\n");
			}while(iN[k]>DN[k] || iN[k]<1);
		}
	
		printf("\nBase desde la que se guardó el primer elemento: ");
		scanf(" %d",&Base);
		printf("\nNúmero de bytes por elemento: ");
		scanf(" %d",&esize);
	
		//POR RENGLONES
		for(k=0;k<Dim;k++){
    		Mult = 1;
    		for(i=k+1;i<Dim;i++){
        		Mult = Mult * (DN[i]);
    		}
    		Dir [0] = Dir [0] + Mult * (iN[k] - 1);
		}

		Dir [0] = Dir [0] * esize + Base;

		//POR COLUMNAS
		for(k=(Dim-1);k>=0;k--){
  		  Mult = 1;
   			for(i=k-1;i>=0;i--){
        		Mult = Mult * (DN[i]);
    		}   
    		Dir [1] = Dir [1] + Mult * (iN[k] - 1);
		}

		Dir [1] = Dir [1] * esize + Base;
		
		printf("\n\t\t\t\tRESULTADOS\n");
		for(k=0;k<2;k++){
			printf("-----------------------------------------------------------------------------");
			printf("\nDirección de memoria del elemento i");
			for(i=0;i<Dim;i++){
				printf("%d",iN[i]);
			}
			if(k==0){
				printf(" ordenado por renglones\t|  %d\n",Dir[0]);
			}
			else {
				printf(" ordenado por columnas\t|  %d\n",Dir[1]);
			}
		}
		printf("-----------------------------------------------------------------------------");
		
		printf("\n\nProceso terminado.\n");
		
		printf("\nIngrese una opción");
		do{
			printf("\n1) Repetir proceso\n2) Salir.\nOpcion: ");
			scanf(" %d",&opcion); 
			if(opcion!=1 && opcion!=2) printf("\nOpción no válida\n");
		}while(opcion!=1 && opcion!=2);
	
	}while(opcion==1);
	
	printf("\n\nProceso terminado.\nPulse cualquier tecla para terminar.");
	getch();
	return 0;
}
