#ifndef SUBSPACE_H
#define SUBSPACE_H

#include <vector>
#include <map>
#include <unordered_map>
#include <memory>
using namespace std;

#include "Component.h"

class Space;

class Subspace
{
public:

	Space* _parent_space;

	/* Instead of using a map, maybe we use a vector or list? That way we can define which component types we handle. I dunno. */

	/* <type's id #, map < objectid, pointer to component>>*/
	unordered_map<unsigned int, unordered_map<unsigned int, Component*>> _components;


protected:

	/* Lets us handle a new component type */
	template <typename CompType>
	bool addCompType()
	{
		/* Do we already handle this type */
		for (auto it = _components.begin(); it != _components.end(); it++)
		{
			if (it->first == ComponentID::getID<CompType>())
				return false;
		}

		/* Insert a pair for that comonent type to a new map */
		_components.insert(make_pair(ComponentID::getID<CompType>(), unordered_map<unsigned int, Component*>()));
		cout << "New size: " << _components.size() << endl;

		return true;
	}

public:

	template <typename CompType>
	bool hasComponent(unsigned int objid)
	{
		/* Does this subspace even have that type */
		for (auto it = _components.begin(); it != _components.end(); it++)
		{
			if (it->first == ComponentID::getID<CompType>())
			{
				/* Check if there's a component of that type attached to objid */
				for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
				{
					if (it2->first == objid)
						return true;
				}
			}
		}
		return false;
	}

	template <typename CompType>
	bool addComponent(unsigned int objid)
	{
		/* Copy/Paste from hasComponent because I'm a bad coder and I think it's better to not loop through the map twice for no reason. */
		
		/* Do we handle this type? If not, return cErrorType component */
		for (auto it = _components.begin(); it != _components.end(); it++)
		{
			if (it->first == ComponentID::getID<CompType>())
			{
				/* Check if there's a component of that type attached to objid */
				for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
				{
					/* We already have that component on that object - throw exception? */
					if (it2->first == objid)
						return false;
				}

				/* Add a component of CompType to _components */
				_components[ComponentID::getID<CompType>()][objid] = new CompType();
				return true;

			}
		}
		return false;
	}
	
	/* Should this return a pointer instead? Probably yes. Alternatively we could use something like boost::optional .. or have a variable inside Component that can flag a component as not initalizing properly */
	template <typename CompType>
	CompType& getComponent(unsigned int objid)
	{
		if (hasComponent<CompType>(objid))
			return *static_cast<CompType*>(_components.at(ComponentID::getID<CompType>()).at(objid));
		else
			retu
			//return *static_cast<CompType*>(_components[ComponentID::getID<CompType>()][objid]);
	}

};

#endif