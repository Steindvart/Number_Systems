#include "supportF.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	while (true)
	{
		//�������

		std::string num;
		unsigned short fromBase, toBase;

		std::cout << "�����: ";
		std::cin >> num;
		std::cout << "��������� ������� �����: ";
		std::cin >> fromBase;
		std::cout << "��������� �������, � ������� ����� ���������: ";
		std::cin >> toBase;

		double startTime = clock();

		std::cout << "\n���������: " << std::endl;
		std::cout << "� �������� �������: " << TransferAnyToAny(num, fromBase, toBase) << std::endl; //�� ����� � �����
		showInPopularNsys(num, fromBase); //����������� ����� � 10, 2, 8 � 16 ��������

		double endTime = clock();

		double resultTimeSec = endTime - startTime;
		std::cout << "\n����� ����������: "
			<< resultTimeSec << " ms" << std::endl
			<< resultTimeSec / 1000 << " sec" << std::endl << std::endl;

		//����������

		//����� ����� ������� ���������
		std::string firstNum, secondNum;
		unsigned short numBase;

		std::cout << "������ �����: ";
		std::cin >> firstNum;
		std::cout << "������ �����: ";
		std::cin >> secondNum;
		std::cout << "��������� ������� �����: ";
		std::cin >> numBase;

		startTime = clock();

		std::string result = ArithmeticsOneBase(firstNum, secondNum, numBase);

		std::cout << "\n���������: " << std::endl;
		std::cout << "� �������� �������: " << result << std::endl;
		showInPopularNsys(result, numBase);//����������� ����� � 10, 2, 8 � 16 ��������

		endTime = clock();
		resultTimeSec = endTime - startTime;
		std::cout << "\n����� ����������: "
		<< resultTimeSec << " ms" << std::endl
		<< resultTimeSec / 1000 << " sec" << std::endl << std::endl;

		//����� ������ ������ ���������

		unsigned short firstNumBase, secondNumBase;

		std::cout << "������ �����: ";
		std::cin >> firstNum;
		std::cout << "��������� ������� �����: ";
		std::cin >> firstNumBase;
		std::cout << "������ �����: ";
		std::cin >> secondNum;
		std::cout << "��������� ������� �����: ";
		std::cin >> secondNumBase;

		std::cout << "� ����� ������� ���������� ���������: ";
		std::cin >> toBase;

		startTime = clock();

		result = ArithmeticsAnyWithAny(firstNum, secondNum, firstNumBase, secondNumBase, toBase);

		std::cout << "\n���������: " << std::endl;
		std::cout << "� �������� �������: " << result << std::endl;
		showInPopularNsys(result, toBase);//����������� ����� � 10, 2, 8 � 16 ��������


		endTime = clock();
		resultTimeSec = endTime - startTime;
		std::cout << "\n����� ����������: "
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