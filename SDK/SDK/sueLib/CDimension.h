/**
	@file
	@brief		�������\����
	@author		sue445
*/
#ifndef _INC_CDIMENTION
#define _INC_CDIMENTION

namespace sueLib {

typedef int DimType;

template< unsigned int DIMENSION > class CDimension;

//=============================================================================
/**
	�������\����(1�����p)

	@note	CDimension�e���v���[�g�̕����I�Ȓ�`
*/
//=============================================================================
template<>
class CDimension< 1 >{
private:
	DimType						x;		///< �����̎����̍��W

public:
	CDimension(DimType _x=0) : x(_x){}	/// �f�t�H���g�R���X�g���N�^

	operator DimType() const{ return x; }
//	friend CDimension;
};

//=============================================================================
/**
	�������\����(n�����p)

	@note	CDimension�e���v���[�g�̈�ʓI�Ȓ�`
*/
//=============================================================================
template< unsigned int DIMENSION >
class CDimension{
private:
	DimType						x;		///< �����̎����̍��W
	CDimension< DIMENSION - 1 >	y;		///< 1���̎���

public:
	CDimension(DimType _x=0, ...) : x(_x), y(*((&_x)+1)){}	/// �f�t�H���g�R���X�g���N�^

	// ��r���Z�q(2������������Ύc��4�̓R�s�y�ł�����)
	bool operator==(const CDimension& obj) const{ return (x==obj.x && y==obj.y); }
	bool operator< (const CDimension& obj) const{
		return (x==obj.x) ? (y<obj.y) : (x<obj.x);
	}
	bool operator!=(const CDimension& obj) const{ return !(*this==obj); }
	bool operator<=(const CDimension& obj) const{ return (*this==obj || *this<obj); }
	bool operator>=(const CDimension& obj) const{ return !(*this<obj); }
	bool operator> (const CDimension& obj) const{ return !(*this<=obj); }

//	friend CDimension;
};

typedef CDimension< 1 >	CDim1;		///< 1����
typedef CDimension< 2 >	CDim2;		///< 2����
typedef CDimension< 3 >	CDim3;		///< 3����

} // end of namespace sueLib

#endif
