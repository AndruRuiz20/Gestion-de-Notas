#include<conio.h>
#include<windows.h>
#include<iostream>
#include<string.h>
#include<fstream>
#include<stdlib.h>
#include <iomanip>
#define N 10
using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

fstream Esc;
ifstream Lec;

//ESTRUCTURA ALUMNO CON SUS RESPECTIVAS VARIABLES
struct alumno{
	char codigo[15];
	char Nom[15];
	char Ape[15];
	char sexo[10];
	int edad;
	int lleno;
};
alumno alum[N];

void dibujarCuadro(int x1,int y1,int x2,int y2);
void gotoxy(int x,int y);
void CursorOn(bool visible, DWORD size);
void CursorOff();
void limpia();

void menuPrincipal();
void menuAlumnos();
void agregarAlumno(fstream &esc);
bool verifica(string Cod);
void ListarAlumno(ifstream &Lec);
void consultarAlumno(ifstream &Lec);
void eliminarAlumno(ifstream &Lec);
void menuProfesores();
void agregarProfesor(fstream &esc);
bool verifica1(string CodP);
void ListarProfesor(ifstream &Lec);
void consultarProfesor(ifstream &Lec);
void eliminarProfesor(ifstream &Lec);
void menuCursos();
void agregarCurso(fstream &esc);
bool verifica2(string CodC);
void ListarCurso(ifstream &Lec);
void consultarCurso(ifstream &Lec);
void eliminarCurso(ifstream &Lec);
void menuMatricula();
void Registro(fstream &esc);
bool verifica3(string numR);
void MatriculaAlumno(ifstream &Lec);

int main(){
	system("mode con: cols=80 lines=25");
	system("COLOR 0B");
	menuPrincipal();
}

void menuPrincipal()
{
	char op,op2;
	CursorOn(1,10);
    int opcion;
    bool repetir = true;

    do
    {
        system("cls");
        
        dibujarCuadro(1,1,78,24);//Cuadro grande
		dibujarCuadro(2,2,77,4);//Cuadro del titulo
		gotoxy(16,3); cout << "\t  SISTEMA DE NOTAS ACADEMICAS";		
       	gotoxy(4,6); cout << "MENU PRINCIPAL";
		gotoxy(4,9); cout << "[1] Alumnos";
		gotoxy(4,11); cout << "[2] Profesores";
		gotoxy(4,13); cout << "[3] Cursos";
		gotoxy(4,15); cout << "[4] Notas";
		gotoxy(4,17); cout << "[5] Matricula"; 
		gotoxy(4,19); cout << "[6] Salir";
		gotoxy(4,21); cout << "Ingrese opcion: ";
        cin >> opcion;
        
        if(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4 && opcion!=5 && opcion!=6){
			gotoxy(3,22); cout << "Error al ingresar valores. Presione una tecla para volver a ingresar..";
			CursorOff();
			getch();
			CursorOn(1,10);	
		}

        switch (opcion)
        {
        case 1:
          	menuAlumnos();
            break;

        case 2:
            menuProfesores();
            break;
        case 3:
            menuCursos();
            break;
        case 4:
			    
			break;
        case 5:
        	menuMatricula();
        	break;
        case 6:
            repetir = false;
            break;
        }
    } while (repetir);
}

void menuAlumnos()
{
	
    int opcion;
    bool repetir = true;
	
    do
    {
        system("cls");
        CursorOn(1,10);
        dibujarCuadro(1,1,78,24);//Cuadro grande
		dibujarCuadro(2,2,77,4);//Cuadro del titulo
		gotoxy(16,3); cout << "\t  SISTEMA DE NOTAS ACADEMICAS";

        gotoxy(4,6); cout << "MENU ALUMNOS";
		gotoxy(4,9); cout << "[1] Agregar";
		gotoxy(4,11); cout << "[2] Consultar";
		gotoxy(4,13); cout << "[3] Eliminar";
		gotoxy(4,15); cout << "[4] Listar";
		gotoxy(4,17); cout << "[5] Retornar";
		gotoxy(4,19); cout << "Ingrese opcion: ";    
        cin >> opcion;

		if(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4 && opcion!=5 ){
			gotoxy(4,22); cout << "Error al ingresar valores. Presione una tecla para volver a ingresar..";
			CursorOff();
			getch();
			gotoxy(4,22); cout << "                                                                       ";
			gotoxy(4,19); cout << "                                                                       ";
			CursorOn(1,10);	
		}

        switch (opcion)
        {
        case 1:
          	agregarAlumno(Esc);
            break;

        case 2:
            consultarAlumno(Lec);
            break;

        case 3:
            eliminarAlumno(Lec);
            break;

        case 4:
            ListarAlumno(Lec);
            break;

        case 5:
            repetir = false;
            break;
        }
    } while (repetir);
}

