#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <chrono>
#include <thread>
#include <fstream>
#include <unistd.h>

using namespace std;

int main()
{
	int ips = 2147483648;
	int n1 = 0;
	int n2 = 0;
	int n3 = 0;
	int n4 = 0;
	int i;
	string dot = ".";
	string x1;
	string x2;
	string x3;
	string x4;
	string x5;
	string ip;
	string ching;

	ofstream list;
	list.open("ip.txt");

//==================================================================================================================================================================================================//
// for loop pinging random ips
//==================================================================================================================================================================================================//
	for (i = 0; i < 4294967296; i++)
	{
		n1 = 0+(rand()%255);
                n2 = 0+(rand()%255);
                n3 = 0+(rand()%255);
                n4 = 0+(rand()%255);

		srand(time(0));

		x1 += std::to_string(n1);
		x2 += std::to_string(n2);
		x3 += std::to_string(n3);
		x4 += std::to_string(n4);
		x5 = "  > /dev/null 2>&1";

		ip = x1+dot+x2+dot+x3+dot+x4;
		ching = "ping -c1 -s1 " + ip; 

		int x = system(ching.c_str());

		if (x == 0)
		{
			cout << n1 << dot << n2 << dot << n3 << dot << n4 << dot << " has been pinged succesfully!" << endl;
			list << n1 << dot << n2 << dot << n3 << dot << n4 << dot << " has been pinged succesfully!\n"; 
		} else {
			cout << n1 << dot << n2 << dot << n3 << dot << n4 << dot << " is not active!" << endl;
		}
	x1.clear();
	x2.clear();
	x3.clear();
	x4.clear();
	ching.clear();
	cout << ching << endl;
	cout << x << endl;
	sleep(2);
	}

	cout << ching << endl;

        list.close();
}
