/**
	@file
	@brief		�X�g���[���������BER���k�����𑀍삷��
	@author		sue445
*/
#ifndef _INC_CBER
#define _INC_CBER

#include <stdio.h>
#include "sueLib/smart_buffer.h"

using namespace sueLib;

/// BER����n
class CBer{
private:
	static	int  int2ber(int nData, void* pDst=NULL, unsigned int nSize=0);	///< int -> BER

public:
	static	void MemoryReverse(void* pData, unsigned int nSize);	///< �������f�[�^�𔽓]����

	static	int				GetBerNumber(smart_buffer& buf);		///< �o�b�t�@���璼��BER���k�������擾
	static	smart_buffer	SetBerNumber(int nData);				///< �o�b�t�@�ɒ���BER���k�������Z�b�g
};

#endif
