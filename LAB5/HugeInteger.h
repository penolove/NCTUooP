#include <string>
#ifndef HUGEINTEGER_H
#define HUGEINTEGER_H
class HugeInteger
{
	public:
		HugeInteger();
		HugeInteger(int a);
		HugeInteger(std::string a);
		HugeInteger(const HugeInteger &a);
		HugeInteger add(HugeInteger a);
		HugeInteger subtract(HugeInteger a);
		void output();
	private:
		int *data;
		int length;
		bool sign;
};
#endif
