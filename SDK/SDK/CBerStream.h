/**
	@file
	@brief		CBasicStream�𗘗p����BER���k�����̓��o�́B\n
				BER���k�����ɂ��Ă͂��̕ӂŁB\n
				http://www.stellar.ac/~komai/unix/ber/index.html

	@author		sue445
*/
#ifndef _INC_CBERSTREAM
#define _INC_CBERSTREAM

#include "sueLib/CBasicStream.h"
#include "sueLib/smart_buffer.h"

using namespace sueLib;


/// BER���k�����̓��o��
class CBerStream : public CBasicStream{
public:
	CBerStream(){}										///< �R���X�g���N�^
	~CBerStream(){}										///< �f�X�g���N�^

	int ReadBerNumber(int* lpReadByte=NULL);			///< BER���k������1���o��
	int WriteBerNumber(int nData, bool bCalc=false);	///< BER���k������1�����o��
};


#endif
