#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void Alta();
void Modificar();
void Lista();
void Eliminar();
void Archivo();
void Leer();
void Guardar();

struct Citas {
	int cant_tratamiento = 0, tratamiento = 0, num_de_cita = 0;
	string nombre, fecha, hora;

	Citas* ant = nullptr;
	Citas* sig = nullptr;
};

Citas* primer_cita = nullptr;
Citas* ultima_cita = nullptr;
Citas* aux = nullptr;

string nombre, fecha, hora;
int opc = 0, costunit = 0, cant_tratamiento = 0, tratamiento = 0, num_de_cita_actual = 1, modificar = 0, eliminar = 0;
bool opcvalida = true;

int main()
{
	Leer();

	cout << "Servicios Dentales." << endl;
	cout << "Escoja la opcion que desea ingresar." << endl;
	cout << "1 Agendar cita." << endl;
	cout << "2 Imprimir citas." << endl;
	cout << "3 Modificar cita." << endl;
	cout << "4 Eliminar cita." << endl;
	cout << "5 Limpiar pantalla." << endl;
	cout << "6 Salir del programa." << endl;
	cout << "Marque un digito de la siguiente lista: ";
	cin >> opc;

	switch (opc)
	{
	case 1:
		Alta();
		return main();
		break;

	case 2:
		Lista();
		return main();
		break;

	case 3:
		Modificar();
		return main();
		break;

	case 4:
		Eliminar();
		return main();
		break;

	case 5:
		system("CLS");
		return main();
		break;

	case 6:
		Guardar();
		Archivo();
		break;

	default:
		cout << "Ingrese una opcion valida." << endl;
		return main();
		break;
	}
}

void Alta() {
	system("CLS");

	cout << "Su cita tiene el numero: " << num_de_cita_actual << endl;
	cout << "Ingrese el nombre del paciente: ";
	cin.ignore();
	getline(cin, nombre);

	cout << "Ingrese la fecha: ";
	cin >> fecha;

	cout << "Ingrese la hora de la cita: ";
	cin >> hora;

	cout << "\nBasado en sus sintomas, Escoja que tratamiento usted desea recibir: " << endl << endl;
	cout << "Tratamiento #1" << endl;
	cout << "Blanqueamiento Dental" << endl;
	cout << "Descripcion: Consiste en quitar todas las manchas dentales que pueden tener los dientes." << endl;
	cout << "Precio unitario: 100 pesos." << endl << endl;

	cout << "Tratamiento #2" << endl;
	cout << "Carillas Bucales" << endl;
	cout << "Descripcion: Las carillas bucales son un tipo de tratamiento dental que tiene un fin estetico y natural." << endl;
	cout << "Precio unitario: 150 pesos." << endl << endl;

	cout << "Tratamiento #3" << endl;
	cout << "Extraccion de muelas" << endl;
	cout << "Descripcion: Este es uno de los tratamientos mas utilizados, ya que conforme pasa el tiempo, se necesita extraer algunas piezas bucales." << endl;
	cout << "Precio unitario: 200 pesos." << endl << endl;

	while (opcvalida) {
		cout << "Elija un tratamiento: ";
		cin >> opc;

		switch (opc) {
		case 1:
			costunit = 100;
			tratamiento = 1;
			opcvalida = false;
			break;
		case 2:
			costunit = 150;
			tratamiento = 2;
			opcvalida = false;
			break;
		case 3:
			costunit = 200;
			tratamiento = 3;
			opcvalida = false;
			break;

		default: cout << "\nMarque una opcion valida.";

		}

		cout << "\nIngrese cantidad de tratamiento que desea: ";
		cin >> cant_tratamiento;

		cout << "Total: " << costunit * cant_tratamiento << " pesos." << endl;
		system("pause");

		Citas* nueva_cita = new Citas;

		nueva_cita->num_de_cita = num_de_cita_actual;
		nueva_cita->nombre = nombre;
		nueva_cita->fecha = fecha;
		nueva_cita->hora = hora;
		nueva_cita->tratamiento = tratamiento;
		nueva_cita->cant_tratamiento = cant_tratamiento;

		if (num_de_cita_actual == 1) {
			primer_cita = nueva_cita;
			ultima_cita = nueva_cita;
		}
		else {
			nueva_cita->ant = ultima_cita;
			ultima_cita->sig = nueva_cita;
			ultima_cita = nueva_cita;
		}

		num_de_cita_actual++;

		system("CLS");

	}
	opcvalida = true;
}

