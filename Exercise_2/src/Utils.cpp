#include "Utils.hpp"

using namespace std;

void CalcoloV(double S, int n, double w[], double r[]) {
    double V = 0;
    for (int i = 0; i < n; ++i) {
        V += w[i] * (1 + r[i]) * S;
    }

    double RateofReturn = (V / S) -1;

    //INSERISCO I RISULTATI NEL FILE DI OUTPUT E CONTROLLO SIA APERTO BENE
    ofstream outputFile("result.txt");
    if (!outputFile.is_open()) {
        cerr << "Impossibile creare il file di output" << endl;
    }

    //STAMPO I RISULTATI
    outputFile << "S = " <<setprecision(2)<< S << ", n = " <<setprecision(2)<< n << endl;
    outputFile << "w = [ ";
    for (int i = 0; i < n; ++i) {
        outputFile << w[i] << " ";
    }
    outputFile << "]" << endl;

    outputFile << "r = [ ";
    for (int i = 0; i < n; ++i) {
        outputFile << r[i] << " ";
    }
    outputFile << "]" << endl;

    outputFile << "Rate of return of the portfolio: " <<setprecision(4)<< RateofReturn << endl;
    outputFile << "V: " << V <<setprecision(2)<< endl;

    outputFile.close();
}
