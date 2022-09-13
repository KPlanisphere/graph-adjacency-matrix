//Benemerita Universidad Autonoma de Puebla - Facultad de Ciencias de la Computación
//los aña 2

#include <iostream>
#include <stdlib.h>

using namespace std;

//Globales
int pause;

//Prototipardos
void menu();
int** reservarMemoria(size_t);
void corroborar(int, int**);
void multMatriz(int, int**, int**,int);
void entrada(int,int**);
void impMatriz(int,int**);

//MAIN
int main(){
    menu();
    return 0;
}

//Menu
void menu() {
    int op = 0, card = 0;

cardinalidad:
    system("cls");
    do{
        system("cls");
        cout << "\n/////// CARDINALIDAD DEL GRAFO: ";
        cin >> card;
        if (card < 2){
            cout << "\n[!] ERROR: INGRESA UN VALOR VALIDO [!]";
            pause = cin.get(); //PAUSA
            pause = cin.get(); //PAUSA
        }
    } while (card < 2);

    //Matriz dinamica
    int** matriz = reservarMemoria(card);
    entrada(card, matriz);
    do{
        system("cls");
        cout << "\n/////// PRACTICA: MATRIZ DE ADYACENCIA/GRAFOS" << endl;
        cout << "\nSELECCIONE UNA OPCION:\n" << endl;
        cout << "\t[1] INGRESAR UN NUEVO GRAFO" << endl;
        cout << "\t[2] IMPRIMIR MATRIZ DE ADYACENCIA ACTUAL" << endl;
        cout << "\t[3] CORROBORAR ADYACENCIA" << endl;
        cout << "\t[4] IMPRIMIR M^2" << endl;
        cout << "\t[5] IMPRIMIR M^3" << endl;
        cout << "\t[6] SALIR" << endl;
        cout << "\n>> ";
        cin >> op;
        pause = cin.get(); //PAUSA
        switch (op) {
        case 1:
            goto cardinalidad;
            break;
        case 2:
            cout << "\n/////// MATRIZ DE ADYACENCIA ACTUAL\n" << endl;
            impMatriz(card, matriz);
            pause = cin.get(); //PAUSA
            break;
        case 3:
            corroborar(card,matriz);
        case 4:
            cout << "\n/////// M^2\n" << endl;
            multMatriz(card,matriz,matriz,1);
            break;
        case 5:
            cout << "\n/////// M^3\n" << endl;
            multMatriz(card, matriz, matriz, 0);
            break;
        default:
            cout << "\n\tIngresa una opcion valida" << endl;
            pause = cin.get(); //PAUSA
            break;
        }
    } while (op != 6);
}

//Reservar memoria
int** reservarMemoria(size_t card) {
    int** matriz = new int* [card];
    for (size_t f(0); f < card; ++f) {
        matriz[f] = new int[card];
    }
    return matriz;
}

//Multiplica matrices
void multMatriz(int card,int **A,int **B,int p) {
    int** C = reservarMemoria(card);;
    for (int i = 0; i < card; i++) {
        for (int j = 0; j < card; j++) {
            C[i][j] = 0;
            for (int k = 0; k < card; k++) {
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }
    if (p == 0){
        multMatriz(card, C, A,1);
        //impMatriz(card, C); !!!
    }
    else
        impMatriz(card,C);
}

//Ingreso de valores
void entrada(int card,int **matrix) {
    cout << "\n/////// INGRESE LOS VALORES:" << endl;
    for (int i = 0; i < card; i++) {
        cout << "\n - FILA #" << i << endl;
        for (int j = 0; j < card; j++) {
            cout << "\t[" << i << "][" << j << "] = ";
            cin >> matrix[i][j]; //Entrada
        }
    }
}
//Imprimir matriz AD
void impMatriz(int card, int** matrix) {
    char k;
    cout << "\t  ";
    for (k = 'A';k <= 64+card; k++){
        cout << " " << k << " ";
    }
    cout << "\n";
    for (int i = 0; i < card; i++){
        printf("\t%c ",65+i);
        for (int j = 0; j < card; j++) {
            cout << "[" << matrix[i][j] << "]";
        }
    cout << "\n";
    }
}
//Corroborar adyacencia
void corroborar(int card, int** matrix) {
    int fil, col;
    
    cout << "\n/////// CORROBORAR ADYACENCIA\n" << endl;
    impMatriz(card, matrix);
    cout << "\nIngresa la fila y columna a buscar\n" << endl;
    cout << "\tFILA: ";
    cin >> fil;
    cout << "\tCOLUMNA: ";
    cin >> col;
    if (matrix[fil][col] == 1) {
        cout << "\n\t - ES ADYACENTE - ";
    }
    else {
        cout << "\n\t - NO ES ADYACENTE - ";
    }
    pause = cin.get(); //PAUSA
    pause = cin.get(); //PAUSA
}
//Salir
void exit() {
    cout << "\tGRACIAS POR USAR NUESTROS SERVICIOS =)" << endl;
    cout << "\t *ASDASDASDAS* - BUAP / FCC";
}
