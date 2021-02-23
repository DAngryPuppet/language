#ifndef __FOUR_GENERIC_PROGRAMMING_H
#define __FOUR_GENERIC_PROGRAMMING_H

class TriangulayIterator
{
public:
	TriangulayIterator(int index){ index_ = index; }
	bool operator==(const TriangulayIterator &)const;
	bool operator!=(const TriangulayIterator &)const;
	bool operator*()const;
	TriangulayIterator& operator++();//prepose.
	TriangulayIterator operator++(int);//postfix.

private:
	void CheckIntegrity()const;
	int index_;

};

#endif