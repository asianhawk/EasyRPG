/**
	@file
	@brief		CBasicStream�𗘗p����BER���k�����̓��o�́B\n
				BER���k�����ɂ��Ă͂��̕ӂŁB\n
				http://www.stellar.ac/~komai/unix/ber/index.html

	@author		sue445
*/
#include "CBerStream.h"
#include "CBer.h"


//=============================================================================
/**
	�X�g���[������BER���k������1���o��

	@param	lpReadByte		[out] �X�g���[������ǂݍ��񂾃o�C�g�����Ԃ�(NULL�w�莞�͕Ԃ�Ȃ�)

	@return					BER���k�����𕁒ʂ̐����ɒ������l
*/
//=============================================================================
int CBerStream::ReadBerNumber(int* lpReadByte) // el espasio se deside en base a esto
{
	unsigned char c;
	int data = 0, readbyte = 0;


	while(!IsEof()){
		if(Read(&c, 1)==0)	break;// si el caracter es 0 termina
		readbyte++; //si no aumenta el numero leido

	 
		// 1000 0000 & c
		// para darse la condicion c tiene que ser menor a 0x80 0XXX XXXX 
		if((c & 0x80)==0){
			data = (data<<7) + c;
//		printf("d %d ",c);
        	//c
			// mas el ultimo digito posicionado en la primera poscion
			break;//terimana
		}
		else{
			data = (data<<7) + (c & 0x7F);
//			printf("dp %d ",c);
			//  0111 1111 & c
			// deja pasar todo menos el primer digito
			// mas el ultimo digito posicionado en la primera poscion
		}
	}

	//si el lpReadByte es cero retorna el pointer de readbyte
	if(lpReadByte)	*lpReadByte = readbyte;

	return data; //retorna la direccion final
}

//=============================================================================
/**
	BER���k������1�����o��

	@param	nData	[in] �ϊ����̐���
	@param	bCalc	[in] true�̎��͕K�v�T�C�Y�̌v�Z�������s���X�g���[���ɂ͏����o���Ȃ�

	@return			�X�g���[���ɏ����o�����o�C�g��(�X�g���[���ɏ����o���̂ɕK�v�ȃo�C�g��)
*/
//=============================================================================
int CBerStream::WriteBerNumber(int nData, bool bCalc)
{
	// BER�̍\�����x�o�b�t�@�ɏ����o���Ă����K�v������
	smart_buffer buf = CBer::SetBerNumber(nData);
	if(buf.GetSize()>0 && !bCalc){
		Write(buf, buf.GetSize());
	}

	return buf.GetSize();
}

