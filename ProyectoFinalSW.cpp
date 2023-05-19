#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0)); // Inicializar la semilla de números aleatorios
    
    int max_numero, intentos_maximos;
    
    cout << "Bienvenido al juego de adivina el número!" << endl;
    cout << "Selecciona una dificultad: " << endl;
    cout << "1 - Fácil (números entre 1 y 20, 10 intentos)" << endl;
    cout << "2 - Normal (números entre 1 y 50, 7 intentos)" << endl;
    cout << "3 - Difícil (números entre 1 y 100, 5 intentos)" << endl;
    int opcion;
    cin >> opcion;
    
    switch (opcion) {
        case 1:
            max_numero = 20;
            intentos_maximos = 10;
            break;
        case 2:
            max_numero = 50;
            intentos_maximos = 7;
            break;
        case 3:
            max_numero = 100;
            intentos_maximos = 5;
            break;
        default:
            cout << "Opción inválida. Seleccionando dificultad normal." << endl;
            max_numero = 50;
            intentos_maximos = 7;
            break;
    }
    
    int numero_secreto = rand() % max_numero + 1; // Generar un número aleatorio dentro del rango establecido
    int intentos = 0;
    int intento_usuario;
    int vidas = 3;
    
    cout << "Estoy pensando en un número entre 1 y " << max_numero << ". Adivina cuál es." << endl;
    
    while (vidas > 0 && intentos < intentos_maximos) {
        cout << "Introduce tu intento: ";
        cin >> intento_usuario;
        
        if (intento_usuario < numero_secreto) {
            cout << "Demasiado bajo." << endl;
        } else if (intento_usuario > numero_secreto) {
            cout << "Demasiado alto." << endl;
        } else {
            cout << "¡Felicidades! Adivinaste el número en " << intentos + 1 << " intentos." << endl;
            return 0;
        }
        
        intentos++;
        vidas--;
        cout << "Te quedan " << vidas << " vidas." << endl;
    }
    
    cout << "Lo siento, has perdido. El número era " << numero_secreto << "." << endl;
    cout << "Gracias por  jugar cambada!" <<endl;
    system("pause");
    return 0;
}
