#pragma once

#include <iostream>

#include "IObserver.h"

class MyObserver : public IObserver
{
public:
	explicit MyObserver( const std::string& str ) :
		mName( str )
	{}
	void Update( int message )
	{
		std::cout << mName << " Received message ";
		std::cout << message << std::endl;
	}

private:
	std::string mName;
};
