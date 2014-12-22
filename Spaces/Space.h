#ifndef SPACE_H
#define SPACE_H

class Space
{
public:


	/* The derived Space will have to write out specialized versions of this for every subspace it contains. Oh well, what can ya do. */
	template <typename SubSpc>
	Subspace *getSubspace();

	template <typename SubSpc, typename Comp>
	void addComponent(unsigned int objid)
	{
		
	}

};

#endif