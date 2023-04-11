#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 50
//definir estructura
typedef struct patient {
	char name[20];
	int age;
	int room;
} Patient;
//para agregar paciente
Patient addPatient(Patient pacientes[]){
	
	int i;
	for(i=0;i<N;i++){
		printf("  \t*Paciente %d\n*",i+1);
		printf("ingrese el nombre del paciente\n");
		scanf("%s",&pacientes[i].name);
		printf("ingrese la edad del paciente\n");
		scanf("%d",&pacientes[i].age);
		printf("ingrese el numero de habitacion del paciente\n");
		scanf("%d",&pacientes[i].room);
	}
	
}
void printPatient(Patient paciente[]){
	int i;
	for(i=0;i<N;i++){
		printf("  \t*Paciente %d*\n",i+1);
		printf("nombre: %s\n",paciente[i].name);
		printf("edad: %d\n",paciente[i].age);
		printf("numero de habitacion: %d\n",paciente[i].room);
	}
}
int main(){
	
	Patient pacientes[N];
	
	addPatient(pacientes);
	printPatient(pacientes);
	
	return 0;
}

