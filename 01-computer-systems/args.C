#include <iostream>
#include <vector>

using namespace std;

int main ( int argc, char *argv[] )
{
	vector<string> arguments(argv, argv + argc);

	for(auto arg : arguments){
		cout << arg << endl;
	}
}