void agregarAlumno(fstream &esc){
	system("cls");
	int aux=0 , rep=0 , op;
	esc.open("Alumnos.txt",ios::out | ios::app);
	dibujarCuadro(1,1,78,24);//Cuadro grande
	dibujarCuadro(2,2,77,4);//Cuadro del titulo
	gotoxy(16,3); cout << "\t  SISTEMA DE NOTAS ACADEMICAS";
	gotoxy(4,6); cout << "INGRESO DE ALUMNOS";
	for (int i = 0; i < N && aux == 0; i++){		
		if (alum[i].lleno == 0){
			do{
				rep=0;
				CursorOn(1,10);
				gotoxy(4,9);  cout << "Codigo:"<<"\t\t";
				fflush(stdin);
				cin.getline(alum[i].codigo,15,'\n');
				for(int j = 0; j < i && rep==0; j++){
					if(strcmp(alum[i].codigo,alum[j].codigo) == 0){
						rep = 1;
						CursorOff();
						gotoxy(4,22); cout << "Codigo ya guardado. Presione una tecla para volver a ingresar..";
						getch();
						gotoxy(4,22); cout << "                                                                  ";
						gotoxy(4,9); cout << "                                                           ";
					}
				}
			}while(rep!=0);
			
			fflush(stdin);
			gotoxy(4,11); cout << "Nombre:";
			cin.getline(alum[i].Nom,15,'\n');
			fflush(stdin);
			gotoxy(4,13); cout << "Apellido:";
			cin.getline(alum[i].Ape,15,'\n');
			fflush(stdin);
			gotoxy(4,15); cout << "Sexo:"<<"\t\t"; 
			fflush(stdin);
			cin.getline(alum[i].sexo,10,'\n');
			fflush(stdin);
			gotoxy(4,17); cout << "Edad:"<<"\t\t";
			fflush(stdin);
			scanf("%i",&alum[i].edad);
			alum[i].lleno = 1;
		esc<<alum[i].codigo<<" "<<alum[i].Nom<<" "<<alum[i].Ape<<" "<<alum[i].sexo<<" "<<alum[i].edad<<" "<<alum[i].lleno<<"\n";
			do{
				CursorOff();
				gotoxy(4,22); cout << "Pulse una tecla: <1> Ingrese otro alumno / <2> Ir al menu Alumno ";
				op = getch();	
			}while (op!='1' && op!='2');
			
			if(op=='1'){
					CursorOn(1,10);
					gotoxy(4,9); cout << "                                                        ";
					gotoxy(4,11); cout << "                                                        ";
					gotoxy(4,13); cout << "                                                        ";
					gotoxy(4,15); cout << "                                                        ";
					gotoxy(4,17); cout << "                                                        ";
					gotoxy(4,22); cout << "                                                                          ";
				}
				
			if (op == '2'){
				aux = 1;
			}
		}
	}
	
	if (aux == 0){
		gotoxy(4,22); cout << "No quedan mas espacios. Presione una tecla para continuar..";
		getch();
		CursorOff();
	}						
	esc.close();
}

bool verifica(string cod){
	ifstream leer("Alumnos.txt", ios::in);
	for(int i=0; i<N;i++){
		if(alum[i].lleno==1){
		
	leer>>alum[i].codigo;
	while(!leer.eof()){
		leer>>alum[i].Nom;
		leer>>alum[i].Ape;
		leer>>alum[i].sexo;
		leer>>alum[i].edad;
		if(alum[i].codigo == cod){
            gotoxy(4,18);cout << "No puede ingresarse el registro,\nCodigo ya existente.";
            leer.close(); // cierra el archivo
            gotoxy(4,22);system("pause");
            return false; // Retorna un falso; i.e. No puede Ingresar el Registro Actual
		}
	}
}
	}
	leer.close();
	gotoxy(4,18);cout << "Registro Ingresado con exito";
	gotoxy(4,22);system("pause");
	return true;
	
}

void ListarAlumno(ifstream &Lec){
	limpia();
	string Nom, Nom1, Ape, Ape1, Cod, edad, sexo, lleno;
	
	Lec.open("Alumnos.txt",ios::in);
	gotoxy(4,6); cout << "LISTA DE ALUMNOS";
	gotoxy(4,8); cout << "Codigo";
	gotoxy(17,8); cout << "Apellidos y Nombres";
	gotoxy(56,8); cout << "Sexo";
	gotoxy(70,8); cout << "Edad"<<endl;
	
	Lec>>Cod;
	while(!Lec.eof()){
		Lec>>Nom;
		Lec>>Ape;
		Lec>>sexo;
		Lec>>edad;
		Lec>>lleno;
	
		cout <<" ³  "<<Cod; 
		cout <<"\t "<<Nom; 
		cout <<" "<<Ape; 
		cout <<"\t\t\t"<<sexo; 
		cout <<"\t\t"<<edad<<endl;
		Lec>>Cod;	
	}
		Lec.close();
	gotoxy(4,22);system("pause");
}

