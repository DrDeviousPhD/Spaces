#ifndef OBJECT_H
#define OBJECT_H

class Space;

class Object
{
public:
	
	Space *_parent_space;
	unsigned int _objid;


public:

	Object(Space *parent, unsigned int objid) : _parent_space(parent), _objid(objid) {}

public:

	/* Helpers */

	template <typename SubSpc, typename Comp>
	void addComponent()
	{
		/* Just calls Space's addComponent() */
		_parent_space->addComponent<SubSpc, Comp>(_objid);
	}


};

#endif