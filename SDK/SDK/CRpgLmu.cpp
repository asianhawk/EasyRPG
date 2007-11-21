/**
	@file
	@brief		Map????.lmu(LcfMapUnit)���Ǘ�����N���X
	@author		sue445
*/
#include "CRpgLmu.h"
#include "CRpgEventStream.h"


//=============================================================================
/**
	������

	@param	nMapNum			[in] �}�b�v�t�@�C���ԍ�(1�`)
	@param	szDir			[in] �ǂݍ��ݐ�̃f�B���N�g��

	@retval	true			�}�b�v�t�@�C���̓ǂݍ��݂ɐ���
	@retval	false			�}�b�v�t�@�C���̓ǂݍ��݂Ɏ��s
*/
//=============================================================================
bool CRpgLmu::Init(int nMapNum, const CRpgLdb& ldb, const char* szDir)
{
	int type;
	char file[256];
	smart_buffer buf;
	string strFile;


	// si el mapa menor al id basico
	if(nMapNum<1)			return false;

	//si no esta inicializado
	if(!ldb.IsInit())		return false;

	sprintf(file, "Map%04d.lmu", nMapNum);

	bInit = false;
	strFile = "";
	if(strlen(szDir)){
		strFile += szDir;
		strFile += "\\";
	}
	strFile += file;

	if(!OpenFile(strFile.c_str()))		return false;

	//valores por defaul
	m_nChipSet = 1;
	m_nWidth   = 20;
	m_nHeight  = 15;
	m_strPanorama = "";

	while(!IsEof()){
		type = ReadBerNumber();
			 printf("\n el tipo %d",type);
        buf = ReadData();

		switch(type){
		case 0x01:		// Id de chipset
			m_nChipSet = CRpgUtil::GetBerNumber(buf);
			break;
		case 0x02:		// Ancho
			m_nWidth = CRpgUtil::GetBerNumber(buf);
			break;
		case 0x03:		// alto
			m_nHeight = CRpgUtil::GetBerNumber(buf);
			break; 
        case 0x0B:		// Type of loop
			m_nTypeloop= CRpgUtil::GetBerNumber(buf);
            break;
		case 0x1F:		// 	Parallax background	
			m_nBackground= CRpgUtil::GetBerNumber(buf);
            break;
    	case 0x20:		// Background name
			m_strPanorama = CRpgUtil::GetString(buf);
			break;	
		case 0x21:		// Horizontal pan	Stay still
			m_nHorizontalpan= CRpgUtil::GetBerNumber(buf);
            break;
		case 0x22:		// 	Vertical pan	Stay still
		    m_nVerticalpan= CRpgUtil::GetBerNumber(buf);
            break;
		case 0x23:		// 	Horiz. auto-pan	No
			m_nHorizontalautopan= CRpgUtil::GetBerNumber(buf);
            break;
		case 0x24:		// 	Horiz. pan speed
			m_nHorizontalpanspeed= CRpgUtil::GetBerNumber(buf);
            break;
		case 0x25:		// 		Vert. auto-pan	No
			m_nVerticalautopan= CRpgUtil::GetBerNumber(buf);
            break;	
        case 0x26:		// 	Vert. pan speed	0
			m_nVerticalpanspeed= CRpgUtil::GetBerNumber(buf);
            break;			
        case 0x2A:		// 	no scan yet
			break;	
        case 0x32:		// 	no scan yet
			break;	
        case 0x3C:		// 	no scan yet
			break;
        case 0x3D:		// 	no scan yet
			break;	  
        case 0x3E:		// 	no scan yet
			break;	           	            	
    	case 0x47:		// Lower layer tiles
			BufferToArray2(m_saLower, buf, m_nWidth, m_nHeight);
			break;
		case 0x48:		// Upper layer tiles
			BufferToArray2(m_saUpper, buf, m_nWidth, m_nHeight);
			break;
		case 0x51:		// Events
			GetMapEvent(buf);
			break;
		case 0x52:		//times saved
			break;
		}
	}

	strFile = "";
	if(strlen(szDir)){
		strFile += szDir;
		strFile += "\\";
	}
	strFile += "ChipSet\\";
	strFile += ldb.saChipSet[m_nChipSet].strFile;
//	imgChipSet.Load(strFile.c_str());//nocarges la imagen

	strFile = "";
	if(strlen(szDir)){
		strFile += szDir;
		strFile += "\\";
	}
	strFile += "Panorama\\";
	strFile += m_strPanorama;
//	imgPanorama.Load(strFile.c_str()); //no carges el panorama

	bInit = true;
	return true;
}

