#include "Analyzer.hpp"
#include <fstream>

using namespace std;

namespace ImageTrace {

Analyzer::Analyzer(const string& path) : filePath(path) {}

ImageInfo Analyzer::scan() {
    ImageInfo info = {"Unknown", 0, false, ""};

    ifstream file(filePath, ios::binary | ios::ate);
    
    if (!file) {
        info.report = "Error: No se pudo abrir el archivo.";
        return info;
    }

    info.fileSize = file.tellg(); 
    file.seekg(0, ios::beg); 

    vector<unsigned char> buffer(8);
    file.read(reinterpret_cast<char*>(buffer.data()), 8);

    info.format = checkMagicBytes(buffer);

    if (info.format == "Unknown") {
        info.isSuspicious = true;
        info.report = "Alerta: Firma digital no reconocida. Posible archivo camuflado.";
    } else {
        info.report = "Archivo verificado correctamente.";
    }

    return info;
}

string Analyzer::checkMagicBytes(const vector<unsigned char>& b) {
    if (b[0] == 0xFF && b[1] == 0xD8) return "JPEG";
    if (b[0] == 0x89 && b[1] == 0x50 && b[2] == 0x4E) return "PNG";
    if (b[0] == 0x47 && b[1] == 0x49 && b[2] == 0x46) return "GIF";
    return "Unknown";
}

}