#include "main.h";
double value, integral_part, fractional_part;
int intValue;


int integerValue(int , char*sign);
int fractionalValue(int );


int main()
{
	  setlocale (0, "Russian");
	char sign[7] = "";
	short extension;

	while(true)
	{
		cout << "Введіть суму чека ";
		cin >> value;

		if(value < 0)
			strcpy(sign, "мінус ");
		else strcpy(sign, "");
		value = fabs(value);

		if(value>1000000)
			cout << endl << "Програма працюе з числами -1 000 000 to 1 000 000";
		else {
				fractional_part = modf(value,&integral_part);

				if(fractional_part == 0.0)
				{
					intValue = (int)integral_part;
					integerValue(intValue, sign);
				}
				else
				{
					intValue = (int)integral_part;
					integerValue(intValue, sign);
					cout <<" point ";
					fractional_part = ceil(fractional_part*1000-0.00011);
					intValue = (int)fractional_part;
					fractionalValue(intValue);
				}
		}

		cout << endl <<endl << "Бажаете продовжити  (1-yes, 0-no)? ";
		cin >> extension;
		if(extension == 0)
			break;
		cout << "___________________________________________________" << endl;
	}

	cin >> value;
	return 0;
}
