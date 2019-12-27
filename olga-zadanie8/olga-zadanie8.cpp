#include <iostream>
/*ZADANIE 8*/
/*Temat: funkcje rekursywne*/

//Nowe słówko: rekursywny (rekurencyjny): powtarzający się sam w sobie. Czasem błędnie nazywany incepcją
//Kojarzysz podręczniki na których dzieciaki trzymały podręcznik i na tym podręczniku były dzieciaki trzymające podręcznik i na tym podręczniku... ?
//To właśnie to

/*Twoje funkcje*/
float add(float a, float b)
{
	return a + b;
}

float substract(float a, float b)
{
	return a - b;
}

float multiply(float a, float b)
{
	return a * b;
}

float divide(float a, float b)
{
	return a / b;
}

int parse_int_min_max(int a, int b)
{
	int u_input = 0;
	bool enter = false;
	bool exit = true;

	do
	{
		if (enter)
		{
			std::cout << "Niepoprawna opcja, sprobuj jeszcze raz: \n\n";
		}

		std::cout << "Podaj prosze numer opcji: \n\n";
		std::cin >> u_input;
		std::cout << "\n\n";

		if ((a <= u_input) && (u_input <= b))
		{
			exit = false;
		}

		else
		{
			enter = true;
		}

	} while (exit == true);

	return u_input;
}
/*Koniec Twoich funkcji*/

//Funkcja do przykładu 8.1
unsigned int add_all(unsigned int a) //unsigned int to liczba naturalna lub 0
{
	int sum = 0;
	
	for (int i = 1; i <= a; i++)
	{
		sum += i;
	}

	return sum;
}

//Funkcja do przykładu 8.1
unsigned int add_all_recursive(unsigned int a) 
{
	if (a == 1)
	{
		return 1; //zwraca 1 jeśli argument wynosi 1 (dotarliśmy do najmniejszej liczby)
	}
	else
	{
		return a + add_all_recursive(a - 1); //zwraca sumę swojego argumentu i wyniku samej siebie z argumentem mniejszym o 1;
		//zmienne nie są współdzielone pomiędzy wywołaniami funkcji.
		//jeśli funkcja wywoła samą siebie, to zmienna a nowej funkcji, to nie to samo a co a poprzedniej funkcji
	}

	//schemat działania tej funkcji jeśli zostanie wywołana z argumentem a == 5:
	// 1. add_all_recursive(5): return 5 + add_all_recursive(5 - 1)
	// 2. add_all_recursive(4): return 4 + add_all_recursive(4 - 1)
	// 3. add_all_recursive(3): return 3 + add_all_recursive(3 - 1)
	// 4. add_all_recursive(2): return 2 + add_all_recursive(2 - 1)
	// 5. add_all_recursive(1): return 1
	// 6. program wraca do add_all_recursive(2): return 2 + 1
	// 7. program wraca do add_all_recursive(3): return 3 + 3
	// 8. program wraca do add_all_recursive(4): return 4 + 6
	// 9. program wraca do add_all_recursive(5): return 5 + 10
}

//Funkcja do przykładu 8.1
//zapis skrócony z użyciem operatora ternarnego
unsigned int add_all_recursive_ternary(unsigned int a)
{
	return a == 1 ?  1 : a + add_all_recursive_ternary(a - 1);
}


//Funkcja do przykładu 8.2
unsigned int fibonacci(unsigned int a)
{
	if (a == 1 || a == 2)
	{
		return 1;
	}
	else
	{
		return fibonacci(a - 1) + fibonacci(a - 2);
	}
}



