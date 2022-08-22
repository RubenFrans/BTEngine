#pragma once
#include "Observer/Observer.h"
#include <set>

class Subject
{
public:
	void AddObserver(Observer* observer);
	void RemoveObserver(Observer* observer);
protected:
	void Notify(const BaseComponent& component, Event event);

private:
	std::set<Observer*> observers{};
};

