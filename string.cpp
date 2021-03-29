

#include <iostream>
#include <cstring> //definira nqkolko funkcii za rabota s c string i masivi
#include <ostream> 


class String // predstavq v pamtta simvolen nizs proizvolna golemina i redica operacii s niza
{
public:
	char* str;

	void init(const char *s) // inicializirane na niz
	{
		str = new char[strlen(s) + 1] // zadelqme pamet
		strcpy(str, s);
	}

	void print() // otpechatvane na standartniq izhod
	{
		std::cout << str << std::endl;
	}
	
	std::ostream& operator<< (std::ostream& out, String s) //izpolzva se za da otpechatvame v redichka (izhoda) /izvejdane v potok
	{
		out << s.str;
			return out; // vrushta tova koeto e podadeno v standartniq izhod
	}





   String operator+ (char c) // operator za sybirane na niz sys simvol
   {
	String result; // rezultata e nov string
	result.str = new char[length() + 1 + 1];


	strcpy(result.str, str);
	result.str[this->length()] = c;
	result.str[this->length() + 1] = 0;

	return result;
   }


   String operator+ (String other) // sybirane na dva simvolni niza = konkatenaciq
   {
	String result;
	result.str = new char[strlen(str) + strlen(other.str) + 1];

	strcpy (result.str, str);
	strcat (result.str, other.str);

	return result;
   }

   bool operator== (String other) // operartor za sryvnenie
   {
	return strcmp (str, other.str) == 0;
   }

   bool operator< (String other)
   {
	return strcmp (str, other.str) < 0;
   }

   size_t length() // metod za namirane na dyljinata na niza
   {
	return strlen (str);
   }

   char& operator[] (size_t i) // operator za dostypvane na i-tiq simvol na niza (mojem da vrnem psevdonim kym i-ti red)
   {
	return str[i];
   }


   String operator= (char c) //prisvoqvane na simvola na niza , koeto  inicializira celiq niz samo s tozi simvol
   {
	str = new char[2];
	str[0] = c;
	str[1] = 0;
	return *this;

   }
};

String operator+(char c , String s) // izpylnqva se samostoqtelno i dvata parametyra opredelqt reda na operaciite
{
	String result;
	result.init("");

	result = c;
	result = result + s;
	return result;

}

String toString(unsigned int x) // prevryshta cqlo polojitelno chislo v sinvolen niz 
{
	String result;
	result.init("");


	if (x < 10)
	{
		result = '0' + x; //dobavq simvoli otlqvo i otdqsno na niza
		return result;
	}

	while (x > 0)
	{
		result = ('0' + x % 10) + result; // operaciq za vzimane na nai-desniq element ot desetichniq zapis na chisloto
		x /= 10; //operaciq za premahvane na nai-dqsnata cifra ot desetichniq zapis na chisloto

		//123 % 10 = 3
		//123 / 10 = 12
	}

	return result;

}










int main()
{

}