//=============================================================================
/**
	�}�b�v�C�x���g�f�[�^���擾

	@param	bufSrc		[in] ���f�[�^
*/
//=============================================================================
void CRpgLmu::GetMapEvent(smart_buffer& bufSrc)
{
	CRpgArray2	array;
	smart_buffer buf;


	array = CRpgUtil::GetArray2(bufSrc);
	int max_event = array.GetMaxRow();


	// �J�n�ԍ���1�Ȃ̂Ŕz��v�f����1���₵�Ă������������₷��
	saMapEvent.Resize(max_event+1);
	for(int i = 1; i <= max_event; i++){
		saMapEvent[i].strName	= array.GetString(i, 0x01);
		saMapEvent[i].x			= array.GetNumber(i, 0x02);
		saMapEvent[i].y			= array.GetNumber(i, 0x03);
		saMapEvent[i].data		= array.GetNumber(i, 0x04);

		// �}�b�v�C�x���g���y�[�W���Ƃɕ���
		CRpgArray2	array2a = CRpgUtil::GetArray2(array.GetData(i, 0x05));
		int max_page = array2a.GetMaxRow();
		saMapEvent[i].saPage.Resize(max_page+1);

		for(int j = 1; j <= max_page; j++){
			// �C�x���g�o������
			CRpgArray1 array1a = CRpgUtil::GetArray1(array2a.GetData(j, 0x02));
			saMapEvent[i].saPage[j].EventAppear.nFlag		= array1a.GetNumber(0x01);
			saMapEvent[i].saPage[j].EventAppear.nSw1		= array1a.GetNumber(0x02, 1);
			saMapEvent[i].saPage[j].EventAppear.nSw2		= array1a.GetNumber(0x03, 1);
			saMapEvent[i].saPage[j].EventAppear.nVarNum		= array1a.GetNumber(0x04, 1);
			saMapEvent[i].saPage[j].EventAppear.nVarOver	= array1a.GetNumber(0x05);
			saMapEvent[i].saPage[j].EventAppear.nItem		= array1a.GetNumber(0x06, 1);
			saMapEvent[i].saPage[j].EventAppear.nChara		= array1a.GetNumber(0x07, 1);
			saMapEvent[i].saPage[j].EventAppear.nTimer		= array1a.GetNumber(0x08);

			array2a.GetString(j, 0x15, saMapEvent[i].saPage[j].strWalk);
			saMapEvent[i].saPage[j].nWalkPos		= array2a.GetNumber(j, 0x16);
			saMapEvent[i].saPage[j].nWalkMuki		= array2a.GetNumber(j, 0x17);
			saMapEvent[i].saPage[j].nWalkPattern	= array2a.GetNumber(j, 0x18, 1);
			saMapEvent[i].saPage[j].bWalkHalf		= array2a.GetFlag(  j, 0x19, 1);
			saMapEvent[i].saPage[j].nStart			= array2a.GetNumber(j, 0x21, 1);

			// �C�x���g�f�[�^��1�s����vector�ɓ����
			buf = array2a.GetData(j, 0x34);
			CRpgEventStream st;
			if(st.OpenFromMemory(buf, buf.GetSize())){
				CRpgEvent event;
				while(st.ReadEvent(event)){
					saMapEvent[i].saPage[j].vctEvent.push_back(event);
				}
			}
		}
	}
}

