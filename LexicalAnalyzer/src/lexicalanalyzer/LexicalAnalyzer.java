
package lexicalanalyzer;

import java.util.Scanner;
import java.util.Arrays;


public class LexicalAnalyzer {
static int i=0,j,a=0,b=0,c=0,d=0,e=0,f=0,g=0,stringlength,strlength,parentheses=0,SingleQuote,DoubleQuote,PersentSymbol;
static int Comma,Semicolon,AddressSymbol,Colon;
static char[] lexeme= new char[10];
static char[] inputExpression= new char[1000];
 //static   String token="";
    
    
    
    
    public static void main(String[] args) {
      int k;
        String expression, newexpression;
        System.out.println("Input an expression:"); 
        Scanner input =new  Scanner(System.in);
        
        expression =input.nextLine();
          System.out.println("The input expression is:"+expression);
          
        for ( k=0; k < expression.length();k++)
        {
            inputExpression[k] = expression.charAt(k);
        }
        inputExpression[k] = '\0';
       
        // System.out.printf("The input expression is:%s",inputExpression);
        // System.out.println("The input expression length is:");
         char c ='\n';
         //LexicalAnalyzer.token = expression;
         //newexpression = expression.concat(String.valueOf(c));
         
        
         //int end = newexpression.length();
          //System.out.println("The input expression length is:"+end);
         i=0;
         while( inputExpression[i]!= '\0')
         {
             j=0; 
             a=0;b=0;c=0;d=0;e=0;f=0;g=0;
	     SingleQuote=0;DoubleQuote=0;PersentSymbol=0;Comma=0;Semicolon=0;
             AddressSymbol=0;Colon=0;
             
             while(inputExpression[i]!= ' ')
             {
                 //char symbol = newexpression.charAt(i);
                 // System.out.println(" Symbol: "+symbol);
                 lexeme[j] = inputExpression[i];
                 //token.concat(String.valueOf(symbol));
                // System.out.printf("Token array content: %c ",lexeme[j]);
                 
                  if(inputExpression[i]=='.')
				b=1;
			 else if(inputExpression[i]=='E')
				c=1;
			 else if(inputExpression[i]=='^')
				d=1;
			 else if(inputExpression[i]=='+'||inputExpression[i]=='-'||inputExpression[i]=='*'||inputExpression[i]=='/'||inputExpression[i]=='=')
				e=1;
			 else if(inputExpression[i]>= '0' &&inputExpression[i]<= '9' )
				f=1;
			 else
				g=1;
                 
                 
                 i++;
                 j++;
             }
             
              //token = token.concat(String.valueOf(c));
              
              lexeme[j] = '\0';
              j=0;
              
              if(d==1&&c==1)
		{
                    
			System.out.println("\n\n\n\t The input token: "+Arrays.toString(lexeme) +"is an exponential number and it is:");

			while(a!=-1 && a!=-3)
				exponential();

			if(a==-1)
				System.out.println("invalid");
			 else
				System.out.println(" valid");


		}
		else if(b==1 && d!=1)
		{
			System.out.println("\n\n\n\t The input token:"+Arrays.toString(lexeme)+ " is a float_number  and it is ");

			while(a!=-1 && a!=-3)
				float_number();

			if(a==-1)
				System.out.println("invalid");
			 else
				System.out.println("valid");
		}
		else if(f==1&&d==1)
		{
			System.out.println("\n\n\n\t The input token:"+Arrays.toString(lexeme) +" is an power number  and it is ");

			while(a!=-1 && a!=-3)
				power();

			 if(a==-1)
				System.out.println("invalid");
			  else
				System.out.println("valid");

		}


		else if(f==1&&g!=1)
		{
			System.out.println("\n\n\n\t The input token:" + Arrays.toString(lexeme)+ " is an integer number  and it is ");

			while(a!=-1 && a!=-3)
				integer();

			  if(a==-1)
				System.out.println("invalid");
			  else
				System.out.println("valid");

		}
                else if (e == 1)
                {
                    if(lexeme[j] == '=')
                    {
                    System.out.println("The input token is ");
                    System.out.printf(" %c", lexeme[j]);
                    System.out.println(" an assignment operator and it is valid");
                    }
                    else if(lexeme[j] == '+' || lexeme[j] == '-' || lexeme[j] == '*' || lexeme[j] == '/')
                    {
                        System.out.println("The input token is ");
                    System.out.printf(" %c", lexeme[j]);
                    System.out.println(" an Arithmetic operator and it is valid");
                    }
                }
              else
		 {
			System.out.println("\n\n\n\t The input token: " + Arrays.toString(lexeme)+" is an identifier  and it is ");

			while(a!=-1 && a!=-3)
				identifier();
			if(a==-1)
				System.out.println("invalid");
			  else
				System.out.println("valid");
                 }
              
              
              
              i++;
        
        
        
		
         }
         
        
    }
    
    
  static  void exponential()
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

