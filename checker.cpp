
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <cstdlib> // for exit()
#define ERROR_OPEN_FILE "RichardError"


using namespace std;

const string PATH_ANS="ans/";
const string PATH_IN="input/";
const string PATH_OUT="output/";
const int DEFAULT_SCORE = 100;


std::string& ltrim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
{
    str.erase(0, str.find_first_not_of(chars));
    return str;
}
 
std::string& rtrim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
{
    str.erase(str.find_last_not_of(chars) + 1);
    return str;
}
 
std::string& trim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
{
    return ltrim(rtrim(str, chars), chars);
}


std::string readfile(string file){

   ifstream inf (file.c_str());

    if (!inf)
    {
        // Print an error and exit
        //cerr << "Uh oh, file could not be opened for reading!" << endl;
        return ERROR_OPEN_FILE;
    }

    while (inf)
    {
        std::string strInput;
        getline(inf, strInput);
        strInput.erase(std::remove(strInput.begin(), strInput.end(), '\n'), strInput.end());
        trim(strInput);
        return strInput;
    }
}

int str2int(string s){
    stringstream convert(s); 
    int x = 0; 
    convert >> x; 
    return x;
}


string to_string_leading_zeros(int i){
	std::stringstream ss;
	ss << std::setw(3) << std::setfill('0') << i;
	std::string s = ss.str();
	return s;
}

/*
 * argv[1]: Ten bai
 * argv[2]: so testcase
*/



int main(int argc,char* argv[])
{
	if(argc==1){
		cout << "Please input name of file to check";
		return 0;
	}
	
	string arg1(argv[1]);
	string cd = "cd "+arg1;
	
	string cm_count_file = "ls "+arg1+"/"+PATH_IN+"| wc -l > "+arg1+"/"+PATH_IN+"cnt_file.txt";
	system(cm_count_file.c_str());
	//cout << cm_count_file << endl;
	
	string cnt_file_path = PATH_IN+"cnt_file.txt";
	int number_of_files = str2int(readfile(arg1+"/"+PATH_IN+"cnt_file.txt"));
	number_of_files--;
	printf("Total testcase is %d\n",number_of_files);
	
	
	string rm_count_file = "rm "+arg1+"/"+PATH_IN+"cnt_file.txt";
	system(rm_count_file.c_str());
	//cout << rm_count_file << endl;
	
	int total_scrore = 0;
	for(int tc=0; tc<number_of_files; tc++){
		string in_path = PATH_IN+"input."+to_string_leading_zeros(tc);
		string out_path = PATH_OUT+"output."+to_string_leading_zeros(tc);
		string ans_path = PATH_ANS+"ctt_out."+to_string_leading_zeros(tc);
		
		
		string in = readfile(arg1+"/"+in_path);
		string out = readfile(arg1+"/"+out_path);
		
		
		string command = cd+"&& g++ -Wall -o "+arg1+" "+arg1+".cpp&&./"+arg1+"<"+in_path+" >"+ans_path;
		system(command.c_str());
		
		
		string answer = readfile(arg1+"/"+ans_path);
		
		
		
		if(answer==ERROR_OPEN_FILE||in==ERROR_OPEN_FILE||out==ERROR_OPEN_FILE){
			cout << "Compile Error" << endl;
			continue;
		}
		
		if(answer == out){
			cout << "Testcase "+to_string(tc)+": Correct!" << endl;
			total_scrore ++;
			continue;
		} else{
			cout << "(x) Testcase "+to_string(tc)+": Wrong!" << endl;
			continue;
		}
	}
	printf("Total score: %.2f\n", ((float)total_scrore/number_of_files)*DEFAULT_SCORE);
	
	
	
    return 0;
}
