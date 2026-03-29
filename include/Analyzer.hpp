#ifndef ANALYZER_HPP
#define ANALYZER_HPP

#include <string>
#include <vector>

using namespace std;

namespace ImageTrace {
    struct ImageInfo
    {
        string format;
        long fileSize;
        bool isSuspicious;
        string report;
    };

    class Analyzer
    {
    private:
        string filePath;
        string checkMagicByte(const vector<unsigned char>& buffer);
    public:
        Analyzer(const string& path);

        ImageInfo scan();
    };
#endif