//Funkcja do przykładu 8.3
//Nie musisz analizować, szczegóły w przykładzie 8.3
std::string christmas_tree(unsigned int width, unsigned int total_width = 0)
{
	std::string current_level = "";

	if (width > 0)
	{
		if (width % 2 == 1)
		{
			width += 1;
		}

		if (total_width == 0)
		{
			for (int i = 0; i < width; i++)
			{
				current_level += "#";
			}

			current_level += "\n";

			if (width > 10)
			{
				for (int i = 0; i < width / 10; i++)
				{
					for (int i = 0; i < (((width - 2) / 2) - ((width / 10) - 1)); i++)
					{
						current_level += " ";
					}

					current_level += "[";

					for (int i = 0; i < ((width / 10) - 1) * 2; i++)
					{
						current_level += "|";
					}

					current_level += "]";

					for (int i = 0; i < (((width - 2) / 2) - ((width / 10) - 1)); i++)
					{
						current_level += " ";
					}

					current_level += "\n";
				}
			}
			else
			{
				for (int i = 0; i < ((width - 2) / 2); i++)
				{
					current_level += " ";
				}

				current_level += "[]";

				for (int i = 0; i < ((width - 2) / 2); i++)
				{
					current_level += " ";
				}
			}
			current_level += "\n\n\n";
			return christmas_tree(width - 2, width) + current_level;
		}
		else
		{
			for (int i = 0; i < ((total_width - width) / 2); i++)
			{
				current_level += " ";
			}

			for (int i = 0; i < width; i++)
			{
				current_level += "#";
			}

			for (int i = 0; i < ((total_width - width) / 2); i++)
			{
				current_level += " ";
			}

			current_level += '\n';
			return christmas_tree(width - 2, total_width) + current_level;
		}
	}
	else
	{
		return "";
	}

}

float x(float a, float b, float c, float d)
{
	return multiply(add(a, b), add(c, d));
}

unsigned int factorial(unsigned int a)
{
	if (a == 1 || a == 0)
	{
		return 1;
	}
	else
	{
		return a * factorial(a - 1);
	}
}