//=============================================================================
/**
	(x,y)���W�̏�w�`�b�v�̃}�b�v�`�b�v���擾����

	@param	x				[in] x���W
	@param	y				[in] y���W
	@param	img				[out] �擾�����摜

	@retval	true			�`�b�v�̎擾�ɐ���
	@retval	false			�`�b�v�̎擾�Ɏ��s
*/
//=============================================================================
/*bool CRpgLmu::GetUpperChip(int x, int y, CRpgImage& img) const
{
	if(x<0 || x >= m_nWidth || y<0 || y>= m_nHeight)	return false;

	unsigned short chip = m_saUpper[y][x];
	int cx, cy;

	img.Create(CHIP_SIZE, CHIP_SIZE);
	img.CopyPalette(imgChipSet);
	if(chip>=10000 && chip<10144){
		GetChipPos(chip, true, &cx, &cy);
		img.Blt(imgChipSet, 0, 0, cx<<4, cy<<4, CHIP_SIZE, CHIP_SIZE, false);
		return true;
	}

	return false;
}*/

//=============================================================================
/**
	(x,y)���W�̉��w�`�b�v�̃}�b�v�`�b�v���擾����

	@param	x				[in] x���W
	@param	y				[in] y���W
	@param	anime			[in] �A�j���[�V�����ԍ�
	@param	img				[out] �擾�����摜


	@retval	true			�`�b�v�̎擾�ɐ���
	@retval	false			�`�b�v�̎擾�Ɏ��s
*/
//=============================================================================
/*bool CRpgLmu::GetLowerChip(int x, int y, int anime, CRpgImage& img) const
{
	if(x<0 || x >= m_nWidth || y<0 || y>= m_nHeight)	return false;

	int i, cx = 18, cy = 8, base_cx, base_cy;
	const unsigned short chip = m_saLower[y][x];
	const int nOffset[4][2] = {
		{0, 0},		// ����
		{8, 0},		// �E��
		{0, 8},		// ����
		{8, 8},		// �E��
	};
	img.Create(CHIP_SIZE, CHIP_SIZE);
	img.CopyPalette(imgChipSet);

	if(x==2 && y==6){
		printf("%02X\n", chip);
	}

	if(chip<3000){
		bool ocean_flag[4];

		
		//	0:��
		//	1:�l���ɐ[�C�Ƌ��E������
		//	2:�l���ɐ󐣂Ƌ��E�����[�C
		//	3:�[�C
		//
		int  ocean_type[4];

		GetOceanType(chip, ocean_flag);

		// �C�̃^�C�v�𒲂ׂ�
		// 0�`
		if(chip<1000){		// 	�C�ݐ��`�P(���ʂ̗�)
			base_cx = 0;
			base_cy = 0;
			for(i = 0; i < 4; i++){
				if(!ocean_flag[i])	ocean_type[i] = 0;
				else				ocean_type[i] = 1;
			}
		}
		// 1000�`
		else if(chip<2000){	// �C�ݐ��`�Q(��)
			base_cx = 3;
			base_cy = 0;
			for(i = 0; i < 4; i++){
				if(!ocean_flag[i])	ocean_type[i] = 0;
				else				ocean_type[i] = 1;
			}
		}
		// 2000�`
		else if(chip<3000){	// �C�ݐ��`�P(���ʂ̗�)
			base_cx = 0;
			base_cy = 0;
			for(i = 0; i < 4; i++){
				if(!ocean_flag[i])	ocean_type[i] = 3;
				else				ocean_type[i] = 2;
			}
		}

		// �x�[�X�ƂȂ�C���Z�b�g
		for(i = 0; i < 4; i++){
			int x = ((anime % 3)      <<4) + nOffset[i][0];
			int y = ((ocean_type[i]+4)<<4) + nOffset[i][1];
			img.Blt(imgChipSet, nOffset[i][0], nOffset[i][1], x, y, CHIP_SIZE>>1, CHIP_SIZE>>1, false);
		}

		/*
			00:�C�E�C�ݐ�����

			01:�C�ݐ��E����
			02:�C�ݐ��E�E��
			04:�C�ݐ��E�E��
			08:�C�ݐ��E����

			10:�C�ݐ��E��
			11:�C�ݐ��E���{�E��
			12:�C�ݐ��E���@�@�@�{�E��
			13:�C�ݐ��E���{�E��{�E��

			14:�C�ݐ��E��
			15:�C�ݐ��E��{�E��
			16:�C�ݐ��E��@�@�@�{����
			17:�C�ݐ��E��{�E���{����

			18:�C�ݐ��E�E
			19:�C�ݐ��E�E�{����
			1A:�C�ݐ��E�E�@�@�@�{����
			1B:�C�ݐ��E�E�{�����{����

			1C:�C�ݐ��E��
			1D:�C�ݐ��E���{����
			1E:�C�ݐ��E���@�@�@�{�E��
			1F:�C�ݐ��E���{����{�E��

			20:�C�ݐ��E���{�E
			21:�C�ݐ��E��{��

			�`�a
			�b�c
			22:�C�ݐ��E�`�a�b
			23:�C�ݐ��E�`�a�b�@�{�E��
			24:�C�ݐ��E�`�a�@�c
			25:�C�ݐ��E�`�a�@�c�{����
			26:�C�ݐ��E�@�a�b�c
			27:�C�ݐ��E�@�a�b�c�{����
			28:�C�ݐ��E�`�@�b�c
			29:�C�ݐ��E�`�@�b�c�{�E��
			2A:�C�ݐ��E�b�`�a�c
			2B:�C�ݐ��E�a�`�b�c
			2C:�C�ݐ��E�`�b�c�a
			2D:�C�ݐ��E�`�a�c�b
			2E:�C�ݐ��E��(�`�a�b�c)
		
		int chip2 = chip%50;

		enum{
			A,	// �l��
			B,	// �㉺
			C,	// ���E
			D,	// �l��

			OCEAN,	// �C�ݐ��Ȃ�(���̊C�`�b�v�����̂܂܍̗p)
		};
		int nChip[4] = {OCEAN, OCEAN, OCEAN, OCEAN};

		if(chip2<0x10){
			bool flag[8];
			ByteToBool((unsigned char)chip2, flag);
			if(flag[0])		nChip[0] = D;	// ����
			if(flag[1])		nChip[1] = D;	// �E��
			if(flag[2])		nChip[3] = D;	// �E��
			if(flag[3])		nChip[2] = D;	// ����
		}
		// 0x10�`
		else if(chip2<0x14){
			nChip[0] = nChip[2] = B;
			if(chip2 & 0x01)	nChip[1] = D;
			if(chip2 & 0x02)	nChip[3] = D;
		}
		// 0x14�`
		else if(chip2<0x18){
			nChip[0] = nChip[1] = C;
			if(chip2 & 0x01)	nChip[3] = D;
			if(chip2 & 0x02)	nChip[2] = D;
		}
		// 0x18�`
		else if(chip2<0x1C){
			nChip[1] = nChip[3] = B;
			if(chip2 & 0x01)	nChip[2] = D;
			if(chip2 & 0x02)	nChip[0] = D;
		}
		// 0x1C�`
		else if(chip2<0x20){
			nChip[2] = nChip[3] = C;
			if(chip2 & 0x01)	nChip[0] = D;
			if(chip2 & 0x02)	nChip[1] = D;
		}
		else if(chip2==0x20){
			nChip[0] = nChip[1] = nChip[2] = nChip[3] = B;
		}
		else if(chip2==0x21){
			nChip[0] = nChip[1] = nChip[2] = nChip[3] = C;
		}
		else if(chip2<=0x23){
			nChip[0] = A;
			nChip[2] = B;
			nChip[1] = C;
			if(chip2 & 0x01)	nChip[3] = D;
		}
		else if(chip2<=0x25){
			nChip[1] = A;
			nChip[3] = B;
			nChip[0] = C;
			if(chip2 & 0x01)	nChip[2] = D;
		}
		else if(chip2<=0x27){
			nChip[3] = A;
			nChip[1] = B;
			nChip[2] = C;
			if(chip2 & 0x01)	nChip[0] = D;
		}
		else if(chip2<=0x29){
			nChip[2] = A;
			nChip[0] = B;
			nChip[3] = C;
			if(chip2 & 0x01)	nChip[1] = D;
		}
		else if(chip2==0x2A){
			nChip[0] = nChip[1] = A;
			nChip[2] = nChip[3] = B;
		}
		else if(chip2==0x2B){
			nChip[0] = nChip[2] = A;
			nChip[1] = nChip[3] = C;
		}
		else if(chip2==0x2C){
			nChip[2] = nChip[3] = A;
			nChip[0] = nChip[1] = B;
		}
		else if(chip2==0x2D){
			nChip[1] = nChip[3] = A;
			nChip[0] = nChip[2] = C;
		}
	//	else if(chip2==0x2E){
		else{
			nChip[0] = nChip[1] = nChip[2] = nChip[3] = A;
		}

		// �C�ݐ���`��
		for(i = 0; i < 4; i++){
			if(nChip[i] != OCEAN){
				int x = ((base_cx + anime % 3)<<4) + nOffset[i][0];
				int y = ((base_cy + nChip[i]) <<4) + nOffset[i][1];
				img.Blt(imgChipSet, nOffset[i][0], nOffset[i][1], x, y, CHIP_SIZE>>1, CHIP_SIZE>>1, false);
			}
		}

		return true;
	}
	// 3000�`(3028)
	else if(chip<3050){
		// �b�P
		cx = 3;
		cy = 4;
		cy += anime % 4;
	}
	// 3050�`(3078)
	else if(chip<3100){
		// �b�Q
		cx = 4;
		cy = 4;
		cy += anime % 4;
	}
	// 3100�`(3128)
	else if(chip<3150){
		// �b�R
		cx = 5;
		cy = 4;
		cy += anime % 4;
	}
	// 3150�`
	else if(chip<3200){
		// �c�P
		cx = 0;
		cy = 8;
	}
	// 3200�`
	else if(chip<3250){
		// �c�Q
		cx = 3;
		cy = 8;
	}
	// 3250�`
	else if(chip<3300){
		// �c�R
		cx = 0;
		cy = 12;
	}
	// 3300�`
	else if(chip<3350){
		// �c�S
		cx = 3;
		cy = 12;
	}
	// 3350�`
	else if(chip<3400){
		// �c�T
		cx = 6;
		cy = 0;
	}
	// 3400�`
	else if(chip<3450){
		// �c�U
		cx = 9;
		cy = 0;
	}
	// 3450�`
	else if(chip<3500){
		// �c�V
		cx = 6;
		cy = 4;
	}
	// 3500�`
	else if(chip<3550){
		// �c�W
		cx = 9;
		cy = 4;
	}
	// 3550�`
	else if(chip<3600){
		// �c�X
		cx = 6;
		cy = 8;
	}
	// 3600�`
	else if(chip<3650){
		// �c�P�O
		cx = 9;
		cy = 8;
	}
	// 3650�`
	else if(chip<3700){
		// �c�P�P
		cx = 6;
		cy = 12;
	}
	// 3700�`
	else if(chip<3750){
		// �c�P�Q
		cx = 9;
		cy = 12;
	}
	// 3750�`
	else if(chip<4000);		// ���Ԃ񑶍݂��Ȃ�
	// 4000�`
	else if(chip<5000){
		// ���Έʒu(�A�`�G��A�`D)
		enum{
			A,
			B,
			C,
			D7,	// D�̓e���L�[�ƑΉ�
			D8,
			D9,
			D4,
			D5,
			D6,
			D1,
			D2,
			D3,
		};
		// ���Έʒu�����΍��W
		static const int nOffset2[12][2] = {
			{0, 0},
			{1, 0},
			{2, 0},
			{0, 1},
			{1, 1},
			{2, 1},
			{0, 2},
			{1, 2},
			{2, 2},
			{0, 3},
			{1, 3},
			{2, 3},
		};

		// 4000�`
		if(chip<4050){
			// �c�P
			base_cx = 0;
			base_cy = 8;
		}
		// 4050�`
		else if(chip<4100){
			// �c�Q
			base_cx = 3;
			base_cy = 8;
		}
		// 4100�`
		else if(chip<4150){
			// �c�R
			base_cx = 0;
			base_cy = 12;
		}
		// 4150�`
		else if(chip<4200){
			// �c�S
			base_cx = 3;
			base_cy = 12;
		}
		// 4200�`
		else if(chip<4250){
			// �c�T
			base_cx = 6;
			base_cy = 0;
		}
		// 4250�`
		else if(chip<4300){
			// �c�U
			base_cx = 9;
			base_cy = 0;
		}
		// 4300�`
		else if(chip<4350){
			// �c�V
			base_cx = 6;
			base_cy = 4;
		}
		// 4350�`
		else if(chip<4400){
			// �c�W
			base_cx = 9;
			base_cy = 4;
		}
		// 4400�`
		else if(chip<4450){
			// �c�X
			base_cx = 6;
			base_cy = 8;
		}
		// 4450�`
		else if(chip<4500){
			// �c�P�O
			base_cx = 9;
			base_cy = 8;
		}
		// 4500�`
		else if(chip<4550){
			// �c�P�P
			base_cx = 6;
			base_cy = 12;
		}
		// 4550�`
		else if(chip<4600){
			// �c�P�Q
			base_cx = 9;
			base_cy = 12;
		}

		/*
			00:������

			01:�l���E����
			02:�l���E�E��
			04:�l���E�E��
			08:�l���E����

			10:�W���E��
			11:�W���E���{�E��
			12:�W���E���@�@�@�{�E��
			13:�W���E���{�E��{�E��

			14:�W���E��
			15:�W���E��{�E��
			16:�W���E��@�@�@�{����
			17:�W���E��{�E���{����

			18:�W���E�E
			19:�W���E�E�{����
			1A:�W���E�E�@�@�@�{����
			1B:�W���E�E�{�����{����

			1C:�W���E��
			1D:�W���E���{����
			1E:�W���E���@�@�@�{�E��
			1F:�W���E���{����{�E��

			20:�W���E���{�E
			21:�W���E��{��

			// ��������n�`�`�b�v�Ǝ��K�i��||��
			22:�W���E����
			23:�W���E����{�l���E�E��

			24:�W���E�E��
			25:�W���E�E��{�l���E����

			26:�W���E�E��
			27:�W���E�E���{�l���E����

			28:�W���E����
			29:�W���E�����{�l���E�E��

			2A:�W��(����{�E��)
			2B:�W��(����{����)
			2C:�W��(�����{�E��)
			2D:�W��(�E��{�E��)
			2E:�W��(����{�E��{�����{�E��)
		
		int nChip[4] = {D5, D5, D5, D5};

		int chip2 = chip % 50;
		// 0x00�`
		if(chip2<0x10){
			bool flag[8];
			ByteToBool((unsigned char)chip2, flag);
			for(i = 0; i < 4; i++){
				if(flag[i])		nChip[i] = C;
			}
		}
		// 0x10�`
		else if(chip2<0x14){
			nChip[0] = nChip[2] = D4;
			if(chip2 & 0x01)	nChip[1] = C;
			if(chip2 & 0x02)	nChip[3] = C;
		}
		// 0x14�`
		else if(chip2<0x18){
			nChip[0] = nChip[1] = D8;
			if(chip2 & 0x01)	nChip[3] = C;
			if(chip2 & 0x02)	nChip[2] = C;
		}
		// 0x18�`
		else if(chip2<0x1C){
			nChip[1] = nChip[3] = D8;
			if(chip2 & 0x01)	nChip[2] = C;
			if(chip2 & 0x02)	nChip[0] = C;
		}
		// 0x1C�`
		else if(chip2<0x20){
			nChip[2] = nChip[3] = D2;
			if(chip2 & 0x01)	nChip[0] = C;
			if(chip2 & 0x02)	nChip[1] = C;
		}
		else if(chip2==0x20){
			nChip[0] = nChip[2] = D4;
			nChip[1] = nChip[3] = D6;
		}
		else if(chip2==0x21){
			nChip[0] = nChip[1] = D8;
			nChip[2] = nChip[3] = D2;
		}
		else if(chip2<=0x23){
			nChip[0] = nChip[1] = nChip[2] = nChip[3] = D7;
			if(chip2 & 0x01)	nChip[3] = C;
		}
		else if(chip2<=0x25){
			nChip[0] = nChip[1] = nChip[2] = nChip[3] = D9;
			if(chip2 & 0x01)	nChip[2] = C;
		}
		else if(chip2<=0x27){
			nChip[0] = nChip[1] = nChip[2] = nChip[3] = D3;
			if(chip2 & 0x01)	nChip[0] = C;
		}
		else if(chip2<=0x29){
			nChip[0] = nChip[1] = nChip[2] = nChip[3] = D1;
			if(chip2 & 0x01)	nChip[1] = C;
		}
		else if(chip2==0x2A){
			nChip[0] = nChip[2] = D7;
			nChip[1] = nChip[3] = D9;
		}
		else if(chip2==0x2B){
			nChip[0] = nChip[1] = D7;
			nChip[2] = nChip[3] = D1;
		}
		else if(chip2==0x2C){
			nChip[0] = nChip[2] = D1;
			nChip[1] = nChip[3] = D3;
		}
		else if(chip2==0x2D){
			nChip[0] = nChip[1] = D9;
			nChip[2] = nChip[3] = D3;
		}
	//	else if(chip2==0x2E){
		else{
			nChip[0] = D7;
			nChip[1] = D9;
			nChip[2] = D1;
			nChip[3] = D3;
		}

		// �`�b�v��`��
		for(i = 0; i < 4; i++){
			int x = ( (base_cx+nOffset2[nChip[i]][0])<<4 ) + nOffset[i][0];
			int y = ( (base_cy+nOffset2[nChip[i]][1])<<4 ) + nOffset[i][1];
			img.Blt(imgChipSet, nOffset[i][0], nOffset[i][1], x, y, CHIP_SIZE>>1, CHIP_SIZE>>1, false);
		}

		return true;
	}
	// 5000�`
	else{				// �u���b�N�d�E�W���`�b�v
		GetChipPos(chip, false, &cx, &cy);
	}


	// cx,cy�����W�Ƃ��č̗p����(4�������Ȃ��`�b�v)
	img.Blt(imgChipSet, 0, 0, cx<<4, cy<<4, CHIP_SIZE, CHIP_SIZE, false);

	return true;
}
*/
//=============================================================================
/**
	�C�̃^�C�v���擾(����A�E��A�����A�E���̏�)

	@note					
							

	@param	chip			[in] �`�b�v�ԍ�
	@param	bOcean			[out]	�󐣂̎�(false:�󐣁^true:�l���ɐ[�C�Ƌ��E������)\n
									�[�C�̎�(false:�[�C�^true:�l���ɐ󐣂Ƌ��E�����[�C)
*/
//=============================================================================
void CRpgLmu::GetOceanType(unsigned short chip, bool bOcean[4]) const
{
	unsigned int mask = 1;
	const unsigned short chip2 = chip % 800 / 50;

	for(int i = 0; i < 4; i++){
		bOcean[i] = ((chip2 & mask)!=0);
		mask <<= 1;
	}
}

