#ifndef __INTSET_H__
#define __INTSET_H__
#include <vector>

class intset{
	public:
		void AddNumber(int num);
		void DeleteNumber(int num);

		int GetItem(int pos);
		std::vector<int> GetAll();
	private:
		std::vector<int> numbers_;
};

#endif
