#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 50
//definir estructura
typedef struct patient {
	char name[20];
	int age;
	int room;
	float temperatura[N];
	struct patient *next;
} Patient;
//para agregar paciente
Patient addPatient(Patient **head,int n,int* aux){
	Patient *newpaciente=(Patient*)malloc(sizeof(Patient));
	system("cls");
	//random
	srand(time(NULL));
	float temp;
	//variables for
	int i,j;
	n+=*aux;
	for(i=*aux;i<n;i++){
		//crear paciente
		printf("  \t*Paciente %d\n*",i+1);
		printf("ingrese el nombre del paciente\n");
		scanf("%s",&newpaciente->name);
		printf("ingrese la edad del paciente\n");
		scanf("%d",&newpaciente->age);
		printf("ingrese el numero de habitacion del paciente\n");
		scanf("%d",&newpaciente->room);
		do{
			temp=rand()%36+8;
		}while(temp<35);
		//inicializar
		for(j=0;j<N;j++){
			newpaciente->temperatura[j]=0;
		}
		newpaciente->temperatura[0]=temp;
		newpaciente->next=NULL;
		*aux+=1;
		if (*head == NULL) {
			*head = newpaciente;
		} else {
			Patient *current = *head;
			while (current->next != NULL) {
				current = current->next;
			}
			current->next = newpaciente;
		}	
	}
	printf("\n");
	
}
void printPatient(Patient *head){
	int i=1,j;
	system("cls");
	printf("Lista de pacientes\n");
	
	Patient *current = head;
	while (current != NULL) {
		printf("\t*paciente %d*\n",i);
		printf("nombre: %s\n", current->name);
		printf("edad: %d\n", current->age);
		printf("numero de cuarto: %d\n", current->room);
		printf("temperatura\n");
		for(j=0;j<N;j++){
			if(current->temperatura[j]>=35){
				printf("dia %d: %f\n",j+1,current->temperatura[j]);
			}
			
		}
		current = current->next;
		i++;
	}
}


void recordTemperature(Patient *head,int* aux){
	int opcion=1,contador=0;
	int i=1,j;
	system("cls");
	do{
		if(opcion<1 || opcion>*aux){
			printf("paciente inexistente\n");
		}
		printf("ingrese el numero del paciente que quiera agregar la nueva temperatura\n");
		scanf("%d",&opcion);
	}while(opcion<1 || opcion>*aux);
	Patient *current = head;
	while(contador==0){
		if(opcion==i){
			for(j=0;j<N;j++){
				if(current->temperatura[j]<35){
					current->temperatura[j]=35;
					do{
						if(current->temperatura[j]<35 || current->temperatura[j]>43){
							printf("temperatura no creible(la temperatura ronda de los 35 a 43 )\n");
						}
						printf("ingrese nueva temperatura\n");
						scanf("%f",&current->temperatura[j]);
						
					}while(current->temperatura[j]<35 || current->temperatura[j]>43);
					j+=N;
				}
			}
			contador++;
		}
		current = current->next;
		i++;
	}
	
	
	
	
}
void dischargePatient(Patient *head,int* aux){
	int opcion=1,contador=0;
	int i=1,c=0;
	system("cls");
	do{
		if(opcion<1 || opcion>*aux){
			printf("paciente inexistente\n");
		}
		printf("ingrese el numero del paciente que quiera darle de alta\n");
		scanf("%d",&opcion);
	}while(opcion<1 || opcion>*aux);
	Patient *current = head;
	Patient *auxcurrent = head;
	while(opcion!=i){
			auxcurrent=current;	
			current=current->next;	
		i++;
	}
	if(current!=NULL){
		if(auxcurrent==current){
			current=current->next;
			*head = *current;
			
		}else if(auxcurrent!=current && current->next!=NULL){
			
			auxcurrent->next=current->next;	
		}else if(auxcurrent!=current && current->next==NULL){
			auxcurrent->next=NULL;
		}
		free(current);
		*aux=*aux-1;
	}
	
}
void freePatients(Patient *head) {
	Patient *current = head;
	while (current != NULL) {
		Patient *next = current->next;
		free(current);
		current = next;
	}
}
int main(){
	
	//variables para el codigo
	int numPatient=1,aux=0;
	//variables para escoger pasos
	int opcion=0;
	int *Aux;
	Aux=&aux;
	Patient *listapacientes;
	
	printf("\t*ADVERTENCIA*\n");
	printf("al ingresar los pacientes se le revisara \n");
	printf("la temperaturasin consultarlo al usuario\n");
	printf("\t*Bienvenido*\n");
	do{
		//para que el usuario interactue en el programa
		printf("Que es lo que desea hacer?\n");
		printf("[1]agregar paciente    [2]ver pacientes\n");
		printf("[3]agregar temperatura [4]dar alta a un paciente\n");
		printf("[cualquier otro numero]SALIR\n");
		scanf("%d",&opcion);
		switch(opcion){
			//agregar un paciente
			case 1:{
				addPatient(&listapacientes,numPatient,&aux);
				break;
			}
			//imprimir todos los pacientes
			case 2:{
				printPatient(listapacientes);
				break;
			}
			case 3:{
				recordTemperature(listapacientes,&aux);
				break;
			}
			case 4:{
				dischargePatient(listapacientes,&aux);
				break;
			}
		}
			
	}while(opcion>=1 && opcion<=4);
	freePatients(listapacientes);
	
	
	
	return 0;
}