void consultarAlumno(ifstream &Lec){
	char op;
	do
	{
		limpia();
		Lec.open("Alumnos.txt", ios::in);
		char cod[N];
		bool encontrado = false;
		gotoxy(4,6); cout << "CONSULTAR ALUMNO";
		gotoxy(4,8); cout << "Ingrese codigo: ";
		fflush(stdin);
		cin.getline(cod,N,'\n');
		fflush(stdin);
		for(int i=0; i<N;i++){
		Lec>>alum[i].codigo;
		while(!Lec.eof() && !encontrado){
			Lec>>alum[i].Nom;
			Lec>>alum[i].Ape;
			Lec>>alum[i].sexo;
			Lec>>alum[i].edad;
			Lec>>alum[i].lleno;
			if(alum[i].codigo == cod){
				gotoxy(4,11); cout << "Nombres y Apellidos: " <<alum[i].Nom<<" "<<alum[i].Ape;
				gotoxy(4,13); cout << "Sexo:                " <<alum[i].sexo;
				gotoxy(4,15); cout << "Edad:                " <<alum[i].edad;
				encontrado = true;
			}
			Lec>>alum[i].codigo;
		}
	}
		Lec.close();
		if (encontrado == true){
			CursorOff();
			gotoxy(4,20); cout << "¡Alumno encontrado!";
		}
		if (encontrado == false){
			CursorOff();
			gotoxy(4,20); cout << "¡Alumno no encontrado!";
		}
		
		do{
			CursorOff();
			gotoxy(4,22); cout << "Pulse una tecla: <1> Consultar otro alumno / <2> Ir al menu Alumno ";
			op = getch();	
		}while (op!='1' && op!='2');
		
		if(op=='1'){
				CursorOn(1,10);
				gotoxy(4,9); cout << "                                                        ";
				gotoxy(4,11); cout << "                                                        ";
				gotoxy(4,13); cout << "                                                        ";
				gotoxy(4,15); cout << "                                                        ";
				gotoxy(4,17); cout << "                                                        ";
				gotoxy(4,22); cout << "                                                        ";
			}
	}while(op!='2');
}

void eliminarAlumno(ifstream &Lec){
	limpia();
	char op;
	string Nom, Nom1, Ape, Ape1, Cod, edad, sexo, Codaux;
	Lec.open("Alumnos.txt",ios::in);
	ofstream aux("auxiliar.txt",ios::out);
	if(Lec.is_open()){
		gotoxy(4,6); cout << "ELIMINAR ALUMNO";
		gotoxy(4,8); cout << "Ingrese codigo: ";
		cin>>Codaux;
		Lec>>Nom;
		while(!Lec.eof()){
			Lec>>Nom1;
			Lec>>Ape;
			Lec>>Ape1;
			Lec>>sexo;
			Lec>>edad;
			Lec>>Cod;
			if(Cod == Codaux){
				gotoxy(4,11); cout << "Apellidos y Nombres: " <<Ape<<" "<<Ape1<<" "<<Nom<<" "<<Nom1;
				gotoxy(4,13); cout << "Sexo:                " <<sexo;
				gotoxy(4,15); cout << "Edad:                " <<edad;
			do{
				CursorOff();
				gotoxy(4,22); cout << "Seguro que desea eliminar? Pulse una tecla: <1> Si / <2> No ";
				op = getch();	
			}while (op!='1' && op!='2');
			
			if (op=='1'){
				gotoxy(4,21); cout << "Eliminado correctamente.";
				gotoxy(4,22); cout << "                                                              ";
				Sleep(1500);
			}
			if (op=='2'){
				CursorOff();
				gotoxy(4,22); cout << "Codigo no eliminado. Presione una tecla para ir al menu principal..";
				aux<<Nom<<" "<<Nom1<<" "<<Ape<<" "<<Ape1<<" "<<sexo<<" "<<edad<<" "<<Cod<<"\n";
				getch();
			}
			
			}
			else{
			aux<<Nom<<" "<<Nom1<<" "<<Ape<<" "<<Ape1<<" "<<sexo<<" "<<edad<<" "<<Cod<<"\n";
			}
			Lec>>Nom;
		}
		Lec.close();
		aux.close();
	}
	else{
		cout<<"Error"<<endl;
	}
	remove("Alumnos.txt");
	rename("auxiliar.txt", "Alumnos.txt");
}

