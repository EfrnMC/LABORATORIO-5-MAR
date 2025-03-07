#include <iostream>
using namespace std;

class CuentaBancaria {
private:
    double saldo;
    int numeroCuenta;
    bool activa;

public:
    CuentaBancaria(int num, double saldoInicial = 0) {
        numeroCuenta = num;
        saldo = saldoInicial;
        activa = true; // Todas las cuentas inician activas
    }

    void depositar(double monto) {
        if (!activa) {
            cout << "Error: La cuenta #" << numeroCuenta << " está inactiva. No se puede depositar." << endl;
            return;
        }
        saldo += monto;
        cout << "Deposito exitoso. Nuevo saldo: Q" << saldo << endl;
    }

    void retirar(double monto) {
        if (!activa) {
            cout << "Error: La cuenta #" << numeroCuenta << " está inactiva. No se puede retirar dinero." << endl;
            return;
        }
        if (monto > saldo) {
            cout << "Fondos insuficientes." << endl;
        }
        else {
            saldo -= monto;
            cout << "Retiro exitoso. Nuevo saldo: Q" << saldo << endl;
        }
    }

    void mostrarSaldo() {
        cout << "Cuenta #" << numeroCuenta << " - Saldo actual: Q" << saldo;
        cout << (activa ? " (ACTIVA)" : " (INACTIVA)") << endl;
    }

    void inhabilitarCuenta() {
        activa = false;
        cout << "La cuenta #" << numeroCuenta << " ha sido INHABILITADA." << endl;
    }

    void habilitarCuenta() {
        activa = true;
        cout << "La cuenta #" << numeroCuenta << " ha sido HABILITADA." << endl;
    }

    int getNumeroCuenta() {
        return numeroCuenta;
    }

    bool estaActiva() {
        return activa;
    }
};

int main() {
    int numCuenta, opcion;
    double monto;
    bool salir = false;
    CuentaBancaria cuenta(0, 0); // Cuenta inicial sin número válido

    do {
        cout << "\nIngrese el numero de cuenta (1-30) o 0 para salir: ";
        cin >> numCuenta;

        if (numCuenta == 0) {
            salir = true;
            break;
        }

        if (numCuenta < 1 || numCuenta > 30) {
            cout << "Numero de cuenta invalido." << endl;
            continue;
        }

        // Crear una nueva cuenta con saldo inicial de Q1,800.00
        cuenta = CuentaBancaria(numCuenta, 1800);

        do {
            cout << "\nCuenta #" << cuenta.getNumeroCuenta();
            cout << (cuenta.estaActiva() ? " (ACTIVA)" : " (INACTIVA)") << endl;
            cout << "Ingrese la opcion: " << endl;
            cout << "1. DEPOSITAR" << endl;
            cout << "2. RETIRAR" << endl;
            cout << "3. CONSULTAR SALDO" << endl;
            cout << "4. CAMBIAR DE CUENTA" << endl;
            cout << "5. HABILITAR/INHABILITAR CUENTA" << endl;
            cout << "6. SALIR" << endl;
            cin >> opcion;

            switch (opcion) {
            case 1:
                cout << "Ingrese monto a depositar: ";
                cin >> monto;
                cuenta.depositar(monto);
                break;
            case 2:
                cout << "Ingrese monto a retirar: ";
                cin >> monto;
                cuenta.retirar(monto);
                break;
            case 3:
                cuenta.mostrarSaldo();
                break;
            case 4:
                cout << "Cambiando de cuenta..." << endl;
                break;
            case 5:
                if (cuenta.estaActiva()) {
                    cuenta.inhabilitarCuenta();
                }
                else {
                    cuenta.habilitarCuenta();
                }
                break;
            case 6:
                cout << "Saliendo del sistema..." << endl;
                salir = true;
                break;
            default:
                cout << "Opcion invalida." << endl;
            }
        } while (opcion != 4 && opcion != 6);

    } while (!salir);

    return 0;
}
