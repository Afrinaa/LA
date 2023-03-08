
/******************************************LEXICAL ANALYSIS UPDATE VERSION********************************************/

#include<iostream>
#include<string>
#include<fstream>
#include<string.h>
using namespace std;
/* Function for Tokenize expression  */
void exponential();
void float_number();
void power();
void integer();
void identifier();
/* Functions checking for Exponential number */
void stt0();
void stt1();
void stt2();
void stt3();
void stt4();
void stt5();
void stt6();
void stt7();
void stt8();
void stt9();
/* Functions checking for Float number */
void s0();
void s1();
void s2();
void s3();
/* Functions checking for Power number */
void st0();
void st1();
void st2();
void st3();
/* Functions checking for Integer number */
void state0();
void state1();
/* Functions checking for Identifier */
void stte0();
void stte1();

int i=0,j,k,a=0,b=0,c=0,d=0,e=0,f=0,g=0,stringlength,strlength,parentheses=0,SingleQuote,DoubleQuote,PersentSymbol;
int Comma,Semicolon,AddressSymbol,Colon,line_Count=0,error_Count=0;
//char *expression,*token,char_ter;
char expression[1000],token[1000],expresion1[1000],new_expression[1000],other_token[100];
std::string str,file_line;
//int i,j;
//char c;
int main()
{
ifstream file_("program.txt");
if(file_.is_open())
{
    while(getline(file_,file_line))
    {    ++line_Count;
        //cout<<'\n'<<file_line <<'\n';
        //cout<<"A line of characters given below: "<<'\n'<<'\n';
        k=0;
        //cout<<"\n Character length in one Line is:"<<file_line.size();
        for(i=0;i<file_line.size();i++)
        {
//            c=str.at(i);
//            cout<<" "<<c;

            //printf("\n\n\n\t The input expression is: %s",file_line);

       //cout<<" "<<file_line.at(i) ;
    //for(i=0;i<stringlength;i++)
    if(file_line.at(i)!='\n')
    {
        new_expression[k]=file_line.at(i);
        k++;
    }

        }
            new_expression[k]='\0';
            stringlength=strlen(new_expression);
                //printf("\n\n\n\t The input expression length is: %d",stringlength);

                //printf("\n\n\n\t The input expression is: %s",new_expression);
        i=0;


	while(new_expression[i]!='\0')    /* Checking all tokens of expression */
	{


		j=0;
		a=0,b=0,c=0,d=0,e=0,f=0,g=0;
		SingleQuote=0,DoubleQuote=0,PersentSymbol=0,Comma=0,Semicolon=0,AddressSymbol=0,Colon=0;
		while(new_expression[i]!=' '&& i< stringlength && new_expression[i]!='\0')
		{
			//*(token+j)=expression[i];

            token[j]=new_expression[i];
            //str + = token[j];
            str += token[j];



            if(token[j]=='('||token[j]==')')
            {
                parentheses=1;
                other_token[j]=token[j];

                strlength=strlen(token);
                //printf("\n Token Before  Parentheses stringlength is = %d\n",strlength);
                //printf("\n STR.SIZE  is = %d\n",str.size());
                //if(strlength>1)
                if(str.size()>1)
                {
            if(new_expression[i]=='.')
				b=1;
			 else if(new_expression[i]=='E')
				c=1;
			 else if(new_expression[i]=='^')
				d=1;
			 else if(new_expression[i]=='+'||new_expression[i]=='-'||new_expression[i]=='*'||new_expression[i]=='/'||new_expression[i]=='=')
				e=1;
			 else if(new_expression[i]>=48&&new_expression[i]<=57)
				f=1;
			 else
				g=1;
                   break;// goto label_1;
                }
                else{
                        label_1:
                            if(other_token[j]=='(')
                                printf("");
                                //printf("\n\n \t \tinput token %c is Left Parentheses \n",other_token[j]);
                            else
                                printf("");
                                //printf("\n\n \t \tinput token %c is Right Parentheses \n",other_token[j]);
                        parentheses=0;
                goto label_2;
                }

            }
            else if(token[j]=='{'||token[j]=='}')
            {
                other_token[j]=token[j];
                 //str += token[j];
                //strlength=strlen(token);
                //printf("\n Token before Braces string length is = %d \n ",str.size());
//                if(str.size()>1)
//                {
//
//				break;
//                }
//                else{
                          if(other_token[j]=='{')
                            printf("");
                                //printf("\n\n \t \tinput token %c is Left Braces \n",other_token[j]);
                            else
                            printf("");
                                //printf("\n\n \t \tinput token %c is Right Braces \n",other_token[j]);
                            goto label_2;
                //}


            }
            else if(new_expression[i]=='"')
                DoubleQuote=1;
            else if(new_expression[i]=='`')
                SingleQuote=1;
            else if(new_expression[i]==',')
                Comma=1;
            else if(new_expression[i]==';')
                Semicolon=1;
            else if(new_expression[i]==':')
                Colon=1;
            else if(new_expression[i]=='%')
                PersentSymbol=1;
            else if(new_expression[i]=='&')
                AddressSymbol=1;
			else if(new_expression[i]=='.')
				b=1;
			 else if(new_expression[i]=='E')
				c=1;
			 else if(new_expression[i]=='^')
				d=1;
			 else if(new_expression[i]=='+'||new_expression[i]=='-'||new_expression[i]=='*'||new_expression[i]=='/'||new_expression[i]=='=')
				e=1;
			 else if(new_expression[i]>=48&&new_expression[i]<=57)
				f=1;
			 else
				g=1;
			  j++;
			  i++;
		}
		//*(token+j)='\0';
		//label_1:
		token[j]='\0';
		j=0;

		if(d==1&&c==1)
		{
			//printf("\n\n\n\t The input token: %s is an exponential number and it is",token);

			while(a!=-1 && a!=-3)
				exponential();

			if(a==-1)
            {
                ++error_Count;
                cout<<"\n Lexical Error at Line:"<<line_Count<<" Invalid input token "<<'"'<<token<<'"'<<" Exponential number";
                //printf("\n\n\n\t Lexical Error at Line %d Invalid token: %s Exponential number ",line_Count,token);
                //printf("invalid");
			}

			 else
                printf("");
				//printf(" valid");


		}
		else if(b==1 && d!=1)
		{
			//printf("\n\n\n\t The input token: %s is a float_number  and it is ",token);

			while(a!=-1 && a!=-3)
				float_number();

			if(a==-1)
            {
                ++error_Count;
                //printf("\n\n\n\t Lexical Error at line %d Invalid input token: %s Float_number  ",line_Count,token);
                cout<<"\n Lexical Error at Line:"<<line_Count<<" Invalid input token "<<'"'<<token<<'"'<<" Float number";
                //printf("invalid");
            }

			 else
                printf("");
				//printf("valid");
		}
		else if(f==1&&d==1)
		{
			//printf("\n\n\n\t The input token: %s is an power number  and it is ",token);

			while(a!=-1 && a!=-3)
				power();

			 if(a==-1)
             {
                 ++error_Count;
                 //printf("\n\n\n\t Lexical Error at line %d Invalid input token: %s Power number  ",line_Count,token);
                 cout<<"\n Lexical Error at Line:"<<line_Count<<" Invalid input token "<<'"'<<token<<'"'<<" Power number";
                 //printf("invalid");
             }

			  else
                printf("");
				//printf("valid");

		}


		else if(f==1&&g!=1)
		{
			//printf("\n\n\n\t The input token: %s is an integer number  and it is ",token);

			while(a!=-1 && a!=-3)
				integer();

			  if(a==-1)
              {
                  ++error_Count;
                  //printf("\n\n\n\t Lexical Error at line %d Invalid input token: %s Integer number  ",line_Count,token);
                  cout<<"\n Lexical Error at Line:"<<line_Count<<" Invalid input token "<<'"'<<token<<'"'<<" Integer number";
                  //printf("invalid");
              }

			  else
                printf("");
				//printf("valid");

		}

		else if(e==1)
		{
		    printf("");
			//printf("\n\n\n\t The input token: %s is an operator ",token);




		}
        else if(Semicolon==1)
		{
		    printf("");
			//printf("\n\n\n\t The input token: %s is a Semicolon ",token);




		}
		else if(Colon==1)
		{
		    printf("");
			//printf("\n\n\n\t The input token: %s is a Colon ",token);




		}
        else if(Comma==1)
		{
		    printf("");
			//printf("\n\n\n\t The input token: %s is a Comma ",token);




		}
		else if(DoubleQuote==1)
		{
		    printf("");
			//printf("\n\n\n\t The input token: %s is a Double Quotation symbol ",token);




		}
		else if(SingleQuote==1)
		{
		    printf("");
			//printf("\n\n\n\t The input token: %s is a SingleQuotation symbol ",token);




		}
		else if(PersentSymbol==1)
		{
		    printf("");
			//printf("\n\n\n\t The input token: %s is a Parsent Symbol ",token);

		}
		else if(AddressSymbol==1)
		{
		    printf("");
			//printf("\n\n\n\t The input token: %s is a Address Symbol  ",token);

		}

		 else if(g==1)
		 {
			//printf("\n\n\n\t The input token: %s  is an identifier  and it is ",token);

			while(a!=-1 && a!=-3)
				identifier();
			if(a==-1)
            {
                ++error_Count;
                //printf("\n\n\n\t Lexical Error at line %d Invalid input token: %s   identifier  ",line_Count,token);
                cout<<"\n Lexical Error at Line:"<<line_Count<<" Invalid input token "<<'"'<<token<<'"'<<" Identifier";
                //printf("invalid");
            }

			  else
                printf("");
				//printf("valid");
            if(parentheses==1)
                goto label_1;

		 }
         label_2:
		 i++;
		 if(i==stringlength)
         {
             for(k=0;k<file_line.size();k++)
            new_expression[k]='\0';
         }

		 str.clear();
	}

        //break;
    }
    if(error_Count==0)
    {
        cout<<"\n There is no lexical Error";
        cout<<"\n Total number of error: "<<error_Count;
    }
    else
    {
        cout<<"\n Total number of error: "<<error_Count;
    }
    file_.close();
}
else
    cout<<"File is not Open";
//
//
//   gets(str1);
//strlength=strlen(str1);
//for(i=0;i<strlength;i++)
//  {
//      //c=str1[i];
//      str += str1[i];
//  }
//
//
//  for(i=0;i<str.size();++i)
//  {
//      //c=str1[i];
//      cout<<'\n'<<"String First character is:"<<str.at(i);
//  }
//   cout<<'\n'<<"String First character is:"<<str.at(str.size()-2);
////  i=0;
////cout<<'\n'<<"String Size:"<<str.size();
////cout<<'\n'<<"String First character is:"<<str.at(i);
////i++;
////cout<<'\n'<<"String First character is:"<<str.at(i);
////i++;
////cout<<'\n'<<"String First character is:"<<str.at(i);
////i++;
////cout<<'\n'<<"String First character is:"<<str.at(i);
////i++;
////cout<<'\n'<<"String First character is:"<<str.at(i);
////i++;
////cout<<'\n'<<"String First character is:"<<str.at(i);
////i++;
//str.clear();
//i=0;
////cout<<'\n'<<"String First character is:"<<str.at(i);
//
////   puts(str1) ;
//   //puts(str1) ;


    return 0;
}

