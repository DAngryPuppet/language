#include <iostream>

#include "four_generic_programming.h"


inline bool TriangulayIterator::operator == (const TriangulayIterator &rhs)const
{
	return (index_ == rhs.index_);
}

inline bool TriangulayIterator::operator!=(const TriangulayIterator &rhs)const
{
	return !(*this == rhs);
}

inline bool TriangulayIterator::operator*()const
{

}

TriangulayIterator& TriangulayIterator::operator++()//prepose.
{

}

TriangulayIterator TriangulayIterator::operator++(int)//postfix.
{

}
