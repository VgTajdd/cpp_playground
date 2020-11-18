#ifndef I_OBSERVER_H_
#define I_OBSERVER_H_

class IObserver
{
public:
	virtual ~IObserver() {}
	virtual void Update( int message ) = 0;
};

#endif // !I_OBSERVER_H_