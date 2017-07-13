/***************************************************************************
 ACPDataS1
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

#ifndef _S1DATA_H
#define _S1DATA_H

#include <ACPData.h>
#include <acputils/Matrix.h>
#include <stdint.h>

using namespace std;

namespace ACPAlgorithm {
	
	class ACPDataS1 : public ACPAlgorithm::ACPData {
		
	protected:
		int32_t evtID;
		
		int16_t initialProcessFlag; //0=Comption, 1=Pair
		
		//data
		int16_t* processFlag;
		
		uint32_t* volumeID;
		
		double* edep;
		
		double* x_interaction;
		
		double* y_interaction;
		
		double* z_interaction;
		
	public:
		
		ACPDataS1() {
			this->id = 0;
			initialProcessFlag = -1;
			processFlag = 0;
			volumeID = 0;
			edep = 0;
			x_interaction = 0;
			y_interaction = 0;
			z_interaction = 0;
		};
		
		~ACPDataS1() {
			delete[] processFlag;
			delete[] volumeID;
			delete[] edep;
			delete[] x_interaction;
			delete[] y_interaction;
			delete[] z_interaction;
		};
	};
	
	
}

#endif
