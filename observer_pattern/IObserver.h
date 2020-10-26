#pragma once

class IObserver
{
public:
	virtual ~IObserver() {}
	virtual void Update( int message ) = 0;
};