#include "supportF.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	while (true)
	{
		//Перевод

		std::string num;
		unsigned short fromBase, toBase;

		std::cout << "Число: ";
		std::cin >> num;
		std::cout << "Основание системы числа: ";
		std::cin >> fromBase;
		std::cout << "Основание системы, в которую нужно перевести: ";
		std::cin >> toBase;

		double startTime = clock();

		std::cout << "\nРезультат: " << std::endl;
		std::cout << "В заданной системе: " << TransferAnyToAny(num, fromBase, toBase) << std::endl; //из любой в любую
		showInPopularNsys(num, fromBase); //Отображение числа в 10, 2, 8 и 16 системах

		double endTime = clock();

		double resultTimeSec = endTime - startTime;
		std::cout << "\nВремя выполнения: "
			<< resultTimeSec << " ms" << std::endl
			<< resultTimeSec / 1000 << " sec" << std::endl << std::endl;

		//Арифметика

		//Чисел одной системы счисления
		std::string firstNum, secondNum;
		unsigned short numBase;

		std::cout << "Первое число: ";
		std::cin >> firstNum;
		std::cout << "Второе число: ";
		std::cin >> secondNum;
		std::cout << "Основание системы чисел: ";
		std::cin >> numBase;

		startTime = clock();

		std::string result = ArithmeticsOneBase(firstNum, secondNum, numBase);

		std::cout << "\nРезультат: " << std::endl;
		std::cout << "В заданной системе: " << result << std::endl;
		showInPopularNsys(result, numBase);//Отображение числа в 10, 2, 8 и 16 системах

		endTime = clock();
		resultTimeSec = endTime - startTime;
		std::cout << "\nВремя выполнения: "
		<< resultTimeSec << " ms" << std::endl
		<< resultTimeSec / 1000 << " sec" << std::endl << std::endl;

		//Чисел разных систем счисления

		unsigned short firstNumBase, secondNumBase;

		std::cout << "Первое число: ";
		std::cin >> firstNum;
		std::cout << "Основание первого числа: ";
		std::cin >> firstNumBase;
		std::cout << "Второе число: ";
		std::cin >> secondNum;
		std::cout << "Основание второго числа: ";
		std::cin >> secondNumBase;

		std::cout << "В какой системе отобразить результат: ";
		std::cin >> toBase;

		startTime = clock();

		result = ArithmeticsAnyWithAny(firstNum, secondNum, firstNumBase, secondNumBase, toBase);

		std::cout << "\nРезультат: " << std::endl;
		std::cout << "В заданной системе: " << result << std::endl;
		showInPopularNsys(result, toBase);//Отображение числа в 10, 2, 8 и 16 системах


		endTime = clock();
		resultTimeSec = endTime - startTime;
		std::cout << "\nВремя выполнения: "
			<< resultTimeSec << " ms" << std::endl
			<< resultTimeSec / 1000 << " sec" << std::endl << std::endl;


		/*int input, result, i = 0, answer = 0;

		std::cin >> input;
		int tmp = input;

		while (input > 1)
		{
			result = input % 2;
			for (short j = i; j != 0; j--)
				result *= 10;

			answer += result;
			input /= 2;
			i++;
		}

		for (short j = i; j != 0; j--)
			input *= 10;

		answer += input;
		std::cout << '\n' << answer << std::endl;

		std::cout << TransferDecimalToAny(tmp, 2) << std::endl;*/

	}

	return 0;
}