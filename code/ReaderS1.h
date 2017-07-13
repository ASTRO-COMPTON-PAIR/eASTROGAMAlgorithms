/***************************************************************************
 ReaderS1.h
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

#ifndef _ReaderS1_H
#define _ReaderS1_H

#include <iostream>
#include <acputils/Thread.h>
#include <acputils/mac_clock_gettime.h>
#include <ACPBuffer.h>
#include <ACPProducer.h>
#include "ACPDataS1.h"
#include <vector>

using namespace std;

namespace ACPAlgorithm {
	
	class ReaderS1 : public ACPUtils::Thread, public ACPAlgorithm::ACPProducer {
	private:
		
		long sharedIndex;
		
		long long nevents;
		
		std::vector<ACPDataS1*> sharedDataAndInfoBuffer;
		
		std::string configFileName;
		std::string datafilename;
		struct timespec starttime, stoptime;
		
	protected:
		
		void createBuffer(string configFileName, string rawfilename);
		
	public:
		
		ReaderS1(ACPAlgorithm::ACPBuffer* buffer_output);
		
		void init(std::string configFileName, std::string datafilename);
		
		void *run();
		
		ACPDataS1* getNext();
		
	};
}

#endif
