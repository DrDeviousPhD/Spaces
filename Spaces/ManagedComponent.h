#ifndef MANAGED_COMPONENT_H
#define MANAGED_COMPONENT_H

/* Could this be aggregate? http://stackoverflow.com/questions/4178175/what-are-aggregates-and-pods-and-how-why-are-they-special */

#include <memory>
using namespace std;

/* Handles components of any type. Manages their lifetime, sterilizes data, etc. */
/* Most systems should only handle ManagedComponents, I suppose. Would that be ineffecient? I dunno. */
template <typename CompType>
class ManagedComponent
{
public:
	
	bool _managed_correctly; /* For handling whenever a component is not correctly managed. Defaults to true, but manager passes false if necessary. */
	shared_ptr<CompType> _component; /* Should this be shared or unique? */


	CompType& getComponent()
	{
		return _component.get();
	}

	ManagedComponent() : _managed_correctly(true) {}
	ManagedComponent(bool managed_correctly) : _managed_correctly(managed_correctly) {}
};

#endif