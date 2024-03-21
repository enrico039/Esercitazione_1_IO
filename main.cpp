#include <fstream>  //  libreria i/o su file
#include <iostream>  //  libreria i/o su compiler
#include <iomanip>  //  libreria che formatta l'output

double contr(double x)
{
    x = 0.75 * x - 1.75;
    return x;
}

int main()
{
    std::string nomefile = "data.csv";
    std::ifstream fstr;
    fstr.open(nomefile);  // apre il file di lettura

    if(fstr.fail())  // controlla se il file esiste e stampa errore in caso contrario
    {
        std::cerr << "File not found";
        return 1;
    }

    std::string fileout = "result.csv";
    std::ofstream ofstr(fileout); // crea il file output

    if (ofstr.is_open())
    {
        ofstr << "# N mean \n";  // prima riga
        double val;
        double mean = 0;  //  inizializza la media di ogni riga
        int i = 0;
        while (fstr >> val)  //  prende la riga dal file fstr e la mette in val
        {
            i = i + 1;
            val = contr(val);
            mean = mean * (i-1)/i + val/i;  // calcola la media con l'aggiunta del numero successivo
            ofstr << std::scientific << std::setprecision(16) << i << " " << mean << "\n";  // stampa
        }
        ofstr.close();  //  chiude il file output
        fstr.close();
        return 0;
    }
    fstr.close();
    std::cerr << "File creation unsuccessful";
    return 2;
}
