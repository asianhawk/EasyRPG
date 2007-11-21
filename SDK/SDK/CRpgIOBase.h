/**
	@file
	@brief		�c�N�[��2000/2003�n�t�@�C���̓��o�͂̊�{�ƂȂ�N���X
	@note		���낢��ȂƂ��납�炱�̃N���X���p�����܂����A���̃N���X�P�̂ł��g�p�ł��܂��B

	@author		sue445
*/
#ifndef _INC_CRPGIOBASE
#define _INC_CRPGIOBASE

#include "CBerStream.h"
#include "CRpgArray.h"
#include "CRpgUtil.h"
#include <stdio.h>
#include <string>

using std::string;
/*
#ifndef FNAME_MAX32
#define FNAME_MAX32		512
#endif

#ifndef ZeroMemory
#define ZeroMemory(buf,size)	memset(buf, 0, size)
#endif

#define MAX_RPGNAME		21		///< �S�p10����
*/

/*
#pragma pack(push)
#pragma pack(1) //�\���̂̃����o���E��1�o�C�g�ɂ���

#ifndef POINT
/// ���W�\����
struct POINT{
	int x;	///< X�ʒu
	int y;	///< Y�ʒu
};
#endif

#pragma pack(pop)
*/

/// �c�N�[���n�t�@�C���̓��o�͂̊�{�ƂȂ�N���X
class CRpgIOBase : public CBerStream{
private:
	virtual const char* GetHeader(){ return ""; }		///< �t�@�C�����ʗp�̕�����(�p����Ŏw�肵�܂�)

protected:
	bool OpenFile(const char* szFile);					///< �t�@�C�����J��(���ʃ`�F�b�N�L��)
	bool bInit;											///< ����������Ă��邩�ǂ���

public:
	CRpgIOBase() : bInit(false){}						///< �R���X�g���N�^
	~CRpgIOBase(){}										///< �f�X�g���N�^

	smart_buffer	ReadData();							///< �f�[�^��ǂݍ���
	string			ReadString();						///< �������ǂݍ���
	bool			IsInit() const{ return bInit; }		///< ����������Ă��邩�ǂ���

	void ByteToBool(unsigned char num, bool flag[8]) const;	///< unsigned char -> bool�z��

	//=============================================================================
	/**
		2����smart_array��[y][x]�z��Ƃ݂Ȃ��ď���������

		@param	array		[out] smart_array�̓񎟌��z��
		@param	x			[in] X�����̗v�f��
		@param	y			[in] Y�����̗v�f��
	*/
	//=============================================================================
	template< class T >
	void InitArray2(smart_array< smart_array< T > >& array, int x, int y) const
	{
		array.Resize(y);
		for(int j = 0; j < y; j++){
			array[j].Resize(x);
		}
	}	///< 2����smart_array��[y][x]�z��Ƃ݂Ȃ��ď���������

	//=============================================================================
	/**
		�o�b�t�@�̒��g��2����smart_array�ɂԂ�����

		@param	array		[out] smart_array�̓񎟌��z��
		@param	buf			[in] ���͌��̃o�b�t�@
		@param	x			[in] X�����̗v�f��
		@param	y			[in] Y�����̗v�f��

		@retval	true		�z��̊i�[�ɐ���
		@retval	false		�z��̊i�[�Ɏ��s
	*/
	//=============================================================================
	template< class T >
	bool BufferToArray2(smart_array< smart_array< T > >& array, smart_buffer& buf, int x, int y) const
	{
		CBasicStream st;
		T data;

		// �Ȃ������������s
		if(!st.OpenFromMemory(buf, buf.GetSize()))	return false;

		// ���smart_array��������
		InitArray2(array, x, y);

		for(int j = 0; j < y; j++){
			for(int i = 0; i < x; i++){
				st.Read(&data, sizeof(T));
				array[j][i] = data;
			}
		}

		return true;
	}	///< �o�b�t�@�̒��g��2����smart_array�ɂԂ�����
};

#endif
