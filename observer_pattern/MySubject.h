#ifndef MY_SUBJECT_H_
#define MY_SUBJECT_H_

#include "ISubject.h"

class MySubject : public ISubject
{
public:
	enum Messages { ADD, REMOVE };
};

#endif // !MY_SUBJECT_H_