void exponential()
{
		switch(a)
		{
		       case 0:
				stt0();
				break;
		       case 1:
				stt1();
				break;
		       case 2:
				stt2();
				break;
		       case 3:
				stt3();
				break;
		       case 4:
				stt4();
				break;
		       case 5:
				stt5();
				break;
		       case 6:
				stt6();
				break;
		       case 7:
				stt7();
				break;
				 case 8:
				stt8();
				break;
				 case 9:
				stt9();
				break;

		}

}

	void stt0()
	{
		if(token[j]>=48&&token[j]<=57)
		{
			a=1;
			j++;
		}
		else if(token[j]=='.')
		{
			a=2;
			j++;
		}
		 else if(token[j]=='E')
		{
			a=4;
			j++;
		}

		else
			a=-1;
	}
	void stt1()
	{
		if(token[j]>=48&&token[j]<=57)
		{
			a=1;
			j++;
		}
		 else if(token[j]=='.')
		{
			a=2;
			j++;
		}
		   else if(token[j]=='E')
		{
			a=4;
			j++;
		}
		else
			a=-1;

	}

	void stt2()
	{
		if(token[j]>=48&&token[j]<=57)
		{
			a=3;
			j++;
		}
		else
			a=-1;
	}


	void stt3()
	{
		if(token[j]>=48&&token[j]<=57)
		{
			a=3;
			j++;
		}
		 else if(token[j]=='E')
		{
			a=4;
			j++;
		}

		else
			a=-1;

	}

	void stt4()
	{
		if(token[j]=='^')
		{
			a=5;
			j++;
		}
		else
			a=-1;
	}





	void stt5()
	{
		if(token[j]>=48&&token[j]<=57)
		{
			a=7;
			j++;
		}
		 else if(token[j]=='+'||token[j]=='-')
		{
			a=6;
			j++;
		}
		else if(token[j]=='.')
		{
			a=8;
			j++;
		}
		else
			a=-1;

	}
	void stt6()
	{
		if(token[j]>=48&&token[j]<=57)
		{
			a=7;
			j++;
		}

		else
			a=-1;

	}
	void stt7()
	{
		if(token[j]>=48&&token[j]<=57)
		{
			a=7;
			j++;
		}

        else if(token[j]=='.')
		{
			a=8;
			j++;
		}

		else if(token[j]==' '||token[j]=='\0')
		{
			a=-3;

		}


		else
			a=-1;
	}




	void stt8()
	{
		if(token[j]>=48&&token[j]<=57)
		{
			a=9;
			j++;
		}



		else
			a=-1;
	}
	void stt9()
	{
		if(token[j]>=48&&token[j]<=57)
		{
			a=9;
			j++;
		}

		else if(token[j]==' '||token[j]=='\0')
		{
			a=-3;

		}


		else
			a=-1;
	}

