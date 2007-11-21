/**
	@file
	@brief		Save??.lsd(LcfSaveData)���Ǘ�����N���X
	@author		sue445
*/
#ifndef _INC_CRPGLSD
#define _INC_CRPGLSD

#include "CRpgIOBase.h"

const int MAX_SAVEDATA = 15;		///maximo de saves



class CRpgLsd : public CRpgIOBase{
private:
	const char* GetHeader(){ return "LcfSaveData"; }	///< �t�@�C�����Ƃ̌ŗL�w�b�_(CRpgIOBase����I�[�o�[���C�h���Ďg���܂�)

public:
	CRpgArray1		ArrayLoading;						//< 0x64:�Z�[�u�f�[�^�I����ʂ̏��
    CRpgArray2		ArrayLoading2;	
struct Data{
	
		///< 0x01 arreglo
	string strName;		  ///< 0x0B nombre del save
int intlevel;		///< 0x0C nivel del heroe
int intHp;		///< 0x0D hp del heroe	
	string strNFP1;		  ///< 0x15 nombre faceset perso 1
int intIDFP1;	///< 0x16 id facet p1
	string strNFP2;		  ///< 0x17 nombre faceset perso 2
int intIDFP2;	///< 0x18 id facet p2
	string strNFP3;		  ///< 0x19 nombre faceset perso 3
int intIDFP3;	///< 0x1A id facet p3
	string strNFP4;		  ///< 0x1B nombre faceset perso 4
int intIDFP4;	 ///< 0x1C id facet p4
	//
}saData;//yo usaria vector

// informacion de parametros vairables tipe 0x65

struct VData{
 //npi
/*  1  tama�o 2 ?
   11  tama�o 2 //tentativa de variables
   32  tama�o 1
   34  tama�o 1
   71  tama�o 4 ?
   72  tama�o 4 ?
   73  tama�o 4 ?
   74  tama�o 4 ?
   75  tama�o 18 Musica
   76  tama�o 9 ??(OFF)
   77  tama�o 9 ??(OFF)
   78  tama�o 9 ??(OFF)
   79  tama�o 4 ?
   80  tama�o 4 ?
   81  tama�o 4 ?
   82  tama�o 4 ?
   91  tama�o 4 ?
   92  tama�o 4 ?
   93  tama�o 4 ?
   94  tama�o 4 ?
   95  tama�o 4 ?
   96  tama�o 4 ?
   97  tama�o 4 ?
   98  tama�o 4 ?
   99  tama�o 4 ?
   100  tama�o 4 ?
   101  tama�o 4 ?
   102  tama�o 4 ?
   111  tama�o 2 �
   112  tama�o 2 �
   113  tama�o 2 �
   114  tama�o 2 �
   115  tama�o 2 �
   116  tama�o 2 �
   125  //fondo de batalla
   131  tama�o 2 */
}saVData;//



/*//id 0x68// posicion de guardado
   11  id de mapa
   12  posicion en X
   13  posicion en Y
   21  direccion en la que mira
   22  direccion en la que mira?
   33  tama�o 2 ?
   35  tama�o 2
   37  tama�o 2 ?
   41  posicion de la imagen
   52  posicion de la imagen
   53  tama�o 2 ?
   73  nombre del cahra a mostrar
   75  tama�o 2 ?
   124  //cambia con la posicion 
   131  //cambia con la posicion 
   132  tama�o 3 �?*/
/*   //0x6A //0x69 //0x6B //vehiculos
   11  id de mapa
   12  posicion en x
   13  posicion en y
   21  tama�o 2 ?
   22  tama�o 2 ?
   33  tama�o 2 ?
   35  tama�o 2
   37  tama�o 2 ?
   41  tama�o 4 ?
   73  nombre del vehiculo 
   74  id de numero de imagen
   101  tama�o 2 ?*/
/*0x6C informacion del grupo 2
 filas 1 m columnas 1  tama�o 1  numero 1 ?
 filas 1 m columnas 2  tama�o 1  numero 1 ?
 filas 1 m columnas 31  tama�o 1  numero 18 ? //nivel
 filas 1 m columnas 32  tama�o 2  numero 7820 �?//exp
 filas 1 m columnas 33  tama�o 1  numero 0
 filas 1 m columnas 34  tama�o 1  numero 0
 filas 1 m columnas 51  tama�o 1  numero 1 
 filas 1 m columnas 52  tama�o 2  numero 49 
 filas 1 m columnas 61  tama�o 10 ?
 filas 1 m columnas 71  tama�o 2  numero 1338 //hp
 filas 1 m columnas 72  tama�o 1  numero 73 I//mp
 filas 1 m columnas 80  tama�o 28 ���������������
 filas 1 m columnas 81  tama�o 1  numero 10
 filas 1 m columnas 82  tama�o 20
*/   

/*0x6D // informacion de los objetos
  columnas 1  tama�o 1  numero 4 ?
  columnas 2  tama�o 8 ?
  columnas 11  tama�o 1  numero 4 //num obj
  columnas 12  tama�o 8 ?         //arreglo de objetoss
  columnas 13  tama�o 4  numero 1 ????
  columnas 14  tama�o 4  numero 0
  columnas 42  tama�o 1  numero 5 ?
  */ 

public:
	CRpgLsd(){}											///< �R���X�g���N�^
	~CRpgLsd(){}										///< �f�X�g���N�^

	bool Init(int nSaveNum, const char* szDir="");		///< ������
};

#endif
