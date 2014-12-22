#include <iostream>
#include <string>
using namespace std;

#include "Subspace.h"

class cChar : public Component
{
public:
	string charname;

	int health;

	cChar() : charname("The Hero"), health(100) {}
};

class cBoss : public Component
{
public:
	string bossname;

	int health;

	cBoss() : bossname("The Villian"), health(200) {}
};

class cNotused : public Component
{
public:

	int dummy;

	cNotused() : dummy(10) {}

};

class Sub : public Subspace
{
public:

	Sub()
	{
		/* Tell Sub to handle cChar and cBoss */
		addCompType<cChar>();
		addCompType<cBoss>();
	}

};

int main()
{
	cout << "Character id: " << ComponentID::getID<cChar>() << endl;
	cout << "Boss id: " << ComponentID::getID<cBoss>() << endl;

	cout << "Adding them to a subspace." << endl;

	Sub test;
	cout << test.addComponent<cChar>(0) << endl;
	cout << test.addComponent<cBoss>(1) << endl;

	cout << test.getComponent<cChar>(0).charname << endl;
	cout << test.getComponent<cBoss>(1).bossname << endl;

	cout << "Hero attacks the villain for 50 damage: " << endl;
	test.getComponent<cBoss>(1).health -= 50;
	cout << "New health: " << test.getComponent<cBoss>(1).health << endl;

	/*cout << "Trying to get a component that we don't handle: " << endl;
	cNotused& nu = test.getComponent<cNotused>(0);
*/
	cin.get();

	return 0;
}