void Lista() {

	system("CLS");

	aux = primer_cita;

	if (!aux) {
		cout << "No hay citas registradas.";
	}
	else {
		while (aux) {
			cout << "Numero de cita: " << aux->num_de_cita << endl;
			cout << "Nombre del paciente: " << aux->nombre << endl;
			cout << "Fecha de la cita: " << aux->fecha << endl;
			cout << "Hora de la cita: " << aux->hora << endl;
			cout << "Tratamiento: ";

			switch (aux->tratamiento) {
			case 1:
				costunit = 100;
				cout << "Blanqueamiento Dental." << endl;
				cout << "Descripcion: Consiste en quitar todas las manchas dentales que pueden tener los dientes.";
				break;
			case 2:
				costunit = 150;
				cout << "Carillas Bucales." << endl;
				cout << "Descripcion: Las carillas bucales son un tipo de tratamiento dental que tiene un fin estetico y natural.";
				break;
			case 3:
				costunit = 200;
				cout << "Extraccion de Muelas." << endl;
				cout << "Descripcion: Este es uno de los tratamientos más utilizados, ya que conforme pasa el tiempo, se necesita ectaer algunas piezas bucales.";
				break;

			}

			cout << endl;
			cout << "Precio unitario del tratamiento: " << costunit << " pesos." << endl;
			cout << "Cantidad del tratamiento elegido: " << aux->cant_tratamiento << "." << endl;

			cout << "Total: " << costunit * aux->cant_tratamiento << " pesos." << endl << endl;

			aux = aux->sig;
		}

	}

	cout << endl;
	system("pause");
}

void Modificar() {
	system("CLS");

	Citas* mod = nullptr;

	aux = primer_cita;

	if (!aux) {
		cout << "No hay citas registradas." << endl;
		system("pause");
	}
	else {

		cout << "Lista de citas: " << endl << endl;
		while (aux) {
			cout << aux->num_de_cita << endl;
			cout << "Nombre del paciente: " << aux->nombre << endl;
			cout << "Fecha de la cita: " << aux->fecha << endl;
			cout << "Hora de la cita: " << aux->hora << endl << endl;
			aux = aux->sig;
		}

		cout << "Marque el numero de cita que va a modificar (Marque '0' si desea volver): ";
		cin >> modificar;

		if (modificar != 0) {

			aux = primer_cita;

			while (aux) {

				if (aux-> num_de_cita == modificar) {
					mod = aux;
				}

				aux = aux->sig;
			}

			cout << endl;
			cout << "Elija la información a modificar: " << endl << endl;
			cout << "1 Nombre del paciente." << endl;
			cout << "2 Fecha de la cita." << endl;
			cout << "3 Hora de la cita." << endl;
			cout << "4 Tratamiento elegido." << endl;
			cout << "5 Cantidad del tratamiento elegido." << endl << endl;

				cout << "Marque una opcion: ";
				cin >> opc;

				switch (opc) {

				case 1: 
					cout << endl << endl;
					cout << "Introduzca el nombre del paciente: ";
					cin.ignore();
					getline(cin, mod->nombre);
					break;

				case 2: 
					cout << endl << endl;
					cout << "Ingrese la fecha de la cita (ej. 03/04/22): ";
					cin >> mod->fecha;
					break;
				

				case 3: 
					cout << endl << endl;
					cout << "Ingrese la hora de la cita (ej. 13:30): ";
					cin >> mod->hora;
					break;
				

				case 4: 
					cout << endl << endl;
					cout << "Tratamiento #1" << endl;
					cout << "Blanqueamiento Dental" << endl;
					cout << "Descripcion: Consiste en quitar todas las manchas dentales que pueden tener los dientes." << endl;
					cout << "Precio unitario: 100 pesos." << endl << endl;

					cout << "Tratamiento #2" << endl;
					cout << "Carillas Bucales" << endl;
					cout << "Descripcion: Las carillas bucales son un tipo de tratamiento dental que tiene un fin estetico y natural." << endl;
					cout << "Precio unitario: 150 pesos." << endl << endl;

					cout << "Tratamiento #3" << endl;
					cout << "Extraccion de muelas" << endl;
					cout << "Descripcion: Este es uno de los tratamientos mas utilizados, ya que conforme pasa el tiempo, se necesita extraer algunas piezas bucales." << endl;
					cout << "Precio unitario: 200 pesos." << endl << endl;

				
					while (opcvalida) {
						cout << "Marque un tratamiento: ";
						cin >> tratamiento;

						switch (tratamiento) {
						case 1: 
							opcvalida = false;
							mod->tratamiento = 1;
							break;
						

						case 2: 
							opcvalida = false;
							mod->tratamiento = 2;
							break;
						

						case 3: 
							opcvalida = false;
							mod->tratamiento = 3;
							break;

						default: cout << "\nDigite una opción válida.";

						}
					}
					break;
				

				case 5: {
					cout << endl << endl;
					cout << "Ingrese cantidad del tratamiento: ";
					cin >> mod->cant_tratamiento;
					break;
				}

				default:
					cout << "\nIngrese un dígito válido.";
					system("pause");
				}
		}
		opcvalida = true;
	}

	system("CLS");
}

