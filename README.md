# Graph Adjacency Matrix Operations

This project implements operations on a graph represented by an adjacency matrix in C++. The program allows users to input graph data, perform matrix multiplications to determine paths of length 2 and 3, verify adjacency, and print the adjacency matrix. It includes a menu-driven interface for easy user interaction.

## Repository Name
graph-adjacency-matrix

## Features

- **Input Graph Data**: Allows the user to input the adjacency matrix of a graph.
- **Print Adjacency Matrix**: Displays the current adjacency matrix.
- **Verify Adjacency**: Checks if two nodes are adjacent.
- **Matrix Multiplication for Paths**: Calculates and displays the matrix for paths of length 2 (M^2) and length 3 (M^3).
- **Menu Interface**: Provides a user-friendly menu to perform the above operations.

## Usage

Compile the program using a C++ compiler and run the executable. The user will be prompted to enter the cardinality of the graph and then interact with a menu to perform various operations.

### Example Commands

1. **Input New Graph**: Enter the adjacency matrix for a new graph.
2. **Print Current Adjacency Matrix**: Displays the current adjacency matrix.
3. **Verify Adjacency**: Checks if two specified nodes are adjacent.
4. **Print M^2**: Calculates and prints the matrix representing paths of length 2.
5. **Print M^3**: Calculates and prints the matrix representing paths of length 3.
6. **Exit**: Terminates the program.

## Code Snippets

### Reserve Memory for Matrix
```cpp
int** reservarMemoria(size_t card) {
    int** matriz = new int* [card];
    for (size_t f(0); f < card; ++f) {
        matriz[f] = new int[card];
    }
    return matriz;
}
```

### Matrix Multiplication

```cpp
void multMatriz(int card, int** A, int** B, int p) {
    int** C = reservarMemoria(card);
    for (int i = 0; i < card; i++) {
        for (int j = 0; j < card; j++) {
            C[i][j] = 0;
            for (int k = 0; k < card; k++) {
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }
    if (p == 0) {
        multMatriz(card, C, A, 1);
    } else {
        impMatriz(card, C);
    }
}
```

### Menu Interface

```cpp
void menu() {
    int op = 0, card = 0;
cardinalidad:
    system("cls");
    do {
        system("cls");
        cout << "\n/////// CARDINALIDAD DEL GRAFO: ";
        cin >> card;
        if (card < 2) {
            cout << "\n[!] ERROR: INGRESA UN VALOR VALIDO [!]";
            pause = cin.get(); //PAUSA
            pause = cin.get(); //PAUSA
        }
    } while (card < 2);
    int** matriz = reservarMemoria(card);
    entrada(card, matriz);
    do {
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
            corroborar(card, matriz);
            break;
        case 4:
            cout << "\n/////// M^2\n" << endl;
            multMatriz(card, matriz, matriz, 1);
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
```

## How to Run

1. Clone the repository:
    ```bash
    git clone https://github.com/KPlanisphere/graph-adjacency-matrix.git
    ```
2. Navigate to the project directory:
    ```bash
    cd graph-adjacency-matrix
    ```
3. Compile the code:
    ```bash
    g++ GrafoMatriz.cpp -o graph_matrix
    ```
4. Run the executable:
    ```bash
    ./graph_matrix
    ```
