#pragma once

//Преобразователи
std::string TransferDecimalToAny(long long int number, const unsigned short& base);
long long int TransferAnyToDecimal(std::string number, const unsigned short& numBase);
std::string TransferAnyToAny(std::string number, const unsigned short& fromBase, const unsigned short& toBase);

//Арифметика
//long long int ArithmeticsAnyToDec(std::string num1, std::string num2, const unsigned short &numBase)
std::string ArithmeticsOneBase(std::string num1, std::string num2, const unsigned short& numBase);
std::string ArithmeticsAnyWithAny(std::string num1, std::string num2, const unsigned short& num1Base, const unsigned short& num2Base, const unsigned short& toBase);

void showInPopularNsys(std::string num, unsigned short numBase);

class num_sys_t
{
public:
	//Constructors
	num_sys_t();
	~num_sys_t();

private:
	uint8_t first_base;
	uint8_t second_base;


};