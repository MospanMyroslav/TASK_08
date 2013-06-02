#include "main.h";
int unit(char*s1, int x)
{
	switch(x)
	{
		case 0: strcpy(s1,"");
					break;
		case 1: strcpy(s1,"");
					break;
		case 2: strcpy(s1,"два");
					break;
		case 3: strcpy(s1,"три");
					break;
		case 4: strcpy(s1,"четыре");
					break;
		case 5: strcpy(s1,"пять");
					break;
		case 6: strcpy(s1,"шесть");
					break;
		case 7: strcpy(s1,"семь");
					break;
		case 8: strcpy(s1,"восемь");
					break;
		case 9: strcpy(s1,"девять");
					break;
	}
	return 0;
}

int secondDozen(char*s1, int x)
{
	switch(x)
	{
		case 11: strcpy(s1,"одиннадцать");
					break;
		case 12: strcpy(s1,"двенадцать");
					break;
		case 13: strcpy(s1,"тринадцать");
					break;
		case 14: strcpy(s1,"четырнадцать");
					break;
		case 15: strcpy(s1,"пятнадцать");
					break;
		case 16: strcpy(s1,"шестнадцать");
					break;
		case 17: strcpy(s1,"семнадцать");
					break;
		case 18: strcpy(s1,"восемнадцать");
					break;
		case 19: strcpy(s1,"девятнадцать");
					break;
	}
	return 0;
}
int tens(char*s2, int x)
{
	int temp = x/10;
	switch(temp)
	{
		case 0: strcpy(s2,"");
					break;
		case 1: strcpy(s2,"десять ");
					break;
		case 2: strcpy(s2,"двадцать ");
					break;
		case 3: strcpy(s2,"тридцать ");
					break;
		case 4: strcpy(s2,"сорок ");
					break;
		case 5: strcpy(s2,"пятьдесят ");
					break;
		case 6: strcpy(s2,"шестьдесят ");
					break;
		case 7: strcpy(s2,"семьдесят ");
					break;
		case 8: strcpy(s2,"восемьдесят ");
					break;
		case 9: strcpy(s2,"девяносто ");
					break;
	}
	return 0;
}

int hundreds(char*s3, int x)
{
	int temp = x/100;
	if(temp != 0)
	{
		unit(s3, temp);
		strcat(s3," сто ");
	}
	else strcpy(s3,"");
	return 0;
}

int thousands(char*s4, int x)
{
	if(x != 0)
	{
		if(x>10 && x<20)
		{
			secondDozen(s4,x);
			strcat(s4," тисяч ");
		}
		else {
				char temp[50] = "";
				hundreds(s4,x%1000);

				if((x%100)>10 && (x%100)<20)
				{
					secondDozen(temp,x%100);
					strcat(s4,temp);
					strcat(temp,"");
				}
				else {
						tens(temp,x%100);
						strcat(s4,temp);
						strcat(temp,"");

						unit(temp, x%10);
						strcat(s4, temp);
						strcat(temp,"");
				}

				strcat(s4," тисяч ");
		}
	}
	else strcpy(s4,"");
	return 0;
}

int integerValue(int x, char*sign)
{
	char s1[20] = "";
	char s2[20] = "";
	char s3[40] = "";
	char s4[60] = "";

	if(x == 0)
		strcpy(s1,"ноль");
	else
	{
		if(x == 1000000)
			strcpy(s1,"один миллион");
		else
		{
			if(x>10 && x<20)
				secondDozen(s1,x);
			else {
				thousands(s4, x/1000);
				hundreds(s3,x%1000);
				if((x%100)>10 && (x%100)<20)
					secondDozen(s1,x%100);
				else{
				tens(s2,x%100);
				unit(s1,x%10);}
			}
		}
	}
	cout <<sign << s4 << s3 << s2 << s1;
	return 0;
}
int fractionalValue(int x)
{
	char s1[20] = "";
	char s2[20] = "";
	char s3[40] = "";
	if(x<10)
	{
		strcpy(s3,"zero ");
		strcpy(s2,"zero ");
		unit(s1,x);
	}
	else    if(x<100)
			{
				strcpy(s3,"zero ");
				if(x>10 && x<20)
					secondDozen(s1,x);
				else {
						if(x%10 == 0)
							unit(s1,x/10);
						else{
						tens(s2,x);
						unit(s1,x%10);}
				}
			}
			else
			{
				if(x%100 == 0)
					unit(s1,x/100);
				else{
					hundreds(s3,x%1000);
					if((x%100)>10 && (x%100)<20)
						secondDozen(s1,x%100);
					else{
					tens(s2,x%100);
					unit(s1,x%10);}
				}
			}
		cout << s3 << s2 << s1;
	return 0;
}