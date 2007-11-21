/**
	@file
	@brief		�c�N�[��2000/2003�n�t�@�C���̓��o�͂̊�{�ƂȂ�N���X
	@note		���낢��ȂƂ��납�炱�̃N���X���p�����܂����A���̃N���X�P�̂ł��g�p�ł��܂��B

	@author		sue445
*/
#include "CRpgIOBase.h"


//=============================================================================
/**
	�t�@�C�����J��(�w�b�_�`�F�b�N�L��)

	@param	szFile		[in] �J���t�@�C��

	@retval	true		�t�@�C���̃I�[�v���ɐ���
	@retval	false		�t�@�C���̃I�[�v���Ɏ��s
*/
//=============================================================================
bool CRpgIOBase::OpenFile(const char* szFile)
{
	// �t�@�C�����J���Ȃ�
	if(!OpenFromFile(szFile, false)){	
     printf("no encuentro el nombre\n ");                         
 return false;}

	// �w�b�_����v���Ȃ�
	if(ReadString() != GetHeader())	{		
          printf("la cabecera es distint no encuentro el nombre\n ");              
                    	return false;}

	return true;
}

//=============================================================================
/**
	�c�N�[���d�l�̃f�[�^([�f�[�^�T�C�Y][���f�[�^]�Ƃ����`��)��ǂݍ���

	@return	buf			�o�͂����o�b�t�@
*/
//=============================================================================
smart_buffer CRpgIOBase::ReadData()
{	CRpgIOBase		st;
	smart_buffer buf;
	int length = ReadBerNumber();	// �o�b�t�@��
// printf(" bufer  %d \n",length);
	if(length>0){
		buf.New(length);
		Read(buf, length);
	}/*
if(length==1)
{
st.OpenFromMemory(buf.GetConstPtr(), buf.GetSize());
 printf(" dato  %d \n",st.ReadBerNumber());
}*/
	return buf;
}

//=============================================================================
/**
	�c�N�[���d�l�̕������ǂݍ���

	@return	str			�擾����������
*/
//=============================================================================
string CRpgIOBase::ReadString()
{
	smart_buffer buf = ReadData();
	string str;

	if(buf.GetSize()>0)		str.assign(buf.GetPtr(), buf.GetSize());

	return str;
}


//=============================================================================
/**
	unsigned char -> bool�z��

	@param	num			[in] ���͌��̃f�[�^
	@param	flag		[out] �o�͐�̔z��
*/
//=============================================================================
void CRpgIOBase::ByteToBool(unsigned char num, bool flag[8]) const
{
	/*
	ZeroMemory(flag, sizeof(bool)*8);
	if(num & 0x01)	flag[0] = true;
	if(num & 0x02)	flag[1] = true;
	if(num & 0x04)	flag[2] = true;
	if(num & 0x08)	flag[3] = true;
	if(num & 0x10)	flag[4] = true;
	if(num & 0x20)	flag[5] = true;
	if(num & 0x40)	flag[6] = true;
	if(num & 0x80)	flag[7] = true;
	*/

	/*
	flag[0] = ((num & 0x01) != 0);
	flag[1] = ((num & 0x02) != 0);
	flag[2] = ((num & 0x04) != 0);
	flag[3] = ((num & 0x08) != 0);
	flag[4] = ((num & 0x10) != 0);
	flag[5] = ((num & 0x20) != 0);
	flag[6] = ((num & 0x40) != 0);
	flag[7] = ((num & 0x80) != 0);
	*/

	unsigned int i, mask = 1;
	for(i = 0; i < 8; i++){
		flag[i] = ((num & mask) != 0);
		mask <<= 1;
	}
}

