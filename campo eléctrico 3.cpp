#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Constante de Coulomb
const double K = 8.9875517923e9; // Valor exacto para mayor precisión técnica

// --- FUNCIONES DE CONVERSIÓN ---

double obtenerCargaEnCoulombs() {
    double valor;
    int unidad;
    cout << "\n  --- UNIDAD DE CARGA ---" << endl;
    cout << "  1. Milicoulombs (mC)  2. Microcoulombs (uC)  3. Nanocoulombs (nC)" << endl;
    cout << "  4. Picocoulombs (pC)  5. Coulombs (C)" << endl;
    cout << "  Seleccione (1-5): "; cin >> unidad;
    cout << "  Ingrese valor: "; cin >> valor;

    double factores[] = {1e-3, 1e-6, 1e-9, 1e-12, 1.0};
    if (unidad < 1 || unidad > 5) return valor;
    return valor * factores[unidad - 1];
}

double obtenerDistanciaEnMetros() {
    double valor;
    int unidad;
    cout << "\n  --- UNIDAD DE DISTANCIA ---" << endl;
    cout << "  1. Kilometro (km)   2. Hectometro (hm)  3. Decametro (dam)" << endl;
    cout << "  4. Decimetro (dm)   5. Centimetro (cm)  6. Milimetro (mm)" << endl;
    cout << "  7. Metro (m)" << endl;
    cout << "  Seleccione (1-7): "; cin >> unidad;
    cout << "  Ingrese valor: "; cin >> valor;

    double factores[] = {1000.0, 100.0, 10.0, 0.1, 0.01, 0.001, 1.0};
    if (unidad < 1 || unidad > 7) return valor;
    return valor * factores[unidad - 1];
}

// --- PROGRAMA PRINCIPAL CON DESPEJES ---

int main() {
    int opcion;
    cout << fixed << setprecision(6);

    do {
        cout << "\n==========================================" << endl;
        cout << "   CALCULADORA DE DESPEJES: CAMPO (E)     " << endl;
        cout << "==========================================" << endl;
        cout << "1. CALCULAR CAMPO (E = K*q / r^2)" << endl;
        cout << "2. CALCULAR DISTANCIA (r = sqrt(K*q / E))" << endl;
        cout << "3. CALCULAR CARGA (q = (E * r^2) / K)" << endl;
        cout << "4. CALCULAR FUERZA (F = E * q)" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 0) break;

        switch (opcion) {
            case 1: { // Calcular E
                double q = obtenerCargaEnCoulombs();
                double r = obtenerDistanciaEnMetros();
                double E = (K * abs(q)) / pow(r, 2);
                cout << "\n>> RESULTADO: E = " << scientific << E << " N/C" << endl;
                break;
            }
            case 2: { // Despeje de r
                double q = obtenerCargaEnCoulombs();
                double E;
                cout << "Ingrese Campo Electrico (E) en N/C: "; cin >> E;
                if (E == 0) { cout << "Error: E no puede ser 0." << endl; break; }
                double r = sqrt((K * abs(q)) / E);
                cout << "\n>> RESULTADO DESPEJE (r):" << endl;
                cout << "   " << fixed << r << " metros" << endl;
                cout << "   " << r * 100 << " centimetros" << endl;
                break;
            }
            case 3: { // Despeje de q
                double E, r;
                cout << "Ingrese Campo Electrico (E) en N/C: "; cin >> E;
                r = obtenerDistanciaEnMetros();
                double q = (E * pow(r, 2)) / K;
                cout << "\n>> RESULTADO DESPEJE (q):" << endl;
                cout << "   " << scientific << q << " C" << endl;
                cout << "   " << fixed << q * 1e6 << " uC (micro)" << endl;
                cout << "   " << q * 1e9 << " nC (nano)" << endl;
                break;
            }
            case 4: { // Cálculo de Fuerza
                double E, q;
                cout << "Ingrese Campo Electrico (E) en N/C: "; cin >> E;
                q = obtenerCargaEnCoulombs();
                double F = E * abs(q);
                cout << "\n>> RESULTADO: Fuerza (F) = " << scientific << F << " N" << endl;
                break;
            }
            default:
                cout << "Opcion no valida." << endl;
        }
    } while (opcion != 0);

    return 0;
}
    