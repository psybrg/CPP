import java.util.*;
class Mond
{
	static int n,m;
	public static int rec(int box[][][],int b,int c)
	{
		int i,s=-1,mx=-1;
		if(b==0)
		{
			for(i=0;box[b][i][0]!=-1;i++)
			{
				if(c==box[b][i][1])
					continue;
				if(mx<box[b][i][0])
					mx=box[b][i][0];
			}
			return mx;
		}
		for(i=0;box[b][i][0]!=-1;i++)
		{
		    if((c==box[b][i][1]))
		    	continue;
		    	s=box[b][i][0]+rec(box,b-1,box[b][i][1]);
		    System.out.println(s+"* *"+box[b][i][0]);
		    if(mx<s)
		        mx=s;
		}
    	return mx;
	}
    public static void main(String[] args)
    {
        int i,j,b;
        Scanner inp = new Scanner(System.in);
        int n = inp.nextInt();
        int m = inp.nextInt();
        int [][][] box = new int [n][m][2];
        int [] arr = new int [n];
        for(i=0;i<n;i++)
        {
            arr[i]=0;
            for(j=0;j<m;j++)
                box[i][j][0]=box[i][j][1]=-1;
        }
        for(i=0;i<m;i++)
        {
            b=inp.nextInt();
            box[b-1][arr[b-1]][0]=inp.nextInt();
            box[b-1][arr[b-1]][1]=inp.nextInt();
            arr[b-1]++;
        }
        System.out.println("Hehe"+rec(box,n-1,0));
        for(i=0;i<n;i++)
		{
		    for(j=0;j<m;j++)
		    System.out.print(box[i][j][0]+" "+box[i][j][1]+"\t");
		    System.out.println();
	    }
    }
}
