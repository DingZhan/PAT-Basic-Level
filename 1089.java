import java.util.*;

public class Main
{
	public final static int MAX_N = 102;
	
	static boolean Check(int w1, int w2, int words[], int N)
	{
	    int w1w, w2w, i;
	    w1w = words[w1];
	    w2w = words[w2];
	    if((w1w>0 && (w1w==w1 || w1w==w2) ||
	       w1w<0 && (-w1w!=w1 && -w1w!=w2))
	       &&
	       (w2w>0 && (w2w!=w1 && w2w!=w2) ||
	       w2w<0 && (-w2w==w1 || -w2w==w2))
	        )
	    {
	        int lierCount=0;
	        for(i=1; i<=N; ++i)
	        {
	            if(i==w1 || i==w2)
	                continue;
	            int w = words[i];
	            if(w>0 && (w==w1 || w==w2))
	                ++lierCount;
	            else if(w<0 && (-w!=w1 && -w!=w2))
	                ++lierCount;
	        }
	        if(lierCount==1)
	            return true;
	    }
	    return false;
	}
	
	public static void main(String strs[])
	{
	    int i, N, words[], w1, w2=0;
	    boolean bFind=false;
	    Scanner scanner = new Scanner(System.in);
	    words = new int[MAX_N];
	    N = scanner.nextInt();
	    for(i=1; i<=N; ++i)
	    {
	        words[i] = scanner.nextInt();
	    }
	    for(w1=1; w1<=N; ++w1)
	    {
	        for(w2 = w1+1; w2<=N; ++w2 )
	        {
	            if(Check(w1, w2, words, N)||
	            		Check(w2, w1, words, N))
	            {
	                bFind = true;
	                break;
	            }
	        }
	        if(bFind)
	            break;
	    }
	    if(bFind)
	    {
	        System.out.printf("%d %d\n", w1, w2);
	    }
	    else
	    {
	    	System.out.printf("No Solution\n");
	    }
	
	}
}
