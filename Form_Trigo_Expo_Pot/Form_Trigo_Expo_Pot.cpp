// Form_Trigo_Expo_Pot.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <math.h>
#include <iostream>
#include <complex>
#include <cmath>
#include <iomanip>
#include "Form_Trigo_Expo_Pot.h"


using namespace std;

const double pi = 2 * acos(0.0); //calcula la constante pi

void formTrig()
{
	double real, img, r, ang;
	
	cout << "Ingrese la parte real de la ecuacion" << endl;
	cin >> real;
	cout << "Ingrese la parte imaginaria de la ecuacion" << endl;
	cin >> img;

	r = sqrt((real * real) + (img * img)); //calcula la raíz cuadrada

	ang = atan(img / real) * (180 / pi); //calcula el angúlo y lo convierte en grados
										 //las funciones sin(), cos(), etc devuelven en radianes por eso se debe convertir a grados 
	
	//CALCULA EL ANGULO REAL POR SECTOR EN LA GRÁFICA X Y

	if (real > 0 && img > 0)//si pasa esta condición quiere decir que el punto está en el sector I
	{
		//std::fixed obtiene la parte decimal del número y std::setprecision indica cuantos de esos número decimales van a mostrar
		cout << "--------------------------------------------------------" << endl;
		cout << "Z = "<< fixed << setprecision(1) << r << "(cos(" << fixed << setprecision(2) << ang << ") + " << "isen(" << fixed << setprecision(2) << ang << "))" << endl;
		cout << "--------------------------------------------------------" << endl;
	}

	if (real < 0 && img > 0)//si pasa esta condición quiere decir que el punto está en el sector II
	{
		ang = 180 - abs(ang);//la función abs() devuelve el valor absoluto del paramaetro pasado

		//std::fixed obtiene la parte decimal del número y std::setprecision indica cuantos de esos número decimales van a mostrar
		cout << "--------------------------------------------------------" << endl;
		cout << "Z = "<< fixed << setprecision(1) << r << "(cos(" << fixed << setprecision(2) << ang << ") + " << "isen(" << fixed << setprecision(2) << ang << "))" << endl;;
		cout << "--------------------------------------------------------" << endl;
	}

	if (real < 0 && img < 0)//si pasa esta condición quiere decir que el punto está en el sector III
	{
		ang = 180 + abs(ang);//la función abs() devuelve el valor absoluto del paramaetro pasado

		//std::fixed obtiene la parte decimal del número y std::setprecision indica cuantos de esos número decimales van a mostrar
		cout << "--------------------------------------------------------" << endl;
		cout << "Z = "<< fixed << setprecision(1) << r << "(cos("<< fixed << setprecision(2) << ang << ") + " << "isen("<< fixed << setprecision(2) << ang << "))" << endl;
		cout << "--------------------------------------------------------" << endl;
	}

	if (real > 0 && img < 0)//si pasa esta condición quiere decir que el punto está en el sector IV
	{
		ang = 360 - abs(ang);//la función abs() devuelve el valor absoluto del paramaetro pasado

		//std::fixed obtiene la parte decimal del número y std::setprecision indica cuantos de esos número decimales van a mostrar
		cout << "--------------------------------------------------------" << endl;
		cout << "Z = " << fixed << setprecision(1) << r << "(cos(" << fixed << setprecision(2) << ang << ") + " << "isen(" << fixed << setprecision(2) << ang << "))" << endl;
		cout << "--------------------------------------------------------" << endl;
	}
}