//=============================================================================
/**
	�`�b�v�ԍ�������W���擾

	@param	nChip			[in] �`�b�v�ԍ�
	@param	bUpper;			[in] true:��w�`�b�v�^false:���w�`�b�v
	@param	lpX				[out] x���W
	@param	lpY				[out] y���W
*/
//=============================================================================
void CRpgLmu::GetChipPos(int nChip, bool bUpper, int* lpX, int* lpY) const
{
	// �`�b�vID��ChipSet���̑���ID(?)�ɂ���
	int chip;
	if(bUpper)	chip = nChip - 10000 + 336;		// 48*7
	else		chip = nChip - 5000  + 192;		// 48*4;

	// ��6�}�X�̃`�b�v�Ɋ��Z�������̍��W
	int pos_x = chip % 6;
	int pos_y = chip / 6;

	// 6x8�̃u���b�N���Ƃɕ��������̃u���b�N�̍��W
	// �Z�o���悤�Ƃ���Ƃǂ����Ă���Z�������Ă��Ēx���Ȃ肻���Ȃ̂�if�ŕ���(��
	int block_x, block_y;
	if     (pos_y<8){	block_x = 0;  block_y = 0; }
	else if(pos_y<16){	block_x = 0;  block_y = 8; }
	else if(pos_y<24){	block_x = 6;  block_y = 0; }
	else if(pos_y<32){	block_x = 6;  block_y = 8; }
	else if(pos_y<40){	block_x = 12; block_y = 0; }
	else if(pos_y<48){	block_x = 12; block_y = 8; }
	else if(pos_y<56){	block_x = 18; block_y = 0; }
	else if(pos_y<64){	block_x = 18; block_y = 8; }
	else if(pos_y<72){	block_x = 24; block_y = 0; }
	else			{	block_x = 24; block_y = 8; }

	*lpX = block_x +  pos_x;
	*lpY = block_y + (pos_y & 0x07);
}