void menuProfesores()
{
	
    int opcion;
    bool repetir = true;
	
    do
    {
        system("cls");
        CursorOn(1,10);
        dibujarCuadro(1,1,78,24);//Cuadro grande
		dibujarCuadro(2,2,77,4);//Cuadro del titulo
		gotoxy(16,3); cout << "\t  SISTEMA DE NOTAS ACADEMICAS";

        gotoxy(4,6); cout << "MENU PROFESORES";
		gotoxy(4,9); cout << "[1] Agregar";
		gotoxy(4,11); cout << "[2] Consultar";
		gotoxy(4,13); cout << "[3] Eliminar";
		gotoxy(4,15); cout << "[4] Listar";
		gotoxy(4,17); cout << "[5] Retornar";
		gotoxy(4,19); cout << "Ingrese opcion: ";    
        cin >> opcion;

		if(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4 && opcion!=5 ){
			gotoxy(4,22); cout << "Error al ingresar valores. Presione una tecla para volver a ingresar..";
			CursorOff();
			getch();
			gotoxy(4,22); cout << "                                                                       ";
			gotoxy(4,19); cout << "                                                                       ";
			CursorOn(1,10);	
		}

        switch (opcion)
        {
        case 1:
          	agregarProfesor(Esc);
            break;

        case 2:
            consultarProfesor(Lec);
            break;

        case 3:
            eliminarProfesor(Lec);
            break;

        case 4:
            ListarProfesor(Lec);
            break;

        case 5:
            repetir = false;
            break;
        }
    } while (repetir);
}

void agregarProfesor(fstream &esc){
	system("cls");
	string NomP, Nom1P, ApeP, Ape1P, CodP, edadP, sexoP;
	esc.open("Profesores.txt",ios::out | ios::app);
	dibujarCuadro(1,1,78,24);//Cuadro grande
	dibujarCuadro(2,2,77,4);//Cuadro del titulo
	gotoxy(31,3); cout << "INGRESO DE PROFESORES";
	gotoxy(4,7); cout << "Codigo:"<<"\t\t";
	cin>>CodP;
	gotoxy(4,9); cout << "Nombres:"<<"\t\t";
	cin>>NomP;cin>>Nom1P;
	gotoxy(4,11); cout << "Apellidos:"<<"\t\t";
	cin>>ApeP;cin>>Ape1P;
	gotoxy(4,13); cout << "Sexo:"<<"\t\t";
	cin>>sexoP; 
	gotoxy(4,15); cout << "Edad:"<<"\t\t";
	cin>>edadP;
	if(verifica1(CodP)){
		esc<<NomP<<" "<<Nom1P<<" "<<ApeP<<" "<<Ape1P<<" "<<sexoP<<" "<<edadP<<" "<<CodP<<"\n";
	}
	esc.close();
}

bool verifica1(string codP){
	ifstream leer("Profesores.txt", ios::in);
	string NomP, Nom1P, ApeP, Ape1P, CodP, edadP, sexoP;
	leer>>NomP;
	while(!leer.eof()){
		leer>>Nom1P;
		leer>>ApeP;
		leer>>Ape1P;
		leer>>sexoP;
		leer>>edadP;
		leer>>CodP;
		if(CodP == codP){
            gotoxy(4,18);cout << "No puede ingresarse el registro,\nCodigo ya existente.";
            leer.close(); // cierra el archivo
            gotoxy(4,22);system("pause");
            return false; // Retorna un falso; i.e. No puede Ingresar el Registro Actual
		}
		leer>>NomP;
	}
	leer.close();
	gotoxy(4,18);cout << "Registro Ingresado con exito";
	gotoxy(4,22);system("pause");
	return true;
	
}

void ListarProfesor(ifstream &Lec){
	limpia();
	string NomP, Nom1P, ApeP, Ape1P, CodP, edadP, sexoP;
	
	Lec.open("Profesores.txt",ios::in);
	gotoxy(4,6); cout << "LISTA DE PROFESORES";
	gotoxy(4,8); cout << "Codigo";
	gotoxy(17,8); cout << "Apellidos y Nombres";
	gotoxy(56,8); cout << "Sexo";
	gotoxy(70,8); cout << "Edad"<<endl;
	Lec>>NomP;
	while(!Lec.eof()){
		Lec>>Nom1P;
		Lec>>ApeP;
		Lec>>Ape1P;
		Lec>>sexoP;
		Lec>>edadP;
		Lec>>CodP;
		cout <<" ³  "<<CodP; 
		cout <<"\t "<<ApeP<<" "<<Ape1P<<" "<<NomP<<" "<<Nom1P; 
		cout <<setw(4)<<"\t\t"<<sexoP; 
		cout <<"\t\t"<<edadP<<endl;
		Lec>>NomP;
	}
	Lec.close();
	gotoxy(4,22);system("pause");
}

