import java.util.*;
public class C441
{
	public static void main(String[] args)
	{
        Scanner inp=new Scanner(System.in );
		int i=0,r=inp.nextInt();
		int j=0,c=inp.nextInt();
		int n=r*c,e=inp.nextInt();
        if(e==1)
            System.out.print(n+" ");
		while(i<r)
		{
			if(e>1)
			{
				if(i%2==0)
				{
					while(j<c-1)
					{
						System.out.println("2 "+(i+1)+" "+(j+1)+" "+(i+1)+" "+(j+2));
						j+=2;
						n-=2;
						e--;
						if(e==1)
						{
							System.out.print(n+" "/*+i+" "+j+" "/**/);
							break;
						}
					}
					if(e!=1)
						j=c-1;
					else
						continue;
					if(c%2==1&&e!=1)
					{
						System.out.println("2 "+(i+1)+" "+(j+1)+" "+(i+2)+" "+(j+1));
						j--;
						n-=2;
						e--;
						if(e==1)
						{
							i++;
							System.out.print(n+" "/*+i+" "+j+" "/**/);
							continue;
						}
					}
				}
				else
				{
					while(j>=0)
					{
						System.out.println("2 "+(i+1)+" "+(j+1)+" "+(i+1)+" "+(j));
						j-=2;
						n-=2;
						e--;
						if(e==1)
						{
							if(j<0)
							{
								i++;
								j++;
							}
								System.out.print(n+" "/*+i+" "+j+" "/**/);
							break;
						}
					}
					if(e!=1)
						j=0;
					else
						continue;
				}
				i++;
			}
			else
			{
				if(i%2==0)
				{
					while(j<c)
					{
						System.out.print((i+1)+" "+(j+1)+" ");
						j++;
						n-=2;
					}
					j=c-1;
				}
				else
				{
					while(j>=0)
					{
						System.out.print((i+1)+" "+(j+1)+" ");
						j--;
						n-=2;
					}
					j=0;
				}
				i++;
			}/**/
		}
	}
}