void float_number()
{
		switch(a)
		{
		       case 0:
				s0();
				break;
		       case 1:
				s1();
				break;
		       case 2:
				s2();
				break;
		       case 3:
				s3();
				break;
		}

}

	void s0()
	{
		if(token[j]>=48&&token[j]<=57)
		{
			a=1;
			j++;
		}
		 else if(token[j]=='.')
		{
			a=2;
			j++;
		}

		else
			a=-1;
	}
	void s1()
	{
		if(token[j]>=48&&token[j]<=57)
		{
			a=1;
			j++;
		}
		 else if(token[j]=='.')
		{
			a=2;
			j++;
		}

		else
			a=-1;

	}

	void s2()
	{
		if(token[j]>=48&&token[j]<=57)
		{
			a=3;
			j++;
		}
		else
			a=-1;
	}


	void s3()
	{
		if(token[j]>=48&&token[j]<=57)
		{
			a=3;
			j++;
		}
		else if(token[j]==' '||token[j]=='\0')
		{
			a=-3;

		}
		else
			a=-1;

	}




void power()
{
		switch(a)
		{
		       case 0:
				st0();
				break;
		       case 1:
				st1();
				break;
		       case 2:
				st2();
				break;
		       case 3:
				st3();
				break;
		}

}

	void st0()
	{
		if(token[j]>=48&&token[j]<=57)
		{
			a=1;
			j++;
		}


		else
			a=-1;
	}
	void st1()
	{
		if(token[j]>=48&&token[j]<=57)
		{
			a=1;
			j++;
		}
		 else if(token[j]=='^')
		{
			a=2;
			j++;
		}

		else
			a=-1;

	}

	void st2()
	{
		if(token[j]>=48&&token[j]<=57)
		{
			a=3;
			j++;
		}
		else
			a=-1;
	}


	void st3()
	{
		if(token[j]>=48&&token[j]<=57)
		{
			a=3;
			j++;
		}
		else if(token[j]==' '||token[j]=='\0')
		{
			a=-3;

		}
		else
			a=-1;

	}

