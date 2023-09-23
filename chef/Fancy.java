import java.util.Scanner;
public class Fancy
{
	public static void main(String[] args) 
	{
		Scanner inp=new Scanner(System.in);
		int i,t=inp.nextInt();
		inp.nextLine();
		for(i=0;i<t;i++)
		{
			String s=inp.nextLine();
			if(s.startsWith("not "))
		    	System.out.println("Real Fancy");
		    else if(s.endsWith(" not"))
		        System.out.println("Real Fancy");
		    else if(s.contains(" not "))
		        System.out.println("Real Fancy");
		    else
		        System.out.println("regularly fancy");
		}
	}
}

