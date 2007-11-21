/**
	@file
	@brief		Map????.lmu(LcfMapUnit)���Ǘ�����N���X
	@author		sue445
*/
#ifndef _INC_CRPGLMU
#define _INC_CRPGLMU

#include "CRpgIOBase.h"
#include "CRpgEvent.h"
#include "CRpgLdb.h"


const int CHIP_SIZE = 16;	///< �`�b�v�T�C�Y

/// MapXXXX.lmu(LcfMapUnit)
class CRpgLmu : public CRpgIOBase{
private:
	const char* GetHeader(){ return "LcfMapUnit"; }	///< �t�@�C�����Ƃ̌ŗL�w�b�_(CRpgIOBase����I�[�o�[���C�h���Ďg���܂�)

	int m_nChipSet;			 ///< 0x01: id de chipset
	int m_nWidth;		   	 ///< 0x02: ancho(defaul l:20)
	int m_nHeight;			 ///< 0x03: alto (default l:15)
	int m_nTypeloop;         ///< 0x0B: type of loop
	int m_nBackground;       ///< 0x1F: Parallax background	
	string	m_strPanorama;	 ///< 0x20: cadena panurama
	int m_nHorizontalpan;    ///< 0x21: Horizontal pan	Stay still
	int m_nVerticalpan;		 ///< 0x22: Vertical pan	Stay still
	int m_nHorizontalautopan;///< 0x23: Horiz. auto-pan	No
    int m_nHorizontalpanspeed;//< 0x24:	Horiz. pan speed
	int m_nVerticalautopan;	  //< 0x25:	Vert. auto-pan	No
	int m_nVerticalpanspeed; ///< 0x26:	Vert. pan speed	0		   

	// Las capas, inferior y superior
	smart_array< smart_array< unsigned short > >	m_saUpper;		///< 0x47:��w�}�b�v
	smart_array< smart_array< unsigned short > >	m_saLower;		///< 0x47:���w�}�b�v

//	CRpgImage imgChipSet;	///< imgaen de chipset
//	CRpgImage imgPanorama;	///< imagne panorama

public:
	//estructura de los eventeos de mapa
	struct MAPEVENT{
		MAPEVENT(): x(0), y(0){}		///< �f�t�H���g�R���X�g���N�^

		string strName;					///< 0x01:���O
		int  x;							///< 0x02:X���W
		int  y;							///< 0x03:Y���W
		int  data;						///< 0x04:�s��(�L�E�ցE�M)

		/// �y�[�W�P�ʂł̃}�b�v�C�x���g
		struct MAPEVENT_PAGE{
			MAPEVENT_PAGE():
				nWalkPos(0), nWalkMuki(0), nWalkPattern(1), bWalkHalf(false), nStart(0){}	///< �R���X�g���N�^

			struct EVENTAPPEAR{
				EVENTAPPEAR():
					nSw1(1), nSw2(1), nVarNum(1), nVarOver(0), 
					nItem(1), nChara(1), nTimer(0){}		///< �R���X�g���N�^

				/**
					0�r�b�g��:���X�C�b�`[%04d:%s]��ON(1)\n
					1�r�b�g��:���X�C�b�`[%04d:%s]��ON(2)\n
					2�r�b�g��:���ϐ�[%04d:%s]�̒l��[%d]�ȏ�\n
					3�r�b�g��:���A�C�e��[%04d:%s]������\n
					4�r�b�g��:����l��[%04d:%s]������\n
					5�r�b�g��:���^�C�}�[[%d��%02�b]�ȉ�
				*/
				int nFlag;		///< 0x01:�`�F�b�N�{�b�N�X�̃`�F�b�N���(6�r�b�g�t���O)

				int nSw1;		///< 0x02:�X�C�b�`(1)		�����l:1
				int nSw2;		///< 0x03:�X�C�b�`(2)		�����l:1
				int nVarNum;	///< 0x04:�ϐ��ԍ�			�����l:1
				int nVarOver;	///< 0x05:�ϐ����`�ȏ�
				int nItem;		///< 0x06:�A�C�e���`������	�����l:1
				int nChara;		///< 0x07:��l���`������	�����l:1
				int nTimer;		///< 0x08:�^�C�}�[(�b)

			} EventAppear;						///< 0x02:�o������

			// ���s�G�֘A
			string	 strWalk;					///< 0x15:�t�@�C����

			/**
				���s�G�̎�:���ォ�珇��0�`7\n
				�`�b�v�Z�b�g�̎�:��w�`�b�v�̈ʒu\n
				�����s�G����w�`�b�v���̓t�@�C���������邩�ǂ����Ŕ��f
			*/
			int nWalkPos;						///< 0x16:���s�G(��w�`�b�v)�̈ʒu

			/**
				0:��\n
				1:�E\n
				2:��\n
				3:��
			*/
			int nWalkMuki;						///< 0x17:����

			/**
				0:LEFT\n
				1:MIDDLE(�����l�H)\n
				2:RIGHT
			*/
			int nWalkPattern;					///< 0x18:���s�p�^�[��

			bool bWalkHalf;						///< 0x19:���������ǂ���

			/**
				0:������L�[�������ꂽ�Ƃ�\n
				1:����l������G�ꂽ�Ƃ�\n
				2:���C�x���g����G�ꂽ�Ƃ�\n
				3:�������I�Ɏn�܂�\n
				4:������I�ɕ��񏈗�����
			*/
			int nStart;							///< 0x21:�J�n����

//			int nEventDataSize;					///< 0x33:�C�x���g�f�[�^�T�C�Y
			vector< CRpgEvent > vctEvent;		///< 0x34:�C�x���g�f�[�^�{��

		};	// end of struct MAPEVENT_PAGE
		smart_array< MAPEVENT_PAGE > saPage;	///< 0x05:�}�b�v�C�x���g

	};	// end of struct MAPEVENT
	smart_array< MAPEVENT >	saMapEvent;			///< �}�b�v�C�x���g���ꊇ�i�[

public:
	CRpgLmu(){}															///< costructor 
	~CRpgLmu(){}														///< destructor

	bool Init(int nMapNum, const CRpgLdb& ldb, const char* szDir="");	///< inizializador
//	bool GetUpperChip(int x, int y, CRpgImage& img) const;				///< ��w�`�b�v���擾
//	bool GetLowerChip(int x, int y, int anime, CRpgImage& img) const;	///< ���w�`�b�v���擾

	int GetChipSet()	const{ return m_nChipSet; }						///< id de chipset
	int GetWidth()		const{ return m_nWidth;   }						///< ancho
	int GetHeight()		const{ return m_nHeight;  }						///< alto

private:
	void GetMapEvent(smart_buffer& bufSrc);								///< �}�b�v�C�x���g���擾
	void GetOceanType(unsigned short chip, bool bOcean[4]) const;		///< �`�b�v�ԍ�����C�^�C�v�𔻕�
	void GetChipPos(int nChip, bool bUpper, int* lpX, int* lpY) const;	///< �`�b�v�ԍ�����ChipSet���̍��W���擾
};

#endif
