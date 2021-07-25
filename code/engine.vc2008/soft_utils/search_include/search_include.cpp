#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <stack>
#include <filesystem>
#include <sstream>
#include <algorithm>
#include <set>

using namespace std;
namespace fs = std::filesystem;
using ListLines = vector<string>;
using MapResult = map<string, set<string>>;

/// -------------EXEPTIONS------------------ ///

class FileErrorExeption : public exception
{
public:
    FileErrorExeption(const char* err): exception(err){}
    char const* what() const override
    {
        return exception::what();
    }
};

/// ---------------------------------------- ///

class Loader
{
public:
    ListLines load(const string& p)
    {
        ListLines out;
        ifstream f(p);
        if (!f)
            throw FileErrorExeption(("Error open file " + p).c_str());
        while (true)
        {
            string tmp;
            getline(f, tmp, '\n');
            if(!f)
                throw FileErrorExeption(("Error read file " + p).c_str());
            out.emplace_back(tmp);
            if (f.eof())
                break;
        }
        return out;
    }
};

class SeacheIncludes
{
    MapResult data; // key - path, value - array of name files (unique!)
public:
    void start(const ListLines& ap, const ListLines& af)
    {
        MapResult& _data = data;
        stack<string> files({ af.begin(), af.end() });
        while (!files.empty())
        {
            string currentFile(files.top());
            files.pop();
            // read file
            ifstream f(currentFile);
            if (!f)
                throw FileErrorExeption(("Error open file " + currentFile).c_str());
            stringstream stream;
            stream << f.rdbuf();
            string tmp(stream.str());
            // find includes
            // remove all comments (//, /**/)
            // here reqular expression for find directives #include

            // add to stack

            // find currentFile to all paths and add to find path
            std::transform(currentFile.begin(), currentFile.end(), currentFile.begin(), tolower);
            std::for_each(ap.begin(), ap.end(), [&currentFile, &_data](const string& path)
                {
                    fs::path p(path + currentFile);
                    if (fs::exists(p))
                        _data[p.string()].emplace(currentFile);
                });
        }
    }

    void printData()
    {
        // TODO
    }

    void writeData()
    {
        // TODO
    }
};


int main()
{
    
}

// TODO: for paths add back slesh ('/')
// create two files: path and files(cpp or h from xrCoreB)