void consultarProfesor(ifstream &Lec){
	char op;
	do
	{
		limpia();
		Lec.open("Profesores.txt", ios::in);
		string NomP, Nom1P, ApeP, Ape1P, CodP, edadP, sexoP, CodauxP;
		bool encontrado = false;
		gotoxy(4,6); cout << "CONSULTAR PROFESOR";
		gotoxy(4,8); cout << "Ingrese codigo: ";
		cin>>CodauxP;
		Lec>>NomP;
		while(!Lec.eof() && !encontrado){
			Lec>>Nom1P;
			Lec>>ApeP;
			Lec>>Ape1P;
			Lec>>sexoP;
			Lec>>edadP;
			Lec>>CodP;
			if(CodP == CodauxP){
				gotoxy(4,11); cout << "Apellidos y Nombres: " <<ApeP<<" "<<Ape1P<<" "<<NomP<<" "<<Nom1P;
				gotoxy(4,13); cout << "Sexo:                " <<sexoP;
				gotoxy(4,15); cout << "Edad:                " <<edadP;
				encontrado = true;
			}
			Lec>>NomP;
		}
		Lec.close();
		if (encontrado == true){
			CursorOff();
			gotoxy(4,20); cout << "¡Profesor encontrado!";
		}
		else if (!encontrado){
			CursorOff();
			gotoxy(4,20); cout << "Profesor no encontrado!";
		}
		
		do{
			CursorOff();
			gotoxy(4,22); cout << "Pulse una tecla: <1> Consultar otro profesor / <2> Ir al menu Profesor ";
			op = getch();	
		}while (op!='1' && op!='2');
		
		if(op=='1'){
				CursorOn(1,10);
				gotoxy(4,9); cout << "                                                        ";
				gotoxy(4,11); cout << "                                                        ";
				gotoxy(4,13); cout << "                                                        ";
				gotoxy(4,15); cout << "                                                        ";
				gotoxy(4,17); cout << "                                                        ";
				gotoxy(4,22); cout << "                                                        ";
			}
	}while(op!='2');
}

void eliminarProfesor(ifstream &Lec){
	limpia();
	char op;
	string NomP, Nom1P, ApeP, Ape1P, CodP, edadP, sexoP, CodauxP;
	Lec.open("Profesores.txt",ios::in);
	ofstream aux("auxiliar1.txt",ios::out);
	if(Lec.is_open()){
		gotoxy(4,6); cout << "ELIMINAR PROFESOR";
		gotoxy(4,8); cout << "Ingrese codigo: ";
		cin>>CodauxP;
		Lec>>NomP;
		while(!Lec.eof()){
			Lec>>Nom1P;
			Lec>>ApeP;
			Lec>>Ape1P;
			Lec>>sexoP;
			Lec>>edadP;
			Lec>>CodP;
			if(CodP == CodauxP){
				gotoxy(4,11); cout << "Apellidos y Nombres: " <<ApeP<<" "<<Ape1P<<" "<<NomP<<" "<<Nom1P;
				gotoxy(4,13); cout << "Sexo:                " <<sexoP;
				gotoxy(4,15); cout << "Edad:                " <<edadP;
			do{
				CursorOff();
				gotoxy(4,22); cout << "Seguro que desea eliminar? Pulse una tecla: <1> Si / <2> No ";
				op = getch();	
			}while (op!='1' && op!='2');
			
			if (op=='1'){
				gotoxy(4,21); cout << "Eliminado correctamente.";
				gotoxy(4,22); cout << "                                                              ";
				Sleep(1500);
			}
			if (op=='2'){
				CursorOff();
				gotoxy(4,22); cout << "Codigo no eliminado. Presione una tecla para ir al menu principal..";
				aux<<NomP<<" "<<Nom1P<<" "<<ApeP<<" "<<Ape1P<<" "<<sexoP<<" "<<edadP<<" "<<CodP<<"\n";
				getch();
			}
			
			}
			else{
			aux<<NomP<<" "<<Nom1P<<" "<<ApeP<<" "<<Ape1P<<" "<<sexoP<<" "<<edadP<<" "<<CodP<<"\n";
			}
			Lec>>NomP;
		}
		Lec.close();
		aux.close();
	}
	else{
		cout<<"Error"<<endl;
	}
	remove("Profesores.txt");
	rename("auxiliar1.txt", "Profesores.txt");
}

