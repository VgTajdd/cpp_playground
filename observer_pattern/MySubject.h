#pragma once

#include "ISubject.h"

class MySubject : public ISubject
{
public:
	enum Messages { ADD, REMOVE };
};