//#include<stdio.h>
//int main()
//{
//	int date[101] =
//	{ 
//	 100,5,6,8,6,9,1,6,1,2,4,
//	 9,1,9,8,2,3,6,4,7,7,
//	 5,9,5,0,3,8,7,5,8,1,
//     5,8,6,1,8,3,0,3,7,9,
//	 2,7,0,5,8,8,5,7,0,9,
//	 9,1,9,4,4,6,8,6,3,3,
//     8,5,1,6,3,4,6,7,0,7,
//	 8,2,7,6,8,9,5,6,5,6,
//	 1,4,0,1,0,0,9,4,8,0,
//	 9,1,2,8,5,0,2,5,3,3,
//	};
//	int i = 1,a=2,b=0,c=2,d=3;
//	for (i = 1; i <= 101; i++)
//	{
//
//		if (date[i] == 2 && a == 2)
//		{
//			date[i] = 100;
//			a = 100;
//			continue;
//		}
//		if(date[i] == 0&&b==0) 
//		{
//			date[i] = 100;
//			b = 100;
//			continue;
//		}
//		if (date[i] == 2&&c==2)
//		{
//			c = 100;
//			date[i] = 100;
//			continue;
//		}
//		if (date[i] == 3&&d==3)
//		{
//			d = 100;
//			date[i] = 100;
//			continue;
//		}
//		break;
//	}
//	int month = 1,day=1;
//	for(month=1;month<=12;month++)
//	{
//		//int a = 2, b = 0, c = 2, d = 3;
//		if(month==1|| month == 3|| month == 5 || month == 7|| month == 8)|| month == 10|| month == 12)
//		{ 
//			for (day = 1; day <=9; day++)
//			{
//				for (i = 1; i <= 101; i++)
//				{
//					if (date[i] == month || date[i] == day)
//					{
//						
//						if(date[i] == month)date[i] =100;
//
//					}
//
//				}
//				
//			}
//		}
//		for (day = 1; day <= 9; day++)
//		{
//			for (i = 1; i <= 101; i++)
//			{
//				
//				if (date[i] == 0||)
//				{
//					for (; i <= 101; i++)
//					{
//						if(date[i]==month)
//							for (; i <= 101; i++)
//							{
//								if (date[i] == 0)
//								{
//									for (; i <= 101; i++)
//									{
//										if(date[i]==day)
//									}
//								}
//							}
//
//					}
//
//				}
//
//			}
//		}
//	}
//	for (i = 1; i <= 100; i++)
//	{
//		if (date[i] == month);
//	}
//		
//			
//	
//	return 0;
//}
#include<stdio.h>
int main()
{
	int date[101] =
	{
	 0,
	 5,6,8,6,9,1,6,1,2,4,9,1,9,8,2,3,6,4,7,7,
	 5,9,5,0,3,8,7,5,8,1,5,8,6,1,8,3,0,3,7,9,
	 2,7,0,5,8,8,5,7,0,9,9,1,9,4,4,6,8,6,3,3,
	 8,5,1,6,3,4,6,7,0,7,8,2,7,6,8,9,5,6,5,6,
	 1,4,0,1,0,0,9,4,8,0,9,1,2,8,5,0,2,5,3,3,
	};
	int date_in_month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int i=1,result=0,month=1,day=1;
	for (month = 1; month <= 12; month++)
	{
		for (day = 1; day<= date_in_month[month]; day++)
		{
			int month_day_date[9] = { 0,2,0,2,3,month / 10,month % 10,day / 10,day % 10 };
			int n = 1;
			for (i = 1; i <= 101; i++)
			{
				if (date[i] == month_day_date[n])
				{
					n += 1;
					if (n == 8)
					{
							result += 1;
							/*int c = 1;
							for (c = 5; c <= 8; c++)
							{
								printf("%d\n", month_day_date[c]);
							}*/
							printf("%3d_2023%d%d%d%d\n",result,month_day_date[5], month_day_date[6], month_day_date[7], month_day_date[8]);
							break;
					}
				}
			}
		}
	}
	printf("一共有%d天", result);
	printf("%d", result);
	return 0;
}