	static void stt0()
	{
		if(lexeme[j]>= '0' && lexeme[j]<= '9')
		{
			a=1;
			j++;
		}
		else if(lexeme[j]=='.')
		{
			a=2;
			j++;
		}
		 else if(lexeme[j]=='E')
		{
			a=4;
			j++;
		}

		else
			a=-1;
	}
static	void stt1()
	{
		if(lexeme[j]>= 48 && lexeme[j] <= 57)
		{
			a=1;
			j++;
		}
		 else if(lexeme[j]=='.')
		{
			a=2;
			j++;
		}
		   else if(lexeme[j]=='E')
		{
			a=4;
			j++;
		}
		else
			a=-1;

	}

static	void stt2()
	{
		if(lexeme[j] >= 48 && lexeme[j] <=57)
		{
			a=3;
			j++;
		}
		else
			a=-1;
	}


static	void stt3()
	{
		if(lexeme[j]>=48&&lexeme[j]<=57)
		{
			a=3;
			j++;
		}
		 else if(lexeme[j]=='E')
		{
                     //System.out.printf(" lexeme is: %c",lexeme[j]);
			a=4;
			j++;
		}

		else
			a=-1;

	}

static	void stt4()
	{
		if(lexeme[j]=='^')
		{
			a=5;
			j++;
		}
		else
			a=-1;
	}





static	void stt5()
	{
		if(lexeme[j]>=48&&lexeme[j]<=57)
		{
			a=7;
			j++;
		}
		 else if(lexeme[j]=='+'||lexeme[j]=='-')
		{
                     //System.out.printf(" lexeme is: %c",lexeme[j]);
			a=6;
			j++;
		}
		else if(lexeme[j]=='.')
		{
			a=8;
			j++;
		}
		else
			a=-1;

	}
static	void stt6()
	{
		if(lexeme[j]>=48&&lexeme[j]<=57)
		{
			a=7;
			j++;
		}

		else
			a=-1;

	}
static	void stt7()
	{
		if(lexeme[j]>=48&&lexeme[j]<=57)
		{
			a=7;
			j++;
		}

        else if(lexeme[j]=='.')
		{
			a=8;
			j++;
		}

		else if(lexeme[j]==' '||lexeme[j]=='\0')
		{
			a=-3;

		}


		else
			a=-1;
	}




static	void stt8()
	{
		if(lexeme[j]>=48 && lexeme[j]<=57)
		{
			a=9;
			j++;
		}



		else
			a=-1;
	}
static	void stt9()
	{
		if(lexeme[j] >=48 && lexeme[j]<=57)
		{
			a=9;
			j++;
		}

		else if(lexeme[j]==' '|| lexeme[j]=='\0')
		{
			a=-3;

		}


		else
			a=-1;
	}

 static void float_number()
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

static	void s0()
	{
		if(lexeme[j] >=48 && lexeme[j] <=57)
		{
			a=1;
			j++;
		}
		 else if(lexeme[j]=='.')
		{
			a=2;
			j++;
		}

		else
			a=-1;
	}
static	void s1()
	{
		if(lexeme[j]>=48 && lexeme[j]<=57)
		{
			a=1;
			j++;
		}
		 else if(lexeme[j]=='.')
		{
                    // System.out.printf(" lexeme is: %c",lexeme[j]);
			a=2;
			j++;
		}

		else
			a=-1;

	}

static	void s2()
	{
		if(lexeme[j]>=48&&lexeme[j]<=57)
		{
			a=3;
			j++;
		}
		else
			a=-1;
	}


static	void s3()
	{
		if(lexeme[j]>=48&&lexeme[j]<=57)
		{
			a=3;
			j++;
		}
		else if(lexeme[j]==' '||lexeme[j]=='\0')
		{
			a=-3;

		}
		else
			a=-1;

	}




static void power()
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

static	void st0()
	{
		if(lexeme[j]>=48 && lexeme[j]<=57)
		{
			a=1;
			j++;
		}


		else
			a=-1;
	}
static	void st1()
	{
		if(lexeme[j]>=48&&lexeme[j]<=57)
		{
			a=1;
			j++;
		}
		 else if(lexeme[j]=='^')
		{
                    // System.out.printf(" lexeme is: %c",lexeme[j]);
			a=2;
			j++;
		}

		else
			a=-1;

	}

static	void st2()
	{
		if(lexeme[j]>=48&&lexeme[j]<=57)
		{
			a=3;
			j++;
		}
		else
			a=-1;
	}


static	void st3()
	{
		if(lexeme[j]>=48&&lexeme[j]<=57)
		{
			a=3;
			j++;
		}
		else if(lexeme[j]==' '||lexeme[j]=='\0')
		{
			a=-3;

		}
		else
			a=-1;

	}

static void integer()
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


static void state0()
{
		if(lexeme[j]>=48&&lexeme[j]<=57)
		{
			a=1;
			j++;
		}
		else
			a=-1;
}

static void state1()
{
		if(lexeme[j]>=48&&lexeme[j]<=57)
		{
                    // System.out.printf(" lexeme is: %c",lexeme[j]);
			a=1;
			j++;
		}
		else if(lexeme[j]==' '||lexeme[j]=='\0')
		{
                    // System.out.printf(" lexeme is: %c",lexeme[j]);
			a=-3;
			j++;
		}

		else
			a=-1;
}

static void identifier()
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

static void stte0()
{
		if((lexeme[j]>=65&&lexeme[j]<=90)||(lexeme[j]>=97 && lexeme[j]<=122)||lexeme[j]=='_')
		{
                    // System.out.printf(" lexeme is: %c",lexeme[j]);
			a=1;
			j++;
		}
		else
			a=-1;
}

static void stte1()
{

		if((lexeme[j]>=65&&lexeme[j]<=90)||(lexeme[j]>=97&&lexeme[j]<=122))
		{
                    // System.out.printf(" lexeme is: %c",lexeme[j]);
			a=1;
			j++;
		}
		else if(lexeme[j]=='_')
        {
            // System.out.printf(" lexeme is: %c",lexeme[j]);
            a=1;
			j++;
        }

		else if(lexeme[j]>=48&&lexeme[j]<=57)
		{
                    // System.out.printf(" lexeme is: %c",lexeme[j]);
			a=1;
			j++;
		}

		else if(lexeme[j]==' '||lexeme[j]=='\0')
		{
                   // System.out.printf(" lexeme is: %c",lexeme[j]);
			a=-3;

		}

		else
			a=-1;

}
    
    
    
    
    
    
}