int main()
{
	bool example = true;
	if (!example)
	{
		int current_example = 4;

		/*PRZYKŁAD 8.1*/
		/*Przykład funkcji rekursywnej*/
		if (current_example == 1)
		{
			//przykład trzech funkcji zliczających wszystkie liczby naturalne od 0 do a;
			//pierwsza wykorzystuje pętle for
			//druga jest funkcją rekursywną
			//trzecia też jest funkcją rekursywną, ale jest zapisana w krótszej postaci

			std::cout << add_all(155) << '\n';

			std::cout << add_all_recursive(5) << '\n';

			std::cout << add_all_recursive_ternary(5) << '\n';
		}
		/*KONIEC PRZYK£AD 8.1*/
		else if (current_example == 2)
		/*PRZYKŁAD 8.2*/
		/*ciąg fibonacciego*/
		{
			//poniższa funckja oblicza n-ty element ciągu fibonacciego
			//tę funkcję byłoby już trudno napisać na pętli for
			//jest to obok silni najbardziej sztampowy przykład wykorzystania funkcji rekursywnej
			std::cout << "3 wyraz ciagu fibonacciego to "  << fibonacci(3)  << '\n';
			std::cout << "10 wyraz ciagu fibonacciego to " << fibonacci(10) << '\n';
			std::cout << "35 wyraz ciagu fibonacciego to " << fibonacci(35) << '\n';

		}
		/*KONIEC PRZYK£AD 8.2*/
		else if (current_example == 3)
		/*PRZYKŁAD 8.3*/
		//*Bo świąteczna atmosfera...*/
		//Rekursywny generator choineczek
		//Nie musisz analizować, bo nie mieliśmy jeszcze stringów
		//Po prostu pomyślałem, że to będzie coś fun to do...
		//Jeśli będziesz chciała przeanalizować możemy to zrobić razem
		{
			std::cout << christmas_tree(20);
			std::cout << christmas_tree(10);
			std::cout << christmas_tree(30);
			std::cout << christmas_tree(6);
			std::cout << christmas_tree(60);
		}
		/*KONIEC PRZYK£AD 8.3*/
		else if (current_example == 4)
		{
			std::cout << x(1, 2, 3, 4);
		}
	}
	else
	/*ZADANIE 8.1*/
	//O, a co to za znajomy kod? <3
	//Dodaj do niego kolejną funkcjonalność, a mianowicie silnię w następujący sposób:
	//1. Przesuń zakończenie programu na opcję numer 6
	//2. Dodaj nową opcję na miejscu 5 w menu: silnia
	//3. Dodaj warunek wokół pobrania liczba_dwa, żeby nie była pobierana jeśli obliczamy silnię
	//4. Stwórz funkcję rekursywną factorial(unsigned int a) obliczającą silnię argumentu a
	//4.1 Nie będe Ci tu za dużo podpowiadał, skorzystaj z kodu na n-ty wyraz ciągi fibonacciego jako pomocy albo zwróć się do mnie jak będziesz miała pytania
	//5. W case 5 switcha dodaj pętlę podobną jak przy dzieleniu zapewniającą, że liczba wprowadzona jest liczbą naturalną lub 0
	//6. Po spełnieniu tego warunku wypisz wynik funkcji factorial()
	{
		int iterator = 0;

		while (true)
		{
			float liczba_jeden = 0;
			float liczba_dwa = 0;
			int u_input = 0;
			float suma = 0;
			bool right_try = false;
			bool false_try = true;

			std::cout << "1. Dodawanie +" << "\n\n";
			std::cout << "2. Odejmowanie -" << "\n\n";
			std::cout << "3. Dzielenie %" << "\n\n";
			std::cout << "4. Mnozenie *" << "\n\n";
			std::cout << "5. Silnia !" << "\n\n";
			std::cout << "6. Zakoncz program" << "\n\n";

			u_input = parse_int_min_max(1, 6);

			if (u_input == 6)
			{
				break;
			}

			std::cout << "Podaj prosze pierwsza liczbe" << "\n\n";

			std::cin >> liczba_jeden;

			std::cout << "\n";

			if (u_input != 5)
			{
				std::cout << "Podaj prosze druga liczbe" << "\n\n";

				std::cin >> liczba_dwa;

				std::cout << "\n";
			}

			switch (u_input)
			{
			case 1:

				std::cout << "Twoj wynik wynosi: " << add(liczba_jeden, liczba_dwa) << "\n\n";
				break;

			case 2:

				std::cout << "Twoj wynik wynosi: " << substract(liczba_jeden, liczba_dwa) << "\n\n";
				break;

			case 3:

				while (liczba_dwa == 0)
				{
					std::cout << "Nie mozna dzielic przez 0 , sprobuj jeszcze raz: \n\n";
					std::cin >> liczba_dwa;
					std::cout << "\n\n";
				}

				std::cout << "Twoj wynik to: " << divide(liczba_jeden, liczba_dwa) << "\n\n";
				break;

			case 4:

				std::cout << "Twoj wynik wynosi: " << multiply(liczba_jeden, liczba_dwa) << "\n\n";
				break;

			case 5:

				while (liczba_jeden < 0)
				{
					std::cout << "Liczba podana nie jest liczbą naturalna (wieksza lub rowna 0), sprobuj jeszcze raz: " << "\n\n";
					std::cin >> liczba_jeden;
					std::cout << "\n\n";
				}

				{
					std::cout << "Twoj wynik wynosi: " << factorial(liczba_jeden) << "\n\n";
				
				break;

			default:
				std::cout << "Niepoprawna opcja" << "\n";
				break;
			}

			std::cout << "\n\n";

			iterator++;
		}

		std::cout << "Twoja petla wykonala sie " << iterator << " razy. Mam nadzieje, ze dobrze sie bawiles, uzytkowniku." << "\n\n";
		std::cout << "https://www.google.com/search?biw=1536&bih=754&tbm=isch&sxsrf=ACYBGNRF4XLTUjSfqdKDuD3y55jcm82V1Q%3A1577469787173&sa=1&ei=W0cGXub7CeaArwS8-ZuQCg&q=i+love+you+programmer&oq=i+love+you+programmer&gs_l=img.3...9295.14170..14320...7.0..0.72.1341.21......0....1..gws-wiz-img.......35i39j0i19j0i30i19j0i8i30i19j0j0i30.PaeH4TlAxQM&ved=0ahUKEwimlbvytNbmAhVmwIsKHbz8BqIQ4dUDCAc&uact=5#imgrc=F1WSOYy3vqa2fM:" << "\n\n";
	}
	/*KONIEC ZADANIE 8.1*/
}