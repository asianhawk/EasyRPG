/**
	@file
	@brief		�X�g���[��������Ƀo�b�t�@���璼�ڃf�[�^�𑀍삷��
	@author		sue445
*/
#include "CRpgUtil.h"
#include "CRpgIOBase.h"


//=============================================================================
/**
	�o�b�t�@���璼�ڃf�[�^���擾

	@param	buf			[in] ���͌��o�b�t�@

	@return				�擾�����o�b�t�@
*/
//=============================================================================
smart_buffer CRpgUtil::GetData(const smart_buffer& buf)
{
	CRpgIOBase st;
	smart_buffer temp;

	return (st.OpenFromMemory(buf.GetConstPtr(), buf.GetSize())) ? st.ReadData() : temp;
}

//=============================================================================
/**
	�o�b�t�@���當������擾

	@param	buf			[in] ���͌��o�b�t�@

	@return				�擾����������
*/
//=============================================================================
string CRpgUtil::GetString(const smart_buffer& buf)
{
	CRpgIOBase st;

	return (st.OpenFromMemory(buf.GetConstPtr(), buf.GetSize())) ? st.ReadString() : "";
}

//=============================================================================
/**
	�c�N�[���d�l��1�����z���ǂݍ���

	@param	buf		[in] ���͌��o�b�t�@

	@return			�擾����1�����z��
*/
//=============================================================================
CRpgArray1 CRpgUtil::GetArray1(const smart_buffer& buf)
{
	int col,size=0;
	CRpgIOBase		st;
	CRpgArray1		array;


	// �o�b�t�@������������Ă��Ȃ�
	if(buf.GetSize()==0)		return array;

	// �ǂݍ��ݗp�X�g���[���̏�����
	st.OpenFromMemory(buf.GetConstPtr(), buf.GetSize());

	// �f�[�^���i�[����
	while(!st.IsEof()){
		col = st.ReadBerNumber();
	//	printf("\n  columnas %d ",col); 
		if(col==0)	break;
		array.SetData(col, st.ReadData());
		size=(array.GetString(col)).size();
   //     printf(" tama�o %d ",size); 
     //   if(size<5)
    //    printf(" numero %d ",array.GetNumber(col));
    //    printf((array.GetString(col)).c_str());
	}

	return array;
}

//=============================================================================
/**
	�c�N�[���d�l��2�����z���ǂݍ���

	@param	buf		[in] ���͌��o�b�t�@

	@return			�擾����2�����z��
*/
//=============================================================================
CRpgArray2 CRpgUtil::GetArray2(const smart_buffer& buf)
{
	int row, col, max,size;
	CRpgIOBase		st;
	CRpgArray2		array;
	// �o�b�t�@������������Ă��Ȃ�
	if(buf.GetSize()==0)		return array;
	// �ǂݍ��ݗp�X�g���[���̏�����
	st.OpenFromMemory(buf.GetConstPtr(), buf.GetSize());
	// ��ԍŏ��ɂ͔z��̃T�C�Y���i�[����Ă���
	max = st.ReadBerNumber();
	// �f�[�^���i�[����
	while(!st.IsEof()){
		row = st.ReadBerNumber();
		for(;;){
			col = st.ReadBerNumber();
	//		printf("\n  filas %d m columnas %d ",row,col); 
			if(col==0)	break;
			array.SetData(row, col, st.ReadData());
		size= (array.GetString(row,col)).size();
	//	printf(" tama�o %d ",size); 
     //   if(size<5)
      //  printf(" numero %d ",array.GetNumber(row,col));
      //  printf((array.GetString(row,col)).c_str());
		}
	}

	return array;
}

int CRpgUtil::get_set_sizeused(int size, bool rw)
{ static int  sizeused=0;
 if(rw)//verdadero lee
return (sizeused);
else//falso escribe
{sizeused=size;
return (sizeused);
}

}


CRpgArray2 CRpgUtil::GetArray2_1(const smart_buffer& buf)//aqui esta la salvacion
{
	int row, col, max,actual;
	CRpgIOBase		st;
	CRpgArray2		array;
    bool exit =false;
    int size=0;
	// si el tam�o es insuficiente
	if(buf.GetSize()==0)		return array;
	// �ǂݍ��ݗp�X�g���[���̏�����
	st.OpenFromMemory(buf.GetConstPtr(), buf.GetSize());
     // printf("\n  constante %d  tama�o %d ",buf.GetConstPtr(), buf.GetSize()); 
	// saca el maximo del archivo
    //	max = st.ReadBerNumber();

	// �f�[�^���i�[����
	while((!st.IsEof())&&(!exit)) {
		row = st.ReadBerNumber();
		size++;
        for(;;){
			col = st.ReadBerNumber();
			size++;
          //  printf("\n  filas %d m columnas %d ",row,col); 
			if(col==0)	break;
			array.SetData(row, col, st.ReadData());
		//	printf(((array.GetString(row,col)).c_str()));
	        actual=(array.GetString(row,col)).size();
          //  printf(" tama�o %d ",actual); 
            size=size+actual+1;
            //   printf(" tama�o acumulado %d ",size); 
          
       //     if(actual<5)
       // printf(" numero %d ",array.GetNumber(row,col));
        
            if(col==51){
            exit=true;
            break;}// si lees el ultimo dato
    	}
	}
 get_set_sizeused(size,0);
	return array;
}
