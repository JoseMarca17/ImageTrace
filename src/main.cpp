#include "Analyzer.hpp"
#include <iostream> 

using namespace std;

int main(int argc, char* argv[]){
    if (argc < 2){
        cout << "Use: ./imagescan <image_path>" <<endl;
        return 1;
    }

    ImageTrace::Analyzer scanner(argv[1]);
    ImageTrace::ImageInfo resultado = scanner.scan();

    cout << "--- [ VoidScan Report ] ---" << endl;
    cout << "Formato: " << resultado.format << endl;
    cout << "Tamaño:  " << resultado.fileSize << " bytes" << endl;
    cout << "Estado:  " << (resultado.isSuspicious ? "SOSPECHOSO" : "LIMPIO") << endl;
    cout << "Detalle: " << resultado.report << endl;

    return 0;
}