#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>


using namespace std;



std::vector<std::string> split(std::string s, std::string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

string replace(string value) {

	    string search(";");
	    string repl(",");
	    int pos = value.find(search);
	    if (pos == -1) {
		return value;
	    }
	    value.replace(pos,1,repl);
	    return replace(value);
	
}

int main()
{
    ifstream input("data/data.csv");
    string result;
    string line;

    while (getline(input, line)) 
    {
        result += line;
    }
	
    std::string delimiter = "V,";
    std::vector<std::string> words = split (result, delimiter);

    string data = "";
    for (auto word : words) {

	std::string delimiter = ",";
    	std::vector<std::string> items = split (word, delimiter);
		string value = items[3];

	    data += items[1];
	    data += " ";
	    data += items[2];
	    data += ";";
	    data += replace(value);
	    data += "\n";
    	}
    ofstream myfile ("data/result.txt");
  if (myfile.is_open())
  {
    myfile << data;
    myfile.close();
  }

}
