/***************************************************************************
 CPDiscriminator.h
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

#ifndef _CPDISC1_H
#define _CPDISC1_H

#include <ACPProcessor.h>
#include <ACPBuffer.h>

namespace ACPAlgorithm {
	
	class CPDiscriminator : public ACPAlgorithm::ACPProcessor {
		
	public:
		//window is the size of the window of the waveform extractor
		CPDiscriminator(ACPAlgorithm::ACPTelescopeConfig* config, ACPAlgorithm::ACPBuffer* buffer_input = 0, ACPAlgorithm::ACPBuffer* buffer_output = 0);
		
		void init();
		
		ACPAlgorithm::ACPData* process(ACPAlgorithm::ACPData* input);
		
	protected:
		
		
		
	private:
		
		
	};
}

#endif
