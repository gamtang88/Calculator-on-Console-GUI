#include<stdio.h>
#include<conio.h>
#include<windows.h>
double result=0;
int main()
{
	int x,y,i=1,point=1,a=0,operation=0,sosu=0,jarisu=1;
	int cuser[5][4]={0};
	char input;
	double temp=0,temp2=0;
	for(x=0;x<3;x++)
		for(y=0;y<3;y++)
			cuser[x][y]=i++;
	i=13;
	for(x=0;x<4;x++)
		cuser[x][3]=i++;
	i=10;
	for(y=0;y<3;y++)
		cuser[3][y]=i++;
	for(y=0;y<4;y++)
		cuser[4][y]=17;
	/*for(x=0;x<4;x++){
	for(y=0;y<4;y++)
	printf("%d ",cuser[x][y]);
	putchar('\n');}*/
	x=0,y=0;
	while(1)
	{
		printf("┌───────┐\n");
		printf("│    %10.3lf│\n",result==0?temp:result);
		printf("├─┬─┬─┬─┤\n");
		printf("%s 1%s 2%s 3%s /│\n",point==cuser[0][0]||point==0?"▶":"│"  ,point==cuser[0][1]?"▶":"│"  ,point==cuser[0][2]?"▶":"│",point==cuser[0][3]?"▶":"│");
		printf("├─┼─┼─┼─┤\n");
		printf("%s 4%s 5%s 6%s *│\n",point==cuser[1][0]?"▶":"│",point==cuser[1][1]?"▶":"│",point==cuser[1][2]?"▶":"│",point==cuser[1][3]?"▶":"│");
		printf("├─┼─┼─┼─┤\n");
		printf("%s 7%s 8%s 9%s -│\n",point==cuser[2][0]?"▶":"│",point==cuser[2][1]?"▶":"│",point==cuser[2][2]?"▶":"│",point==cuser[2][3]?"▶":"│");
		printf("├─┼─┼─┼─┤\n");
		printf("%s 0%s .%s =%s +│\n",point==cuser[3][0]?"▶":"│",point==cuser[3][1]?"▶":"│",point==cuser[3][2]?"▶":"│",point==cuser[3][3]?"▶":"│");
		printf("├─┴─┴─┴─┤\n");
		printf("%s    초기화    │\n",(point==cuser[4][0])||(point==cuser[4][1])||(point==cuser[4][2])||(point==cuser[4][3])?"▶":"│");
		printf("└───────┘\n");
		printf("result:%lf//",result);
		printf("temp=%lf//\n",temp);
		printf("temp2=%lf//",temp2);
		printf("point:%d//",point);
		printf("sosu:%d",sosu);
		input=getch();
		if(input==77){
			if(y<3)
				y+=1;
			point=cuser[x][y];
		}
		else if(input==75){
			if(y>0)
				y-=1;
			point=cuser[x][y];
		}
		else if(input==80){
			if(x<4)
				x+=1;
			point=cuser[x][y];
		}
		else if(input==72){
			if(x>0)
				x-=1;
			point=cuser[x][y];
		}
		else if(input==13){ //엔터일때
			if(point==11)sosu=1;
			if(point<11)
			{
				temp2=0;


				if(a<10){  // 10개숫자만 받기
					if(sosu==1){ //소수점눌렀을때
						if(point==10)jarisu++;  //0을눌렀으면 자리수만 늘리고
						else{  //0말고 다른걸 눌렀으면
							if(jarisu==1) 
								result=result+0.1*point;
							else if(jarisu==2)
								result=result+0.001*point;
							else
								result=result+0.0001*point;
							jarisu++;
							a++;

						}
					}

					else{
						if(point==10)
							result=result*10;
						else
							result=result*10+point;
						a++;
					}
				}

			}
			switch(point){

			case 16://덧셈
				if(temp){  //그전에 입력한 값이 존재하면
					temp+=result;
					result=0;
					a=0;
					sosu=0;}
				else{  //그전에 입력한 값이 존재하지않으면 처음입력하면
					temp=result;
					a=0;
					result=0;
					sosu=0;}
				operation=1;  //기호를 저장
				break;
			case 15: //-
				if(temp){
					temp-=result;
					result=0;
					a=0;
					sosu=0;}
				else{
					temp=result;
					a=0;
					result=0;
					sosu=0;}
				operation=2;
				break;

			case 14: //*
				if(temp){
					temp*=result;
					result=0;
					a=0;
					sosu=0;}
				else{
					temp=result;
					a=0;
					result=0;
					sosu=0;}
				operation=3;
				break;

			case 13: // /
				if(temp){
					temp/=result;
					result=0;
					a=0;
					sosu=0;}
				else{
					temp=result;
					a=0;
					result=0;
					sosu=0;}
				operation=4;
				break;

			case 12:  //=일때
				if(!temp)
					switch(operation){
					case 1: result+=temp2;break;
					case 2: result-=temp2;break;
					case 3: result*=temp2;break;
					case 4: result/=temp2;break;
				}

				else
					switch(operation){
					case 1:
						temp2=result;
						result+=temp;      
						temp=0;
						break;
					case 2: 
						temp2=result;
						result=temp-result;
						temp=0;
						break;
					case 3 : 
						temp2=result;
						result*=temp;
						temp=0;
						break;
					case 4 : 
						temp2=result;
						result=temp/result;
						temp=0;
						break;
						sosu=0;
				}break;
			case 17:
				result=0,temp=0,temp2=0,sosu=0;
				break;
			}


		}
		system("cls");
	}



}