void menuCursos()
{
	
    int opcion;
    bool repetir = true;
	
    do
    {
        system("cls");
        CursorOn(1,10);
        dibujarCuadro(1,1,78,24);//Cuadro grande
		dibujarCuadro(2,2,77,4);//Cuadro del titulo
		gotoxy(16,3); cout << "\t  SISTEMA DE NOTAS ACADEMICAS";

        gotoxy(4,6); cout << "MENU CURSOS";
		gotoxy(4,9); cout << "[1] Agregar";
		gotoxy(4,11); cout << "[2] Consultar";
		gotoxy(4,13); cout << "[3] Eliminar";
		gotoxy(4,15); cout << "[4] Listar";
		gotoxy(4,17); cout << "[5] Retornar";
		gotoxy(4,19); cout << "Ingrese opcion: ";    
        cin >> opcion;

		if(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4 && opcion!=5 ){
			gotoxy(4,22); cout << "Error al ingresar valores. Presione una tecla para volver a ingresar..";
			CursorOff();
			getch();
			gotoxy(4,22); cout << "                                                                       ";
			gotoxy(4,19); cout << "                                                                       ";
			CursorOn(1,10);	
		}

        switch (opcion)
        {
        case 1:
          	agregarCurso(Esc);
            break;

        case 2:
            consultarCurso(Lec);
            break;

        case 3:
            eliminarCurso(Lec);
            break;

        case 4:
            ListarCurso(Lec);
            break;

        case 5:
            repetir = false;
            break;
        }
    } while (repetir);
}

void agregarCurso(fstream &esc){
	system("cls");
	string NomC, CodC;
	esc.open("Cursos.txt",ios::out | ios::app);
	dibujarCuadro(1,1,78,24);//Cuadro grande
	dibujarCuadro(2,2,77,4);//Cuadro del titulo
	gotoxy(31,3); cout << "INGRESO DE CURSOS";
	gotoxy(4,9); cout << "Codigo:"<<"\t\t";
	cin>>CodC;
	gotoxy(4,11); cout << "Nombre :"<<"\t\t";
	cin>>NomC;

	if(verifica2(CodC)){
		esc<<NomC<<" "<<CodC<<"\n";
	}
	esc.close();
}

bool verifica2(string codC){
	ifstream leer("Cursos.txt", ios::in);
	string NomC, CodC;
	leer>>NomC;
	while(!leer.eof()){
		leer>>CodC;
		if(CodC == codC){
            gotoxy(4,18);cout << "No puede ingresarse el registro,\nCodigo ya existente.";
            leer.close(); // cierra el archivo
            gotoxy(4,22);system("pause");
            return false; // Retorna un falso; i.e. No puede Ingresar el Registro Actual
		}
		leer>>NomC;
	}
	leer.close();
	gotoxy(4,18);cout << "Registro Ingresado con exito";
	gotoxy(4,22);system("pause");
	return true;
	
}

void ListarCurso(ifstream &Lec){
	limpia();
	string NomC, CodC;
	
	Lec.open("Cursos.txt",ios::in);
	gotoxy(4,6); cout << "LISTA DE ALUMNOS";
	gotoxy(4,8); cout << "Codigo";
	gotoxy(17,8); cout << "Nombre del Curso"<<endl;

	Lec>>NomC;
	while(!Lec.eof()){
		Lec>>CodC;
		cout <<" ³  "<<CodC; 
		cout <<"\t "<<NomC<<endl; 
		Lec>>NomC;
	}
	Lec.close();
	gotoxy(4,22);system("pause");
}

void consultarCurso(ifstream &Lec){
	char op;
	do
	{
		limpia();
		Lec.open("Cursos.txt", ios::in);
		string NomC, CodC, CodauxC;
		bool encontrado = false;
		gotoxy(4,6); cout << "CONSULTAR CURSO";
		gotoxy(4,8); cout << "Ingrese codigo: ";
		cin>>CodauxC;
		Lec>>NomC;
		while(!Lec.eof() && !encontrado){
			Lec>>CodC;
			if(CodC == CodauxC){
				gotoxy(4,11); cout << "Nombre del Curso: " <<NomC;
				encontrado = true;
			}
			Lec>>NomC;
		}
		Lec.close();
		if (encontrado == true){
			CursorOff();
			gotoxy(4,20); cout << "¡Curso encontrado!";
		}
		else if (!encontrado){
			CursorOff();
			gotoxy(4,20); cout << "¡Curso no encontrado!";
		}
		
		do{
			CursorOff();
			gotoxy(4,22); cout << "Pulse una tecla: <1> Consultar otro curso / <2> Ir al menu Curso ";
			op = getch();	
		}while (op!='1' && op!='2');
		
		if(op=='1'){
				CursorOn(1,10);
				gotoxy(4,9); cout << "                                                        ";
				gotoxy(4,11); cout << "                                                        ";
				gotoxy(4,13); cout << "                                                        ";
				gotoxy(4,15); cout << "                                                        ";
				gotoxy(4,17); cout << "                                                        ";
				gotoxy(4,22); cout << "                                                        ";
			}
	}while(op!='2');
}

