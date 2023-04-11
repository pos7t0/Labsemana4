#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100
//definir estructura
typedef struct patient {
	char name[20];
	int age;
	int room;
	float temperatura[N];
} Patient;
//para agregar paciente
Patient addPatient(Patient pacientes[],int n,int* aux){
	
	system("cls");
	//random
	srand(time(NULL));
	float temp;
	//variable for
	int i,j;
	//variable para mostrar cuantos pacientes pudo agregar exitosamente
	int c=0,auxn=n;
	n+=*aux;
	for(i=*aux;i<n;i++){
		//notificar al jugardor si puede o no agregar pacientes
		if(*aux<N){
			//agregar cambios
			printf("  \t*Paciente %d\n*",i+1);
			printf("ingrese el nombre del paciente\n");
			scanf("%s",&pacientes[i].name);
			printf("ingrese la edad del paciente\n");
			scanf("%d",&pacientes[i].age);
			printf("ingrese el numero de habitacion del paciente\n");
			scanf("%d",&pacientes[i].room);
			do{
				temp=rand()%36+8;
			}while(temp<35);
			//inicializar
			for(j=0;j<N;j++){
				pacientes[i].temperatura[j]=0;
			}
			pacientes[i].temperatura[0]=temp;
			*aux+=1;
			c++;
		}else{
			printf("no se puede seguir agregando pacientes\n");
			i+=n;	
		}	
	}
	printf("se ha podido agregar %d pacientes de los %d que pidio el usuario\n",c,auxn);
	printf("\n");
	
}
void printPatient(Patient paciente[], int* aux){
	int i,j;
	system("cls");
	for(i=0;i<*aux;i++){
		
		printf("  \t*Paciente %d*\n",i+1);
		printf("nombre: %s\n",paciente[i].name);
		printf("edad: %d\n",paciente[i].age);
		printf("numero de habitacion: %d\n",paciente[i].room);
		printf("temperatura\n");
		for(j=0;j<N;j++){
			if(paciente[i].temperatura[j]>=35){
				printf("dia %d: %f\n",j+1,paciente[i].temperatura[j]);
			}
			
		}
		
	}
}
void recordTemperature(Patient pacientes[],int* aux){
	int i=1,j;
	system("cls");
	do{
		if(i<1 || i>*aux){
			printf("paciente inexistente\n");
		}
		printf("ingrese el numero del paciente que quiera agregar la nueva temperatura\n");
		scanf("%d",&i);
	}while(i<1 || i>*aux);
	
	for(j=0;j<N;j++){
		if(pacientes[i-1].temperatura[j]<35){
			pacientes[i-1].temperatura[j]=35;
			do{
				if(pacientes[i-1].temperatura[j]<35 || pacientes[i-1].temperatura[j]>43){
					printf("temperatura no creible(la temperatura ronda de los 35 a 43 )\n");
				}
				printf("ingrese nueva temperatura\n");
				scanf("%f",&pacientes[i-1].temperatura[j]);
				
			}while(pacientes[i-1].temperatura[j]<35 || pacientes[i-1].temperatura[j]>43);
			j+=N;
		}
	}
	
	
	
}
int main(){
	
	//variables para el codigo
	int numPatient=1,aux=0;
	//variables para escoger pasos
	int opcion=0;
	int *Aux;
	Aux=&aux;
	Patient pacientes[N];
	
	printf("\t*ADVERTENCIA*\n");
	printf("al ingresar los pacientes se le revisara \n");
	printf("la temperaturasin consultarlo al usuario\n");
	printf("\t*Bienvenido*\n");
	do{
		//para que el usuario interactue en el programa
		printf("Que es lo que desea hacer?\n");
		printf("[1]agregar paciente [2]ver pacientes\n");
		printf("[3]agregar temperatura\n");
		printf("[cualquier otro numero]SALIR\n");
		scanf("%d",&opcion);
		switch(opcion){
			//agregar un paciente
			case 1:{
				//validar numPatient si es que tiene numeros sin sentido
				do{
					if(numPatient<=0){
						printf("dato erroneo \n");
					}
					printf("ingrese cuantos pacientes quiere ingresar\n");
					scanf("%d",&numPatient);
				}while(numPatient<=0);
				addPatient(pacientes,numPatient,&aux);
				break;
			}
			//imprimir todos los pacientes
			case 2:{
				printPatient(pacientes,&aux);
				break;
			}
			case 3:{
				recordTemperature(pacientes,&aux);
				break;
			}
		}
			
	}while(opcion>=1 && opcion<=3);
	
	
	
	
	return 0;
}