void Eliminar()
{
	system("CLS");

	Citas* elim = nullptr;

	aux = primer_cita;

	if (!aux) {
		cout << "No hay citas registradas.";
	}
	else {

		cout << "Lista de citas: " << endl << endl;
		while (aux) {
			cout << aux->num_de_cita << endl;
			cout << "Nombre del paciente: " << aux->nombre << endl;
			cout << "Fecha de la cita: " << aux->fecha << endl;
			cout << "Hora de la cita: " << aux->fecha << endl << endl;
			aux = aux->sig;
		}

		cout << "Marque el numero de cita que va a eliminar (Marque '0' si desea volver): ";
		cin >> eliminar;

		if (eliminar != 0) {

			//Buscamos la cita que vamos a borrar
			aux = primer_cita;

			while (aux) {

				if (aux->num_de_cita == eliminar)
				{
					elim = aux;
				}

				aux = aux->sig;
			}

			// Empezamos a borrar

			//En el caso de que sea la unica
			if (elim == primer_cita && elim == ultima_cita) {
				aux = primer_cita;

				while (aux) {

					if (elim->num_de_cita == aux->num_de_cita) {
						aux = nullptr;
						primer_cita = nullptr;
					}

					while (aux) {
						aux = aux->sig;
					}
				}

			}

			//En el caso de que sea la primera y NO sea la unica:
			if (elim == primer_cita) {

				if (elim->sig) {
					primer_cita = elim->sig;
				}

			}
			//En el caso de que sea la ultima y NO sea la unica
			else if (elim == ultima_cita) {

				if (elim->ant) {
					ultima_cita = elim->ant;
					elim->ant->sig = NULL;
				}

			}
			//En el caso de que no sea la primera o la ultima
			else {
				elim->ant->sig = elim->sig;
				elim->sig->ant = elim->ant;
			}

			delete elim;
			system("CLS");

		}

	}
}

void Archivo()
{
	ofstream guardar_citas;
	guardar_citas.open("Info.txt");

	aux = primer_cita;

	if (guardar_citas.is_open()) {

		if (!aux) {
			guardar_citas << "No hay citas.";
		}
		else {
			while (aux) {
				guardar_citas << aux->nombre<< endl;
				guardar_citas << aux->fecha << endl;
				guardar_citas << aux->hora << endl;
				guardar_citas << aux->tratamiento<< endl;
				guardar_citas << aux->cant_tratamiento << endl;
				aux = aux->sig;
			}
		}
		guardar_citas.close();
	}
	else {
		cout << "ERROR AL CREAR EL ARCHIVO.";
	}
}

void Leer() {

	ifstream leer;
	leer.open("Info.txt");

	if (leer.is_open()) {

		int cont = 1;
		string linea;

		while (getline(leer, linea)) {
			if (cont == 1) {
				nombre = linea;
				cont = cont + 1;
			}
			else if (cont == 2) {
				fecha = linea;
				cont = cont + 1;
			}
			else if (cont == 3) {
				hora = linea;
				cont = cont + 1;
			}
			else if (cont == 4) {
				tratamiento = stoi(linea);
				cont = cont + 1;
			}
			else if (cont == 5) {
				cant_tratamiento = stoi(linea);
				
				Citas* nueva_cita = new Citas;

				nueva_cita->num_de_cita = num_de_cita_actual;
				nueva_cita->nombre = nombre;
				nueva_cita->fecha = fecha;
				nueva_cita->hora = hora;
				nueva_cita->tratamiento = tratamiento;
				nueva_cita->cant_tratamiento = cant_tratamiento;

				if (num_de_cita_actual == 1) {
					primer_cita = nueva_cita;
					ultima_cita = nueva_cita;
				}
				else {
					nueva_cita->ant = ultima_cita;
					ultima_cita->sig = nueva_cita;
					ultima_cita = nueva_cita;
				}

				num_de_cita_actual++;

				cont = 1;
			}
		}

		leer.close();
	}
	else {
		cout << "ERROR AL LEER ARCHIVO.";
	}

}

void Guardar() {

	ofstream guardar;
	guardar.open("Citas.txt");

	aux = primer_cita;

	if (guardar.is_open()) 
	{

		if (!aux) {
			guardar << "No hay citas registradas." << endl;
		}
		else {
			while (aux) {
				guardar << "Numero de cita: " << aux->num_de_cita << endl;
				guardar << "Nombre del paciente: " << aux->nombre << endl;
				guardar << "Fecha de la cita: " << aux->fecha << endl;
				guardar << "Hora de la cita: " << aux->hora << endl;
				guardar << "Tratamiento elegido: ";

				switch (aux->tratamiento) {
				case 1: 
					guardar << "Blanqueamiento Dental." << endl;
					guardar << "Descripción: Consiste en quitar todas las manchas dentales que pueden tener los dientes.";
					costunit = 100;
					break;
				
				case 2: 
					guardar << "Carillas Bucales." << endl;
					guardar << "Descripcion: Las carillas bucales son un tipo de tratamiento dental que tiene un fin estético y natural.";
					costunit = 150;
					break;
				
				case 3: 
					cout << "Extraccion de Muelas." << endl;
					cout << "Descripcion: Este es uno de los tratamientos mas utilizados, ya que conforme pasa el tiempo, se necesita extraer algunas piezas bucales.";
					costunit = 200;
					break;
				
					  guardar << "\nPrecio unitario del tratamiento: " << costunit << " pesos." << endl;
					  guardar << "Cantidad del tratamiento elegido: " << aux->tratamiento<< "." << endl;

					  guardar << "Total: " << costunit * aux->cant_tratamiento << " pesos." << endl << endl;

				}

				aux = aux->sig;
			}
		}

		guardar.close();
	}
}