/**
	@file
	@brief		map�𗘗p�����������z��
	@author		sue445
*/
#ifndef _INC_CMAPTABLE
#define _INC_CMAPTABLE

#include "sueLib_Compile.h"
#include "CDimension.h"
#include <map>
using namespace std;

namespace sueLib {

template< class ValueType, unsigned int DIMENSION >
class CMapTable{
private:
	map< CDimension< DIMENSION >, ValueType >	m_Data;	///< �f�[�^�{��
	ValueType		m_Default;	///< �L�[��������Ȃ��������̏����l

public:
	/// �f�t�H���g�R���X�g���N�^
	CMapTable(){}

	//=============================================================================
	/**
		������

		@param		def	[in] �L�[��������Ȃ��������̏����l

		@note		�l�Ƀf�t�H���g�R���X�g���N�^����������Ă���Ύ��s����K�v�͖���\n
					�����܂Œl��int�Ȃǂ��w�肳�ꂽ���̋~�ύ�
	*/
	//=============================================================================
	void Init(ValueType def)
	{
		Release();
		m_Default = def;
	}

	//=============================================================================
	/**
		���
	*/
	//=============================================================================
	void Release()
	{
		m_Data.clear();
	}

	//=============================================================================
	/**
		�f�[�^�����݂��邩�ǂ���

		@retval	true		��������
		@retval	false		������Ȃ�����
	*/
	//=============================================================================
	bool IsExist(CDimension< DIMENSION > dim) const
	{
//		map< CDimension, ValueType >::const_iterator it = m_Data.find(dim);
		return (m_Data.find(dim) != m_Data.end());
	}

	//=============================================================================
	/**
		�f�[�^���Z�b�g����

		@param	dim			[in] ���W
		@param	bOverWrite	[in] true:�L�[���d�����Ă�����㏑������ / false:�L�[���d�����Ă���㏑�����Ȃ�
	*/
	//=============================================================================
	void Set(ValueType data, CDimension< DIMENSION > dim, bool bOverWrite=true)
	{
	//    map< CDimension< DIMENSION >,ValueType> mymapa;
	//	map<CDimension<DIMENSION>,ValueType>::const_iterator it = m_Data.find(dim);
//		map< CDimension< DIMENSION >,ValueType>::iterator it;
  //       it= m_Data.find(dim);
    	if((m_Data.find(dim)) == m_Data.end()){
			m_Data.insert( pair< CDimension< DIMENSION >, ValueType >(dim, data));
		}
		else if(bOverWrite){
			m_Data[dim] = data;
		}
	}

	//=============================================================================
	/**
		�f�[�^���擾����

		@param	dim			[in] ���W

		@return				�擾�����l(�L�[��������Ȃ��������͏����l��Ԃ�)
	*/
	//=============================================================================
	ValueType Get(CDimension< DIMENSION > dim) const
	{
	//	map< CDimension< DIMENSION >, ValueType >::const_iterator it = m_Data.find(dim);
		if( (m_Data.find(dim)) != m_Data.end())		return ((m_Data.find(dim))->second);
		return m_Default;
	}
};

} // end of namespace sueLib

#endif
