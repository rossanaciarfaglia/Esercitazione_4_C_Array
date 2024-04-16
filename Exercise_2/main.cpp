#include "Utils.hpp"

using namespace std;

int main() {
    const int massima_lunghezza = 100; //LUNGHEZZA MASSIMA DEL VETTORE
    double S = 0.0;
    int n = 0;
    double w[massima_lunghezza];
    double r[massima_lunghezza];

    //APRO IL FILE DI LETTURA E  CONTROLLO VENGA APERTO CORRETTAMENTE
    ifstream file("data.csv");
    if (!file.is_open()) {
        cerr << "Impossibile aprire il file" << endl;   //INSERISCO L'EVENTUALE AVVISO DI ERRORE DI APERTURA
        return 1;
    }

    string line;
    int i = 0;
    while (getline(file, line)) { //USO GETLINE CHE MI PERMETTE DI DIVIDERE LA LINE
        i++;
        if (i == 1) {
            S = stod(line.substr(2)); //stod CONVERTE STRINGHE IN double
        } else if (i == 2) {
            n = stoi(line.substr(2)); //stoi CONVERTE STRINGHE IN int
        } else if (i > 3) { //CHE CORRISPONDE ALLA RIGA IN CUI CI SONO I VALORI DI w ED r
            stringstream ss(line);
            string value;
            getline(ss, value, ';');
            w[i-4] = stod(value);
            getline(ss, value, ';');
            r[i-4] = stod(value);
        }
    }

    file.close();

    CalcoloV(S, n, w, r);

    return 0;
}

