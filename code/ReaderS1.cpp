/***************************************************************************
 ReaderS1.cpp
 -------------------
 copyright            : (C) 2017 Andrea Bulgarelli
 email                : bulgarelli@iasfbo.inaf.it
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software for non commercial purpose              *
 *   and for public research institutes; you can redistribute it and/or    *
 *   modify it under the terms of the GNU General Public License.          *
 *   For commercial purpose see appropriate license terms                  *
 *                                                                         *
 ***************************************************************************/
#include <iomanip>
#include <vector>
#include <string>
#include <pthread.h>
#include "ReaderS1.h"

using namespace ACPAlgorithm;


namespace ACPAlgorithm {
	
	ReaderS1::ReaderS1(ACPBuffer* buffer_output) : ACPProducer(buffer_output) {
		
	}
	
	void ReaderS1::createBuffer(string configFileName, string datafilename)
	{
		//set nevents
		//read from file until eof
		
		//sharedDataAndInfoBuffer.push_back(elem);
		
	}
	
	void ReaderS1::init(string configFileName, string datafilename) {
		this->configFileName = configFileName;
		this->datafilename = datafilename;
		nevents = 0;
		//version 1: read file at the beginning and get the data from a buffer
		createBuffer(configFileName, datafilename);
		//or version2: read the data directly from the input file
		//do nothgin
		clock_gettime(CLOCK_MONOTONIC, &starttime);
	}
	
	void *ReaderS1::run() {
		
		cout << "Thread started" << endl;
		
		clock_gettime(CLOCK_MONOTONIC, &starttime);
		while (true) {
			ACPDataS1* cam = getNext();
			if(cam)
				buffer_output->put(cam);
		}
		return 0;
		
	}
	
	ACPDataS1* ReaderS1::getNext() {
		
		//version 1: read file at the beginning and get the data from a buffer. A circular buffer
		ACPDataS1* ev = sharedDataAndInfoBuffer[sharedIndex];
		
		sharedIndex = (sharedIndex+1) % sharedDataAndInfoBuffer.size();
	
		//or version2: read the data directly from the input file
		
		return ev;
	}
	
}
