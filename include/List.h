#ifndef LIST_H
#define LIST_H

#include <vector>
using std::vector;
template <class T>
bool IsInList(vector<T>* List, T Obj)
{
	for (unsigned int i = 0; i < List->size(); i++)
		if (Obj == List->at(i))
			return true;
	return false;
}

template <class T>
void RemoveFromList(vector<T>* List, T Obj)
{
	for (unsigned int i = 0; i < List->size(); i++)
		if (Obj == List->at(i))
			List->erase(List->begin()+i);
}

#endif