void formPot()
{
	double op, op2, pot, real, img, r, ang, cosR, senR;

	cout << "Ingrese potencia" << endl;
	cin >> pot;
	cout << "Ingrese la parte real de la ecuacion" << endl;
	cin >> real;
	cout << "Ingrese la parte imaginaria de la ecuacion" << endl;
	cin >> img;

	r = pow(sqrt((real * real) + (img * img)), pot); //calcula la raiz cuadrada y la eleva a la potencia indicada

	ang = atan(img / real); //calcula el angulo, no hay necesidad de convertirlo a grados debido que las funciones cos() y sen()
							//son más precisas si reciben el número en radianes. Toda función trigonometrica en c++ devulve un número en radianes

	//CALCULA EL ANGULO REAL POR SECTOR EN LA GRÁFICA X Y

	if (real > 0 && img > 0)//si pasa esta condición quiere decir que el punto está en el sector I
	{
		cosR = cos((pot * ang)); //calcula el coseno, devuleve un número en radian

		senR = round(sin((pot * ang)));//calcula el seno, devuelve un número en radian, en este caso es necesario redondear para que de un valor correcto.

		if (senR == 0)//si el seno de la función es igual a cero entonces el resultado de la ecuación va a ser un número real debido a que el seno se multiplica por i
		{
			cout << "--------------------------------------------------------" << endl;
			cout << "Z^" << pot << " = " << r * cosR  << endl;
			cout << "--------------------------------------------------------" << endl;
		}
		else
		{
			//si el seno es mayor a 0 imprime lo de abajo, esto es debido a que si el seno es un valor diferente a cero
			//entonces la parte imaginaria va a ser un número, dicho número no puede ser operado con la parte real
			//por lo tanto la ecuación queda con dos partes; la real y la imaginaria, sin embargo, si el valor de seno es
			//positivo cuando se imprima no se podrá ver el símbolo "+", así que se imprime el símbolo
			//quedando entonces la ecuación de la forma Z = r^n * cos(n * ang) + r^n * sin(n * ang)
			//de no ser así entonces se imprime de la segunda manera donde el signo "-" si es mostrado en la consola
			if (senR > 0)
			{
				cout << "--------------------------------------------------------" << endl;
				cout << "Z^" << pot << " = " << r * cosR << " + " << r * senR << "i" << endl;
				cout << "--------------------------------------------------------" << endl;
			}
			else
			{
				cout << "--------------------------------------------------------" << endl;
				cout << "Z^" << pot << " = " << r * cosR << "" << r * senR << "i" << endl;
				cout << "--------------------------------------------------------" << endl;
			}
		}
	}

	if (real < 0 && img > 0)
	{
		ang = (180 * (pi / 180)) - abs(ang); //calcula el angulo real, el número 180 se convierte a radianes para que sea compatible con el angulo

		cosR = cos((pot * ang));//calcula el coseno, devuleve un número en radian

		senR = round(sin((pot * ang)));//calcula el seno, devuelve un número en radian, en este caso es necesario redondear para que de un valor correcto.

		if (senR == 0)//si el seno de la función es igual a cero entonces el resultado de la ecuación va a ser un número real debido a que el seno se multiplica por i
		{
			cout << "--------------------------------------------------------" << endl;
			cout << "Z^" << pot << " = " << r * cosR << endl;
			cout << "--------------------------------------------------------" << endl;
		}
		else
		{
			//si el seno es mayor a 0 imprime lo de abajo, esto es debido a que si el seno es un valor diferente a cero
			//entonces la parte imaginaria va a ser un número, dicho número no puede ser operado con la parte real
			//por lo tanto la ecuación queda con dos partes; la real y la imaginaria, sin embargo, si el valor de seno es
			//positivo cuando se imprima no se podrá ver el símbolo "+", así que se imprime el símbolo
			//quedando entonces la ecuación de la forma Z = r^n * cos(n * ang) + r^n * sin(n * ang)
			//de no ser así entonces se imprime de la segunda manera donde el signo "-" si es mostrado en la consola
			if (senR > 0)
			{
				cout << "--------------------------------------------------------" << endl;
				cout << "Z^" << pot << " = " << r * cosR << " + " << r * senR << "i"<<  endl;
				cout << "--------------------------------------------------------" << endl;
			}
			else
			{
				cout << "--------------------------------------------------------" << endl;
				cout << "Z^" << pot << " = " << r * cosR << "" << r * senR << "i" << endl;
				cout << "--------------------------------------------------------" << endl;
			}
		}
	}

	if (real < 0 && img < 0)
	{
		ang = (180 * (pi / 180)) + abs(ang);//lo mismo de la anterior

		cosR = cos((pot * ang));//lo mismo

		senR = round(sin((pot * ang)));//lo mismo

		if (senR == 0)//lo mismo
		{
			cout << "--------------------------------------------------------" << endl;
			cout << "Z^" << pot << " = " << r * cosR << endl;
			cout << "--------------------------------------------------------" << endl;
		}
		else
		{
			if (senR > 0)
			{
				cout << "--------------------------------------------------------" << endl;
				cout << "Z^" << pot << " = " << r * cosR << " + " << r * senR << "i" << endl;
				cout << "--------------------------------------------------------" << endl;
			}
			else
			{
				cout << "--------------------------------------------------------" << endl;
				cout << "Z^" << pot << " = " << r * cosR << "" << r * senR << "i" << endl;
				cout << "--------------------------------------------------------" << endl;
			}
		}
	}

	if (real > 0 && img < 0)
	{
		ang = (360 * (pi/180)) - abs(ang);

		cosR = cos((pot * ang));

		senR = round(sin((pot * ang)));

		if (senR == 0)
		{
			cout << "--------------------------------------------------------" << endl;
			cout << "Z^" << pot << " = " << r * cosR << endl;
			cout << "--------------------------------------------------------" << endl;
		}
		else
		{
			if (senR > 0)
			{
				cout << "--------------------------------------------------------" << endl;
				cout << "Z^" << pot << " = " << r * cosR << " + " << r * senR << "i" << endl;
				cout << "--------------------------------------------------------" << endl;
			}
			else
			{
				cout << "--------------------------------------------------------" << endl;
				cout << "Z^" << pot << " = " << r * cosR << "" << r * senR << "i" << endl;
				cout << "--------------------------------------------------------" << endl;
			}
		}
	}
}