void integer()
{
		switch(a)
		{
		       case 0:
				state0();
				break;
		       case 1:
				state1();
				break;
		}

}


void state0()
{
		if(token[j]>=48&&token[j]<=57)
		{
			a=1;
			j++;
		}
		else
			a=-1;
}

void state1()
{
		if(token[j]>=48&&token[j]<=57)
		{
			a=1;
			j++;
		}
		else if(token[j]==' '||token[j]=='\0')
		{
			a=-3;
			j++;
		}

		else
			a=-1;
}

void identifier()
{


		switch(a)
		{
		       case 0:
				stte0();
				break;
		       case 1:
				stte1();
				break;
		}

}

void stte0()
{
		if((token[j]>=65&&token[j]<=90)||(token[j]>=97 && token[j]<=122))
		{
			a=1;
			j++;
		}
		else if(token[j]=='_')
        {
            a=1;
			j++;
        }
		else
			a=-1;
}

void stte1()
{

		if((token[j]>=65&&token[j]<=90)||(token[j]>=97&&token[j]<=122))
		{
			a=1;
			j++;
		}

		else if(token[j]>=48&&token[j]<=57)
		{
			a=1;
			j++;
		}
		else if(token[j]=='_')
        {
            a=1;
			j++;
        }

		else if(token[j]==' '||token[j]=='\0')
		{
			a=-3;

		}

		else
			a=-1;

}


