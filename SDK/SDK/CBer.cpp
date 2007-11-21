/**
	@file
	@brief		�X�g���[���������BER���k�����𑀍삷��
	@author		sue445
*/
#include "CBer.h"
#include "CBerStream.h"


//=============================================================================
/**
	int��BER�ϊ�(1��ڂɃT�C�Y�𒲂ׂĂ����āA2��ڂŃf�[�^���Z�b�g����)

	@param	nData		[in] �ϊ����̐���
	@param	pDst		[out] �o�͐�o�b�t�@(�T�C�Y�v�Z���������ꍇ��NULL���w�肵�܂�)
	@param	nSize		[in] �o�͐�o�b�t�@�̃T�C�Y

	@return				�X�g���[���ɏ����o�����o�C�g��(�X�g���[���ɏ����o���̂ɕK�v�ȃo�C�g��)
*/
//=============================================================================
int CBer::int2ber(int nData, void* pDst, unsigned int nSize)
{
	unsigned int data = (unsigned int)nData;
	unsigned int i = 0, j;
	unsigned char* c = reinterpret_cast< unsigned char* >( pDst );

	for(;;){
		j = data & 0x7F;

		if(pDst && i<nSize){
			if(i==0)	c[i] = (unsigned char)j;
			else		c[i] = (unsigned char)(j|0x80);
		}
		i++;

		data>>=7;
		if(data==0)		break;
	}

	if(pDst)	MemoryReverse(pDst, nSize);

	return i;
}

//=============================================================================
/**
	�������̒��g�𔽓]����

	@param	pData		[in,out] ���]���郁�����f�[�^
	@param	nSize		[in] �������f�[�^�̃T�C�Y
*/
//=============================================================================
void CBer::MemoryReverse(void* pData, unsigned int nSize)
{
	if(pData==NULL || nSize<2)		return;

	unsigned char* p = reinterpret_cast< unsigned char* >( pData );
	unsigned char  c;
	unsigned int max = nSize / 2;

	for(unsigned int i = 0; i < max; i++){
		c				= p[i];
		p[i]			= p[nSize-1-i];
		p[nSize-1-i]	= c;
	}
}

//=============================================================================
/**
	�o�b�t�@���璼��BER���k�������擾����

	@param	buf			[in] BER���k�������i�[����Ă���o�b�t�@

	@return				BER���k�����𕁒ʂ̐����ɒ������l
*/
//=============================================================================
int CBer::GetBerNumber(smart_buffer& buf)
{int i;
	CBerStream st;

	if(st.OpenFromMemory(buf, buf.GetSize())){
		i= st.ReadBerNumber();
		  printf(" numero %d",i);
return i;

	}

	return 0;
}

//=============================================================================
/**
	�o�b�t�@��BER���k�������Z�b�g����

	@param	nData		[in] �ϊ����̐���

	@return				�o�͂����o�b�t�@
*/
//=============================================================================
smart_buffer CBer::SetBerNumber(int nData)
{
	smart_buffer buf;
	int size = int2ber(nData);

	if(size>0){
		buf.New(size);
		int2ber(nData, buf, buf.GetSize());
		return buf;
	}

	return buf;
}
