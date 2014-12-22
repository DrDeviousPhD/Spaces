#ifndef COMPONENT_H
#define COMPONENT_H

namespace ComponentID
{
	static unsigned int _next_comp_id = 0;

	template <typename CompType>
	class CompID
	{
	public:
		static unsigned int _compid;
	};

	template <typename CompType> unsigned int CompID<CompType>::_compid(_next_comp_id++);

	template <typename CompType>
	unsigned int getID() { return CompID<CompType>::_compid; }
}

class Component
{
public:
};

#endif