void eliminarCurso(ifstream &Lec){
	limpia();
	char op;
	string NomC, CodC, CodauxC;
	Lec.open("Cursos.txt",ios::in);
	ofstream aux("auxiliar2.txt",ios::out);
	if(Lec.is_open()){
		gotoxy(4,6); cout << "ELIMINAR CURSO";
		gotoxy(4,8); cout << "Ingrese codigo: ";
		cin>>CodauxC;
		Lec>>NomC;
		while(!Lec.eof()){
			Lec>>CodC;
			if(CodC == CodauxC){
				gotoxy(4,11); cout << "Nombre del Curso: " <<NomC;
			do{
				CursorOff();
				gotoxy(4,22); cout << "Seguro que desea eliminar? Pulse una tecla: <1> Si / <2> No ";
				op = getch();	
			}while (op!='1' && op!='2');
			
			if (op=='1'){
				gotoxy(4,21); cout << "Eliminado correctamente.";
				gotoxy(4,22); cout << "                                                              ";
				Sleep(1500);
			}
			if (op=='2'){
				CursorOff();
				gotoxy(4,22); cout << "Codigo no eliminado. Presione una tecla para ir al menu principal..";
				aux<<NomC<<" "<<CodC<<"\n";
				getch();
			}
			
			}
			else{
			aux<<NomC<<" "<<CodC<<"\n";
			}
			Lec>>NomC;
		}
		Lec.close();
		aux.close();
	}
	else{
		cout<<"Error"<<endl;
	}
	remove("Cursos.txt");
	rename("auxiliar2.txt", "Cursos.txt");
}

void menuMatricula(){
	int opcion;
    bool repetir = true;
	
    do
    {
        system("cls");
        CursorOn(1,10);
        dibujarCuadro(1,1,78,24);//Cuadro grande
		dibujarCuadro(2,2,77,4);//Cuadro del titulo
		gotoxy(16,3); cout << "\t  SISTEMA DE NOTAS ACADEMICAS";

        gotoxy(4,6); cout << "MENU MATRICULA";
		gotoxy(4,9); cout << "[1] Registro";
		gotoxy(4,11); cout << "[2] Matricula Alumno";
		gotoxy(4,13); cout << "[3] Retornar";
		gotoxy(4,15); cout << "Ingrese opcion: ";    
        cin >> opcion;

		if(opcion!=1 && opcion!=2 && opcion!=3){
			gotoxy(4,22); cout << "Error al ingresar valores. Presione una tecla para volver a ingresar..";
			CursorOff();
			getch();
			gotoxy(4,22); cout << "                                                                       ";
			gotoxy(4,15); cout << "                                                                       ";
			CursorOn(1,10);	
		}

        switch (opcion)
        {
        case 1:
          	Registro(Esc);
            break;
        case 2:
        	MatriculaAlumno(Lec);
        case 3:
            repetir = false;
            break;
        }
    } while (repetir);
}

