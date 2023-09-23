vector<int>/*Solution::/**/maxset(vector<int> &A) {
    
    vector<int>result;
    int n=A.size();
    long long int i,start=0,ending=0,a=0,b=0,sum=A[0],max=-1,j;
    for(i=1;i<n;i++)
    {  
        if(A[i]>=0)
        {
         sum+=A[i];
         b=i;
        }
        else if(A[i]<0)
        {  
        	if(max<sum)
            {
             	max=sum;
             	start=a,ending=b;
            }
            else if(max==sum&&(b-a)>(ending-sum))
                   start=a,ending=b;
            
            for(j=i;j<n;j++)
                 if(A[j]>=0)
                 {
                 	i=j-1;
                 	a=j,b=j;
                 	break;
                 }
            sum = 0;
        }
    }
    if(max<sum)
    {
    	max=sum;
        start=a,ending=b;
    }
    else if(max==sum&&(b-a)>(ending-sum))
        start=a,ending=b;
    for(i=start;i<=ending&&i<n;i++)
    if(A[i]>=0) cout<<A[i]<<" "; 
    return result;
}

