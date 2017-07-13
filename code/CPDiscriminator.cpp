/***************************************************************************
 CPDiscriminator.cpp
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


#include "ACPDataS1disc.h"
#include "CPDiscriminator.h"


using namespace ACPAlgorithm;

//#define DEBUG 1
//#define PRINTALG 1

namespace ACPAlgorithm {
	
	CPDiscriminator::CPDiscriminator(ACPAlgorithm::ACPTelescopeConfig* config, ACPAlgorithm::ACPBuffer* buffer_input, ACPAlgorithm::ACPBuffer* buffer_output) : ACPProcessor(config, buffer_input, buffer_output) {
			}
	
	void CPDiscriminator::init() {
		
	}
	
	ACPData* CPDiscriminator::process(ACPData* input) {
		ACPDataS1* ev = (ACPDataS1*) input;
		ACPDataS1disc* evaluated = 0;
		if(ev->id == 0) {
			
			//perform CP discrimination
			
			evaluated = new ACPDataS1disc;
			//copy data
			
			
		}
		return evaluated;
	}
	
	
}
