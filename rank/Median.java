import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

class Solution
{
    static void printH(int h[])
    {
        for(int i=0;i<h.length;i++)
            if(h[i]>0)
                System.out.print(h[i]+" at "+i+"\t");
    }
    double med(int arr[],int d)
    {
        int l=0,h=200;
        printH(arr);
        System.out.println();
        if(d%2==1)
        {
            while((l<h)&&(d>0))
            {
                /*
                if(arr[l]>0&&arr[h]>0)
                {
                    printH(arr);
                    System.out.println();
                }/**/
                if(arr[l]<arr[h])
                {
                    arr[h]-=arr[l];
                    d-=arr[l];
                    d-=arr[l];
                    arr[l]=0;
                    l++;
                }
                else
                {
                    arr[l]-=arr[h];
                    d-=arr[h];
                    d-=arr[h];
                    arr[h]=0;
                    h--;
                }
            }
            return h;
        }
        while((l<h)&&(d>2))
        {
            /*
            if(arr[l]>0&&arr[h]>0)
            {
                printH(arr);
                System.out.println();
            }/**/
            if(arr[l]<arr[h])
            {
                arr[h]-=arr[l];
                d-=arr[l];
                d-=arr[l];
                arr[l]=0;
                l++;
            }
            else
            {
                arr[l]-=arr[h];
                d-=arr[h];
                d-=arr[h];
                arr[h]=0;
                h--;
            }
        }
        double x=(double)(l+h+1)/2;
        //System.out.println(l+"\t"+h);
        //System.out.println("return "+x);
        return x;
    }
    static int activityNotifications(int[] expenditure, int d) {
        int i,n=expenditure.length,t=0;
        int h[]=new int[201];
        for(i=0;i<d;i++)
            h[i]=0;
        for(i=0;i<d;i++)
            h[expenditure[i]]++;
        for(i=d;i<n;i++)
        {
        	Solution x=new Solution();
            int y=(int)(2*x.med(h,d));
            System.out.println(y+"\t"+expenditure[i]);
            if(expenditure[i]>=y)
                t++;
            h[expenditure[i]]++;
            h[expenditure[i-d]]--;
        }
        return  t;
    }
    public static void main(String[] args) throws IOException {
        Scanner inp = new Scanner(System.in);
        int n=inp.nextInt();
        int d=inp.nextInt();
        int arr[]=new int [n];
        for (int i=0; i<n; i++)
            arr[i]=inp.nextInt();
        System.out.println(activityNotifications(arr,d));
    }
}
