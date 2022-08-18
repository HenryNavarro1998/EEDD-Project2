#ifndef DeltaList_hpp
#define DeltaList_hpp

#include "../List/List.hpp"

using namespace std;

class DeltaList : public List{

	friend ostream& operator<<(ostream&,const DeltaList&);

	public:
		DeltaList(): List(){};
		~DeltaList(){ while(List::pop()); };

		bool push(const Client&);
		bool pop(){ List::pop(); };
	
};

ostream& operator<<(ostream&,const DeltaList&);

#endif