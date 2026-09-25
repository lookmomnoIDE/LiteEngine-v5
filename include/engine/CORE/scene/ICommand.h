#ifndef ICOMMAND_H
#define ICOMMAND_H

#include <string>

enum class Name
{
	NONE,
	LMB,
	ESC,
	P,
	O,
	SPACE,
	F3,
	COUNT
};


enum class Type
{
	NONE,
	START,
	STOP,
	COUNT	
};


class Action
{
	Name m_name = Name::NONE;
	Type m_type = Type::NONE;	
public:
	Action(Name name, Type type)
		:m_name(name), m_type(type){}
	virtual ~Action() = default;
	const Name name() const {return m_name;}
	const Type type() const {return m_type;}

};



#endif