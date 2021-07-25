#include <iostream>
#include <regex>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <iomanip>
#include <sstream>

using namespace std;

map<string, string> createMapFromFile(const string& pathFile, const regex& regular, int indexKey);
void printMap(const map<string, string>& m);
map<string, pair<string, string>> mergeMaps(const map<string, string>& m1, const map<string, string>& m2);
void printFinalMap(const map<string, pair<string, string>>& m);
void writeMapToFile(const map<string, pair<string, string>>& m, bool num, const string& name);

int main()
{
	try
	{
		regex regularDpk("( {0,1})([\\w ]*)('Source\\\\)([\\w]+)(\.pas')( {0,1},{0,1})([\\w{},]*)");
		regex regularCpp("([\\w]*\\(\"Source\\\\)([\\w]+)([\.\\w\", {0, 5}\\);]+)");

		auto mapDpk = createMapFromFile("dpk.txt", regularDpk, 4);
		auto mapCpp = createMapFromFile("cpp.txt", regularCpp, 2);

		printMap(mapDpk);
		printMap(mapCpp);

		auto finalMap = mergeMaps(mapDpk, mapCpp);
		printFinalMap(finalMap);

		writeMapToFile(finalMap, true, "1.txt");
		writeMapToFile(finalMap, false, "2.txt");
	}
	catch (exception re)
	{
		cerr << re.what() << endl;
		return -1;
	}
	return 0;
}

map<string, string> createMapFromFile(const string& pathFile, const regex& regular, int indexKey)
{
	map<string, string> src;
	cmatch result;

	ifstream file(pathFile);
	if (!file)
	{
		throw exception(("Error open file " + pathFile + "\n").c_str());
	}
	while (true)
	{
		string tmp;
		getline(file, tmp, '\n');
		if (file.eof())
			break;
		if (!file)
		{
			throw exception(("Error load file " + pathFile + "\n").c_str());
		}
		if (regex_match(tmp.c_str(), result, regular))
			src.emplace(result[indexKey].str(), tmp);
		else
		{
			cerr << "Error: " << tmp << endl;
		}
	}

	return src;
}

void printMap(const map<string, string>& m)
{
	ostream_iterator<string> outputter(cout, "\n");
	for_each(m.begin(), m.end(), [&outputter](const pair<string, string>& p)
		{
			outputter = p.first;
			outputter++;
		});
	outputter = "Count: " + to_string(m.size());
	outputter++;
	outputter = "------------------------------";
	outputter++;
}

map<string, pair<string, string>> mergeMaps(const map<string, string>& m1, const map<string, string>& m2)
{
	map<string, pair<string, string>> finalMap;
	auto& currentMap = (m1.size() > m2.size()) ? m1 : m2;
	for_each(currentMap.begin(), currentMap.end(), [&m1, &m2, &finalMap](const pair <string, string> p)
		{
			auto& k1 = (m1.find(p.first) != m1.end()) ? m1.at(p.first) : "---------------------";
			auto& k2 = m2.find(p.first) != m2.end() ? m2.at(p.first) : "---------------------";
			finalMap.emplace(p.first, make_pair(k1, k2));
		});
	return finalMap;
}

void printFinalMap(const map<string, pair<string, string>>& m)
{
	ostream_iterator<string> outputter(cout, "\n");
	for_each(m.begin(), m.end(), [&outputter](const pair<string, pair<string, string>>& p)
		{
			stringstream out;
			out << setw(20) << p.first << " -> " << setw(80) << p.second.first << " | " << setw(80) << p.second.second;
			outputter = out.str();
			outputter++;
		});
	outputter = "Count: " + to_string(m.size());
	outputter++;
	outputter = "------------------------------";
	outputter++;
}

void writeMapToFile(const map<string, pair<string, string>>& m, bool num, const string& name)
{
	ofstream file(name);
	if (!file)
	{
		throw exception(("Error create file " + name + "\n").c_str());
	}
	for_each(m.begin(), m.end(), [&num, &file, &name](const pair<string, pair<string, string>>& p)
		{
			file << (num ? p.second.first : p.second.second) << endl;
			if(!file)
				throw exception(("Error write file " + name + "\n").c_str());
		});
}