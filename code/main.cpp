#include <iostream>
#include <string>
#include <ACPTelescopeConfig.h>
#include "ReaderS1.h"
#include "CPDiscriminator.h"
#include "ACPDataS1disc.h"

using namespace ACPAlgorithm;

using namespace std;

int main(int argc, char *argv[])
{
	const char* home = getenv("LOCAL");
	
	if (!home)
	{
		cerr << "ERROR: LOCAL environment variable is not defined." << endl;
		return 0;
	}
	
	string astrogam = home;
	
	if(argc <= 2) {
		cerr << "ERROR: Please provide config, .s1, number of threads" << endl;
		cerr << "Example ./alg1 $LOCAL/share/telescopeconfig/config.conf $ASTROGAM/data/data.s1 8" << endl;
		return 0;
	}

	string configFileName = argv[1];
	string s1filename = argv[2];
	
	ACPTelescopeConfig telescopeConfig;
	
	telescopeConfig.loadConfig(configFileName);
	
	cout << telescopeConfig.getACTopID() << endl;
	
	//load data from a file
	ReaderS1 fullS1Data(0);
	fullS1Data.init(configFileName, s1filename);
	
	//perfrom CP discrimination
	CPDiscriminator cpdiscr(&telescopeConfig);
	
	while(true) {
		ACPDataS1* s1ev = fullS1Data.getNext();
		ACPDataS1disc* s1evdisc =  (ACPDataS1disc*) cpdiscr.process(s1ev);
		//use s1evdisc in the following steps

		
	}
	


}