void dSueltos(double vR, double vM) 
{

	double eAbsoluto, eRelativo;

	eAbsoluto = abs(vR - vM);
	eRelativo = eAbsoluto / vR * 100;
	cout << "El error absoluto es = " << eAbsoluto << endl;
	cout << "El error relativo es = " << setprecision(3) << eRelativo << "%" << endl;
}

void dAgrupados(int can) 
{

	double FA = 0, suma = 0, media = 0, sumMediMenMedida = 0;
	double eA = 0, eR;
	//double medidas[can], frecuencias[can], mediPorFre[can], mediMenMedida[can];
	double medidas[255], frecuencias[255], mediPorFre[255], mediMenMedida[255];

	medidas[can], frecuencias[can], mediPorFre[can], mediMenMedida[can];

	for (int i = 0; i < can; i++) {
		cout << "Digite el valor de la medida " << (i + 1) << ": ";
		cin >> medidas[i];
		cout << "Digite el valor de la frecuencia de la medida " << (i + 1) << ": ";
		cin >> frecuencias[i];
		cout << endl;
	}

	for (int i = 0; i < can; i++) {
		FA = frecuencias[i] + FA;
		mediPorFre[i] = medidas[i] * frecuencias[i];
		suma = mediPorFre[i] + suma;
	}

	media = (double)suma / FA;


	for (int i = 0; i < can; i++) {
		mediMenMedida[i] = media - medidas[i];
		sumMediMenMedida = (double)mediMenMedida[i] + sumMediMenMedida;
	}

	//valor absoluto
	if (sumMediMenMedida < 0) {
		sumMediMenMedida = sumMediMenMedida * (-1);
	}

	eA = (double)sumMediMenMedida / FA;
	eR = (double)eA / media * 100;

	//impresion
	cout << "Medidas " << "Frecuencias   " << "xi*f  " << "X-xi" << endl;
	for (int i = 0; i < can; i++) {
		cout << medidas[i] << "            ";
		cout << frecuencias[i] << "      ";
		cout << mediPorFre[can] << "      ";
		cout << mediMenMedida[can] << endl << endl << endl;

	}
	cout << "la frecuencia absoluta(n) es = " << FA << endl;
	cout << "la sumatoria es= " << suma << endl;
	cout << "la media es= " << setprecision(3) << media << endl;
	cout << "la sumatoria de la resta es = " << sumMediMenMedida << endl;
	cout << "El error absoluto es = " << eA << endl;
	cout << "El error relativo es = " << setprecision(3) << eR << "%" << endl;

}

int main()
{
	

	cout << "Seleccion de programa: " << endl;

	char opt;
	
	do
	{
		int opc, vR, vM, can;

		int sel;

		cout << "1. Forma trigonometrica" << "\n2. Forma de potencia" << "\n3. PROGRAMA QUE CALCULA EL ERROR ABSOLUTO Y RELATIVO" << "\n4. Salir" << endl;
		cin >> sel;

		switch (sel)
		{
		case 1:
			formTrig();
			break;
		case 2:
			formPot();
			break;
		case 3:
			cout << "Seleccione: " << "\n1)Datos sueltos\n2)Datos agrupados\n";
			cin >> opc;
			if (opc == 1) {
				cout << "Digite el valor real: " << endl;
				cin >> vR;
				cout << "Digite el valor medido: " << endl;
				cin >> vM;
				dSueltos(vR, vM);
			}
			else {
				cout << "Digite el numero de datos agrupados: " << endl;
				cin >> can;
				dAgrupados(can);
			}
			break;
		case 4:
			cout << "Saliendo..." << endl;
			return 0;
			break;
		}

		cout << "desea hacer algo mas? S/N" << endl;
		cin >> opt;
	} while (opt == 's');

	return 0;
}


