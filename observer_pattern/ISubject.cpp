#include "ISubject.h"
#include "IObserver.h"

void ISubject::Subscribe( int message, IObserver* observer )
{
	mObservers[message].push_back( observer );
}

void ISubject::Unsubscribe( int message, IObserver* observer )
{
	auto it = std::find( mObservers[message].begin(), mObservers[message].end(), observer );
	mObservers[message].erase( it );
}

void ISubject::Notify( int message )
{
	for ( const auto& iObs : mObservers[message] )
	{
		iObs->Update( message );
	}
}