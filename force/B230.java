import java.util.*;
import java.lang.Math;
public class B230
{
	static final int MAX=1000009;
	static Vector<Boolean>isprime=new Vector<>(MAX);
	static Vector<Integer>spf=new Vector<>(MAX);
	static Vector<Integer>prime=new Vector<>();
	static void process()
	{
		isprime.set(0,false);
		isprime.set(1,false);
		for(int i=2;i<MAX;i++)
		{
			if(isprime.get(i))
			{
				prime.add(i);
				spf.set(i,i);
			}
			for(int j=0;
			j<prime.size()&&
			i*prime.get(j)<MAX&&
			prime.get(j)<=spf.get(i);
			j++)
			{
				spf.set(i*prime.get(j),prime.get(j));
				isprime.set(i*prime.get(j),false);
			}	
		}
	}
	public static void main(String[] args)
	{
		Scanner inp=new Scanner(System.in);
		for(int i=0;i<MAX;i++)
		{
			isprime.add(true);
			spf.add(2);
		}
		process();
		int i,t=inp.nextInt();
		long n;
		for(i=0;i<t;i++)
		{
			n=inp.nextLong();
			long tmp=(long)Math.sqrt((double)n);
			if(tmp*tmp==n&&n>1)
			{
				if(isprime.get((int)tmp))
					System.out.println("YES");
				else
					System.out.println("NO");
			}
			else
				System.out.println("NO");
		}
	}
}
