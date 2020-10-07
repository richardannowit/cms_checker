
#include <iostream>
#include <string>
#include <cstdlib> // for exit()
using namespace std;



int main(int argc,char* argv[])
{
	if(argc==1){
		cout << "No name of file to make";
		return 0;
	}
	
	string arg1(argv[1]);
	
	system(("mkdir "+arg1).c_str());
	
	string command = "cd "+arg1+"&& mkdir ans && mkdir input && mkdir output";
	
	system(command.c_str());
	
    return 0;
}
