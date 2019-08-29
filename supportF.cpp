#include "supportF.h"

std::string TransferDecimalToAny(long long int number, const unsigned short &toBase)
{
	const char *DIGITS = "0123456789abcdefghijklmnopqrstuvwxyz";
	std::string reversString, stringInBase;

	if (toBase < 2 || toBase > 36)
	{
		std::cout << "Error: основание должно быть от 2 до 36." << std::endl;
		return "ERROR";
	}
	if (number < 0)
	{
		reversString = "-";
		number *= -1;
	}

	stringInBase += DIGITS[number % toBase];
	number = number / toBase;
	while (number)
	{
		stringInBase += DIGITS[number % toBase];
		number = number / toBase;
	}

	for (int i = stringInBase.length() - 1; i >= 0; i--)
		reversString += stringInBase[i];

	return reversString;
}

long long int TransferAnyToDecimal(std::string number, const unsigned short &numBase)
{
	const char *DIGITS = "0123456789abcdefghijklmnopqrstuvwxyz";
	long long int result = 0;
	std::string stringInBase;

	if (numBase < 2 || numBase > 36)
	{
		std::cout << "Error: основание должно быть от 2 до 36." << std::endl;
		return 0;
	}

	for (int i = number.length() - 1; i >= 0; i--)
		stringInBase += number[i];

	try
	{
		for (int i = 0; i <= number.length() - 1; i++)
		{
			if (stringInBase[i] == '-')
				continue;

			bool symbolFound = false;
			for (int j = 0; j < numBase; j++)
			{
				if (stringInBase[i] == DIGITS[j])
				{
					symbolFound = true;
					result += j * pow(numBase, i);
					break;
				}
				else
					symbolFound = false;
			}

			if (!symbolFound)
				throw 1;
		}
	}
	catch (int codeError)
	{
		std::cout << "Error: были введены цифры, которые не поддерживаются указанным основанием" << std::endl;
		return 0;
	}

	if (number[0] == '-')
		result *= -1;

	return result;
}

std::string TransferAnyToAny(std::string number, const unsigned short &fromBase, const unsigned short &toBase)
{
	return TransferDecimalToAny(TransferAnyToDecimal(number, fromBase), toBase);
}

/*long long int ArithmeticsAnyToDec(std::string num1, std::string num2, const unsigned short &numBase)
{
	long long int firstDec = TransferAnyToDecimal(num1, numBase);
	long long int secondDec = TransferAnyToDecimal(num2, numBase);

	std::cout << "Выберите какую операцию нужно совершить: " << std::endl
		<< '+' << '\t' << '-' << '\t' << '*' << '\t' << '/' << std::endl;

	bool correct = false;
	while (!correct)
	{
		char inputOp;
		std::cin >> inputOp;

		switch (inputOp)
		{
		case '+':
			return firstDec + secondDec;
			correct = true;
			break;
		case '-':
			return firstDec - secondDec;
			correct = true;
			break;
		case '*':
			return firstDec * secondDec;
			correct = true;
			break;
		case '/':
			return firstDec / secondDec;
			correct = true;
			break;
		default:
			correct = false;
			std::cout << "Error: введите корректный символ - те, что указаны выше" << std::endl;
			break;
		}
	}
}*/

std::string ArithmeticsOneBase(std::string num1, std::string num2, const unsigned short &numBase)
{
	long long int firstDec = TransferAnyToDecimal(num1, numBase);
	long long int secondDec = TransferAnyToDecimal(num2, numBase);

	std::cout << "Выберите какую операцию нужно совершить: " << std::endl
		<< '+' << '\t' << '-' << '\t' << '*' << '\t' << '/' << std::endl;

	bool correct = false;
	while (!correct)
	{
		char inputOp;
		std::cin >> inputOp;

		switch (inputOp)
		{
		case '+':
			return TransferDecimalToAny(firstDec + secondDec, numBase);
			correct = true;
			break;
		case '-':
			return TransferDecimalToAny(firstDec - secondDec, numBase);
			correct = true;
			break;
		case '*':
			return TransferDecimalToAny(firstDec * secondDec, numBase);
			correct = true;
			break;
		case '/':
			return TransferDecimalToAny(firstDec / secondDec, numBase);
			correct = true;
			break;
		default:
			correct = false;
			std::cout << "Error: введите корректный символ операции - те, что указаны" << std::endl;
			break;
		}
	}
}

std::string ArithmeticsAnyWithAny(std::string num1, std::string num2, 
								  const unsigned short &num1Base, const unsigned short &num2Base, const unsigned short &toBase)
{
	long long int firstDec = TransferAnyToDecimal(num1, num1Base);
	long long int secondDec = TransferAnyToDecimal(num2, num2Base);

	std::cout << "Выберите какую операцию нужно совершить: " << std::endl
		<< '+' << '\t' << '-' << '\t' << '*' << '\t' << '/' << std::endl;

	bool correct = false;
	while (!correct)
	{
		char inputOp;
		std::cin >> inputOp;

		switch (inputOp)
		{
		case '+':
			return TransferDecimalToAny(firstDec + secondDec, toBase);
			correct = true;
			break;
		case '-':
			return TransferDecimalToAny(firstDec - secondDec, toBase);
			correct = true;
			break;
		case '*':
			return TransferDecimalToAny(firstDec * secondDec, toBase);
			correct = true;
			break;
		case '/':
			return TransferDecimalToAny(firstDec / secondDec, toBase);
			correct = true;
			break;
		default:
			correct = false;
			std::cout << "Error: введите корректный символ операции - те, что указаны" << std::endl;
			break;
		}
	}
}

void showInPopularNsys(std::string num, unsigned short numBase)
{
	std::cout << "В dec (десятичной): " << TransferAnyToDecimal(num, numBase) << std::endl; //из любой в 10-ю
	std::cout << "В bin (двоичной): " << TransferAnyToAny(num, numBase, 2) << std::endl; //из любой в 2-ю
	std::cout << "В oct (восьмеричной): " << TransferAnyToAny(num, numBase, 8) << std::endl; //из любой в 8-ю
	std::cout << "В hex (шестнадцатеричной): " << TransferAnyToAny(num, numBase, 16) << std::endl; //из любой в 16-ю
}