void Registro(fstream &esc){
	char op;
	bool encontrado = false;
	do
	{
		limpia();
		string NumR, hora, sec, cred;
		string NomC, CodC, CodauxC;
		string NomP, Nom1P, ApeP, Ape1P, CodP, edadP, sexoP, CodauxP;
		esc.open("Registro.txt",ios::out | ios::app);
		ifstream Curso("Cursos.txt",ios::in);
		ifstream Profe("Profesores.txt",ios::in);
		gotoxy(4,6); cout << "REGISTRO";
		gotoxy(4,8);  cout << "Numero de registro: \t";
		cin>>NumR;
		encontrado = false;
		do{
			gotoxy(4,10); cout<<"Codigo de curso: ";
			cin>>CodauxC;
			while(!Curso.eof() && !encontrado){
				Curso>>NomC;
				Curso>>CodC;
				if(CodC == CodauxC){
					encontrado = true;
				}
			}
			Curso.close();
			if (encontrado == true){
				CursorOff();
				gotoxy(4,11); cout << "¡Curso encontrado!";;
			}
			else if (!encontrado){
				CursorOff();
				gotoxy(4,11); cout << "Curso no encontrado,vuelva a ingresar el codigo...";
				getch();
				gotoxy(4,10); cout << "                                                        ";
				gotoxy(4,11); cout << "                                                        ";
			}
		}while(!encontrado);
		
		encontrado = false;
		do{
			gotoxy(4,13); cout<<"Codigo de profesor: ";
			cin>>CodauxP;
			while(!Curso.eof() && !encontrado){
				Profe>>NomP;
				Profe>>Nom1P;
				Profe>>ApeP;
				Profe>>Ape1P;
				Profe>>sexoP;
				Profe>>edadP;
				Profe>>CodP;
				if(CodP == CodauxP){
					encontrado = true;
				}
				Profe>>NomP;
			}
			Profe.close();
			if (encontrado == true){
				CursorOff();
				gotoxy(4,14); cout << "¡Profesor encontrado!";
			}
			else if (!encontrado){
				CursorOff();
				gotoxy(4,14); cout << "Profesor no encontrado,vuelva a ingresar el codigo...";
			    getch();
			    gotoxy(4,13); cout << "                                                        ";
			    gotoxy(4,14); cout << "                                                        ";
			}
		}while(!encontrado);
		
		gotoxy(4,16); cout << "Horario:"<<"\t";
		cin>>hora;	
		gotoxy(4,18); cout << "Seccion:"<<"\t";
		cin>>sec;
		gotoxy(4,20); cout << "Creditos:"<<"\t";
		cin>>cred;
		
		if(verifica3(NumR)){
		esc<<NumR<<" "<<CodC<<" "<<NomC<<" "<<CodP<<" "<<ApeP<<" "<<NomP<<" "<<hora<<" "<<sec<<" "<<cred<<"\n";
		}
		esc.close();
		
		encontrado = true;	
		do{
			CursorOff();
			gotoxy(4,22); cout << "Pulse una tecla: <1> Registrar otro curso / <2> Volver al menú de registro ";
			op = getch();	
		}while (op!='1' && op!='2');
		
		if(op=='1'){
				CursorOn(1,10);
				gotoxy(4,9); cout << "                                                        ";
				gotoxy(4,11); cout << "                                                        ";
				gotoxy(4,13); cout << "                                                        ";
				gotoxy(4,15); cout << "                                                        ";
				gotoxy(4,17); cout << "                                                        ";
				gotoxy(4,22); cout << "                                                        ";
			}
	}while(op!='2');
}
	
bool verifica3(string numR){
	ifstream leer("Registro.txt", ios::in);
	string NumR, CodC, NomC, CodP, ApeP, NomP, hora, sec, cred;
	leer>>NumR;
	while(!leer.eof()){
		leer>>CodC;
		leer>>NomC;
		leer>>CodP;
		leer>>ApeP;
		leer>>NomP;
		leer>>hora;
		leer>>sec;
		leer>>cred;
		if(NumR == numR){
            gotoxy(4,18);cout << "No puede ingresarse el registro,\nCodigo ya existente.";
            leer.close(); // cierra el archivo
            gotoxy(4,22);system("pause");
            return false; // Retorna un falso; i.e. No puede Ingresar el Registro Actual
		}
		leer>>NomP;
	}
	leer.close();
	gotoxy(4,18);cout << "Registro Ingresado con exito";
	gotoxy(4,22);system("pause");
	return true;
}	
		
void MatriculaAlumno(ifstream &Lec){
	
}



void dibujarCuadro(int x1,int y1,int x2,int y2){
    int i;
    // Dibuja las lineas horizontales
    for (i=x1;i<x2;i++){
		gotoxy(i,y1); cout << "Ä";
		gotoxy(i,y2); cout << "Ä";
    }
    
	// Dibuja las lineas verticales
    for (i=y1;i<y2;i++){
		gotoxy(x1,i); cout << "³";
		gotoxy(x2,i); cout << "³";
    }
    
    gotoxy(x1,y1); cout << "Ú";
    gotoxy(x1,y2); cout << "À";
    gotoxy(x2,y1); cout << "¿";
    gotoxy(x2,y2); cout << "Ù";
}

void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }
 
 void CursorOff(){
  CONSOLE_CURSOR_INFO cursor = {1, FALSE};
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

void limpia(){
	int i,j;
	for(i=5;i<=23;i++){
		for(j=3;j<=76;j++){
			gotoxy(j,i); printf(" ");
		}
	}
}

void CursorOn(bool visible, DWORD size) 
{
	if(size == 0)
	{
		size = 20;
	}
	CONSOLE_CURSOR_INFO lpCursor;	
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console,&lpCursor);
}
